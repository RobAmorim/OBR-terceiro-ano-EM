/*
 * Libray ControlMotors v1.1
 * -------------------------
 * $Based on Adafruit's library: AFMotor $
 * $Author Alberto Daniel $
 * $Date 2015-06-27 12:49:06 (Sat, 27 Jun 2015) $
 * -------------------------------------------------
 * $Encoders added in 2015-08-02 12:17:39 (Sun, 02 Aug 2015)$
 */

 //ATTACH1 = Blue Wire
 //ATTACH2 = Yellow Wire

#include <ControlMotorsEncoderEnglish.h>
#include "AFMotor.h"
#include "Encoder.h"

//MOTORS INSTANCE
AF_DCMotor mLeft(4);
AF_DCMotor mRight(3);

//ENCODERS INSTANCE
Encoder Encoder_LEFT(ATTACH1_LEFT, ATTACH2_LEFT);
Encoder Encoder_RIGHT(ATTACH1_RIGHT, ATTACH2_RIGHT);

#define CircumferenceWheel 12

Motors::Motors(){

	#define STOP 4
	#define FORWARD 1
	#define BACKWARD 2
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


                       //SETTING ENCODER 

void Motors::forwardCM(int DistanceCm){

	int pulses = 0;
	pulses = DistanceCm * 360 / CircumferenceWheel;

	resetEncoders();
	readBegin();
	do {
		forward();
		readEnd();
		DeltaEncoders();
	} while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
	stop();
	resetEncoders();
}

void Motors::forwardCM(int DistanceCm, uint8_t speedLeft, uint8_t speedRight){

    int pulses = 0;
	pulses = DistanceCm * 360 / CircumferenceWheel; 

	resetEncoders();
	readBegin();
	do {
		forward(speedLeft, speedRight);
		readEnd();
		DeltaEncoders();
	} while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
	stop();
	resetEncoders();
}

void Motors::backwardCM(int DistanceCm){

	int pulses = 0;
	pulses = DistanceCm * 360 / CircumferenceWheel;

	resetEncoders();
	readBegin();
	do {
		backward();
		readEnd();
		DeltaEncoders();
	} while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
	stop();
	resetEncoders();
}

void Motors::backwardCM(int DistanceCm, uint8_t speedLeft, uint8_t speedRight){

	int pulses = 0;
	pulses = DistanceCm * 360 / CircumferenceWheel;

	resetEncoders();
	readBegin();
	do {
		backward(speedLeft, speedRight);
		readEnd();
		DeltaEncoders();
	} while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
	stop();
	resetEncoders();
}



//===========================================================

void Motors::resetEncoders(){
	Encoder_LEFT.write(0);
	Encoder_RIGHT.write(0);
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

