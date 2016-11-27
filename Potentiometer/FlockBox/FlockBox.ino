
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

void setup() {
  Serial.begin(9600); // Rate is ignored for USB devices such as the Teensy.
}

void loop() {

    OSCBundle bndl;
    bndl.add("/fader/0").add( analogRead(0) );
    bndl.add("/fader/1").add( analogRead(1) );
    bndl.add("/fader/2").add( analogRead(2) );
    bndl.add("/fader/3").add( analogRead(3) );
    bndl.add("/fader/4").add( analogRead(4) );
    bndl.add("/fader/5").add( analogRead(5) );
    bndl.add("/fader/6").add( analogRead(6) );

    SLIPSerial.beginPacket();
        bndl.send(SLIPSerial); // send the bytes to the SLIP stream
    SLIPSerial.endPacket(); // mark the end of the OSC Packet
    bndl.empty(); // empty the bundle to free room for a new one
  
  delay(1000);
  
}


