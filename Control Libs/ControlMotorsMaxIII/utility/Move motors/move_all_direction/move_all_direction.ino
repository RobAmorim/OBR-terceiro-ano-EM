
#include <ControlMotorsRobot.h>

Motors Robot; 


void setup() 

{

  
}

void loop() 
{
  Robot.forward(200, 200, 2000);
  Robot.right(200, 200, 2000);
  Robot.left(200, 200, 2000);
  Robot.backward(200, 200, 2000); 
  
  delay(2000); 
  
}
