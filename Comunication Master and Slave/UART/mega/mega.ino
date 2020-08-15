#include <communication.h>
#include <uart/megaUART.h>
#include <digital/megaDIGITAL.h>

Trigger Trigger; 
Master Mega; 


void setup() {
  Serial.begin(115200);
  Trigger.begin(); 
  Mega.begin(); 
}
int received = 0; 

void loop() {
   Trigger.condition_1(); 
  delay(1);
  Serial.println(Mega.receive()); 

  Trigger.condition_2(); 
  delay(1);
  Serial.println(Mega.receive()); 

  Trigger.condition_3(); 
  delay(1);
  Serial.println(Mega.receive()); 

   Trigger.condition_4(); 
  delay(1);
  Serial.println(Mega.receive()); 

   Trigger.condition_5(); 
  delay(1);
  Serial.println(Mega.receive()); 

   Trigger.condition_6(); 
  delay(1);
  Serial.println(Mega.receive()); 

   Trigger.condition_7(); 
  delay(1);
  Serial.println(Mega.receive()); 

   Trigger.condition_8(); 
  delay(1);
  Serial.println(Mega.receive()); 

   Trigger.condition_9(); 
  delay(1);
  Serial.println(Mega.receive()); 

   Trigger.condition_10(); 
  delay(1);
  Serial.println(Mega.receive()); 

   Trigger.condition_11(); 
  delay(1);
  Serial.println(Mega.receive()); 

   Trigger.condition_12(); 
  delay(1);
  Serial.println(Mega.receive()); 

   Trigger.condition_13(); 
  delay(1);
  Serial.println(Mega.receive()); 

   Trigger.condition_14(); 
  delay(1);
  Serial.println(Mega.receive()); 

   Trigger.condition_15(); 
  delay(1);
  Serial.println(Mega.receive()); 

   Trigger.condition_16(); 
  delay(1);
  Serial.println(Mega.receive()); 

}
