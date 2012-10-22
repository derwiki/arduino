void setup() {
  DDRB = DDRB | B11111111; // set 8,9,10,11,12,13 to output
  DDRD = DDRD | B10000000; // set 7 to output
}

const int BOTTOMRIGHT = B10000000; // PORTD
const int TOPRIGHT    = B00000001; // PORTB
const int TOP         = B00000010;
const int BOTTOM      = B00000100;
const int BOTTOMLEFT  = B00001000;
const int MIDDLE      = B00010000;
const int TOPLEFT     = B00100000;

void show_digit(unsigned int num) {
  switch (num) {
    case 0:
      PORTB = TOPRIGHT | TOP | TOPLEFT | BOTTOMLEFT | BOTTOM;
      PORTD = BOTTOMRIGHT;
      break;
    case 1:
      PORTB = TOPRIGHT;
      PORTD = BOTTOMRIGHT;
      break;
    case 2:
      PORTB = TOP | TOPRIGHT | MIDDLE | BOTTOMLEFT | BOTTOM;
      PORTD = 0;
      break;
    case 3:
      PORTB = TOP | MIDDLE | BOTTOM | TOPRIGHT;
      PORTD = BOTTOMRIGHT;
      break;
    case 4:
      PORTB = TOPLEFT | TOPRIGHT | MIDDLE;
      PORTD = BOTTOMRIGHT;
      break;
    case 5:
      PORTB = TOP | TOPLEFT | MIDDLE | BOTTOM;
      PORTD = BOTTOMRIGHT;
      break;
    case 6:
      PORTB = TOP | TOPLEFT | BOTTOMLEFT | BOTTOM | MIDDLE;
      PORTD = BOTTOMRIGHT;
      break;
    case 7:
      PORTB = TOP | TOPRIGHT;
      PORTD = BOTTOMRIGHT;
      break;
    case 8:
      PORTB = TOPRIGHT | TOP | TOPLEFT | BOTTOMLEFT | BOTTOM | MIDDLE;
      PORTD = BOTTOMRIGHT;
      break;
    case 9:
      PORTB = TOPRIGHT | TOP | TOPLEFT | BOTTOM | MIDDLE;
      PORTD = BOTTOMRIGHT;
      break;
  }
}

unsigned int i;
void loop() {
  show_digit(0);
  for (i = 0; i  < 10; i++) {
    show_digit(i);
    delay(100);
  }
}