#include <LED.h>
// http://lithne.id.tue.nl/docs/LED/class_l_e_d.html

LED * led1  =  new LED( 11, true ); 
LED * led2  =  new LED( 10, true );
LED * led3  =  new LED( 9, true );

// Or create an Array of LEDs
// LED * lamps[10]; 

void setup()
{
/** In case of an array, initialize it
  for (int i=0; i < 10; i++) {
      lamps[i] = new LED( );
  }
**/

   led1->setAnimationType( QUADRATIC , true , false );
   led2->setAnimationType( QUADRATIC , true , false );  
   led3->setAnimationType( QUADRATIC , true , false );  
}

void loop()
{
  if( !led1->isAnimating()) // Returns true if the LED is in an animation
  {
    if (led1->getIntensity() == 0) { led1->intensityTo( 255, 1250 );  } else { led1->intensityTo( 0, 1000 ); }
    if (led2->getIntensity() == 0) { led2->intensityTo( 255, 1000 ); } else { led2->intensityTo( 0, 1000 ); }
    if (led3->getIntensity() == 0) { led3->intensityTo( 255, 1000 ); } else { led3->intensityTo( 0, 1000 ); }
  }
  // Always call the update function; if autoWrite is on, the Arduino will write the current intensity to the set channel 
  led1->update();
  led2->update();
  led3->update();
  /**
  // If autoWrite is OFF, manually set the desired value
  // In this case we write to arduino pins; but you can use this for instance to control DMX lighting
  analogWrite( led1->getChannel(), led1->getIntensity() );
  **/
}
