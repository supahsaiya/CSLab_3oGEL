#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
byte ledPin = 2;

char ssid[] = "xxxxxx";           // SSID of your home WiFi
char pass[] = "xxxxxx";            // password of your home WiFi
WiFiServer server(80);                    


IPAddress ip(192, 168, 1, 90);            // IP address of the server
IPAddress gateway(192,168,1,1);           // gateway of your network
IPAddress subnet(255,255,255,0);          // subnet mask of your network

void setup() {
  Serial.begin(115200);
  // initialize the LCD *******************************************************
  lcd.begin(); 
  lcd.backlight();
  lcd.setCursor(0, 0);
  
  Serial.print(F("Setting static ip to : "));
  Serial.println(ip);
  WiFi.config(ip, gateway, subnet);       // forces to use the fix IP
  WiFi.begin(ssid, pass);                 // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  server.begin();                         // starts the server
  
  Serial.println("Connected to wifi");
  Serial.print("Status: "); Serial.println(WiFi.status());  // some parameters from the network
  Serial.print("IP: ");     Serial.println(WiFi.localIP());
  Serial.print("Subnet: "); Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: "); Serial.println(WiFi.gatewayIP());
  Serial.print("SSID: "); Serial.println(WiFi.SSID());
  Serial.print("Signal: "); Serial.println(WiFi.RSSI());
  Serial.print("Networks: "); Serial.println(WiFi.scanNetworks());
  
  pinMode(ledPin, OUTPUT);
  Serial.println("");
  Serial.println("WiFi Connected");

  
  Serial.print("Assigned IP: ");
  Serial.print(WiFi.localIP());
  Serial.println("");
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());
}

void loop () {
  WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      digitalWrite(ledPin, LOW);  // to show the communication only (inverted logic)
      Serial.println(".");
      String request = client.readStringUntil('\r');    // receives the message from the client
      Serial.print("From client: "); Serial.println(request);
      client.flush();
      client.println("I got the value, OK\r"); // sends the answer to the client
      digitalWrite(ledPin, HIGH);
     
      client.println(request.toInt());
      if(request.toInt() < 20){
         Serial.println("Alert");  
      }
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(WiFi.localIP());
      lcd.setCursor(0, 1);
      lcd.print(request.toInt());
    }
    client.stop();                // tarminates the connection with the client
    
  }
}

