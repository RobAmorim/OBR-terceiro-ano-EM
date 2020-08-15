
#include <ControlMotorsRobot.h>

Motors Robot; 


void setup() 

{

  
}

void loop() 
{
  Robot.clawDown(); 
  delay(1000); 
  Robot.clawClimb(); 
  delay(1000); 
}


