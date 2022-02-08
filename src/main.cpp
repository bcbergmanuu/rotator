#include <Arduino.h>

/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(1, 2);
//   avoid using pins with LEDs attached

void setup() {
  
  //Keyboard.begin();
  Serial.begin(500000);
  Serial.println("Encoder Test:");
}

long oldPosition  = -999;
long previous = 0;

void loop() {
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    
    previous = oldPosition;
    oldPosition = newPosition;
    
    Serial.println(newPosition);      
  }
}