#include <Thread.h>
#include <ArduinoSensors.h>
#include <sensors/PingUltrasonic.h>

/*
	Echo and Trigger pins must be the same
	to your connections on the arduino
*/
int F_echoPin 	= 24;
int F_triggerPin 	= 25;

int D_echoPin   = 26;
int D_triggerPin  = 27;

int E_echoPin   = 28;
int E_triggerPin  = 29;

PingUltrasonic F_myUltrasonic(F_triggerPin, F_echoPin);
PingUltrasonic D_myUltrasonic(D_triggerPin, D_echoPin);
PingUltrasonic E_myUltrasonic(E_triggerPin, E_echoPin);

void setup() {
	Serial.begin(9600);

 //pinMode(F_echoPin, OUTPUT);
// pinMode(F_triggerPin, INPUT);
 
	
}

void loop()
{
	float distanceFrente = F_myUltrasonic.readDistance();
  float distanceDireita = D_myUltrasonic.readDistance();
  float distanceEsquerda = E_myUltrasonic.readDistance();

	Serial.print("Distance Frente: ");  
	Serial.print(distanceFrente);  
	Serial.print("cm");

 Serial.print("Distance Direita: ");  
 Serial.print(distanceDireita);   
 Serial.print("cm");

  Serial.print("Distance Esquerda: ");  
  Serial.print(distanceEsquerda);  
  Serial.println("cm");

	delay(300);

 

 delay(300);
}



/*void leituraSharp()
{
  
  for( i = 0; i <= 3; i++)
  
  {
    
  ultra = myUltrasonic.readDistance();
  
  Sharp_Media += Sharp;

  Sharp_Media.process();

   Sharp_Media.mean = Distancia;
   
  }
 */
