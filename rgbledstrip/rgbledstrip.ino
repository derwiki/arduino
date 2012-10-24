// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!
 
#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3
 
#define FADESPEED 20     // make this higher to slow down

#include "rgb.h"

const RGB black = { 0 , 0 , 0 };
const RGB red = { 255 , 0 , 0 };
const RGB orange = { 255 , 127 , 0 };
const RGB yellow = { 255 , 255 , 0 };
const RGB green = { 0, 255 , 0 };
const RGB blue = { 0, 0, 255 };
const RGB indigo = { 111 , 0, 255 };
const RGB violet =  { 143 , 0 , 255 };
const RGB rainbow[7] = {red, orange, yellow, green, blue, indigo, violet};

void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  Serial.begin(9600);
  set_color(black);
}

void loop() {
  Serial.println("yellow to green");
  fade_from_to(yellow, green);
  Serial.println("green to blue");
  fade_from_to(green, blue);
  Serial.println("blue to green");
  fade_from_to(blue, green);
  Serial.println("green to yellow");
  fade_from_to(green, yellow);
}
