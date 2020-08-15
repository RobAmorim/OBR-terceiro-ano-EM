
#include <ReadMaxII.h>

Read Read; 


void setup() {

  Serial.begin(9600);
}

void loop() {

 if(Read.verificationRamp() == true)
 {
  Serial.print("   Ramp:");
  Serial.println("  True");
 }
 else
 {
 if(Read.verificationRamp() == false)
 {
  Serial.print("  Ramp:");
  Serial.println("  False");
 }
  
 }

}
