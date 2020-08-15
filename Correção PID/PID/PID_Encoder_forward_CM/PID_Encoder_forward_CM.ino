//===================================================
//Team: maX Bots 
//Programmer: Robson Amorim 
//Begin: 05/05/2017 
//===================================================

// Ours libraries 
//#include <ControlMotorsRobot.h>
#include <Read.h>
#include <Led.h>
#include <Battery.h> 

//=============================================================================
#define A 4
#define speedRamp 100
#define speedRobot 140 
#define speedCurve 160 
//=============================================================================
              //Instances 
//Motors Robot; 
Led Led; 
//Read Read; 
Battery Battery; 
//==============================================================================


// Outside libraries 
#include <Thread.h>  //Function Tread        
#include <ArduinoSensors.h> //Functions of sensors 
#include <sensors/PingUltrasonic.h> //Functions of the ultrasonic Sensor  
#include <SharpIR.h> //Functions of the ultrasonic Sensor 
#include <Wire.h> //Control of the Gyro Sensor 
#include <Servo.h> //Control of the motor servo (claw)
#include <Encoder.h>

//===============================================================================  






#include <Encoder.h>

#include <ControlMotorsRobot.h>

Motors Robot; 

Encoder MotorDir(19, 17);     //Pinagem do interrupitor do MotoDir    
Encoder MotorEsq(18, 16);   //Pinagem do interrupitor do MotoDir 


long Pulsos_Dir = 0;
long Pulsos_Esq = 0; 
long SpeedDir = 0; 
long SpeedEsq = 0; 

//#define SpeedBase  180

long lastProcess = 0.0; 

double error = 0.0;
double lastError = 0.0; 

double P = 0.0; 
double I = 0.0;
double D = 0.0; 

double kp = 0.15; 
double ki = 0.02; 
double kd = 2.0;  

double PID = 0;  

void setup()

{

  Serial3.begin(9600);
  Serial.begin(9600);

  delay(5000); 

  Serial3.println("--------------- GO GO GO GO GO GO GO GO GO GO GO GO GO GO GO GO GO GO -------------------");
  
}

void loop()

{
   

 
  //forward_PID(180); 
  backwardCM_PID(180, 50); 
  Robot.stop(50000);  

 

 /* Serial3.print("Delta Time:"); 
  Serial3.println(deltaTime);  */
  
/*
Serial3.print("Pulsos_Dir:"); Serial3.print(Pulsos_Dir);  
Serial3.print("\t");
Serial3.print("Pulsos_Esq:"); Serial3.print(Pulsos_Esq); 
Serial3.print("\t");
Serial3.print("error:"); Serial3.print(error);
Serial3.print("\t");
Serial3.print("Speed Dir:"); Serial3.print(SpeedDir);
Serial3.print("\t");
Serial3.print("Speed Esq:"); Serial3.print(SpeedEsq);
Serial3.print("\t");
Serial3.print("P:"); Serial3.print(P);
Serial3.print("\t");
Serial3.print("I:"); Serial3.print(I);
Serial3.print("\t");
Serial3.print("D:"); Serial3.print(D);
Serial3.print("\t");
Serial3.print("PID:"); Serial3.println(PID);*/

}
/*
void forwardCM_PID(int SpeedBase, int distanceCM)
{
Robot.resetEncodersRoom3(); 

while(Robot.forwardCM_Room3() < distanceCM)
{
  
  Pulsos_Dir = MotorDir.read();
Pulsos_Esq = MotorEsq.read(); 

error = Pulsos_Dir - Pulsos_Esq; 

float deltaTime = (millis() - lastProcess) / 1000.0;
     lastProcess = millis();

  P = error * kp; 

  I = I + (error * ki) * deltaTime; 

  D = (lastError - error) * kd / deltaTime; 
  lastError = error; 


  PID = P + I + D;  
  
SpeedDir = SpeedBase - PID; 
SpeedEsq = SpeedBase + PID; 


Robot.forward(SpeedEsq, SpeedDir); 
}
}

void forwardMS_PID(int SpeedBase, int ms)
{
  
float realTime = millis();  

while((millis() - realTime) <= ms)

{
  Pulsos_Dir = MotorDir.read();
Pulsos_Esq = MotorEsq.read(); 

error = Pulsos_Dir - Pulsos_Esq; 

float deltaTime = (millis() - lastProcess) / 1000.0;
     lastProcess = millis();

  P = error * kp; 

  I = I + (error * ki) * deltaTime; 

  D = (lastError - error) * kd / deltaTime; 
  lastError = error; 


  PID = P + I + D;  
  
SpeedDir = SpeedBase - PID; 
SpeedEsq = SpeedBase + PID; 


Robot.forward(SpeedEsq, SpeedDir); 

}

}

void forward_PID(int SpeedBase)
{
  
Pulsos_Dir = MotorDir.read();
Pulsos_Esq = MotorEsq.read(); 

error = Pulsos_Dir - Pulsos_Esq; 

float deltaTime = (millis() - lastProcess) / 1000.0;
     lastProcess = millis();

  P = error * kp; 

  I = I + (error * ki) * deltaTime; 

  D = (lastError - error) * kd / deltaTime; 
  lastError = error; 


  PID = P + I + D;  
  
SpeedDir = SpeedBase - PID; 
SpeedEsq = SpeedBase + PID; 


Robot.forward(SpeedEsq, SpeedDir); 

}

//================================================================================================================
*/
void backwardCM_PID(int SpeedBase, int distanceCM)
{
Robot.resetEncodersRoom3(); 

while(Robot.backwardCM_Room3() < distanceCM)
{
  
  Pulsos_Dir = MotorDir.read();
Pulsos_Esq = MotorEsq.read(); 

error = Pulsos_Dir - Pulsos_Esq; 

float deltaTime = (micros() - lastProcess) / 1000000.0;
     lastProcess = micros();

  P = error * kp; 

  I = I + (error * ki) * deltaTime; 

  D = (lastError - error) * kd / deltaTime; 
  lastError = error; 


  PID = P + I + D;  
  
SpeedDir = SpeedBase + PID; 
SpeedEsq = SpeedBase - PID; 


Robot.backward(SpeedEsq, SpeedDir); 
}
}
/*
void backwardMS_PID(int SpeedBase, int ms)
{
  
float realTime = millis();  

while((millis() - realTime) <= ms)

{
  Pulsos_Dir = MotorDir.read();
Pulsos_Esq = MotorEsq.read(); 

error = Pulsos_Dir - Pulsos_Esq; 

float deltaTime = (millis() - lastProcess) / 1000.0;
     lastProcess = millis();

  P = error * kp; 

  I = I + (error * ki) * deltaTime; 

  D = (lastError - error) * kd / deltaTime; 
  lastError = error; 


  PID = P + I + D;  
  
SpeedDir = SpeedBase + PID; 
SpeedEsq = SpeedBase - PID; 


Robot.backward(SpeedEsq, SpeedDir); 

}

}

void backward_PID(int SpeedBase)
{
  
Pulsos_Dir = MotorDir.read();
Pulsos_Esq = MotorEsq.read(); 

error = Pulsos_Dir - Pulsos_Esq; 

float deltaTime = (millis() - lastProcess) / 1000.0;
     lastProcess = millis();

  P = error * kp; 

  I = I + (error * ki) * deltaTime; 

  D = (lastError - error) * kd / deltaTime; 
  lastError = error; 


  PID = P + I + D;  
  
SpeedDir = SpeedBase + PID; 
SpeedEsq = SpeedBase - PID; 


Robot.backward(SpeedEsq, SpeedDir); 

}
*/
