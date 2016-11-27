#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
 Wire.begin();
 strip.begin();
 strip.show(); // Initialize all pixels to 'off'
 Serial.begin(9600);
}
void loop(void)
{
 byte x,z,g;
 Wire.beginTransmission(0x10);
 Wire.write(0x08);
 Wire.endTransmission();
 Wire.requestFrom(0x10, 1, true);
 if (Wire.available()) {
 x = Wire.read();
 }
 Wire.beginTransmission(0x10);
 Wire.write(0x0a);
 Wire.endTransmission();
 Wire.requestFrom(0x10, 1, true);
 if (Wire.available()) {
 z = Wire.read();
 }
 Wire.beginTransmission(0x10);
 Wire.write(0x04);
 Wire.endTransmission();
 Wire.requestFrom(0x10, 1, true);
 if (Wire.available()) {
 g = Wire.read();
 }
 Serial.print("X = ");
 Serial.print(x);
 Serial.print(", Z = ");
 Serial.print(z);
 if (g != 0) {
 Serial.print(" gesture ");
   if (g == 1){ // swipe right
    strip.setPixelColor(0, 255, 0, 0);
   }
   if (g == 2){ // swipe left
    strip.setPixelColor(0, 0, 255, 0);
   }
  if (g == 8){ // near to far
    strip.setPixelColor(0, 0, 0, 255); 
  }     
 Serial.print(g);
 }
 else{
   strip.setPixelColor(0, 10, 10, 10);
 }
 Serial.println(".");

 
 strip.show();
 
 delay(100); // change this value “100” to different values
}
