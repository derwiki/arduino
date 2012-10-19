int counter = 1;
int ledPin = 13;
int dir = 1;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  warmBlink();
  delay(1500);
}

void warmBlink() {
  counter = 1;
  while (counter > 0) {
    counter += dir * 1;
    blink_for(counter);
    delay(17);
    if (counter == 20) {
      dir = -1;
    } else if (counter == 0) {
      dir = 1;
    }
  }
}

void blink_for(int t) {
  digitalWrite(ledPin, HIGH);
  delay(t);
  digitalWrite(ledPin, LOW);
}
