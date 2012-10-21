// 3, 5, 6, 9, 10, 11
// PORTD: 0-7
// PORTB: 8-13

void setup() {
  DDRB = DDRB | B00111111; // set 8,9,10,11,12,13 to output
  DDRD = DDRD | B11111100; // set 3,4,5,6,7 to output
}

byte port_b_all_on  = B00111111; // end at `16380`
byte port_d_all_on  = B11111100; // start at `4`
byte port_d_all_off = B00000000;
byte port_b_all_off = B00000000;

unsigned int all_on  = 16380;
unsigned int all_off = 0;

void setall(unsigned int state) {
  PORTD = (byte)(state & 255);
  PORTB = (byte)(state >> 8);
}

unsigned int i;
void loop() {
  setall(all_on);
  delay(500);
  for (i = 0; i <= all_on; i++) {
    setall(i);
    delay(500);
  }
}
