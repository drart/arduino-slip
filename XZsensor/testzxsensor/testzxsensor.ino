#include <Wire.h>
void setup()
{
 Wire.begin();
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
 Serial.print(g);
 }
 Serial.println(".");
 delay(100); // change this value “100” to different values
}
