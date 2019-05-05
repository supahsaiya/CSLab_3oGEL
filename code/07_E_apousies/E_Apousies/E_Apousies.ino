
#define SS_PIN 4  //D2
#define RST_PIN 5 //D1
//wifi *********************************
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
//**************************************
#include <SPI.h>
#include <MFRC522.h>
#include <ESP8266HTTPClient.h>   // for time
// for MYSQL
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
//int statuss = 0;
int out = 0;

int ledGreenOK = 2;   // D4 
int ledYellowStby=16; // D0 Nodemcu

char ssid[] = "xxxxxx";               // SSID of your home WiFi
char pass[] = "xxxxxx";               // password of your home WiFi


unsigned long askTimer = 0;

IPAddress server(192,168,1,96);       // the fix IP address of the server
WiFiClient client;
//Time *********************************
const char* host      = "http://api.timezonedb.com/v2/get-time-zone?key=XXXXXX&format=xml&fields=formatted&by=zone&zone=Europe/Athens";
String payload;               
String nowday;
String nowmonth;
String nowyear;
String nowhour;
String nowmin;
String nowsec;

unsigned long prevMillis = millis();
unsigned long interval = 30000;                 // Refresh in loop every 30 seconds

//**************************************

//Struct record for student
typedef struct studRec{
  int am;
  String rfidcard;
  String surname;
  String fname;
  String tmimagen;
};
struct studRec studRecALL[100];
int num_students=15;
int thesi; 

MySQL_Connection conn((Client *)&client);

char INSERT_SQL[] = "INSERT INTO DBname.tbl_apousies(student_AM,student_RFIDno,student_surname,student_fname,student_tmima,student_year,student_month,student_day,student_hour,student_min,student_sec) VALUES ";

char query[512]; //512

IPAddress server_addr(5, 9 ,70, 242);          // MySQL server IP
char user[] = "xxxxxx";           // MySQL user
char password[] = "xxxxxx";       // MySQL password

int d;                                                        
  int mo;
  int y;
  int h;
  int mi;
  int s;
// time parse
void setup() 
{
  db_student_fill();
  
    
  Serial.begin(115200);   
  SPI.begin();      
  mfrc522.PCD_Init();   
  
  WiFi.begin(ssid, pass);             
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected to wifi");
  Serial.print("Status: "); Serial.println(WiFi.status());    
  Serial.print("IP: ");     Serial.println(WiFi.localIP());
  Serial.print("Subnet: "); Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: "); Serial.println(WiFi.gatewayIP());
  Serial.print("SSID: "); Serial.println(WiFi.SSID());
  Serial.print("Signal: "); Serial.println(WiFi.RSSI());
  pinMode(ledGreenOK,OUTPUT);
  pinMode(ledYellowStby,OUTPUT);
   
}
void loop() 
{
  int answer;
  digitalWrite(ledGreenOK, LOW);
  digitalWrite(ledYellowStby,HIGH);
  //digitalWrite(relay,LOW);
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.println();
  Serial.print(" UID tag :");
  String content="" ;
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println();
  
  
    digitalWrite(ledGreenOK, LOW);    // to show the communication only (inverted logic)
  
    
    
    client.flush();
    Serial.println(content);
    answer=Search_4_RFID_card(content.substring(1)); //content=id card
   
    if (answer==1){
      digitalWrite(ledGreenOK, HIGH);
      digitalWrite(ledYellowStby,LOW);
      //digitalWrite(relay,HIGH);
      Serial.println(" Access Granted ");
      tzdb();
      parse_response();
      connect_2_SQL_server_and_Send_Record();

    }
    else{
      digitalWrite(ledGreenOK, LOW);
      int j;
      for(j=0;j<5;j++){
        digitalWrite(ledYellowStby, LOW);
        delay(50);
        digitalWrite(ledYellowStby, HIGH);
        delay(50);
      }
      Serial.println(" Access Denied ");
    }
    
    delay(500);                  
   
} 
// Time **************************************
void tzdb() {
  int httpCode = 0;                                       
  HTTPClient http;                                          
  
  Serial.println("Connecting to TimezoneDB...");

  http.begin(host);                                        
  httpCode = http.GET();                               

  while (httpCode == 0) {                             
    delay(1000);                                          
    http.begin(host);                                     
    httpCode = http.GET();
  }

  payload = http.getString();                        
  Serial.println(payload);                             
  http.end();                                                

}


