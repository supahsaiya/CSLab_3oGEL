
#include <SPI.h>
#include <ESP8266WiFi.h>

byte ledPin = 2;

char ssid[] = "xxxxxx";           // SSID of your home WiFi
char pass[] = "xxxxxx";            // password of your home WiFi
WiFiServer server(80);                    

IPAddress ip(192, 168, 1, 105);            // IP address of the server
IPAddress gateway(192,168,1,1);           // gateway of your network
IPAddress subnet(255,255,255,0);          // subnet mask of your network

int led01=5; //D1
int led02=4; //D2
int led03=0; //D3

void setup() {
  Serial.begin(115200);                   // only for debug
  Serial.println("Initialising connection");
  Serial.print(F("Setting static ip to : "));
  Serial.println(ip);
  WiFi.config(ip, gateway, subnet);       // forces to use the fix IP
  WiFi.begin(ssid, pass);                 // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  server.begin();                         // starts the server
x
  pinMode(ledPin, OUTPUT);
  Serial.println("");
  Serial.println("WiFi Connected");

  
  Serial.print("Assigned IP: ");
  Serial.print(WiFi.localIP());
  Serial.println("");
  pinMode(led01,OUTPUT);
  pinMode(led02,OUTPUT);
  pinMode(led03,OUTPUT);
  digitalWrite(led01,LOW);
  digitalWrite(led02,LOW);
  digitalWrite(led03,LOW);
}

void loop () {
  WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      digitalWrite(ledPin, LOW);  // to show the communication only (inverted logic)
      Serial.println(".");
      String request = client.readStringUntil('\r');    // receives the message from the client
      //---------------------
      int ind1 = request.indexOf('?');  //finds location of first ,
      String angle = request.substring(0, ind1);   //captures first data String
      //int ind2 = request.indexOf('?', ind1+1 );   //finds location of second ,
      int ind2 = request.indexOf('H');
      String fuel = request.substring(ind1+1, ind2);   //captures second data String
      int ind3 = request.indexOf(',', ind2+1 );
      String speed1 = request.substring(ind2+1, ind3+1);
      int ind4 = request.indexOf(',', ind3+1 );
      String altidude = request.substring(ind3+1); //captures remain part of data after last ,
      
      Serial.print("From client: "); Serial.println(fuel);
      if (fuel=="pin1=ON "){
        digitalWrite(led01,HIGH);
      }
      if (fuel=="pin1=OFF "){
        digitalWrite(led01,LOW);
      }
      if (fuel=="pin2=ON "){
        digitalWrite(led02,HIGH);
      }
      if (fuel=="pin2=OFF "){
        digitalWrite(led02,LOW);
      }
      if (fuel=="pin3=ON "){
        digitalWrite(led03,HIGH);
      }
      if (fuel=="pin3=OFF "){
        digitalWrite(led03,LOW);
      }
            
      client.flush();
      client.println("OK i got it!\r"); // sends the answer to the client
     
      digitalWrite(ledPin, HIGH);
     
    }
    client.stop();               
  }
}
