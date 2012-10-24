#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3
 
#define FADESPEED 5     // make this higher to slow down

// need this for analogWrite and delay
#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
	#include "cppfix.h"
#endif


union RGB {
  struct {
    byte r;
    byte g;
    byte b;
  } s;

  byte rgb[3];
};

void fade_from_to(RGB from, RGB to) {
  for (byte i = 0; i < 256; i++) {
    byte range = to.s.r - from.s.r;
    unsigned int ratio = range >> 7;
    analogWrite(REDPIN, i / ratio);
    delay(FADESPEED);
  }
}
