
//ESTRUTURAS - LED.h /




#ifndef LedMaxII_H
#define LedMaxII_H 


#include "Arduino.h"


//SETTING LED RGB

#define LedBlue 50 // Pin -> Connections of LED'S 
#define LedGreen 48
#define LedRed 52

#define R_LedBlue 49 // Pin -> Connections of LED'S 
#define R_LedGreen 51
#define R_LedRed 53


class Led {

    public:

   Led(); 
   void begin(); 
   void blue(); 
   void red(); 
   void green();
   void yellow();
   void purple(); 


private: 



};


#endif 