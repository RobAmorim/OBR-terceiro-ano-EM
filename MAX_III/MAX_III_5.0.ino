 
//===================================================
//Team: maX Bots 
//Programmer: Robson Amorim 
//Begin: 05/05/2017 
//===================================================

// Ours libraries 
#include <ControlMotorsMaxIII.h>
#include <ReadMaxIII.h>
#include <LedMaxIII.h>

//=============================================================================
#define A 5

#define speedRampUp 120
#define speedRampDown 100


#define speedRobot 140 
#define speedCurve 160
//=============================================================================
              //Instances 
Motors Robot; 
Led Led; 
Read Read; 
Servos Servos; 

bool triLeft = false;
bool triRight = false;
bool triCorner = false; 


//==============================================================================
// Outside libraries 
//#include <Thread.h>  //Function Tread        
//#include <ArduinoSensors.h> //Functions of sensors 
//#include <sensors/PingUltrasonic.h> //Functions of the ultrasonic Sensor  
#include <SharpIR.h> //Functions of the ultrasonic Sensor 
#include <Wire.h> //Control of the Gyro Sensor 
#include <Servo.h> //Control of the motor servo (claw)

//===============================================================================  
                      //SETTING REFLECTANCE SENSOR 
                      
int cutoffValue = 100; //Cuttoff value of reflective sensor 

int _leftLine = 0;
int _rightLine = 0; 
int _leftCorner = 0;
int _rightCorner = 0;
int _leftEx = 0;
int _rightEx = 0;
int _rightSuper = 0;
int _leftSuper = 0;

boolean battery; 

//==================================================================================

#define _buzzer 2

void buzzer(int time)
{
  digitalWrite(_buzzer, HIGH); 
  delay(time);
  digitalWrite(_buzzer, LOW); 
}
//===============================================================================
                      //Declaration void's 
void CrossroadRight();
void CrossroadLeft();
void Crossroad(); 
void line();
void RightObstacle();
void LeftObstacle();
void ramp();
void room3(); 
void Turn_Right_Crossroad(); 
void Turn_Left_Crossroad();



//=================================================================================

void setup()

{
  pinMode(28, INPUT);
  pinMode(29, OUTPUT); 
  Serial.begin(115200); 
  Robot.gyroBegin(); 
  Servos.begin(); 
  Read.colorBegin(); 
  Led.begin();  
}

void loop() 

{
//==================================================================================================
                            //Checking if have obstacle 
//=================================================================================================== 
    if(Read.verificationObstacle() == true)
   {
    Led.red(); 
    RightObstacle();
   }

//==================================================================================================
else{                     //Gyro Sensor - verification Ramp Up
//==================================================================================================

     if(digitalRead(28) == LOW)
     {
     digitalWrite(29, HIGH);
      Robot.stop(1000); 
      bool rampUpUp = true;
      Servos.clawDown();
      Robot.stop(2000); 
      while(rampUpUp == true)
      {
        rampUp(); 
       

       /*  if(digitalRead(30) == LOW)
         {
          Robot.stop(50000);        
          }*/
         
        /* while(digitalRead(28) == HIGH)
          {
            rampUp(); 
            delta = millis() - times; 
            if(delta > 1000)
            {
              Led.yellow();
              Robot.stop(50000);
          }*/
        }
      }
     // digitalWrite(29, HIGH);
       //Robot.stop(50000); 
    //}
   /*if(Read.verificationRampUp() == true)
   {
    //clawDownRampUp();
    while(Read.verificationRampUp() == true)
    {
      rampUp(); 
    }
    
    }
    */
 //==================================================================================================
else{                     //Gyro Sensor - verification Ramp Down
//==================================================================================================
 if(Read.verificationRampDown() == true)
   {
     //clawDownRampUp();
    while(Read.verificationRampDown() == true)
    {
      rampDown(); 
    }
    
    }
 
//=====================================================================================================
 else {                           //Basic - Line following 
//=====================================================================================================
     
     line(); 

//=====================================================================================================
  } //First else  
   } // Second else
    } //  Third else 
      }//Loop 















