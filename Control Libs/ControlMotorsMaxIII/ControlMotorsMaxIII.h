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
 * $Translat portuguese/English added in 2016-08(Feb 2017) 
 * ----------------------------------------------------------
 */


#ifndef ControlMotorsMaxIII_H
#define ControlMotorsMaxIII_H 

#include <Arduino.h>
#include <Wire.h> 
#include <Servo.h>
//#include <Led.h>
 
#include "AFMotor.h"
#include "Encoder.h"

//ENCODER - SETTINGS
#define ATTACH1_LEFT 18
#define ATTACH2_LEFT 16

#define ATTACH1_RIGHT 19
#define ATTACH2_RIGHT 17


//GYRO SENSOR - SETTING 

#define ninetyDegreeRight 23000 // Default Settings for turn with gyro sensor 
#define ninetyDegreeLeft  -25000 

#define fortyFiveDegreeRight -11500 // Default Settings for turn with gyro sensor 
#define fortyFiveDegreeLeft  10500

#define thirtyDegreeRight -8500 // Default Settings for turn with gyro sensor 
#define thirtyDegreeLeft  7800 


#define TriRight -15950 
#define TriLeft  1350
#define adjustLeft  4050 


class Motors
{
public:
	Motors();

	//~Motors();
	void corrente();

	void speed(uint8_t speedLeft, uint8_t speedRight);
	void maxSpeed();

	void forward();
	void forward(int ms);
	void forward(uint8_t speedLeft, uint8_t speedRight);
	void forward(uint8_t speedLeft, uint8_t speedRight, int ms);

	void backward();
	void backward(int ms);
	void backward(uint8_t speedLeft, uint8_t speedRight);
	void backward(uint8_t speedLeft, uint8_t speedRight, int ms);

	void right();
	void right(int ms);
	void right(uint8_t speedLeft, uint8_t speedRight);
	void right(uint8_t speedLeft, uint8_t speedRight, int ms);

	void left();
	void left(int ms);
	void left(uint8_t speedLeft, uint8_t speedRight);
	void left(uint8_t speedLeft, uint8_t speedRight, int ms);

	void stop();
	void stop(int ms);
	void stopMicroseconds(int ms);

	//With Encoder

	void forwardEncoder(int pulses);
	void forwardEncoder(int pulses, uint8_t speedLeft, uint8_t speedRight);

	void rightEncoder(int pulses);
	void rightEncoder(int pulses, uint8_t speedLeft, uint8_t speedRight);

	void leftEncoder(int pulses);
	void leftEncoder(int pulses, uint8_t speedLeft, uint8_t speedRight);

	void backwardEncoder(int pulses);
	void backwardEncoder(int pulses, uint8_t speedLeft, uint8_t speedRight);

    void forwardCM(double DistanciaCm);
    void forwardCM(double DistanciaCm, uint8_t speedLeft, uint8_t speedRight);

    void backwardCM(double DistanciaCm);
    void backwardCM(double DistanciaCm, uint8_t speedLeft, uint8_t speedRight);

	void resetEncoders();

	void gyroBegin(); 
	void turnRight90(); 
	void turnLeft90();
	void turnRight45(); 
	void turnLeft45();
	void turnLeft30(); 
	void turnRight30(); 

     void resetGyro();

     

     void resetEncodersRoom3(); 
     void readRoom3(); 
     long forwardCM_Room3(); 
     long backwardCM_Room3();

private:

	// Encoder 
	long Delta_RIGHT;
	long Delta_LEFT;
	long ENC_LEFT_Begin;
	long ENC_LEFT_End;
	long ENC_RIGHT_Begin;
	long ENC_RIGHT_End;
	long ENC_LEFT_Room3; 
	long ENC_RIGHT_Room3; 

	double Room3_pulses;
    double Room3_DistanceCM; 

	void readBegin();
	void readEnd();
	void DeltaEncoders();

	//Gyro sensor 
	const int MPU_addr = 0x68;  // I2C address of the MPU-6050
    int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
    int GDegreesX, GDegreesY, GDegreesZ, DegreesY, ACDegreesX, ACDegreesY, ACDegreesZ;
    const int minAC = -16800;
    const int maxAC = 16800;

    long TotalDegrees = 0; 

    //int TotalDegrees = 0;
    //int TotalDegreesY = 0; 

    void AGRead(); 
    void Degrees();
    //void resetGyro(); 

  
};

class Servos
{


  public:

    void begin();
	void clawDown();
	void clawClimb();
	void clawRescueArea(); 
	void clawDownRamp(); 
	void clawAfterRamp(); 
	void clawDownSlow();
	void claw(int degrees); 
	void center(int degrees); 
	void bucket(int degrees);
	int readBucket();

  private: 
};


#endif

