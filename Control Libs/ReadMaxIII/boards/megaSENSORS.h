/*
 * Libray Read v1.0
 * -------------------------
 * $Author Robson Amorim 
 * $Date 2017-04-28 $
 */

#ifndef megaSENSORS_H
#define megaSENSORS_H

#include <Arduino.h>

#include <communication.h>
#include <uart/megaUART.h>


//====================================================================
              //SETTING REFLECTANCE SENSOR 
                      
#define sensorRighLine A12     //Pins -> Connections of Reflectance Sensor 
#define sensorLeftLine A11
#define sensorLeftCorner A10
#define sensorRightCorner A6
#define sensorRightEx A7
#define sensorLeftEx A9 
#define sensorRightSuper A5
#define sensorLeftSuper A8 
//===============================================================================  

                         //SETTING COLOR SENSOR 

#define Right_s0 30 //Pins -> Connections of color right sensor 
#define Right_s1 32  
#define Right_s2 34  
#define Right_s3 36
#define Right_out 38 
 
#define Left_s0 31  //Pins -> Connections of color left sensor 
#define Left_s1 33
#define Left_s2 35  
#define Left_s3 37
#define Left_out 39  

int cutoff_Green = 80;  //Cuttoff value of color sensor 

//===============================================================================  



class Read
{
private:
	
            int greenRight;  // variable to store the value coming from the right sensor 
            int greenLeft;   // variable to store the value coming from the left sensor 


            int _GreenDir = 0; 
            int  GreenDir = 0; 

            int _GreenEsq = 0; 
            int GreenEsq = 0; 
public: 

//=======================================================================================
                                //COLOR SENSOR
//=======================================================================================
void colorBegin() 
{
  pinMode(Right_s1, OUTPUT);  //Color sensor Right
  pinMode(Right_s2, OUTPUT);  
  pinMode(Right_s3, OUTPUT);  
  pinMode(Right_out, INPUT);  
  digitalWrite(Right_s0, HIGH); 
  digitalWrite(Right_s1, LOW);  

  pinMode(Left_s1, OUTPUT);  //Color Sensor Left
  pinMode(Left_s2, OUTPUT);  
  pinMode(Left_s3, OUTPUT);  
  pinMode(Left_out, INPUT);  
  digitalWrite(Left_s0, HIGH);  
  digitalWrite(Left_s1, LOW);  
}

 int colorRight()  //Reading color sensor right 
{  
  //count OUT, pGreen, GREEN 
    digitalWrite(Right_s2, HIGH);
    digitalWrite(Right_s3, HIGH);
    greenRight = pulseIn(Right_out, digitalRead(Right_out) == HIGH ? LOW : HIGH);  
 
    return greenRight; 
}

int Read::colorLeft()  //Reading color sensor left
{ 
    //count OUT, pGreen, GREEN  
     digitalWrite(Left_s2, HIGH);
     digitalWrite(Left_s3, HIGH);
    greenLeft = pulseIn(Left_out, digitalRead(Left_out) == HIGH ? LOW : HIGH);  

    return greenLeft; 
}


bool verificationColorRight() 

{
    SGreenDir = 0; 
   _GreenDir = 0;
    for(int i = 0; i < 10; i++)
    {
      _GreenDir += colorRight(); 
    }

    GreenDir = _GreenDir/10;  


    if(GreenDir  > cutoff_Green)
     {
      return true; 
     }

      if(GreenDir  < cutoff_Green)
     {
       return false; 
     }
}

bool verificationColorLeft()

{
    GreenEsq = 0;  
    _GreenEsq = 0; 
      for(int i = 0; i < 10; i++)
    {
      _GreenEsq += colorLeft(); 
    }

    GreenEsq = _GreenEsq/10;  


    if(GreenEsq  > cutoff_Green)
     {
      return true; 
     }

      if(GreenEsq  < cutoff_Green)
     {
       return false; 
     }
}

int _colorRight() {
  return GreenDir; 
}
int _colorLeft() {
  return GreenEsq; 
}

//=======================================================================================
                                //REFLECTANCE SENSORS
//=======================================================================================

int leftLine(){ //Reading reflectance sensors 
  return analogRead(sensorLeftLine);    
}
int rightLine(){ //Reading reflectance sensors 
  return analogRead(sensorRighLine);    
}
int leftCorner(){ //Reading reflectance sensors 
  return analogRead(sensorLeftCorner);    
}
int rightCorner(){ //Reading reflectance sensors 
  return analogRead(sensorRightCorner);    
}
int leftEx(){ //Reading reflectance sensors 
  return analogRead(sensorLeftEx);    
}
int rightEx(){ //Reading reflectance sensors 
  return analogRead(sensorRightEx);    
}
/* int leftSuper(){ //Reading reflectance sensors 
  return analogRead(sensorLeftSuper);    
}
intrightSuper(){ //Reading reflectance sensors 
  return analogRead(sensorRightSuper);    
} */
//=======================================================================================
                                // VERIFICATION MICRO CONDITIONS 
//=======================================================================================

  bool Read::verificationObstacle()

{
  int condition = Master.receive(); 

  if(condition == 20)
    return true;

   else if(condition != 20)
    return false; 
}

};
#endif

