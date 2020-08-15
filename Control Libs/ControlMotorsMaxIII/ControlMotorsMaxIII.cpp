/*
 * Libray ControlMotorsRobot v.2 
 * -----------------------------------------------------------
 * $Based on Adafruit's library: AFMotor $
 * $Author Alberto Daniel Calvalcante  
 * $Date 2015-06-27 12:49:06 (Sat, 27 Jun 2015) $
 * $Encoders added in 2015-08-02 12:17:39 (Sun, 02 Aug 2015)$
 * -----------------------------------------------------------
 * $Author Roboson Vincius AMorim Silva
 * $Walking with Centimetres added in 2016-08 (july 2016))$
 * $Translat portuguese->English added in 2016-08(Feb 2017) 
 * ----------------------------------------------------------
 */

 //ATTACH1 = Blue Wire
 //ATTACH2 = Yellow Wire

#include <ControlMotorsMaxIII.h>
#include <Servo.h>
#include <Wire.h>
//#include <Led.h>  

#include "AFMotor.h"
#include "Encoder.h"

 //extern Led Led; 

AF_DCMotor porta1(1);
AF_DCMotor porta2(2);
AF_DCMotor porta3(3);
AF_DCMotor porta4(4);  

//MOTORS INSTANCE
AF_DCMotor mLeft(4);
AF_DCMotor mRight(3);

//ENCODERS INSTANCE
Encoder Encoder_LEFT(ATTACH1_LEFT, ATTACH2_LEFT);
Encoder Encoder_RIGHT(ATTACH1_RIGHT, ATTACH2_RIGHT);

//SERVO SETTING 

Servo motorRightClaw; //Motor CLAW-RIGHT
Servo motorLeftClaw;
Servo CentralMotor; //Central Motor 
Servo motorRightBucket; //Motor CLAW-RIGHT
Servo motorLeftBucket;



#define CircumferenceWheel 11


Motors::Motors(){

	#define STOP 4
	#define FORWARD 1
	#define BACKWARD 2
}

void Motors::corrente()

{
 porta1.setSpeed(255);
 porta2.setSpeed(255);
 porta3.setSpeed(255);
 porta4.setSpeed(255); 

 porta1.run(FORWARD);
 porta2.run(FORWARD);
 porta3.run(FORWARD);
 porta4.run(FORWARD);    

}

void Motors::maxSpeed(){
	mLeft.setSpeed(255);
	mRight.setSpeed(255);
}

void Motors::speed(uint8_t speedLeft, uint8_t speedRight){
	mLeft.setSpeed(speedLeft);
	mRight.setSpeed(speedRight);
}


void Motors::forward(){
	mLeft.run(FORWARD);
	mRight.run(FORWARD);
}

void Motors::forward(int ms){
	mLeft.run(FORWARD);
	mRight.run(FORWARD);
	delay(ms);
}

void Motors::forward(uint8_t speedLeft, uint8_t speedRight){
	mLeft.setSpeed(speedLeft);
	mRight.setSpeed(speedRight);
	mLeft.run(FORWARD);
	mRight.run(FORWARD);
}

void Motors::forward(uint8_t speedLeft, uint8_t speedRight, int ms){
	mLeft.setSpeed(speedLeft);
	mRight.setSpeed(speedRight);
	mLeft.run(FORWARD);
	mRight.run(FORWARD);
	delay(ms);
}

void Motors::backward(){
	mLeft.run(BACKWARD);
	mRight.run(BACKWARD);
}

void Motors::backward(int ms){
	mLeft.run(BACKWARD);
	mRight.run(BACKWARD);
	delay(ms);
}

void Motors::backward(uint8_t speedLeft, uint8_t speedRight){
	mLeft.setSpeed(speedLeft);
	mRight.setSpeed(speedRight);
	mLeft.run(BACKWARD);
	mRight.run(BACKWARD);
}

