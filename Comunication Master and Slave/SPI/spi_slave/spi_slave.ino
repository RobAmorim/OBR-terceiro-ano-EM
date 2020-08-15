/*
      RoboCore - Tutorial Comunicacao entre Arduinos: SPI -(Slave)
                                                       (30/05/2015)
*/

 // MEGA MEGA MEGA MEGA 
 
#include "SPI.h"

#define pin0 5 // numero do pino onde o botao esta conectado
#define pin1 6 // numero do pino onde o botao esta conectado
#define pin2 7 // numero do pino onde o botao esta conectado

char received_data; // armazena o dado recebidos
volatile boolean received_flag; // flag de recebimento de dado

void setup() {
  
  pinMode(pin0, OUTPUT); 
  pinMode(pin1, OUTPUT); 
  pinMode(pin2, OUTPUT); 

    // inicia a SPI no modo escravo
  SPCR |= bit (SPE);
  
  // configura o pino MISO como saida
  pinMode(MISO, OUTPUT);
  
  // prepara o flag de recebimento para interrupcao
  received_flag = false;
  
  // liga as interrupcoes
  SPI.attachInterrupt();

//  pinMode(bazzerPin, OUTPUT);  // configura o pino do LED como saida

  Serial.begin(115200); 
}


void loop() {


 digitalWrite(pin0, LOW);  //1
 digitalWrite(pin1, LOW);
 digitalWrite(pin2, LOW);

  if (received_flag)
   
   {
      int data = received_data; 
     Serial.println(data);    
   }
   
 //delay(1000);
 

  digitalWrite(pin0, HIGH);  //2
 digitalWrite(pin1, LOW);
 digitalWrite(pin2, LOW);

  if (received_flag)
   
   {
      int data = received_data; 
     Serial.println(data);    
   }
   
 //delay(1000);
 
  digitalWrite(pin0, HIGH);  //3
 digitalWrite(pin1, HIGH);
 digitalWrite(pin2, LOW);
  if (received_flag)
   
   {
      int data = received_data; 
     Serial.println(data);    
   }
   
  //delay(1000);

  digitalWrite(pin0, HIGH);  //4
 digitalWrite(pin1, HIGH);
 digitalWrite(pin2, HIGH);

  if (received_flag)
   
   {
      int data = received_data; 
     Serial.println(data);    
   }

     digitalWrite(pin0, LOW);  //5
 digitalWrite(pin1, HIGH);
 digitalWrite(pin2, HIGH);

  if (received_flag)
   
   {
      int data = received_data; 
     Serial.println(data);    
   }

     digitalWrite(pin0, LOW);  //6
 digitalWrite(pin1, LOW);
 digitalWrite(pin2, HIGH);

  if (received_flag)
   
   {
      int data = received_data; 
     Serial.println(data);    
   }

     digitalWrite(pin0, LOW);  //7
 digitalWrite(pin1, HIGH);
 digitalWrite(pin2, LOW);

  if (received_flag)
   
   {
      int data = received_data; 
     Serial.println(data);    
   }

     digitalWrite(pin0, HIGH);  //8
 digitalWrite(pin1, LOW);
 digitalWrite(pin2, HIGH);

  if (received_flag)
   
   {
      int data = received_data; 
     Serial.println(data);    
   }
   
 //delay(1000);
 
 
   
   
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

