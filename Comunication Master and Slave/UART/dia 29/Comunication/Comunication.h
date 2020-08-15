#ifndef Comunication_H
#define Comunication_H

#include <Arduino.h>

class Check
{

public:
   
   void begin();
   bool condition_1(); 
   bool condition_2(); 
   bool condition_3(); 
   bool condition_4(); 
   bool condition_5(); 
   bool condition_6(); 
   bool condition_7(); 
   bool condition_8(); 
   bool condition_9(); 
   bool condition_10(); 
   bool condition_11(); 
   bool condition_12(); 
   bool condition_13(); 
   bool condition_14(); 
   bool condition_15(); 
   bool condition_16(); 


private:

    #define Check_pin1 2
    #define Check_pin2 3 
    #define Check_pin3 4
    #define Check_pin4 5
};

class Trigger
{

public:

void Trigger::begin() 
{
  pinMode(Trigger_pin1, OUTPUT); 
  pinMode(Trigger_pin2, OUTPUT); 
  pinMode(Trigger_pin3, OUTPUT); 
  pinMode(Trigger_pin4, OUTPUT);
}

void Trigger::condition_1()
{
 digitalWrite(Trigger_pin1, LOW);  //1
 digitalWrite(Trigger_pin2, LOW);
 digitalWrite(Trigger_pin3, LOW);
 digitalWrite(Trigger_pin4, LOW);

}

void Trigger::condition_2()
{
 digitalWrite(Trigger_pin1, HIGH);  //2
 digitalWrite(Trigger_pin2, LOW);
 digitalWrite(Trigger_pin3, LOW);
 digitalWrite(Trigger_pin4, LOW);
}

void Trigger::condition_3()
{
  digitalWrite(Trigger_pin1, LOW);  //3
  digitalWrite(Trigger_pin2, HIGH);
  digitalWrite(Trigger_pin3, LOW);
  digitalWrite(Trigger_pin4, LOW);
}

void Trigger::condition_4()
{
 digitalWrite(Trigger_pin1, LOW);  //4
 digitalWrite(Trigger_pin2, LOW);
 digitalWrite(Trigger_pin3, HIGH);
 digitalWrite(Trigger_pin4, LOW);
}

void Trigger::condition_5()
{
 digitalWrite(Trigger_pin1, LOW);  //5
 digitalWrite(Trigger_pin2, LOW);
 digitalWrite(Trigger_pin3, LOW);
 digitalWrite(Trigger_pin4, HIGH);
}
void Trigger::condition_6()
{
   digitalWrite(Trigger_pin1, HIGH);  //6
   digitalWrite(Trigger_pin2, HIGH);
   digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, HIGH);
}

void Trigger::condition_7()
{
     digitalWrite(Trigger_pin1, LOW);  //7
     digitalWrite(Trigger_pin2, HIGH);
     digitalWrite(Trigger_pin3, HIGH);
     digitalWrite(Trigger_pin4, HIGH);

}

void Trigger::condition_8()
{
   digitalWrite(Trigger_pin1, HIGH);  //8
   digitalWrite(Trigger_pin2, LOW);
   digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, HIGH);
}

void Trigger::condition_9()
{
   digitalWrite(Trigger_pin1, HIGH);  //8
   digitalWrite(Trigger_pin2, HIGH);
   digitalWrite(Trigger_pin3, LOW);
   digitalWrite(Trigger_pin4, HIGH);
}

void Trigger::condition_10()
{
   digitalWrite(Trigger_pin1, HIGH);  //9
   digitalWrite(Trigger_pin2, HIGH);
   digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, LOW);
}

void Trigger::condition_11()
{
   digitalWrite(Trigger_pin1, HIGH);  //10
   digitalWrite(Trigger_pin2, HIGH);
   digitalWrite(Trigger_pin3, LOW);
   digitalWrite(Trigger_pin4, LOW);
}

void Trigger::condition_12()
{
   digitalWrite(Trigger_pin1, HIGH);  //11
   digitalWrite(Trigger_pin2, LOW);
   digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, LOW);
}

void Trigger::condition_13()
{
   digitalWrite(Trigger_pin1, HIGH);  //12
   digitalWrite(Trigger_pin2, LOW);
   digitalWrite(Trigger_pin3, LOW);
   digitalWrite(Trigger_pin4, HIGH);
}
void Trigger::condition_14()
{
   digitalWrite(Trigger_pin1, LOW);  //13
   digitalWrite(Trigger_pin2, LOW);
   digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, HIGH);
}

void Trigger::condition_15()
{
   digitalWrite(Trigger_pin1, LOW);  //14
   digitalWrite(Trigger_pin2, HIGH);
   digitalWrite(Trigger_pin3, LOW);
   digitalWrite(Trigger_pin4, HIGH);
}

void Trigger::condition_16()
{
   digitalWrite(Trigger_pin1, LOW);  //15
   digitalWrite(Trigger_pin2, HIGH);
   digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, LOW);
}

//==========================================================================

private:
     
     #define Trigger_pin1 22
     #define Trigger_pin2 23
     #define Trigger_pin3 24   
     #define Trigger_pin4 25  
};

#endif