void Motors::backward(uint8_t speedLeft, uint8_t speedRight, int ms){
	mLeft.setSpeed(speedLeft);
	mRight.setSpeed(speedRight);
	mLeft.run(BACKWARD);
	mRight.run(BACKWARD);
	delay(ms);
}

void Motors::right(){
	mLeft.run(FORWARD);
	mRight.run(BACKWARD);
}

void Motors::right(int ms){
	mLeft.run(FORWARD);
	mRight.run(BACKWARD);
	delay(ms);
}

void Motors::right(uint8_t speedLeft, uint8_t speedRight){
	mLeft.setSpeed(speedLeft);
	mRight.setSpeed(speedRight);
	mLeft.run(FORWARD);
	mRight.run(BACKWARD);
}

void Motors::right(uint8_t speedLeft, uint8_t speedRight, int ms){
	mLeft.setSpeed(speedLeft);
	mRight.setSpeed(speedRight);
	mLeft.run(FORWARD);
	mRight.run(BACKWARD);
	delay(ms);
}

void Motors::left(){
	mLeft.run(BACKWARD);
	mRight.run(FORWARD);
}

void Motors::left(int ms){
	mLeft.run(BACKWARD);
	mRight.run(FORWARD);
	delay(ms);
}

void Motors::left(uint8_t speedLeft, uint8_t speedRight){
	mLeft.setSpeed(speedLeft);
	mRight.setSpeed(speedRight);
	mLeft.run(BACKWARD);
	mRight.run(FORWARD);
}

void Motors::left(uint8_t speedLeft, uint8_t speedRight, int ms){
	mLeft.setSpeed(speedLeft);
	mRight.setSpeed(speedRight);
	mLeft.run(BACKWARD);
	mRight.run(FORWARD);
	delay(ms);
}

void Motors::stop(){
	mLeft.run(STOP);
	mRight.run(STOP);
}

void Motors::stop(int ms){
	mLeft.run(STOP);
	mRight.run(STOP);
	delay(ms);
}

void Motors::stopMicroseconds(int ms){
	mLeft.run(STOP);
	mRight.run(STOP);
	delay(ms);
}


//============================================================

                     //ENCODER FUNCTIONS

//============================================================

void Motors::forwardEncoder(int pulses){
	resetEncoders();
	readBegin();
	do {
		forward();
		readEnd();
		DeltaEncoders();
	} while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
	resetEncoders();
}

void Motors::forwardEncoder(int pulses, uint8_t speedLeft, uint8_t speedRight){
	resetEncoders();
	readBegin();
	do {
		forward(speedLeft, speedRight);
		readEnd();
		DeltaEncoders();
	} while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
	resetEncoders();
}

void Motors::rightEncoder(int pulses){
	resetEncoders();
	readBegin();
	do {
		right();
		readEnd();
		DeltaEncoders();
	} while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
	resetEncoders();
}

void Motors::rightEncoder(int pulses, uint8_t speedLeft, uint8_t speedRight){
	resetEncoders();
	readBegin();
	do {
		right(speedLeft, speedRight);
		readEnd();
		DeltaEncoders();
	} while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
	resetEncoders();
}

void Motors::leftEncoder(int pulses){
	resetEncoders();
	readBegin();
	do {
		left();
		readEnd();
		DeltaEncoders();
	} while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
	resetEncoders();
}

void Motors::leftEncoder(int pulses, uint8_t speedLeft, uint8_t speedRight){
	resetEncoders();
	readBegin();
	do {
		left(speedLeft, speedRight);
		readEnd();
		DeltaEncoders();
	} while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
	resetEncoders();
}
void Motors::backwardEncoder(int pulses){
	resetEncoders();
	readBegin();
	do {
		backward();
		readEnd();
		DeltaEncoders();
	} while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
	resetEncoders();
}

void Motors::backwardEncoder(int pulses, uint8_t speedLeft, uint8_t speedRight)
    
     {
	resetEncoders();
	readBegin();
	do {
		backward(speedLeft, speedRight);
		readEnd();
		DeltaEncoders();
	} while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
	resetEncoders();
}


