#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3
 
#define FADESPEED 5     // make this higher to slow down
#define RGB_CHANNELS 3

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

unsigned int color_to_pin(unsigned int color) {
  if (color == 0) { return REDPIN; }
  else if (color == 1) { return GREENPIN; }
  else if (color == 2) { return BLUEPIN; }
}

unsigned int i, val, amount;
int range;
byte color, pin;
void fade_from_to(RGB from, RGB to) {
  for (i = 0; i < 256; i++) {
    for (color = 0; color < 3 ; color++) {
      pin = color_to_pin(color);
      if (to.rgb[color] == from.rgb[color]) {
        if (i == 0) { analogWrite(pin, from.rgb[color]); }
      } else {
        // scale the transition
        range = to.rgb[color] - from.rgb[color];
        amount = (int)((float)i * (range > 0 ? ((float)range / 255) : ((float)range / -255)));
        if (range < 0) { val = from.rgb[color] - (amount); }
        else { val = amount; }
        analogWrite(pin, val);
      }
    }
    delay(FADESPEED);
  }
}

void set_color(RGB color) {
  analogWrite(REDPIN, color.s.r);
  analogWrite(GREENPIN, color.s.g);
  analogWrite(BLUEPIN, color.s.b);
}
