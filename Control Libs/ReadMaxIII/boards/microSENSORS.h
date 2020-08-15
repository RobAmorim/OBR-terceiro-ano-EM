/*
 * Libray Read v1.0
 * -------------------------
 * $Author Robson Amorim 
 * $Date 2017-04-28 $
 */

#ifndef microSENSORS_H
#define microSENSORS_H

#include <Arduino.h>
#include "SharpIR.h" //Functions of the ultrasonic Sensor 

//===============================================================
        // SETTING SHARPS SENSOR FILTER

#define irR A0 //Pins -> Connections of Sharp Sensor 
#define irL A1
#define irT_R A7 
#define irT_L A8 
#define ir_F A6

SharpIR sharpRightSensor(irR, 30, 93, model);   // Default Settings 
SharpIR sharpLeftSensor(irL, 30, 93, model);  
SharpIR sharpTriLeftSensor(irT_L, 30, 93, model);  
SharpIR sharpTriRightSensor(irT_R, 30, 93, model);  
SharpIR sharpFrontSensor(ir_F, 5, 93, model);  

#define model 1080
//===============================================================================  


class Read
{
private:
	
          int distanceRight = 0; 
          int distanceLeft = 0; 
          int distanceTriRight = 0; 
          int distanceTriLeft = 0; 
          int distanceFront = 0; 
 public:

//=======================================================================================
                                //SHARP SENSOR
//=======================================================================================
  
 int Read::sharpRight() {
  
  distanceRight = sharpRightSensor.distance();
  return distanceRight; 
}

 int Read::sharpLeft(){
  
   distanceLeft = sharpLeftSensor.distance();
   return distanceLeft; 
}

int Read::sharpTriRight(){

  distanceTriRight = sharpTriRightSensor.distance();
  return distanceTriRight; 
}

int Read::sharpTriLeft(){

  distanceTriLeft = sharpTriLeftSensor.distance();
  return distanceTriLeft; 
}

int Read::sharpFront(){

  distanceFront = sharpFrontSensor.distance();
  return distanceFront; 
}


};
#endif

