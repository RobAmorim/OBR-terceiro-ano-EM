#include <Encoder.h>


Encoder MotorDir(19, 17);     //Pinagem do interrupitor do MotoDir    
Encoder MotorEsq(18, 16);   //Pinagem do interrupitor do MotoDir 


long Pulsos_Dir = 0;
long Pulsos_Esq = 0; 

void setup()

{
  Serial.begin(9600);
  
}

void loop()

{

Pulsos_Dir = MotorDir.read();
Pulsos_Esq = MotorEsq.read(); 

Serial.print("Dir:");
Serial.print(Pulsos_Dir);

Serial.print("Esq:");
Serial.println(Pulsos_Esq);

delay(100); 

}
