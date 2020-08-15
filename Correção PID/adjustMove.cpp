

void Motors::forwardCM(int DistanceCm){

	int pulses = 0;
	pulses = DistanceCm * 360 / CircumferenceWheel;

	resetEncoders();
	resetAdjustMove();
	readBegin();
	do {
		readEnd();
		adjustMove();
		forward(left_Speed_Adjust, right_Speed_Adjust);
		DeltaEncoders();
	} while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
	stop();
	resetEncoders();
	resetAdjustMove();
}



//=========================================================

void Motors::adjustMove()

{
int error = ENC_LEFT_End - ENC_RIGHT_End; 
int P_error = 1; 

int addSpeed = error * P_error; 

int right_Speed_Adjust = BaseSpeed + addSpeed; 
int left_Speed_Adjust = BaseSpeed - addSpeed; 
}


//===========================================================

void Motors::forward(uint8_t speedLeft, uint8_t speedRight){
	mLeft.setSpeed(speedLeft);
	mRight.setSpeed(speedRight);
	mLeft.run(FORWARD);
	mRight.run(FORWARD);
}

//============================================================
void Motors::resetEncoders(){
	Encoder_LEFT.write(0);
	Encoder_RIGHT.write(0);
}

void Motors::resetAdjustMove()
{
  	error = 0;
 	P_error = 0; 
   	addSpeed = 0; 
 	right_Speed_Adjust = 0; 
	left_Speed_Adjust = 0; 
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
