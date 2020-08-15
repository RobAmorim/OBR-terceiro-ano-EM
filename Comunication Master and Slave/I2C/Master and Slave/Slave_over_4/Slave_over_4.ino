

#include <Wire.h> 


int LED = 13;
int _x = 0;
void setup() {

  Serial.begin(9600); 
  
  // Define the LED pin as Output
  pinMode (LED, OUTPUT);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int x) {
  _x = Wire.read();    // read one character from the I2C
}
void loop() {
  //If value received is 0 blink LED for 200 ms

int   x = _x*4; 
  Serial.println(x); 

 delay(400);   
  
  /*if (x == 0) {
    digitalWrite(LED, LOW);
  }
  //If value received is 3 blink LED for 400 ms
  if (x == 1) {
    digitalWrite(LED, HIGH);
  }
  */
}
