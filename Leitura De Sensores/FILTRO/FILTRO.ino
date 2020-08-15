#include <LinkedList.h>
#include <Gaussian.h>
#include <GaussianAverage.h>

#define SENSOR A8

GaussianAverage myMovingAverage(10); //Minha média móvel

void setup() {


  pinMode(SENSOR, INPUT);
  Serial.begin(9600);
  

}

void loop() {


 int value = analogRead(SENSOR);

 myMovingAverage += value;

  myMovingAverage.process();

 Serial.print("Valor normal"); // valor PRIMÁRIO do sensor
 Serial.print(value);
 
Serial.print('/t'); //ESPAÇO

Serial.print(" Valor filtrado"); // Valor FILTRADO do sensor
Serial.println(myMovingAverage.mean);

delay(200);

}
