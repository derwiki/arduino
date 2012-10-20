#include <LED.h>
// http://lithne.id.tue.nl/docs/LED/class_l_e_d.html

LED * lamps[9];
void setup() {
  for (int i=0; i < 9; i++) {
    lamps[i] = new LED( i + 3 , true );
    lamps[i]->setAnimationType( QUADRATIC , true , false );
  } 
}

void loop() {
  int to;
  for (int i=0; i < 9; i++) {
    if ( !lamps[i]->isAnimating() ) {
      to = (lamps[i]->getIntensity() == 0) ? 255 : 0;
      lamps[i]->intensityTo (to, random(500, 1250));
    }
    lamps[i]->update();
  }
}
