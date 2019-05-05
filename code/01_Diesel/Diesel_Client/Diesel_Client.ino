#include <ESP8266WiFi.h>

byte ledPin = 2;

char ssid[] = "xxxxxx";           // SSID of your home WiFi
char pass[] = "xxxxxx";           // password of your home WiFi
IPAddress server(192,168,1,90);   // the fix IP address of the server
WiFiClient client;

// defines pins numbers
#define echoPin 13 // D7 
#define trigPin 15 // D8 

int maximumRange = 350; // Maximum range needed
int minimumRange = 0;   // Minimum range needed
long duration, distance; // Duration used to calculate distance

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
 client.connect(server, 80);   // Connection to the server
  digitalWrite(ledPin, LOW);    // to show the communication only (inverted logic)
  Serial.println(".");
  
  client.print(distance);
  client.println("\r");
  String answer = client.readStringUntil('\r');   // receives the answer from the sever
  Serial.println("from server: " + answer);
  client.flush();
  digitalWrite(ledPin, HIGH);
delay(1000);
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



