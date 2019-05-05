
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WebSocketsClient.h>   //  https://github.com/kakopappa/sinric/wiki/How-to-add-dependency-libraries
#include <ArduinoJson.h>        // https://github.com/kakopappa/sinric/wiki/How-to-add-dependency-libraries
#include <StreamString.h>

ESP8266WiFiMulti WiFiMulti;
WebSocketsClient webSocket;
WiFiClient client;

#define MyApiKey "xxxxx-xxxx-xxxx-xxxx-xxxxxxxxxx" // TODO: Change to your sinric API Key. Your API Key is displayed on sinric.com dashboard

#define MySSID "xxxxx" // TODO: Change to your Wifi network SSID
#define MyWifiPassword "xxxxxx" // TODO: Change to your Wifi network password

#define HEARTBEAT_INTERVAL 300000 // 5 Minutes 

uint64_t heartbeatTimestamp = 0;
bool isConnected = false;

int buzzer1 = 5; //D1
int buzzer2 = 4; //D2
int buzzer3 = 14; //D5
 
void turnOn(String deviceId) {
  if (deviceId == "5c1f3bbc601d036f4d37b424") // Device ID of first device
  
  {  
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(buzzer1, HIGH); 
  } 
  else if (deviceId == "5c208afba1be7e7f651b5f4d") // Device ID of second device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(buzzer2, HIGH);
  }
  else if (deviceId == "5c208b22a1be7e7f651b5f50") // Device ID of third device
  { 
    Serial.print("Turn on device id: ");
    Serial.println(deviceId);
    digitalWrite(buzzer3, HIGH);
  }
  else {
    Serial.print("Turn on for unknown device id: ");
    Serial.println(deviceId); 
      
  }     
}

void turnOff(String deviceId) {
   if (deviceId == "5c1f3bbc601d036f4d37b424") // Device ID of first device
   {  
     Serial.print("Turn off Device ID: ");
     Serial.println(deviceId);
     digitalWrite(buzzer1, LOW); 
   }
   else if (deviceId == "5c208afba1be7e7f651b5f4d") // Device ID of second device
   { 
     Serial.print("Turn off Device ID: ");
     Serial.println(deviceId);
     digitalWrite(buzzer2, LOW);
  }
  else if (deviceId == "5c208b22a1be7e7f651b5f50") // Device ID of second device
   { 
     Serial.print("Turn off Device ID: ");
     Serial.println(deviceId);
     digitalWrite(buzzer3, LOW);
  }
  else {
     Serial.print("Turn off for unknown device id: ");
     Serial.println(deviceId);  
       
  }
}

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  switch(type) {
    case WStype_DISCONNECTED:
      isConnected = false;    
      Serial.printf("[WSc] Webservice disconnected from sinric.com!\n");
      break;
    case WStype_CONNECTED: {
      isConnected = true;
      Serial.printf("[WSc] Service connected to sinric.com at url: %s\n", payload);
      Serial.printf("Waiting for commands from sinric.com ...\n");        
      }
      break;
    case WStype_TEXT: {
        Serial.printf("[WSc] get text: %s\n", payload);
        
        DynamicJsonBuffer jsonBuffer;
        JsonObject& json = jsonBuffer.parseObject((char*)payload); 
        String deviceId = json ["deviceId"];     
        String action = json ["action"];
        
        
        
        if(action == "setPowerState") { // Switch 
            //String value = json ["value"]["on"];
            String value = json ["value"];
            
            if(value == "ON") {
                turnOn(deviceId);
            
            } else {
                turnOff(deviceId);
            }
        }
        else if (action == "test") {
            Serial.println("[WSc] received test command from sinric.com");
        }
      }
      break;
    case WStype_BIN:
      Serial.printf("[WSc] get binary length: %u\n", length);
      break;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(buzzer3, OUTPUT);
  
  WiFiMulti.addAP(MySSID, MyWifiPassword);
  Serial.println();
  Serial.print("Connecting to Wifi: ");
  Serial.println(MySSID);  

  // Waiting for Wifi connect
  while(WiFiMulti.run() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  if(WiFiMulti.run() == WL_CONNECTED) {
    Serial.println("");
    Serial.print("WiFi connected. ");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }

 
  webSocket.begin("iot.sinric.com", 80, "/"); //"iot.sinric.com", 80
  webSocket.onEvent(webSocketEvent);
  webSocket.setAuthorization("apikey", MyApiKey);
  
  // try again every 5000ms if connection has failed
  webSocket.setReconnectInterval(5000);   // If you see 'class WebSocketsClient' has no member named 'setReconnectInterval' error update arduinoWebSockets
}

void loop() {
  webSocket.loop();
  
  if(isConnected) {
      uint64_t now = millis();
      
      // Send heartbeat in order to avoid disconnections during ISP resetting IPs over night. Thanks @MacSass
      if((now - heartbeatTimestamp) > HEARTBEAT_INTERVAL) {
          heartbeatTimestamp = now;
          webSocket.sendTXT("H");          
      }
  }   
}
 
