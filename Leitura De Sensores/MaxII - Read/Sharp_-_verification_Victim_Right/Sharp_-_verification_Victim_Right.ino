
#include <ReadSensorsMega.h>

Sharp Sharp; 


void setup() {

  Serial.begin(9600); 

}

void loop() {

 if(Sharp.verificationVictimRight() == true)
 {
  Serial.print("  Victim Right:");
  Serial.print("  True");
  Serial.print("  Diference Victim Right:");
  Serial.print(Sharp.diferenceVictimRight());
  Serial.print( "Right Down:");
  Serial.print(Sharp.rightDown());
  Serial.print("  Right Up:");
  Serial.println(Sharp.rightUp());
 }
 else
 {
 if(Sharp.verificationVictimRight() == false)
 {
  Serial.print("   Victim Right:");
  Serial.print("  False");
  Serial.print("  Diference Victim Right:");
  Serial.print(Sharp.diferenceVictimRight());
    Serial.print( "Right Down:");
  Serial.print(Sharp.rightDown());
  Serial.print("  Right Up:");
  Serial.println(Sharp.rightUp());
 }
  
 }
delay(500);
}
