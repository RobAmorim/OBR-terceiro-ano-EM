
#include <communicationUART.h>
#include <boards/Slave.h>


Slave Micro;

void setup() {

 Micro.begin(); 

}

int received = 0; 

void loop() {

  received = Micro.receive(); 
  Serial.println(received);

  if(received == 100)
  {
  Micro.send(50); 

  }

   if(received == 101)
  {
  Micro.send(51); 

  
  }

   if(received == 102)
  {
  Micro.send(52); 
  }
  

  




}
