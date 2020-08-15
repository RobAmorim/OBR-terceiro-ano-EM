
#include "SoftwareSerial.h" // Inclui a biblioteca SoftwareSerial

// Cria uma serial em software 
#define Mega Serial3


void setup() {
  // inicia a serial em software com uma taxa de 9600 bit/s

 pinMode(7, OUTPUT);
 Mega_begin(115200); 
 Serial.begin(115200); 

}
int received; 
void loop() {


    digitalWrite(7, HIGH); // 1 --> Micro --> send  
    //delay(1);
    
    received = Mega_receive(); 
    
    Serial.print("Micro Value:");
    Serial.print(received); 
    Serial.println("\t");


    digitalWrite(7, LOW); // 0 --> Micro --> to receive 
    //delay(1);
    
    Mega_send(100); 
}

