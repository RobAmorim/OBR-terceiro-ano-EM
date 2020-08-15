#include <QTRSensors.h>
#include <ControlMotorsEncoder.h>

//===============================================
             // MOTORS SETTING

 //ROBOT INSTANCE
    Motors Robot;
//==================================================

#define Kp 0.5 // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd 0 // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define MaxSpeed 250 // max speed of the robot
#define MaxSpeed 250 // max speed of the robot
#define BaseSpeed 150 // this is the speed at which the motors should spin when the robot is perfectly on the line
#define BaseSpeed 150  // this is the speed at which the motors should spin when the robot is perfectly on the line
#define NUM_SENSORS  6     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2



QTRSensorsRC qtrrc((unsigned char[]) {  A15, A14, A13, A12, A11, A10} ,NUM_SENSORS, TIMEOUT, EMITTER_PIN); // sensor connected through analog pins A0 - A5 i.e. digital pins 14-19

unsigned int sensorValues[NUM_SENSORS];

void setup()
{

 
  int i;
for (int i = 0; i < 100; i++) // calibrate for sometime by sliding the sensors across the line, or you may use auto-calibration instead

  /* comment this part out for automatic calibration 
  if ( i  < 25 || i >= 75 ) // turn to the left and right to expose the sensors to the brightest and darkest readings that may be encountered
     turn_right();  
   else
     turn_left(); */ 
   qtrrc.calibrate();   
   delay(20);
wait();  
delay(2000); // wait for 2s to position the bot before entering the main loop 
    
    /* comment out for serial printing
    
    Serial.begin(9600);
    for (int i = 0; i < NUM_SENSORS; i++)
    {
      Serial.print(qtrrc.calibratedMinimumOn[i]);
      Serial.print(' ');
    }
    Serial.println();

    for (int i = 0; i < NUM_SENSORS; i++)
    {
      Serial.print(qtrrc.calibratedMaximumOn[i]);
      Serial.print(' ');
    }
    Serial.println();
    Serial.println();
    */
  } 

int lastError = 0;

void loop()
{
  unsigned int sensors[6];
  int position = qtrrc.readLine(sensors); // get calibrated readings along with the line position, refer to the QTR Sensors Arduino Library for more details on line position.
  int error = position - 2500;

  int motorSpeed = 0;
   motorSpeed = Kp * error + Kd * (error - lastError);
  lastError = error;

  int rightSpeed = rightBaseSpeed + motorSpeed; 
  int leftSpeed = leftBaseSpeed - motorSpeed;   

  int CorretSpeed = 0; 

  if(motorSpeed > 0)
  CorretSpeed = rightSpeed; 

 if(motorSpeed < 0) 
 CorretSpeed = leftSpeed; 

  if (CorretSpeed > MaxSpeed ) CorretSpeed = MaxSpeed; // prevent the motor from going beyond max speed
  if (CorretSpeed < baseSpeed) CorrectSpeed = baseSpeed; // keep the motor speed positive
  if ((error > -200)&&(error < 200));
   {
     Robot.frente(250, 250);  
   }
  if (CorretSpeed > MaxSpeed ) CorretSpeed = MaxSpeed; // prevent the motor from going beyond max speed
  if (CorretSpeed < baseSpeed) CorrectSpeed = baseSpeed; // keep the motor speed positive
  if (error > 200)
   {
    Robot.velocidade(CorretSpeed,  CorretSpeed); 
    Robot.esquerda(); 
}

  if (CorretSpeed > MaxSpeed ) CorretSpeed = MaxSpeed; // prevent the motor from going beyond max speed
  if (CorretSpeed < baseSpeed) CorrectSpeed = baseSpeed; // keep the motor speed positive
  if (error < - 200)
   {

    Robot.velocidade(CorretSpeed, CorretSpeed); 
    Robot.direita(); 
}


}
  
void wait(){
    Robot.parar(); 
}
