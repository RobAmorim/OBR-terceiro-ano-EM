

#include <ReadMaxII.h>

Read Read; 


void setup() {

  Serial.begin(9600);
  Read.colorBegin(); 

}

void loop() {

  Serial.print("Read Right:");
  Serial.print(Read.colorRight()); 

  Serial.print("Read Left:");
  Serial.println(Read.colorLeft()); 
  

}
