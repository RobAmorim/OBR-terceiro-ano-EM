
#include <ControlMotorsRobot.h>

Motors Robot; 


void setup() 

{

  
}

void loop() 
{
  Robot.turnRight90(); 
  delay(1000); 
  Robot.turnLeft90();
  delay(1000); 

}
