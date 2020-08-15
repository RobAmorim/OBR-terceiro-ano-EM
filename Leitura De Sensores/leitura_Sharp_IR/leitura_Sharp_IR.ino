
// CONFIGURAÇÕES SHARPS
#include <SharpIR.h>
#define ir A4
#define model 1080
SharpIR sharpSensor(ir, 25, 93, model);
unsigned int sharpValue = 0;


void LeituraSharps();

void setup() {
 Serial.begin(9600);

}

void loop() {

LeituraSharps(); 

Serial.print("Distância:");
Serial.print(sharpValue);
Serial.print("Valeu crude:");
Serial.println(analogRead(ir));



}

void LeituraSharps() {
  sharpValue = sharpSensor.distance();
  
}
