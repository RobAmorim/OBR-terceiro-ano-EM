/*
      RoboCore - Tutorial Comunicacao entre Arduinos: SPI - (Master)
                                                        (30/05/2015)
*/

#include "SPI.h"

#define ssPin 53 // pino seletor do slave

#define pin0 5
#define pin1 6 
#define pin2 7

//low low low 
  
void setup() {

  
  SPI.begin();  // ingressa ao barramento SPI
  SPI.setClockDivider(SPI_CLOCK_DIV4); 
  pinMode(ssPin, OUTPUT);  // configura o pino seletor do slave como saida
  digitalWrite(ssPin, HIGH);  // coloca o pino seletor do slave em nivel alto

 
  pinMode(pin0, INPUT_PULLUP); 
  pinMode(pin1, INPUT_PULLUP); 
  pinMode(pin2, INPUT_PULLUP); 
  
 // delay(5000); 
}

void loop() {

         while((digitalRead(pin0) == 0)&&(digitalRead(pin1) == 0)&&(digitalRead(pin2) == 0))
         {
          
           digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(1); 
           digitalWrite(ssPin, HIGH);
           
         } 

         while((digitalRead(pin0) == 1)&&(digitalRead(pin1) == 0)&&(digitalRead(pin2) == 0))
         {
          
           digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(2); 
           digitalWrite(ssPin, HIGH);
           
         } 

           while((digitalRead(pin0) == 1)&&(digitalRead(pin1) == 1)&&(digitalRead(pin2) == 0))
         {
          
           digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(3); 
           digitalWrite(ssPin, HIGH);
           
         } 
         
          
           while((digitalRead(pin0) == 1)&&(digitalRead(pin1) == 1)&&(digitalRead(pin2) == 1))
         {
          
           digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(4); 
           digitalWrite(ssPin, HIGH);
           
         } 

          while((digitalRead(pin0) == 0)&&(digitalRead(pin1) == 1)&&(digitalRead(pin2) == 1))
         {
          
           digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(5); 
           digitalWrite(ssPin, HIGH);
           
         }

          while((digitalRead(pin0) == 0)&&(digitalRead(pin1) == 0)&&(digitalRead(pin2) == 1))
         {
          
           digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(6); 
           digitalWrite(ssPin, HIGH);
           
         } 

          while((digitalRead(pin0) == 0)&&(digitalRead(pin1) == 1)&&(digitalRead(pin2) == 0))
         {
          
           digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(7); 
           digitalWrite(ssPin, HIGH);
           
         } 

          while((digitalRead(pin0) == 1)&&(digitalRead(pin1) == 0)&&(digitalRead(pin2) == 1))
         {
          
           digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(8); 
           digitalWrite(ssPin, HIGH);
           
         } 
         
}

