
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <ESP8266WiFi.h>

int minimum2 = 7; //200
int maximum2= 15;//1023
int maxdelay2 = 400;//

LiquidCrystal_I2C lcd(0x27, 16, 2);
byte ledPin = 2;
char ssid[] = "xxxxxx";           // SSID of your home WiFi
char pass[] = "xxxxxx";            // password of your home WiFi

// Custom Character
byte seismic[8] = { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111, };


int sensePin= A0;

void setup() {
  pinMode(A0, INPUT);
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
  Serial.print("Status: "); Serial.println(WiFi.status());    // Network parameters
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

void loop() {

int reading= analogRead(sensePin);

Serial.println(reading);

reading = constrain(reading, minimum2, maximum2);

Serial.println(reading);

reading = map(reading, minimum2, maximum2, 0, 15);

Serial.println(reading); 

lcd.clear();

for (int i=0; i <= reading; i++){

  lcd.write('*');
}

if (4<=reading && 8>reading){

lcd.setCursor(0, 1);

lcd.print(" ");

lcd.print("Seismic Activity");

delay(500);

}

if (8<=reading){

lcd.setCursor(0, 1);

lcd.print(" ");

lcd.print("Earthquake");

delay(500);

}

delay(maxdelay2);

lcd.clear();

}
