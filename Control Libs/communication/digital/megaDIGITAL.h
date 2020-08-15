#ifndef megaDIGITAL_H
#define megaDIGITAL_H 

#include "Arduino.h"


/*     combinations with 4 digits 

    1-     0000
    2-     1000
    3-     0100   
    4-     0010
    5-     0001
    6-     1111
    7-     0111
    8-     1011
    9-     1101
    10-    1110
    11-    1100
    12-    1010
    13-    1001
    14-    0011
    15-    0101
    16-    0110

*/

class Trigger
{
private:
     
     #define Trigger_pin1 22
     #define Trigger_pin2 23
     #define Trigger_pin3 24   
     #define Trigger_pin4 25 

public:

//==============================================

void begin() 
{
  pinMode(Trigger_pin1, OUTPUT); 
  pinMode(Trigger_pin2, OUTPUT); 
  pinMode(Trigger_pin3, OUTPUT); 
  pinMode(Trigger_pin4, OUTPUT);
}

void condition_1()
{
 digitalWrite(Trigger_pin1, LOW);  //1
 digitalWrite(Trigger_pin2, LOW);
 digitalWrite(Trigger_pin3, LOW);
 digitalWrite(Trigger_pin4, LOW);

}

void condition_2()
{
 digitalWrite(Trigger_pin1, HIGH);  //2
 digitalWrite(Trigger_pin2, LOW);
 digitalWrite(Trigger_pin3, LOW);
 digitalWrite(Trigger_pin4, LOW);
}

void condition_3()
{
  digitalWrite(Trigger_pin1, LOW);  //3
  digitalWrite(Trigger_pin2, HIGH);
  digitalWrite(Trigger_pin3, LOW);
  digitalWrite(Trigger_pin4, LOW);
}

void condition_4()
{
 digitalWrite(Trigger_pin1, LOW);  //4
 digitalWrite(Trigger_pin2, LOW);
 digitalWrite(Trigger_pin3, HIGH);
 digitalWrite(Trigger_pin4, LOW);
}

void condition_5()
{
 digitalWrite(Trigger_pin1, LOW);  //5
 digitalWrite(Trigger_pin2, LOW);
 digitalWrite(Trigger_pin3, LOW);
 digitalWrite(Trigger_pin4, HIGH);
}
void condition_6()
{
   digitalWrite(Trigger_pin1, HIGH);  //6
   digitalWrite(Trigger_pin2, HIGH);
   digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, HIGH);
}

void condition_7()
{
     digitalWrite(Trigger_pin1, LOW);  //7
     digitalWrite(Trigger_pin2, HIGH);
     digitalWrite(Trigger_pin3, HIGH);
     digitalWrite(Trigger_pin4, HIGH);

}

void condition_8()
{
   digitalWrite(Trigger_pin1, HIGH);  //8
   digitalWrite(Trigger_pin2, LOW);
   digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, HIGH);
}

void condition_9()
{
   digitalWrite(Trigger_pin1, HIGH);  //8
   digitalWrite(Trigger_pin2, HIGH);
   digitalWrite(Trigger_pin3, LOW);
   digitalWrite(Trigger_pin4, HIGH);
}

void condition_10()
{
   digitalWrite(Trigger_pin1, HIGH);  //9
   digitalWrite(Trigger_pin2, HIGH);
   digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, LOW);
}

void condition_11()
{
   digitalWrite(Trigger_pin1, HIGH);  //10
   digitalWrite(Trigger_pin2, HIGH);
   digitalWrite(Trigger_pin3, LOW);
   digitalWrite(Trigger_pin4, LOW);
}

void condition_12()
{
   digitalWrite(Trigger_pin1, HIGH);  //11
   digitalWrite(Trigger_pin2, LOW);
   digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, LOW);
}

void condition_13()
{
   digitalWrite(Trigger_pin1, HIGH);  //12
   digitalWrite(Trigger_pin2, LOW);
   digitalWrite(Trigger_pin3, LOW);
   digitalWrite(Trigger_pin4, HIGH);
}
void condition_14()
{
   digitalWrite(Trigger_pin1, LOW);  //13
   digitalWrite(Trigger_pin2, LOW);
   digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, HIGH);
}

void condition_15()
{
   digitalWrite(Trigger_pin1, LOW);  //14
   digitalWrite(Trigger_pin2, HIGH);
   digitalWrite(Trigger_pin3, LOW);
   digitalWrite(Trigger_pin4, HIGH);
}

void condition_16()
{
   digitalWrite(Trigger_pin1, LOW);  //15
   digitalWrite(Trigger_pin2, HIGH);
   digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, LOW);
}

//========================================================================== 
};
#endif 