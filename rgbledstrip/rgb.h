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
    unsigned short r;
    unsigned short g;
    unsigned short b;
  } s;

  unsigned short rgb[3];
};

int range;
byte color;
short i;
byte pin;
short ratio;
int val;
void fade_from_to(RGB from, RGB to) {
  for (i = 0; i < 256; i++) {
    for (color = 2; color < 3; color++) {
      range = to.rgb[color] - from.rgb[color];
      if (color == 0) { pin = REDPIN; }
      else if (color == 1) { pin = GREENPIN; }
      else if (color == 2) { pin = BLUEPIN; }

      if (range == 0) {
        if (i > 0) {
          analogWrite(pin, to.rgb[color]);
        }
      } else {
		  ratio = 255 / range;
		  val = i * ratio;
		  if (val < 0) { val = 255 + val; }
		  analogWrite(pin, val);
		  Serial.print(i); Serial.print(" , setting to ");
		  Serial.print(val); Serial.print(" , pin ");
		  Serial.println(pin);
      }
    }
    delay(FADESPEED);
  }
}
