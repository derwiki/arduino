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

void loop() {
  RGB red = { 0 , 0 , 127 };
  RGB yellow = { 255, 255, 0 };
  RGB to = { 255 , 0 , 255 };
  fade_from_to(red, yellow);
  fade_from_to(yellow, red);
}
