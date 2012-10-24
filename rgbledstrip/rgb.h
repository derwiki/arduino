#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3
 
#define FADESPEED 20     // make this higher to slow down

union RGB {
  struct {
    char r;
    char g;
    char b;
  }

  char[3] rgb;
};

void fade_to_from(RGB from, RGB to, unsigned int duration) {
  for (unsigned int i = 0; i < 256; i++) {
	char range = from.r - to.r;
	unsigned int ratio = range / 256;
    analogWrite(REDPIN, i / ratio);
    delay(FADESPEED);
  }
}
