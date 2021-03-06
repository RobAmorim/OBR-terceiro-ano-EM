#include <Wire.h>
#include <ControlMotorsRobot.h>

Motors Robot; 

const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
int GDegreesX, GDegreesY, GDegreesZ, DegreesY, ACDegreesX, ACDegreesY, ACDegreesZ;
const int minAC = -16800;
const int maxAC = 16800;
int TotalDegrees = 0;
void Degrees();
void AGRead();

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
  //delay(5000); 
  Serial.println("Ready");

  Wire.write(0);
}

void AGRead() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8 |Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  Degrees();
}

void Degrees() {

  GDegreesX = map(GyX, minAC, maxAC, -90, 90);
  GDegreesY = map(GyY, minAC, maxAC, -90, 90);
  GDegreesZ = map(GyZ, minAC, maxAC, -90, 90);

}

int Sara = 0; 
int speedRight = 0; 
int speedLeft = 0; 
int baseRight = 160; 
int baseLeft = 160; 
int P = 0; 
double _P = 0.1; 

void loop(){
  AGRead();
 

  /*
  //Serial.print(" | GyX = "); Serial.print(GyX);
  //Serial.print(" | GyY = "); Serial.print(GyY);

  P = _P * Sara; 

  speedLeft = baseLeft + P;   
  speedRight = baseRight - P;   
  

  Robot.forward(speedLeft, speedRight); 
  
  if(GDegreesY < -2)
  {
    Sara +=  GDegreesZ; 
  }

    if(GDegreesY > 2)
  {
    Sara +=  GDegreesZ; 
  }*/
  
  Serial.print(" | Z = "); Serial.println=(AcZ);  
  //Serial3.print("Speed Right:"); Serial3.print(speedRight);  
  //Serial3.print("Speed Left:"); Serial3.println(speedLeft);  
  
}
