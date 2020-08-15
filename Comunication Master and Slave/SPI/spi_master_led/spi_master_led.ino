/*
      RoboCore - Tutorial Comunicacao entre Arduinos: SPI - (Master)
                                                        (30/05/2015)
*/

#include "SPI.h"
#include <Read.h>

Read Read; 

#define ssPin 53 // pino seletor do slave
#define pin 0 

int cutoffValue = 150; //Cuttoff value of reflective sensor 

int _leftLine = 0;
int _rightLine = 0; 
int _leftCorner = 0;
int _rightCorner = 0;
int _leftEx = 0;
int _rightEx = 0;
int _rightSuper = 0;
int _leftSuper = 0;

void readReflectance();
void line(); 

void setup() {
  
  SPI.begin();  // ingressa ao barramento SPI
  SPI.setClockDivider(SPI_CLOCK_DIV4); 
  pinMode(ssPin, OUTPUT);  // configura o pino seletor do slave como saida
  pinMode(ssPin, OUTPUT);  // configura o pino seletor do slave como saida
  digitalWrite(ssPin, HIGH);  // coloca o pino seletor do slave em nivel alto

  Serial.begin(115200); 
  
  delay(5000); 
}

void loop() {

           digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer16(100); 
           digitalWrite(ssPin, HIGH);
}

