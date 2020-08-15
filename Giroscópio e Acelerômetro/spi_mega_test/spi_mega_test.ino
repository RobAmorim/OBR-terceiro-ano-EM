/*
      RoboCore - Tutorial Comunicacao entre Arduinos: SPI -(mega)
                                                       (100/05/10015)
*/

 // MEGA MEGA MEGA MEGA 
#include <Comunication.h>
#include <ControlMotorsMaxIII.h>
#include <ReadMaxIII.h>
#include <boards/megaSENSORS.h>

Read Read;
Motors Robot;
Trigger Trigger; 


int data;

void setup() {
  
  Trigger.begin(); 
  Read.sensorsMicroBegin();
  Serial.begin(115200); 
}


void loop() {


  Trigger.condition_line(); 
  delayMicroseconds(100);
  

  if(Read.verificationObstacle() == true)
  {
    Robot.speed(180, 180);
    Robot.backwardCM(2);
    Robot.stop(500); 
  }

  else if(Read.verificationObstacle() == false)
  {
    Robot.speed(180, 180);
    Robot.forward(); 
  }


/*
  Trigger.condition_rightObstacle(); 
  delayMicroseconds(100);
  data = mega.receive();  
  Serial.print("Condition 2:"); 
  Serial.println(data);    
   
   
  Trigger.condition_leftObstacle(); 
  delayMicroseconds(100);
  data = mega.receive(); 
  Serial.print("Condition 3:");
  Serial.println(data);    
  
  
  Trigger.condition_ramp(); 
  delayMicroseconds(100);
  data = mega.receive(); 
  Serial.print("Condition 4:");
  Serial.println(data);    
   

     Trigger.condition_triRight();
     delayMicroseconds(100);
     data = mega.receive(); 
     Serial.print("Condition 5:");  
     Serial.println(data);    
   

      Trigger.condition_triLeft();
      delayMicroseconds(100);
      data = mega.receive(); 
      Serial.print("Condition 6:"); 
      Serial.println(data);    
   
     Trigger.condition_searchingOnlyRight();
     delayMicroseconds(100);
     data = mega.receive();
     Serial.print("Condition 7:");
     Serial.println(data);    
   

      Trigger.condition_searchingOnlyLeft();
      delayMicroseconds(100);
      data = mega.receive(); 
      Serial.print("Condition 8:");
      Serial.println(data);  

         Trigger.condition_searchingLeftAndRight(); 
      delayMicroseconds(100);
      data = mega.receive(); 
      Serial.print("Condition 9:");
      Serial.println(data);   

       Trigger.condition_front(); 
      delayMicroseconds(100);
      data = mega.receive(); 
      Serial.print("Condition 10:");
      Serial.println(data);   

       Trigger.condition_rear(); 
      delayMicroseconds(100);
      data = mega.receive(); 
      Serial.print("Condition 11:");
      Serial.println(data);   

       Trigger.condition_frontAndRear(); 
      delayMicroseconds(100);
      data = mega.receive(); 
      Serial.print("Condition 12:");
      Serial.println(data);   

       Trigger.condition_13();
      delayMicroseconds(100);
      data = mega.receive(); 
      Serial.print("Condition 13:");
      Serial.println(data);   

       Trigger.condition_14();
      delayMicroseconds(100);
      data = mega.receive(); 
      Serial.print("Condition 14:");
      Serial.println(data);   

       Trigger.condition_15();
      delayMicroseconds(100);
      data = mega.receive(); 
      Serial.print("Condition 15:");
      Serial.println(data);   


       Trigger.condition_16();
      delayMicroseconds(100);
      data = mega.receive(); 
      Serial.print("Condition 16:");
      Serial.println(data);   
      */
   }

