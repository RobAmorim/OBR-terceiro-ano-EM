


#ifndef Slave_H
#define Slave_H 


#include "Arduino.h"
#define pinEnablet 11   


class Slave {


    public:

     
        void begin()
         {
           Serial1.begin(500000);
           pinMode(pinEnablet, INPUT_PULLUP);
         }

 void send(int value)
 {
      if(digitalRead(pinEnablet) == 1)
      {
      delayMicroseconds(200);
      Serial1.write(value); 
      }
 }
 int receive()
 {
  if(digitalRead(pinEnablet) == 0)
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
          start = true;
        }
      }
     }
    
 }
}
     
     private: 
         
    int valueSerialSlave; 
};

#endif