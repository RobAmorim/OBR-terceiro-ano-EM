
#include <communicationUART.h>
#include <boards/Master.h>


Master Mega;

void setup() {

  Serial.begin(115200); 

 Mega.begin(); 

}

int received = 0; 
void loop() {
/*
   Mega.send(105);
   Mega.send(105);
   received = Mega.receive(); 
   Serial.println(received);
*/
   if (Serial.available() > 0) {
    int inByte = Serial.read();
  
    switch (inByte) {
      case 'a':
        Mega.send(100);
        delay(1);
        Serial.println(Mega.receive());
        break;
      case 'b':
         Mega.send(101);
         delay(1);
        Serial.println(Mega.receive());
        break;
        case 'c':
         Mega.send(102);
         delay(1);
         Serial.println(Mega.receive());
        break;
   
    }
  }
  
}
