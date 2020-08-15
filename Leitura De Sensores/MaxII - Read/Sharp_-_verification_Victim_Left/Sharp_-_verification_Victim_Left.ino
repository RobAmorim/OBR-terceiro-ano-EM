
#include <ReadSensorsMega.h>

Sharp Sharp; 


void setup() {

  Serial.begin(9600); 

}

void loop() {

 if(Sharp.verificationVictimLeft() == true)
 {
  Serial.print("  Victim Left:");
  Serial.print("  True");
  Serial.print("  Diference Victim Left:");
  Serial.print(Sharp.diferenceVictimLeft());
  Serial.print( "Left Down:");
  Serial.print(Sharp.leftDown());
  Serial.print("  Left Up:");
  Serial.println(Sharp.leftUp());
 }
 else
 {
 if(Sharp.verificationVictimLeft() == false)
 {
  Serial.print("   Victim Left:");
  Serial.print("  False");
  Serial.print("  Diference Victim Left:");
  Serial.print(Sharp.diferenceVictimLeft());
    Serial.print( "Left Down:");
  Serial.print(Sharp.leftDown());
  Serial.print("  Left Up:");
  Serial.println(Sharp.leftUp());
  
 }
}
delay(500);
}
