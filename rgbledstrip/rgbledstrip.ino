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
const RGB cyan = { 0 , 255 , 255 };
const RGB magenta = { 255 , 0 , 255 };
const RGB white = { 255 , 255, 255 };
const RGB binary[8] = { black, red, yellow, green, cyan, blue, magenta, white };

void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}

void loop() {
  for (unsigned int i = 0; i < 7; i++) {
    fade_from_to(binary[i], binary[i+1]);
  }
  for (unsigned int i = 7; i > 0; i--) {
    fade_from_to(binary[i], binary[i-1]);
  }
}
