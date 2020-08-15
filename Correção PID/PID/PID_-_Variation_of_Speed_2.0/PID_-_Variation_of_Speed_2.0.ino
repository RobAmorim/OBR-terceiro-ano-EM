#include <QTRSensors.h>
#include <ControlMotorsRobot.h>


//===============================================
             // MOTORS SETTING

 //ROBOT INSTANCE
   Motors Robot;
//==================================================

#define Kp 0.02 // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd 0.2 // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define MaxSpeed 250 // max speed of the robot
#define baseError 500
//#define MaxSpeed 220 // max speed of the robot
#define baseSpeed 150 // this is the speed at which the motors should spin when the robot is perfectly on the line
//#define BaseSpeed 180  // this is the speed at which the motors should spin when the robot is perfectly on the line
#define rightBaseSpeed 180
#define leftBaseSpeed 180 
#define NUM_SENSORS  8     // number of sensors used
#define TIMEOUT       3500  // waits for 2500 us for sensor outputs to go low
#define EMITTER_PIN   22     // emitter is controlled by digital pin 2


void wait(); 

QTRSensorsRC qtrrc((unsigned char[]) {  A15, A14, A13, A12, A11, A10, A9, A8} ,NUM_SENSORS, TIMEOUT, EMITTER_PIN); // sensor connected through analog pins A0 - A5 i.e. digital pins 14-19

unsigned int sensorValues[NUM_SENSORS];

void setup()
{

 Serial.begin(9600); 
 
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
  unsigned int sensors[8];
  int position = qtrrc.readLine(sensors); // get calibrated readings along with the line position, refer to the QTR Sensors Arduino Library for more details on line position.

   //Serial.print("Value:"); 
   //Serial.println(position); 

  
//=========================================
     //PID CALCULES 
//=========================================
  int error = position - 3500;


  double motorSpeed = 0.0;
  motorSpeed = Kp * error + Kd * (error - lastError);

  int rightMotorSpeed = rightBaseSpeed + motorSpeed;
  int leftMotorSpeed = leftBaseSpeed - motorSpeed;   
  
  lastError = error;

  int AddSpeed = 0; 
  
  if(motorSpeed > 0)
  {
  AddSpeed = motorSpeed * 1;
  }
  
  if(motorSpeed < 0)
  {
  AddSpeed = motorSpeed * -1; 
  }

  int CorrectSpeed = 0;
  CorrectSpeed = rightBaseSpeed + AddSpeed; 
  /*Serial.print("ADD SPEED:"); 
  Serial.print(AddSpeed); 
  Serial.print("CorrectSpeed"); 
  Serial.println(CorrectSpeed); 
*/
 // Serial.print("Position:"); 
 // Serial.println(position); 

  
//======================================================

  if ((error > - baseError)&&(error < baseError));
   {
     Robot.forward(200, 200);  
   }
//======================================================
     if (error > baseError)
   {
   if (CorrectSpeed > MaxSpeed)
   { 
     CorrectSpeed = MaxSpeed; 
   } 
   
    Robot.left(CorrectSpeed, CorrectSpeed); 
   
   }
 //======================================================
  if (error < - baseError)
  {
   if (CorrectSpeed > MaxSpeed ) 
   {
   CorrectSpeed = MaxSpeed; // prevent the motor from going beyond max speed
   }
    Robot.right(CorrectSpeed, CorrectSpeed); 
  }
//======================================================
  
}
 
void wait(){
    Robot.stop(); 
}
