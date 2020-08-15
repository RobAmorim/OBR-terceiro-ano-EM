
//ESTRUTURAS - LED.h /




#ifndef Master_H
#define Master_H 


#include "Arduino.h"
#define pinEnablet 7 

class Master {

    public:
     
    	  void begin()
         {
                
         Serial3.begin(500000);
         pinMode(pinEnablet, OUTPUT); 
               
         }

  void send(int value)
         {    
              digitalWrite(pinEnablet, LOW);
              //delayMicroseconds(200); 
              Serial3.write(value);

             /* if(Serial3.available() > 0)
                 {
                    valueSerialMaster = Serial3.read();  
                 }

                 if(valueSerialMaster == value)
                 {
                   Serial3.write(1);
                 }*/
         }
  int receive()

         {     
              digitalWrite(pinEnablet, HIGH); 
              // delay(1); 
               if (Serial3.available() > 0)
                 {
                    valueSerialMaster = Serial3.read();  
                    return valueSerialMaster;
                 }
                 else
               {/*
                int i = 10; 
                return i;
                */
               }
                                
         }
 
    private:

        int valueSerialMaster; 
};



#endif 