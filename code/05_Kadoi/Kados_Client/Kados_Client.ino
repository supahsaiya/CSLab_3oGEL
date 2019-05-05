#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>   // for time

byte ledPin = 2;
char ssid[] = "xxxxxx";           // SSID of your home WiFi
char pass[] = "xxxxxx";            // password of your home WiFi

WiFiClient client;
//Time *********************************
const char* host      = "http://api.timezonedb.com/v2/get-time-zone?key=XXXXXXX&format=xml&fields=formatted&by=zone&zone=Europe/Athens";
String payload;               
String nowday;
String nowmonth;
String nowyear;
String nowhour;
String nowmin;
String nowsec;
//-------------
int d;                                                       
int mo;
int y;
int h;
int mi;
int s;

unsigned long prevMillis = millis();
unsigned long interval = 30000;                

//**************************************
// defines pins numbers
#define echoPin 13 // D7 
#define trigPin 15 // D8 

int maximumRange = 350; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

//**************************************

MySQL_Connection conn((Client *)&client);

char INSERT_SQL[] = "INSERT INTO DBname.tbl_skoupidia(id_kados,val_kados,day_kados,month_kados,year_kados,hour_kados,min_kados,sec_kados) VALUES ";

char query[256];

IPAddress server_addr(5, 9 ,70, 242);          // MySQL server IP
char user[] = "xxxxxx";           // MySQL user
char password[] = "xxxxxx";       // MySQL password

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

Serial.begin(115200);               // only for debug
  connect_2_wifi();
  
}

void loop() {

 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = duration/58.2; //Calculate the distance (in cm) based on the speed of sound.
 Serial.println(distance); // distance in cm
 //send to server

  digitalWrite(ledPin, LOW);    // to show the communication only (inverted logic)
  tzdb();
  parse_response();
  client.flush();
  
  digitalWrite(ledPin, HIGH);
  // send data *******************************************
  connect_2_SQL_server_and_Send_Record();
  
  delay(5000); //5 sec
 
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
  SQL_query = String(SQL_query + "(" + 1 + "," + distance + "," + d + "," + mo + "," + y + ",");
  SQL_query = String(SQL_query + h + "," + mi + "," + s + ")");
  
  SQL_query.toCharArray(query,sizeof(query));
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
  cur_mem->execute(query);

  delete cur_mem;
  Serial.println(query);
  
}
void connect_2_wifi(){
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
//------------------------------------

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
