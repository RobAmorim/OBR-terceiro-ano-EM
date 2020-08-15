/*
      RoboCore - Tutorial Comunicacao entre Arduinos: SPI -(Slave)
                                                       (30/05/2015)
*/

#include "SPI.h"

#define bazzerPin 0 // numero do pino onde o botao esta conectado

char received_data; // armazena o dado recebidos
volatile boolean received_flag; // flag de recebimento de dado

void setup() {
  // inicia a SPI no modo escravo
  SPCR |= bit (SPE);
  
  // configura o pino MISO como saida
  pinMode(MISO, OUTPUT);
  
  // prepara o flag de recebimento para interrupcao
  received_flag = false;
  
  // liga as interrupcoes
  SPI.attachInterrupt();

  //pinMode(bazzerPin, OUTPUT);  // configura o pino do LED como saida

  Serial.begin(115200); 

  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  
}

long timeLine;
long finalTimeLine;
long realTime; 

void loop() {




   if (received_flag)
   
   {
    int data = received_data; 
    Serial.println(data);
     //Serial.println(data);    

     //Serial.println(data); 
   }


   }
  
 /* // se o flag de recebimento for verdadeiro:
  if (received_flag){
    // se o byte recebido for igual a 0, apaga o LED
    if (received_data == 0) {
      digitalWrite(bazzerPin, LOW);
    }

    // se o byte recebido for igual a 1 acende o LED
    if (received_data == 1) {
      digitalWrite(bazzerPin, HIGH);
    }

    // limpa o flag de recebimento
    received_flag = false;
  }
  */


// Rotina de interrupcao do SPI
ISR (SPI_STC_vect) {
  // le e salva o byte do Registrador de dados da SPI
  received_data = SPDR; 

  // seta o flag de recebimento para que o dado recebido 
  // seja processado no proximo loop
  received_flag = true;
}

