void setup() {
  DDRB = DDRB | B11111111; // set 8,9,10,11,12,13 to output
  DDRD = DDRD | B10000000; // set 7 to output
  Serial.begin(9600);
}

const unsigned int BOTTOMRIGHT = B10000000; // PORTD
const unsigned int TOPRIGHT    = B00000001; // PORTB
const unsigned int TOP         = B00000010;
const unsigned int BOTTOM      = B00000100;
const unsigned int BOTTOMLEFT  = B00001000;
const unsigned int MIDDLE      = B00010000;
const unsigned int TOPLEFT     = B00100000;

void show_digit(unsigned int num) {
  switch (num) {
    case 0:
      PORTB = TOPRIGHT | TOP | TOPLEFT | BOTTOMLEFT | BOTTOM;
      PORTD = BOTTOMRIGHT;
      break;
    case 1:
      PORTB = TOPLEFT | BOTTOMLEFT;
      PORTD = 0;
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
      PORTB = TOPRIGHT;
      PORTB |= (TOP | TOPLEFT | BOTTOMLEFT | BOTTOM | MIDDLE);
      PORTD = BOTTOMRIGHT;
      break;
    case 9:
      PORTB = TOPRIGHT | TOP | TOPLEFT | BOTTOM | MIDDLE;
      PORTD = BOTTOMRIGHT;
      break;
  }
}

void blank() {
  PORTD = 0;
  PORTB = 0;
}

void show_digits(unsigned int num) {
  if (num < 10) {
    show_digit(num);
    delay(200);
  } else if (num < 100) {
    show_digit(num / 10);
    delay(200);
    if (num / 10 == num % 10) {
      blank();
      delay(50);
    }
    show_digit(num % 10);
    delay(200);
  }
  blank();
}

unsigned int x;
void loop() {
  for (x = 1; x < 100; x += 1) {
    Serial.println(x);
    show_digits(x);
    delay(500);
  }
}
