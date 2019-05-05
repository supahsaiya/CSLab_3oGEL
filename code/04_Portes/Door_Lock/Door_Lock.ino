
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

int out = 0;

//wifi *********************************

int ledGreenOK = 2;
int ledYellowStby=16; // D0 Nodemcu
int relay=15; //D8 Nodemcu

char ssid[] = "xxxxxx";
char pass[] = "xxxxxx";

unsigned long askTimer = 0;

IPAddress server(192,168,1,96);       // the fix IP address of the server
WiFiClient client;
//Time *********************************
const char* host      = "http://api.timezonedb.com/v2/get-time-zone?key=XXXXXXXXXXXX&format=xml&fields=formatted&by=zone&zone=Europe/Athens";
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
typedef struct teacherRec{
  int am;
  String rfidcard;
  String surname;
  String fname;
  String aithousa;
};
struct teacherRec teacherRecALL[50];
int num_teachers=7;
int thesi; 
//SQL
MySQL_Connection conn((Client *)&client);

char INSERT_SQL[] = "INSERT INTO DBname.tbl_portes(teacher_AM,teacher_RFIDno,teacher_surname,teacher_fname,teacher_aithousa,teacher_year,teacher_month,teacher_day,teacher_hour,teacher_min,teacher_sec) VALUES ";

char query[512]; 

IPAddress server_addr(xx, xx ,xx, xxx);          // MySQL server IP
char user[] = "xxxxxx";           // MySQL user
char password[] = "xxxxxxx";       // MySQL password
//time parse
int d;                                                        // Variables to hold data as integers
  int mo;
  int y;
  int h;
  int mi;
  int s;
// time parse
void setup() 
{
  db_student_fill();
  
    
  Serial.begin(115200);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  //wifi******************
  WiFi.begin(ssid, pass);             // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected to wifi");
  Serial.print("Status: "); Serial.println(WiFi.status());    // Network parameters
  Serial.print("IP: ");     Serial.println(WiFi.localIP());
  Serial.print("Subnet: "); Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: "); Serial.println(WiFi.gatewayIP());
  Serial.print("SSID: "); Serial.println(WiFi.SSID());
  Serial.print("Signal: "); Serial.println(WiFi.RSSI());
  pinMode(ledGreenOK,OUTPUT);
  pinMode(ledYellowStby,OUTPUT);
  pinMode(relay,OUTPUT);
   
}
void loop() 
{
  int answer;
  digitalWrite(ledGreenOK, LOW);
  digitalWrite(ledYellowStby,HIGH);
  digitalWrite(relay,LOW);
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
   
    digitalWrite(ledGreenOK, LOW);    
    
    client.flush();
    Serial.println(content);
    answer=Search_4_RFID_card(content.substring(1)); //content=id card
    
    if (answer==1){
      digitalWrite(ledGreenOK, HIGH);
      digitalWrite(ledYellowStby,LOW);
      digitalWrite(relay,HIGH);
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
//------------------------------------

void parse_response() {
  int colon = payload.indexOf(':');                 // Set the first colon in time as reference point
  

  nowday = payload.substring(colon - 5, colon - 3);     // Get data as substring
  d = nowday.toInt();                                                // and convert to int
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

  // Print integers without leading zeros - use in calculations

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
  
  teacherRecALL[0].am =100;
  teacherRecALL[0].rfidcard="E7 77 74 5B";
  teacherRecALL[0].surname="Epwnymo_01";
  teacherRecALL[0].fname="Onoma_01";
  teacherRecALL[0].aithousa="AITHOUSA 01";
  //--------------------------------------
  teacherRecALL[1].am =101;
  teacherRecALL[1].rfidcard="BC 11 7D 5B";
  teacherRecALL[1].surname="Epwnymo_02";
  teacherRecALL[1].fname="Onoma_02";
  teacherRecALL[1].aithousa="AITHOUSA 01";
  //--------------------------------------
  teacherRecALL[2].am =102;
  teacherRecALL[2].rfidcard="7F 96 9F 59";
  teacherRecALL[2].surname="Epwnymo_03";
  teacherRecALL[2].fname="Onoma_03";
  teacherRecALL[2].aithousa="AITHOUSA 01";
 //--------------------------------------
  teacherRecALL[3].am =103;
  teacherRecALL[3].rfidcard="95 8B 74 5B";
  teacherRecALL[3].surname="Epwnymo_04";
  teacherRecALL[3].fname="Onoma_04";
  teacherRecALL[3].aithousa="AITHOUSA 01";
  //--------------------------------------
  teacherRecALL[4].am =104;
  teacherRecALL[4].rfidcard="99 84 72 5B";
  teacherRecALL[4].surname="Epwnymo_05";
  teacherRecALL[4].fname="Onoma_05";
  teacherRecALL[4].aithousa="AITHOUSA 01";
    //--------------------------------------
  teacherRecALL[5].am =105;
  teacherRecALL[5].rfidcard="30 7E 73 5B";
  teacherRecALL[5].surname="Epwnymo_06";
  teacherRecALL[5].fname="Onoma_06";
  teacherRecALL[5].aithousa="AITHOUSA 01";
    //--------------------------------------
  teacherRecALL[6].am =106;
  teacherRecALL[6].rfidcard="0D EB 4E D3";
  teacherRecALL[6].surname="Epwnymo_07";
  teacherRecALL[6].fname="Onoma_07";
  teacherRecALL[6].aithousa="AITHOUSA 01";
}

  bool Search_4_RFID_card(String gotRFID){
    int i;
    bool found;
    i=0;
    found=false;
    while (i<num_teachers && found==false){
        if (teacherRecALL[i].rfidcard==gotRFID){
            thesi=i;         
            found=true;
            
            //break;
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
  SQL_query = String(SQL_query + "(" + teacherRecALL[thesi].am + ",");
  SQL_query = String(SQL_query + "'" + teacherRecALL[thesi].rfidcard + "'" + ",");
  SQL_query = String(SQL_query + "'" + teacherRecALL[thesi].surname +  "'" + ",");
  SQL_query = String(SQL_query + "'" + teacherRecALL[thesi].fname +  "'" + ",");
  SQL_query = String(SQL_query + "'" + teacherRecALL[thesi].aithousa + "'" + ",");
  SQL_query = String(SQL_query + d + "," + mo + "," + y + ",");
  SQL_query = String(SQL_query + h + "," + mi + "," + s + ")");
  
  SQL_query.toCharArray(query,sizeof(query));
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
  cur_mem->execute(query);

  delete cur_mem;
  Serial.println(query);
  
}
