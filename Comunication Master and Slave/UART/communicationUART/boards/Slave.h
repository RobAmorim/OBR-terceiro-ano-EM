


#ifndef Slave_H
#define Slave_H 


#include "Arduino.h"
//#include <SoftwareSerial.h>


class Slave {


    public:

     
        void begin()
         {
           Serial1.begin(115200);
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
     }
    return valueSerialSlave; 
 }
     
     private: 
         
    int valueSerialSlave; 
};

#endif