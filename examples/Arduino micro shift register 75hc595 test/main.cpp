#include <Arduino.h>


//**************************************************************//
//  Name    : shiftOutCode, Hello World                                
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis 
//  Date    : 25 Oct, 2006    
//  Modified: 23 Mar 2010                                 
//  Version : 2.0                                             
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255                           
//****************************************************************

//Pin connected to ST_CP of 74HC595
int latchPin = 12;
//Pin connected to SH_CP of 74HC595
int clockPin = 11;
////Pin connected to DS of 74HC595
int dataPin = 10;



void setup() {

  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

}

void loop() {
int x = 0;
int y = 0;
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, 0);  
    shiftOut(dataPin, clockPin, MSBFIRST, 0);  
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);

while (y < 16)  {
if (y < 4) bitSet(x,0);

    digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, highByte(x));  
    shiftOut(dataPin, clockPin, MSBFIRST, lowByte(x));  
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
delay(50);
x = x << 1;
y++;
}
//y--;
x = 0;

while (y > 0)  {
if (y > 12) bitSet(x,11);

    digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, highByte(x));  
    shiftOut(dataPin, clockPin, MSBFIRST, lowByte(x));  
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
delay(50);
x = x >> 1;
y--;
}


}