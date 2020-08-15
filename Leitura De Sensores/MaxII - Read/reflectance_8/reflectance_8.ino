

#include<ReadMaxII.h>

Read Read;

void setup() {

  Serial.begin(9600); 

}

void loop() 

{
    
      Serial.print("--(1):");
      Serial.print(Read.leftEx());

      Serial.print("--(2):");
      Serial.print(Read.leftCorner());

      Serial.print("--(3):");
      Serial.print(Read.leftLine());

      Serial.print("--(4):");
      Serial.print(Read.rightLine());

      Serial.print("--(5):");
      Serial.print(Read.rightCorner());

      Serial.print("--(6):");
      Serial.println(Read.rightEx());

      
      
}
