

#include <LedMaxII.h>


Led::Led()
{

}

void Led::begin() 

{

                      //LED RGB
 pinMode(LedBlue, OUTPUT); 
 pinMode(LedGreen, OUTPUT);
 pinMode(LedRed, OUTPUT);

 pinMode(R_LedBlue, OUTPUT); 
 pinMode(R_LedGreen, OUTPUT);
 pinMode(R_LedRed, OUTPUT);
}

void Led::green() //Light up - LED RGB BLUE 

{
  digitalWrite(LedBlue, LOW);
  digitalWrite(LedGreen, HIGH);
  digitalWrite(LedRed, LOW);

  digitalWrite(R_LedBlue, LOW);
  digitalWrite(R_LedGreen, HIGH);
  digitalWrite(R_LedRed, LOW);
  }

void Led::red() //Light up - LED RGB Red 

{
  digitalWrite(LedBlue, LOW);
  digitalWrite(LedGreen, LOW);
  digitalWrite(LedRed, HIGH); 

  digitalWrite(R_LedBlue, LOW);
  digitalWrite(R_LedGreen, LOW);
  digitalWrite(R_LedRed, HIGH); 
  }

void Led::blue() //Light up - LED RGB Green 

{
  digitalWrite(LedBlue, HIGH);
  digitalWrite(LedGreen, LOW);
  digitalWrite(LedRed, LOW);

  digitalWrite(R_LedBlue, HIGH);
  digitalWrite(R_LedGreen, LOW);
  digitalWrite(R_LedRed, LOW);
  }

void Led::yellow() //Light up - LED RGB Yellow

{
  digitalWrite(LedBlue, LOW);
  digitalWrite(LedGreen, HIGH);
  digitalWrite(LedRed, HIGH);

  digitalWrite(R_LedBlue, LOW);
  digitalWrite(R_LedGreen, HIGH);
  digitalWrite(R_LedRed, HIGH);
  
  }

void Led::purple() //Light up - LED RGB Green 

{
  digitalWrite(LedBlue, HIGH);
  digitalWrite(LedGreen, LOW);
  digitalWrite(LedRed, HIGH);

  digitalWrite(R_LedBlue, HIGH);
  digitalWrite(R_LedGreen, LOW);
  digitalWrite(R_LedRed, HIGH);

  }









