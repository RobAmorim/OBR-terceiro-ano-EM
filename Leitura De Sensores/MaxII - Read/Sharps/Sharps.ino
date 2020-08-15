
#include <ReadSensorsMega.h>

Sharp Sharp; 



void setup() {

 Serial.begin(9600); 

}

void loop() {

       Serial.print("Front:");
       Serial.print(Sharp.front());

      Serial.print("RightUP:");
      Serial.print(Sharp.rightUp());

      Serial.print("RightDOWN:");
      Serial.print(Sharp.rightDown());

      Serial.print("RightTRI:");
      Serial.print(Sharp.rightTri());

      Serial.print("LeftUP:");
      Serial.print(Sharp.leftUp());

      Serial.print("LeftDOWN:");
      Serial.print(Sharp.leftDown());

       Serial.print("LeftTRI:");
       Serial.println(Sharp.leftTri());

      delay(500); 

}