//==============================================================


                       //SETTING ENCODER CM 

void Motors::forwardCM(double DistanceCm){

	double pulses = 0;
	pulses = DistanceCm * 720 / CircumferenceWheel;

	resetEncoders();
	readBegin();
	do {
		forward();
		readEnd();
		DeltaEncoders();
	} while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
	resetEncoders();
}

void Motors::forwardCM(double DistanceCm, uint8_t speedLeft, uint8_t speedRight){

    double pulses = 0;
	pulses = DistanceCm * 720 / CircumferenceWheel; 

	resetEncoders();
	readBegin();
	do {
		forward(speedLeft, speedRight);
		readEnd();
		DeltaEncoders();
	} while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
	resetEncoders();
}
void Motors::backwardCM(double DistanceCm){

	double pulses = 0;
	pulses = DistanceCm * 720 / CircumferenceWheel;

	resetEncoders();
	readBegin();
	do {
		backward();
		readEnd();
		DeltaEncoders();
	} while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
	resetEncoders();
}

void Motors::backwardCM(double DistanceCm, uint8_t speedLeft, uint8_t speedRight){

	double pulses = 0;
	pulses = DistanceCm * 720 / CircumferenceWheel;

	resetEncoders();
	readBegin();
	do {
		backward(speedLeft, speedRight);
		readEnd();
		DeltaEncoders();
	} while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
	resetEncoders();
}

//================================================================================


						//Move ROOM 3 

  long Motors::forwardCM_Room3(){
    
    readRoom3();
	Room3_DistanceCM = (ENC_LEFT_Room3 * 11 / 720) * -1; 
    
    return Room3_DistanceCM; 
}

long Motors::backwardCM_Room3(){
    
    readRoom3();
	Room3_DistanceCM = (ENC_LEFT_Room3 * 11 / 720); 
    
    return Room3_DistanceCM; 
}

//=======================================================================


void Motors::resetEncoders(){
	Encoder_LEFT.write(0);
	Encoder_RIGHT.write(0);
	ENC_LEFT_Begin = 0; 
	ENC_RIGHT_Begin = 0; 
	ENC_LEFT_End = 0; 
	ENC_RIGHT_End = 0; 
	Delta_RIGHT = 0; 
	Delta_LEFT = 0; 
}

void Motors::resetEncodersRoom3(){
  
    Encoder_LEFT.write(0);
	Encoder_RIGHT.write(0);
	//Room3_pulses = 0; 
    Room3_DistanceCM = 0; 

    ENC_LEFT_Room3 = 0; 
    ENC_RIGHT_Room3 =0; 

}

//PRIVATE METHODS
void Motors::readBegin(){
	ENC_LEFT_Begin = Encoder_LEFT.read();
	ENC_RIGHT_Begin = Encoder_RIGHT.read();
}

void Motors::readEnd(){
	ENC_LEFT_End = Encoder_LEFT.read();
	ENC_RIGHT_End = Encoder_RIGHT.read();
}

void Motors::DeltaEncoders(){
	Delta_RIGHT = abs(ENC_RIGHT_End - ENC_RIGHT_Begin);
    Delta_LEFT = abs(ENC_LEFT_End - ENC_LEFT_Begin);
}

void Motors::readRoom3()

{
	ENC_LEFT_Room3 = Encoder_LEFT.read();
	ENC_RIGHT_Room3 = Encoder_RIGHT.read();
}

//===========================================================================================================================

                     //MOTOR SERVO 

//===========================================================================================================================
int positionBucket; 
/*
     1 = (0 degrees);
     2 = (20 degrees);
     3 = (180 degrees);
*/

void Servos::begin()

{   
	bucket(0); 
    delay(500); 
    claw(0);
    center(0);
    delay(1000);

     CentralMotor.detach();
     motorRightClaw.detach();
	 motorLeftClaw.detach();
	 motorRightBucket.detach();
	 motorLeftBucket.detach();
}

void Servos::clawDown() //Claw - Down 

