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

dht DHT;

IPAddress server(192,168,1,103);       // the fix IP address of the server
WiFiClient client;

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

  
  Serial.begin(115200);               
  WiFi.begin(ssid, pass);             // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.print("Status: "); Serial.println(WiFi.status());    
  Serial.print("IP: ");     Serial.println(WiFi.localIP());
  Serial.print("Subnet: "); Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: "); Serial.println(WiFi.gatewayIP());
  Serial.print("SSID: "); Serial.println(WiFi.SSID());
  Serial.print("Signal: "); Serial.println(WiFi.RSSI());
  pinMode(ledPin, OUTPUT);
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());
  delay(2000);
}

void loop()
{
  client.connect(server, 80);   // Connection to the server
  digitalWrite(ledPin, LOW);    // to show the communication only (inverted logic)
  Serial.println(".");
  
  int chk = DHT.read11(DHT11_PIN);
  //--------------------------------
  client.print(int(DHT.temperature));client.print("?");
  client.print(int(DHT.humidity));client.print("?");
  client.println("\r");
  String answer = client.readStringUntil('\r');   // receives the answer from the sever
  Serial.println("from server: " + answer);
  client.flush();
  //--------------------------------
  delay(1000);
  digitalWrite(ledPin,LOW);
  
}
