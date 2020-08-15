
//ESTRUTURAS - LED.h /




#ifndef Master_H
#define Master_H 


#include "Arduino.h"

class Master {

    public:
     
    	  void begin()
         {
                
         Serial3.begin(115200);
               
         }

  void send(int value)
         {
              delayMicroseconds(200); 
               Serial3.write(value);
         }
  int receive()

         {
               if (Serial3.available() > 0)
                 {
                    valueSerialMaster = Serial3.read();  
                 }
               return valueSerialMaster;
                                
         }
 
    private:

        int valueSerialMaster; 
};



#endif 