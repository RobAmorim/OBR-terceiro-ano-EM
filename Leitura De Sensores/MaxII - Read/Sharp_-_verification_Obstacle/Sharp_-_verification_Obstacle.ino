
#include <ReadMaxII.h>

Read Read; 


void setup() {

  Serial.begin(9600);

}

void loop() {

 if(Read.verificationObstacle() == true)
 {
  Serial.print("   Obstacle:");
  Serial.println("  True");
  
 }
 else
 {
 if(Read.verificationObstacle() == false)
 {
  Serial.print("  Obstacle:");
  Serial.println("  False");
 }
  
 }

}
