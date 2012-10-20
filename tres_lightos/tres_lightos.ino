#include <LED.h>
// http://lithne.id.tue.nl/docs/LED/class_l_e_d.html

LED * lamps[3];
void setup() {
  for (int i=0; i < 3; i++) {
    lamps[i] = new LED( i + 9, true );
    lamps[i]->setAnimationType( QUADRATIC , true , false );
  }
}

void loop() {
  for (int i=0; i < 3; i++) {
    if ( !lamps[i]->isAnimating() ) {
      lamps[i]->intensityTo (255, random(500, 1250));
    }
    lamps[i]->update();
  }
}
