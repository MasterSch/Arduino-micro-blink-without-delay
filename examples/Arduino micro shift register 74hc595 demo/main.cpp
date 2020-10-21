#include <Arduino.h>
/*
  ShiftRegister74HC595.h - Library for easy control of the 74HC595 shift register.
  Created by Timo Denk (www.simsso.de), Nov 2014.
  Additional information are available on http://shiftregister.simsso.de/
  Released into the public domain.
*/

#include <ShiftRegister74HC595.h>

// create shift register object (number of shift registers, data pin, clock pin, latch pin)
ShiftRegister74HC595 sr (2, 10, 11, 12); 
 
void setup() { 
}

void loop() {


  sr.setAllLow(); // set all pins LOW
  delay(1000); 

  sr.setAllHigh(); // set all pins HIGH
  delay(100);
  
  sr.setAllLow(); // set all pins LOW
  delay(1000); 
  
  
  for (int i = 0; i < 12; i++) {
    
    sr.set(i, HIGH); // set single pin HIGH
    delay(250); 
  }
  
    delay(500); 
  
  
  for (int i = 0; i < 12; i++) {
    
    sr.set(i, LOW); // set single pin HIGH
    delay(50); 
  }
  
  
  // read pin (zero based)
  uint8_t stateOfPin5 = sr.get(5);
  
}
