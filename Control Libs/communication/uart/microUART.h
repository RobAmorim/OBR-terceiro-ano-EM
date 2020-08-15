


#ifndef microUART_H
#define microUART_H 


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

#endif