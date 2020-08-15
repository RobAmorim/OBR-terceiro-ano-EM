
#include <ReadSensorsMega.h>

Sharp Sharp; 


void setup() {
  // put your setup code here, to run once:

}

void loop() {

 if(Sharp.verificationLeftTri() == true)
 {
  Serial.print("   Left Tri:");
  Serial.println("  True");
 }
 else
 {
 if(Sharp.verificationLeftTri() == false)
 {
  Serial.print("  Left Tri:");
  Serial.println("  False");
 }
  
 }

}