void parse_response() {
  int colon = payload.indexOf(':');                
  

  nowday = payload.substring(colon - 5, colon - 3);     
  d = nowday.toInt();                                               
  nowmonth = payload.substring(colon - 8, colon - 6);
  mo = nowmonth.toInt();
  nowyear = payload.substring(colon - 13, colon - 9);
  y = nowyear.toInt();

  nowhour = payload.substring(colon - 2, colon);
  h = nowhour.toInt();
  nowmin = payload.substring(colon + 1, colon + 3);
  mi = nowmin.toInt();
  nowsec = payload.substring(colon + 4, colon + 6);
  s = nowsec.toInt();

  Serial.print("Today's date is:   ");
  Serial.print(y);
  Serial.print("-");
  Serial.print(mo);
  Serial.print("-");
  Serial.println(d);

  Serial.print("Current local time is:   ");
  Serial.print(h);
  Serial.print(":");
  Serial.print(mi);
  Serial.print(":");
  Serial.println(s);
  Serial.println();

 
}
  void db_student_fill(){
  
  studRecALL[0].am =100;
  studRecALL[0].rfidcard="05 D1 90 89";
  studRecALL[0].surname="Student_01";
  studRecALL[0].fname="Georgios";
  studRecALL[0].tmimagen="B1";
  //--------------------------------------
  studRecALL[1].am =101;
  studRecALL[1].rfidcard="95 49 BF 59";
  studRecALL[1].surname="Student_02";
  studRecALL[1].fname="Panagiota";
  studRecALL[1].tmimagen="B1";
  //--------------------------------------
  studRecALL[2].am =102;
  studRecALL[2].rfidcard="87 2A BE 89";
  studRecALL[2].surname="Student_03";
  studRecALL[2].fname="Nikos";
  studRecALL[2].tmimagen="B1";
 //--------------------------------------
  studRecALL[3].am =103;
  studRecALL[3].rfidcard="A4 44 BF 59";
  studRecALL[3].surname="Student_04";
  studRecALL[3].fname="Kostantinos";
  studRecALL[3].tmimagen="B1";
  //--------------------------------------
  studRecALL[4].am =104;
  studRecALL[4].rfidcard="E7 18 C0 59";
  studRecALL[4].surname="Student_05";
  studRecALL[4].fname="Giorgos";
  studRecALL[4].tmimagen="B1";
  //--------------------------------------
  studRecALL[5].am =105;
  studRecALL[5].rfidcard="15 74 A4 A9";
  studRecALL[5].surname="Student_06";
  studRecALL[5].fname="Athanasios";
  studRecALL[5].tmimagen="B1";
    //--------------------------------------
  studRecALL[6].am =106;
  studRecALL[6].rfidcard="87 A8 C0 59";
  studRecALL[6].surname="Student_07";
  studRecALL[6].fname="Xristina";
  studRecALL[6].tmimagen="A4";
    //--------------------------------------
  studRecALL[7].am =107;
  studRecALL[7].rfidcard="7D 3F A6 A9";
  studRecALL[7].surname="Student_08";
  studRecALL[7].fname="Panagiotis";
  studRecALL[7].tmimagen="B3";
    //--------------------------------------
  studRecALL[8].am =108;
  studRecALL[8].rfidcard="89 63 BD 89";
  studRecALL[8].surname="Student_09";
  studRecALL[8].fname="Anastasios";
  studRecALL[8].tmimagen="B2";
      //--------------------------------------
  studRecALL[9].am =109;
  studRecALL[9].rfidcard="36 61 A4 A9";
  studRecALL[9].surname="Student_10";
  studRecALL[9].fname="Dimitra";
  studRecALL[9].tmimagen="A2";
//--------------------------------------
  studRecALL[10].am =110;
  studRecALL[10].rfidcard="5F 3D BE 89";
  studRecALL[10].surname="Student_11";
  studRecALL[10].fname="Eleni";
  studRecALL[10].tmimagen="A4";
    //--------------------------------------
  studRecALL[11].am =111;
  studRecALL[11].rfidcard="B2 22 A4 A9";
  studRecALL[11].surname="Student_12";
  studRecALL[11].fname="Eri";
  studRecALL[11].tmimagen="B1";
    //--------------------------------------
  studRecALL[12].am =112;
  studRecALL[12].rfidcard="87 C8 A5 A9";
  studRecALL[12].surname="Student_13";
  studRecALL[12].fname="Euaggelos";
  studRecALL[12].tmimagen="B2";
    //--------------------------------------
  studRecALL[13].am =113;
  studRecALL[13].rfidcard="5E 73 BD 89";
  studRecALL[13].surname="Student_14";
  studRecALL[13].fname="Aikaterini";
  studRecALL[13].tmimagen="A2";
      //--------------------------------------
  studRecALL[14].am =114;
  studRecALL[14].rfidcard="C2 F2 C0 59";
  studRecALL[14].surname="Student_15";
  studRecALL[14].fname="Spiros";
  studRecALL[14].tmimagen="A4";
   
  
  
}

  bool Search_4_RFID_card(String gotRFID){
    int i;
    bool found;
    i=0;
    found=false;
    while (i<num_students && found==false){
        if (studRecALL[i].rfidcard==gotRFID){
            thesi=i;         
            found=true;
        }
        i++;
    }
    return found;
}
void connect_2_SQL_server_and_Send_Record(){
  
// Connect to SQL Server *****************************************
  while (conn.connect(server_addr, 3306, user, password) != true) {
    delay(200);
    Serial.print ( "." );
  }

  Serial.println("");
  Serial.println("Connected to SQL Server!"); 
  //**********************   SQL Server ****************************  

  String SQL_query=INSERT_SQL;
  SQL_query = String(SQL_query + "(" + studRecALL[thesi].am + ",");
  SQL_query = String(SQL_query + "'" + studRecALL[thesi].rfidcard + "'" + ",");
  SQL_query = String(SQL_query + "'" + studRecALL[thesi].surname +  "'" + ",");
  SQL_query = String(SQL_query + "'" + studRecALL[thesi].fname +  "'" + ",");
  SQL_query = String(SQL_query + "'" + studRecALL[thesi].tmimagen + "'" + ",");
  SQL_query = String(SQL_query + d + "," + mo + "," + y + ",");
  SQL_query = String(SQL_query + h + "," + mi + "," + s + ")");
  
  SQL_query.toCharArray(query,sizeof(query));
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
  cur_mem->execute(query);

  delete cur_mem;
  Serial.println(query);
  
}
