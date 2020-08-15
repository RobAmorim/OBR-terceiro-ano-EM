#include <LinkedList.h>
#include <Gaussian.h>
#include <GaussianAverage.h>


GaussianAverage myMovingAverage(4); //Minha média móvel

#define sensorSharp A15// Porta analógia do sensor


int valorSharp = 0;  // Variável que guardará o valor lido pela porta



void setup() {

  Serial.begin(9600); // Comunicação Serial
  pinMode(sensorSharp, INPUT);
}

void loop() {

 valorSharp = analogRead(sensorSharp); //Valor da variável é igual ao valor lido pela porta analógica

 
 myMovingAverage += valorSharp;

 myMovingAverage.process();

 // Serial.print("Distancia Normal:"); // Printa distância
 // Serial.print(valorSharp); // Printa em frente de distância o valor lido pelo sensor 
 //==========================================================================================

  Serial.print("         Distancia Filtrada: "); // Printa distância
 Serial.println(myMovingAverage.mean); // Printa em frente de distância o valor lido pelo sensor 

 delay(500); // Espera para começar a leitura novamente
}
