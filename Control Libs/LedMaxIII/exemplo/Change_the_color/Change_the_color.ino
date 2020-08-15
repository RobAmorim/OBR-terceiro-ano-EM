

#include <Led.h> 



void setup() 
{
 Led.begin(); 
}

void loop()

{

  Led.blue(); 
  delay(1000); 
  Led.red(); 
  delay(1000); 
  Led.green(); 
  delay(1000); 
  Led.yellow();
  delay(1000); 
  
}
 