{
	claw(180);
	delay(500);
	center(180);
	delay(500); 
}


void Servos::clawClimb()  //Claw - Up

{
    claw(0);
	delay(500);
	bucket(20);
	delay(500);
	center(0);

	//CentralMotor.detach();
     motorRightClaw.detach();
	 motorLeftClaw.detach();
	 motorRightBucket.detach();
	 motorLeftBucket.detach();
}


void Servos::clawRescueArea() //Claw - Down 

{
   center(140);
   claw(100); 
   delay(2000);
   center(0);
   claw(0); 
}

void Servos::clawDownRamp() //Claw - Down 

{
	//claw(180);
	center(160);
	delay(1000); 
}




void Servos::clawDownSlow()
{
   center(180); 
   delay(500);
   claw(50);
   delay(500);
   claw(100);
   delay(500);
   claw(180);
   delay(500); 
}

     void Servos::claw(int degrees)  
   {
     
     motorRightClaw.attach(41); //Motor CLAW-RIGHT
	 motorLeftClaw.attach(37);
     
     /*
	 int degreesRight = 180 - (degrees + 70);
     int degreesLeft = degrees + 30;
     */

     if(degrees == 0)
     {
     //after the claw open 180 degrees
     //right -- 25 ---> 95 ----  (+70)
     //Left -- 115 ---> 35 ----- (-80)

	 motorRightClaw.write(95); //Motor CLAW-RIGHT
	 motorLeftClaw.write(35);

	/* for(int right = 25, left = 115;right <= 95 || left >= 35; right++, left--)
	 {   

	 	 if(right <= 95)
	 	 {
	 	 motorRightClaw.write(right); //Motor CLAW-RIGHT
	 	}
		 motorLeftClaw.write(left);
		 delay(15);
	 } */

	}

	if(degrees == 180)
     {

	 motorRightClaw.write(25); //Motor CLAW-RIGHT
	 motorLeftClaw.write(115);
	}
    
    if(degrees == 50)
     {

	 motorRightClaw.write(80); //Motor CLAW-RIGHT
	 motorLeftClaw.write(60);
	}

	if(degrees == 100)
	{
     motorRightClaw.write(70); // > close
	 motorLeftClaw.write(50);  // < open 
	}

	 //CentralMotor.detach();
    // motorRightClaw.detach();
	// motorLeftClaw.detach();


	}

	void Servos::center(int degrees)
	{
     
     if(degrees == 0)
     {
     CentralMotor.attach(43); //Central Motor 
	 CentralMotor.write(30); //Central Motor 
	}
     
     if(degrees == 180)
     {
     CentralMotor.attach(43); //Central Motor 
	 CentralMotor.write(180); //Central Motor 
	}
    
    if((degrees != 0)&&(degrees != 180))
     {
     CentralMotor.attach(23); //Central Motor 
	 CentralMotor.write(degrees); //Central Motor 
	}
/*
	 CentralMotor.detach();
     motorRightClaw.detach();
	 motorLeftClaw.detach();

*/
	}

	void Servos::bucket(int degrees) 
	{
   
		 motorRightBucket.attach(39); //Motor CLAW-RIGHT
		 motorLeftBucket.attach(35);

		if(degrees == 0)
		{
          motorRightBucket.write(180);
          motorLeftBucket.write(0);
		}

		if(degrees == 20){

        //after the bucket close to 0 degrees
     	//right -- 180 ---> 150 ----  (+30)
     	//Left -- 0 ---> 30 ----- (-30)

         for(int right = 180, left = 0;right >= 150 && left <= 30; right--, left++)
	 {   
	 	 motorRightClaw.write(right); //Motor CLAW-RIGHT
		 motorLeftClaw.write(left);
		 delay(15);
	 } 

		}

		if(degrees == 180)
		{
           motorRightBucket.write(0);
           motorLeftBucket.write(180);
         
          
		}
	}

	int Servos::readBucket()
	{
		int position = motorRightBucket.readMicroseconds(); 
		return position; 
	}

