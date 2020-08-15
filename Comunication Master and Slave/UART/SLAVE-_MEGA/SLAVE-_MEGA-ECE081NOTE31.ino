
#include "SoftwareSerial.h" // Inclui a biblioteca SoftwareSerial

// Cria uma serial em software 
#define Mega Serial3


void setup() {
  // inicia a serial em software com uma taxa de 9600 bit/s
 Mega_begin(115200); 
 Serial.begin(115200); 

}
int received; 
void loop() {

long time = micros(); 

    received = Mega_receive(); 
    
 long lastTime = micros(); 
  long Delta = lastTime - time; 

  Serial.print("Micro Value:");
  Serial.print(received); 
  Serial.print("\t");

  Serial.print("Time:");
  Serial.print(Delta); 
  Serial.println("\t");

  received = 0; 
  
   //Mega_send(100); 
}

