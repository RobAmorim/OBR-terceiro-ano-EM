
//ESTRUTURAS - LED.h /




#ifndef megaUART_H
#define megaUART_H 


#include "Arduino.h"


class Master {

    public:
     
    	  void begin()
         {
                
         Serial3.begin(500000);
               
         }

  void send(int value)
         {    
              delayMicroseconds(200); 
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
               if (Serial3.available() > 0)
                 {
                    valueSerialMaster = Serial3.read();  
                    return valueSerialMaster;
                 }
                 else
               {   
                /*
                     bool start = false;
                    while(start == false)
                    {
                      if(Serial3.available() > 0)
                      {
                        valueSerialMaster = Serial3.read();  
                        return valueSerialMaster;
                      }

      }*/
               }
                                
         }
 
    private:

        int valueSerialMaster; 
};

#endif 