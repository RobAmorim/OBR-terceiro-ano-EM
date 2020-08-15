// Include the required Wire library for I2C<br>#include

 #include <Wire.h> 
 
int x = 0;

long timeLine;
long finalTimeLine;
long realTime; 

void setup() {
  // Start the I2C Bus as Master
  Serial.begin(115200);
  Wire.begin(); 
  //pinMode(A0, INPUT); 
}
void loop() {

  timeLine = micros(); 
  
  //Wire.beginTransmission(9); // transmit to device #9  
   Wire.beginTransmission(9); // transmit to device #9 
  Wire.write(100);              // sends x 
   Wire.endTransmission();    // stop transmitting

  finalTimeLine = micros(); 
  realTime = timeLine - finalTimeLine; 
  Serial.print("Time Battery:"); 
  Serial.println(realTime); 
  
  //Wire.endTransmission();    // stop transmitting

}


