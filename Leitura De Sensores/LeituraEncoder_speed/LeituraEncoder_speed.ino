#include <Encoder.h>

#include <ControlMotorsRobot.h>

Motors Robot; 

Encoder Motor_Dir(19, 17);     //Pinagem do interrupitor do MotoDir    
Encoder Motor_Esq(18, 16);   //Pinagem do interrupitor do MotoDir 

long Pulsos_Dir; 
void setup()

{

  Serial.begin(115200);



}
float lastTime = 0; 
float time = 0; 
float deltaTime = 0; 

float speed = 1.5; 
int P = 0; 
int _P = 10; 
 float error = 0; 
int correctSpeed = 0; 
void loop()

{

  
  
Pulsos_Dir = Motor_Dir.read() * -1;
//Pulsos_Esq = MotorEsq.read(); 

  time = millis(); 
  deltaTime = time - lastTime; 
  
 if(deltaTime > 1000)
 {
  lastTime = millis();
  Motor_Dir.write(0); 
 } 

  Robot.speed(100, 100); 
  Robot.forward(); 

  Serial.print("Pulsos Right: "); 
  Serial.print(Pulsos_Dir);  
  Serial.print("\t");  
  
  Serial.print("Time:");
  Serial.print(deltaTime); 
  Serial.print("\t"); 

  float speedRight = 0; 

   speedRight = Pulsos_Dir / deltaTime; 

   error = speed - speedRight; 
   
   P = error * _P; 


 //  correctSpeed +=  P; 
  // Robot.speed(0, 230);  

   if(error > 0.1)
   {
    correctSpeed += 5; 
    if(correctSpeed > 255)
    {
      correctSpeed = 255;
    }
   }

    if(error < -0.1)
   {
    correctSpeed = - 5; 
    if(correctSpeed < 0)
    {
      correctSpeed = 0;
    }
   }
   
   Robot.speed(0, correctSpeed); 
     
  Serial.print("correctSpeed:");
  Serial.print(correctSpeed); 
  Serial.print("\t"); 

  Serial.print("error:");
  Serial.print(error); 
  Serial.print("\t"); 
  
  Serial.print("Pulsos/millis:");
  Serial.println(speedRight);  


  
  
}
