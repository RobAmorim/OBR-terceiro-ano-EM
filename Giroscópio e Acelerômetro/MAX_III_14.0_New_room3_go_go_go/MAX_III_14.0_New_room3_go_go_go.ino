 
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
#define A 3

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
                      
int cutoffValue = 200; //Cuttoff value of reflective sensor 

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
    verificationObstacleSide();
   }

//==================================================================================================
else{                     //Gyro Sensor - verification Ramp Up
//==================================================================================================

  if(Read.verificationMercuryUp() == true)
     {
   
      Robot.stop(1500); 
      Robot.speed(130, 130); 
      Robot.forwardCM(1);
      Robot.stop(500); 
      

      //Robot climb Ramp 
       if(Read.verificationMercuryUp() == true)
     {
      Led.purple(); 
      bool _rampUp = true;
      Servos.center(180);   
      Robot.stop(1000);
       
      while(_rampUp == true)
      {
               
        Led.purple(); 
        rampUp(); 
       //Indentification underground
       if(Read.verificationMercuryDown() == true)
       {
        Robot.forwardCM(5); 
        Robot.stop(1000); 
        if(Read.verificationMercuryDown() == true)
       {
        Led.green();
        Robot.stop(1000); 
        //Servos.center(0);
        //Robot.speed(110, 110); 
      //  Robot.forwardCM(4);
        Robot.stop(500); 
        _rampUp = false;
       }
       }
       
       }

      //Robot underground 
      bool _rampUnderground = true; 

       while(_rampUnderground == true)
       {
        Led.green(); 
        rampUnderground(); 


        //identification ramp Down 
        Serial.println(Robot.verificationRampDown()); 
        if(Robot.verificationRampDown() > 7000)
        {
          Robot.backward(50, 50); 
          delay(500); 
          if(Robot.verificationRampDown() > 7000)
        {
          if(Robot.verificationRampDown() > 7000)
        {
          _rampUnderground = false; 
          Led.blue(); 
          
          float time = millis();
          bool _rampDown = true; 
          
          while(_rampDown == true) 
          {
            Led.yellow();
            rampDown(); 
            

            if(millis() > (time + 2000))
            {
              Robot.stop(500); 
              _rampDown = false;
              Servos.begin();
              
/*
              if((Read.leftLine() < cutoffValue)&&(Read.rightLine() < cutoffValue)&&(Read.leftCorner() < cutoffValue)&&  // ALL sensors is in White 
  (Read.rightCorner() < cutoffValue)&&(Read.leftEx() < cutoffValue)&&(Read.rightEx() < cutoffValue))

              {  
                 Robot.speed(190, 190);
                 Robot.left(1000); 
                 Robot.stop(500); 
                 if((Read.leftLine() < cutoffValue)&&(Read.rightLine() < cutoffValue)&&(Read.leftCorner() < cutoffValue)&&  // ALL sensors is in White 
  (Read.rightCorner() < cutoffValue)&&(Read.leftEx() < cutoffValue)&&(Read.rightEx() < cutoffValue))

              {
                Robot.speed(190, 190);
                Robot.right(1500); 
                Robot.stop(); 
              }
              
              }
              */
            } 
            }
            /* 
             if(Robot.verificationRampDown() < 4000)
            {
              Robot.backward(50, 50); 
              Robot.speed(100, 100);
              Robot.forwardCM(2);
              Robot.backward(50, 50); 
              delay(500); 
              if(Robot.verificationRampDown() < 4000)
            {
            */
              
            }
            }
          
             }
          }
        }
        }
        
         
       
     
//=====================================================================================================
 else {                           //Basic - Line following 
//=====================================================================================================
     
     line(); 

//=====================================================================================================
  } //First else  
   } // Second else
      }//Loop 















