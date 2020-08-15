// Include the required Wire library for I2C<br>#include

 #include <Wire.h> 
 
int x = 0;

void setup() {
  // Start the I2C Bus as Master
  Serial.begin(9600);
  Wire.begin(); 
  pinMode(A0, INPUT); 
}
void loop() {
  Wire.beginTransmission(9); // transmit to device #9

  int _x = analogRead(A0)/4; 
  
  Wire.write(_x);              // sends x 
  Wire.endTransmission();    // stop transmitting
 // x++; // Increment x
  //if (x > 5) x = 0; // `reset x once it gets 6
  Serial.println(analogRead(A0)); 
  
  delay(500);
}