//===============================================================

//===============================================================

                     //GYRO SENSOR FUNCTIONS

//============================================================

void Motors::gyroBegin()

{

   //Serial.begin(9600);
   //Led.begin(); 
//==============================================
                //Settings of Gyro sensor 
                
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
//=======================================================

}

void Motors::turnRight90() //Turn robot for right with gyro sensor 
{
   speed(220, 220);
   resetGyro();
while(TotalDegrees < ninetyDegreeRight) //Turn right 
  {  
  	//Led.blue(); 
     AGRead();
       if(GDegreesZ > 0)
      {
      TotalDegrees += GDegreesZ;
  }
      right();
          
  }
   //backward(100, 100, 200); 
    stop(50);
    speed(180, 180);
    resetGyro();
    //Led.red(); 
}

void Motors::turnLeft90() //Turn robot for right with gyro sensor 

{
      speed(220, 220);
      resetGyro();
 while(TotalDegrees > ninetyDegreeLeft)  //Turn Left 
   {
   	  //Led.blue();
      AGRead();

      if(GDegreesZ < -3)
      { 
      TotalDegrees += GDegreesZ;
  }
      left();
      
   }
    //backward(100, 100, 200); 
    stop(50); 
    speed(180, 180);
    resetGyro();
    //Led.red(); 
}
void Motors::turnRight45() //Turn robot for right with gyro sensor 
{
   speed(220, 220);
   resetGyro();
while(TotalDegrees > fortyFiveDegreeRight) //Turn right 
  {  
  	//Led.blue(); 
     AGRead();
      
      TotalDegrees += GDegreesZ;
      right();
          
  }
   //backward(100, 100, 200); 
    stop(1000);
    speed(180, 180);
    resetGyro();
    //Led.red(); 
}

void Motors::turnLeft45() //Turn robot for right with gyro sensor 

{
      speed(220, 220);
      resetGyro();
 while(TotalDegrees < fortyFiveDegreeLeft)  //Turn Left 
   {
   	  //Led.blue();
      AGRead();

      
      TotalDegrees += GDegreesZ;
      left();
      
   }
    //backward(100, 100, 200); 
    stop(1000); 
    speed(180, 180);
    resetGyro();
    //Led.red(); 
}

void Motors::turnRight30() //Turn robot for right with gyro sensor 
{
   speed(190, 190);
   resetGyro();
while(TotalDegrees > thirtyDegreeRight) //Turn right 
  {  
  	//Led.blue(); 
     AGRead();
      
      TotalDegrees += GDegreesZ;
      right();
          
  }
   //backward(100, 100, 200); 
    stop(500);
    speed(180, 180);
    resetGyro();
    //Led.red(); 
}

void Motors::turnLeft30() //Turn robot for right with gyro sensor 

{
      speed(190, 190);
      resetGyro();
 while(TotalDegrees < thirtyDegreeLeft)  //Turn Left 
   {
   	  //Led.blue();
      AGRead();

      
      TotalDegrees += GDegreesZ;
      left();
      
   }
    //backward(100, 100, 200); 
    stop(500); 
    speed(180, 180);
    resetGyro();
    //Led.red(); 
}

//============================================================
void Motors::AGRead() { //Read of Gyro sensor 
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8 |Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  Degrees();
}

void Motors::Degrees() { //Map raw values of gyro sensor 
  ACDegreesX = map(AcX, minAC, maxAC, -90, 90);
  ACDegreesY = map(AcY, minAC, maxAC, -90 , 90);
  ACDegreesZ = map(AcZ, minAC, maxAC, -90 , 90);
  GDegreesX = map(GyX, minAC, maxAC, -90, 90);
  GDegreesY = map(GyY, minAC, maxAC, -90, 90);
  GDegreesZ = map(GyZ, minAC, maxAC, -90, 90);
}
void Motors::resetGyro() //Reset gyro sensor 
{
  Wire.write(0);
  TotalDegrees = 0;
  GDegreesZ = 0; 
} 

