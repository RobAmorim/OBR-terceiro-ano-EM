
#include <ReadSensorsMega.h>

Sharp Sharp; 


void setup() {
  // put your setup code here, to run once:

}

void loop() {

 if(Sharp.verificationRightTri() == true)
 {
  Serial.print("   Right Tri:");
  Serial.println("  True");
 }
 else
 {
 if(Sharp.verificationRightTri() == false)
 {
  Serial.print("  Right Tri:");
  Serial.println("  False");
 }
  
 }

}
