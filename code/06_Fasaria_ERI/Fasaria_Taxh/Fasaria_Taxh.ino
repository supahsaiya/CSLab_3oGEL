/****************************************
Example Sound Level Sketch for the 
Adafruit Microphone Amplifier
****************************************/
 
const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
#include <FastLED.h>
#define NUM_LEDS 10
#define DATA_PIN 5
CRGB leds[NUM_LEDS];

void setup() 
{
   Serial.begin(9600);
   FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}


void loop() 
{
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level

   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
  

   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   
   {
      sample = analogRead(0);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
    
    int h = map(peakToPeak,0,signalMax,0,25);  
    int z = constrain(h, 0, 10);  
 
 Serial.print(h);     
 Serial.print(' ');
 Serial.print(z);
 Serial.println();
 
    for(int dot = 0;dot < (z); dot++)
    
    {
    
    leds[dot] = CRGB::Aqua;
    FastLED.show();
    delay (50);

    }
    
    for (int dot = (NUM_LEDS-1); dot >=(z) ; dot--)
    
    { leds[dot] = CRGB::Black;
    
    FastLED.show();
    
    delay(20);
    
    }
 }


