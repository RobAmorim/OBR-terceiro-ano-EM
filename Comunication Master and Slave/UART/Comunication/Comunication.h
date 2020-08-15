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
   
   
   void begin();
   void condition_1(); 
   void condition_2(); 
   void condition_3(); 
   void condition_4(); 
   void condition_5(); 
   void condition_6(); 
   void condition_7(); 
   void condition_8(); 
   void condition_9(); 
   void condition_10(); 
   void condition_11(); 
   void condition_12(); 
   void condition_13(); 
   void condition_14(); 
   void condition_15(); 
   void condition_16(); 

private:
     
     #define Trigger_pin1 22
     #define Trigger_pin2 23
     #define Trigger_pin3 24   
     #define Trigger_pin4 25  
};

#endif
