
#include <OSCBundle.h>

#if defined(CORE_TEENSY)
#include <SLIPEncodedUSBSerial.h>
#else
#include <SLIPEncodedSerial.h>
#endif

#if defined(CORE_TEENSY)
SLIPEncodedUSBSerial SLIPSerial(Serial);
#else
SLIPEncodedSerial SLIPSerial(Serial);
#endif


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

 if (g != 0) {
   if (g == 1){ // swipe right
    strip.setPixelColor(0, 255, 0, 0);
   }
   if (g == 2){ // swipe left
    strip.setPixelColor(0, 0, 255, 0);
   }
  if (g == 8){ // near to far
    strip.setPixelColor(0, 0, 0, 255); 
  }     
 }
 else{
   strip.setPixelColor(0, 10, 10, 10);
 }

    OSCBundle bndl;
    bndl.add("/zx/x").add(x);
    bndl.add("/zx/z").add(z);

    SLIPSerial.beginPacket();
        bndl.send(SLIPSerial); // send the bytes to the SLIP stream
    SLIPSerial.endPacket(); // mark the end of the OSC Packet
    bndl.empty(); // empty the bundle to free room for a new one


 strip.show();
 
 delay(100); // change this value “100” to different values
}
