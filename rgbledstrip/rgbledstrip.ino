// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!
 
#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3
 
#define FADESPEED 20     // make this higher to slow down

#include "rgb.h"

void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  Serial.begin(9600);
}

const RGB red = { 255 , 0 , 0 };
const RGB orange = { 255 , 127 , 0 };
const RGB yellow = { 255 , 255 , 0 };
const RGB green = { 0, 255 , 0 };
const RGB blue = { 0, 0, 255 };
const RGB indigo = { 111 , 0, 255 };
const RGB violet =  { 143 , 0 , 255 };
const RGB rainbow[7] = {red, orange, yellow, green, blue, indigo, violet};

void loop() {
  for (unsigned int i = 0; i < 6; i++) {
    fade_from_to(rainbow[i], rainbow[i+1]);
  }
}
