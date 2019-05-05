#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <ESP8266WiFi.h>
#include<dht.h>

#define DHT11_PIN 14 //D5 NodeMcu

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
byte ledPin = 2;

char ssid[] = "xxxxxx";           // SSID of your home WiFi
char pass[] = "xxxxxx";            // password of your home WiFi


WiFiServer server(80);
IPAddress ip(192, 168, 1, 103);            // IP address of the server
IPAddress gateway(192,168,1,1);           // gateway of your network
IPAddress subnet(255,255,255,0);          // subnet mask of your network

dht DHT;
String humiout="XX";
String tempout="XX";

void setup()
{
  // initialize the LCD
  lcd.begin(); // Init with pin default ESP8266 or ARDUINO
  lcd.backlight();
  lcd.setCursor(0, 0);

#if defined(ESP8266)
  lcd.print("ESP8266");
#else
  lcd.print("ARDUINO");
#endif

  
  //******************************
  Serial.begin(115200);               // only for debug
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
  
  Serial.println("Connected to wifi");
  Serial.print("Status: "); Serial.println(WiFi.status());  // some parameters from the network
  Serial.print("IP: ");     Serial.println(WiFi.localIP());
  Serial.print("Subnet: "); Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: "); Serial.println(WiFi.gatewayIP());
  Serial.print("SSID: "); Serial.println(WiFi.SSID());
  Serial.print("Signal: "); Serial.println(WiFi.RSSI());
  Serial.print("Networks: "); Serial.println(WiFi.scanNetworks());
  pinMode(ledPin, OUTPUT);
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());
  delay(2000);
}

void loop()
{
    
  int chk = DHT.read11(DHT11_PIN);
  print_vals_LCD();
    
  delay(2000); 
  digitalWrite(ledPin,HIGH);
  WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      digitalWrite(ledPin, LOW);  // to show the communication only (inverted logic)
      Serial.println(".");
      String request = client.readStringUntil('\r');    // receives the message from the client
            
      Serial.print("From client: "); 
      Serial.println(request);
      //----------------------------------
      int ind1 = request.indexOf('?');  //finds location of first ,
      tempout = request.substring(0, ind1);   //captures first data String
      int ind2 = request.indexOf('?', ind1+1 );   //finds location of second ,
      humiout = request.substring(ind1+1, ind2);   //captures second data String
      Serial.print("Temp out");Serial.print(tempout);
      Serial.print("Humi out");Serial.println(humiout);
      //----------------------------------
      
      client.println("Hi client! No, I am listening.\r"); // sends the answer to the client
      digitalWrite(ledPin, HIGH);
      print_vals_LCD();
      client.flush();
    }
    client.stop();                // tarminates the connection with the client
  }
}

void print_vals_LCD(){
 lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("H IN:" );
  lcd.print(int(DHT.humidity));lcd.print("%");
  lcd.print(" O:" );
  lcd.print(humiout);lcd.print("%");
  
  lcd.setCursor(0,1);
  lcd.print("T IN:");
  lcd.print(int(DHT.temperature));lcd.print("c");
  lcd.print(" O:");
  lcd.print(tempout);lcd.print("c"); 
}

