
#include "SoftwareSerial.h" // Inclui a biblioteca SoftwareSerial

// Cria uma serial em software 
#define Mega Serial2


void setup() {
  // inicia a serial em software com uma taxa de 9600 bit/s
 Mega_begin(9600); 
 Serial.begin(9600); 

}
int received; 
void loop() {

//long time = micros(); 

    received = Mega_receive(); 
    delay(10);
 /*   
 long lastTime = micros(); 
  long Delta = lastTime - time; 
*/
  Serial.print("Micro Value:");
  Serial.print(received); 
  Serial.println("\t");

 /*
  Serial.print("Time:");
  Serial.print(Delta); 
  Serial.println("\t");*/

  received = 0; 
  
   //Mega_send(100); 
}

