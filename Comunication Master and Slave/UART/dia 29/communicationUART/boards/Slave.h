


#ifndef Slave_H
#define Slave_H 


#include "Arduino.h"

class Slave {


    public:

     
        void begin()
         {
           Serial1.begin(500000);
         }

 void send(int value)
 {
      delayMicroseconds(200);
      Serial1.write(value); 
 }
 int receive()
 {
     if (Serial1.available() > 0)
     {
        valueSerialSlave = Serial1.read();  
        return valueSerialSlave; 
     }
     else
     {
      bool start = false;
      while(start == false)
      {
        if(Serial1.available() > 0)
        {
          valueSerialSlave = Serial1.read();  
          return valueSerialSlave; 
          start = true;
        }
      }
     }  
}
     
     private: 
         
    int valueSerialSlave; 
};


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
class Check
{

private:

    #define Check_pin1 2
    #define Check_pin2 3 
    #define Check_pin3 4
    #define Check_pin4 5

public:
   
  void begin()
{
  pinMode(Check_pin1, INPUT_PULLUP); 
  pinMode(Check_pin2, INPUT_PULLUP); 
  pinMode(Check_pin3, INPUT_PULLUP); 
  pinMode(Check_pin4, INPUT_PULLUP); 
}

bool condition_1()
{
    if((digitalRead(Check_pin1) == 0)&&(digitalRead(Check_pin2) == 0)
      &&(digitalRead(Check_pin3) == 0)&&(digitalRead(Check_pin4) == 0))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool condition_2()
{
     if((digitalRead(Check_pin1) == 1)&&(digitalRead(Check_pin2) == 0)
      &&(digitalRead(Check_pin3) == 0)&&(digitalRead(Check_pin4) == 0))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool condition_3()
{
    if((digitalRead(Check_pin1) == 0)&&(digitalRead(Check_pin2) == 1)
      &&(digitalRead(Check_pin3) == 0)&&(digitalRead(Check_pin4) == 0))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool condition_4()
{
    if((digitalRead(Check_pin1) == 0)&&(digitalRead(Check_pin2) == 0)
      &&(digitalRead(Check_pin3) == 1)&&(digitalRead(Check_pin4) == 0))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool condition_5()
{
    if((digitalRead(Check_pin1) == 0)&&(digitalRead(Check_pin2) == 0)
      &&(digitalRead(Check_pin3) == 0)&&(digitalRead(Check_pin4) == 1))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool condition_6()
{
    if((digitalRead(Check_pin1) == 1)&&(digitalRead(Check_pin2) == 1)
      &&(digitalRead(Check_pin3) == 1)&&(digitalRead(Check_pin4) == 1))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool condition_7()
{
     if((digitalRead(Check_pin1) == 0)&&(digitalRead(Check_pin2) == 1)
      &&(digitalRead(Check_pin3) == 1)&&(digitalRead(Check_pin4) == 1))
    {
      return true;
    }
    else
    {
      return false; 
    }
}
bool condition_8()
{
   if((digitalRead(Check_pin1) == 1)&&(digitalRead(Check_pin2) == 0)
    &&(digitalRead(Check_pin3) == 1)&&(digitalRead(Check_pin4) == 1))
    {
      return true;
    }
    else
    {
      return false; 
    }
}
bool condition_9()
{
   if((digitalRead(Check_pin1) == 1)&&(digitalRead(Check_pin2) == 1)
    &&(digitalRead(Check_pin3) == 0)&&(digitalRead(Check_pin4) == 1))
    {
      return true;
    }
    else
    {
      return false; 
    }
}
bool condition_10()
{
   if((digitalRead(Check_pin1) == 1)&&(digitalRead(Check_pin2) == 1)
    &&(digitalRead(Check_pin3) == 1)&&(digitalRead(Check_pin4) == 0))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool condition_11()
{
   if((digitalRead(Check_pin1) == 1)&&(digitalRead(Check_pin2) == 1)
    &&(digitalRead(Check_pin3) == 0)&&(digitalRead(Check_pin4) == 0))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool condition_12()
{
   if((digitalRead(Check_pin1) == 1)&&(digitalRead(Check_pin2) == 0)
    &&(digitalRead(Check_pin3) == 1)&&(digitalRead(Check_pin4) == 0))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool condition_13()
{
   if((digitalRead(Check_pin1) == 1)&&(digitalRead(Check_pin2) == 0)
    &&(digitalRead(Check_pin3) == 0)&&(digitalRead(Check_pin4) == 1))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool condition_14()
{
   if((digitalRead(Check_pin1) == 0)&&(digitalRead(Check_pin2) == 0)
    &&(digitalRead(Check_pin3) == 1)&&(digitalRead(Check_pin4) == 1))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool condition_15()
{
   if((digitalRead(Check_pin1) == 0)&&(digitalRead(Check_pin2) == 1)
    &&(digitalRead(Check_pin3) == 0)&&(digitalRead(Check_pin4) == 1))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool condition_16()
{
   if((digitalRead(Check_pin1) == 0)&&(digitalRead(Check_pin2) == 1)
    &&(digitalRead(Check_pin3) == 1)&&(digitalRead(Check_pin4) == 0))
    {
      return true;
    }
    else
    {
      return false; 
    }
}
//==============================================
};

#endif