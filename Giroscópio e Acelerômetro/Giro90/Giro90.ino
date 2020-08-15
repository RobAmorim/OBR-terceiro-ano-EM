// Giroscópio & Acelerômetro
#include <Wire.h>
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
int GDegreesX, GDegreesY, GDegreesZ, DegreesY, ACDegreesX, ACDegreesY, ACDegreesZ;
const int minAC = -16800;
const int maxAC = 16800;
int TotalDegrees = 0;

#include <ControlMotorsEncoder.h>


void Degrees();
void AGRead();


//PINO DO DE SENSOR_PROXIMIDADE CENTRAL 
#define SharpDireito A0
#define SharpEsquerdo A1

 
 int D_Sharp_Esq = 0; 
 int D_Sharp_Dir =0;

 //ROBOT INSTANCE
  
  Motors Robot;


// QTRPololu
/*#include <QTRSensors.h>
#define numSensores 5
QTRSensorsAnalog QTRSensor ((unsigned char[]) {8, 9, 10, 11, 12}, numSensores, 4, QTR_NO_EMITTER_PIN);
unsigned int QTRValues[numSensores];



//Configurações Shield Motor
#include <AFMotor.h>
AF_DCMotor motorDir(1);
AF_DCMotor motorEsq(4);

// CONFIGURAÇÕES SHARPS
#include <SharpIR.h>
#define irD A14
#define irE A15
#define model 1080
SharpIR sharpDirSensor(irD, 25, 93, model);
SharpIR sharpEsqSensor(irE, 25, 93, model);
unsigned int sharpDirValue = 0;
unsigned int sharpEsqValue = 0;

// Ultrassônico
#include <Ultrasonic.h>
int trigger = 34;
int echo = 35;
Ultrasonic ultrasonicSensor(trigger, echo);
unsigned int ultrasonicValue = 51;

// Constantes do algotimo de controle (PID)
#define kP 1        // Controle progressivo
#define kD 0        // Controle Diferencial
#define kI 0        // Controle Integrativo

float PID[2];
int erro[2];        // PID - erro atual do robo
int U;              // Variavel de controle pro PID
*/
void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
  Serial.println("Ready");
  
 // motorDir.setSpeed(200); 
 // motorEsq.setSpeed(220); 



  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);

  
  Robot.velocidade(250, 250);
}
/*
void direita(int tempo = 0) {
  motorEsq.run(FORWARD);
  motorDir.run(BACKWARD);
  delay(tempo);
}

void esquerda(int tempo = 0) {
  motorEsq.run(BACKWARD);
  motorDir.run(FORWARD);
  delay(tempo);
}

void ahead(int tempo = 0) {
  motorEsq.run(FORWARD);
  motorDir.run(FORWARD);
  delay(tempo);
}

void back(int tempo = 0) {
  motorEsq.run(BACKWARD);
  motorDir.run(BACKWARD);
  delay(tempo);
}

void parar(int tempo = 0) {
  motorEsq.run(RELEASE);
  motorDir.run(RELEASE);
  delay(tempo);
}

void pid() {
  // Calculo da Proporcional
  for(int i = 0; i < 2; i++) {
    PID[i] = map(QTRValues[i+1]*kP, 40, 900, 210, 255);
  }
}
*/
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
  ACDegreesX = map(AcX, minAC, maxAC, -90, 90);
  ACDegreesY = map(AcY, minAC, maxAC, -90 , 90);
  ACDegreesZ = map(AcZ, minAC, maxAC, -90 , 90);
  GDegreesX = map(GyX, minAC, maxAC, -90, 90);
  GDegreesY = map(GyY, minAC, maxAC, -90, 90);
  GDegreesZ = map(GyZ, minAC, maxAC, -90, 90);
}
/*
void LeituraUltrasonic() {
  ultrasonicValue = ultrasonicSensor.Ranging(CM);
}

void LeituraSharps() {
  sharpEsqValue = sharpEsqSensor.distance();
  sharpDirValue = sharpDirSensor.distance();
}


*/

  
  void leituraSharp() 
  
  {
     
    D_Sharp_Dir = analogRead(SharpDireito);
    D_Sharp_Esq = analogRead (SharpEsquerdo);
    
    
    
    }

void loop() {
  //LeituraUltrasonic();
  //LeituraSharps();

  leituraSharp();
  
  if(D_Sharp_Dir > 500) {
    while(TotalDegrees > -13650*2) {  // -12020*2
      AGRead();
      TotalDegrees += GDegreesZ;
       Robot.direita();

     
    }
    digitalWrite(50, HIGH);
    digitalWrite(51, LOW);
    
    TotalDegrees = 0;
  }
  
  else if (D_Sharp_Esq > 500) {
    while(TotalDegrees < 11050*2) {  //11920*2
      AGRead();
      TotalDegrees += GDegreesZ;    // 
      Robot.esquerda();

    }
digitalWrite(51, HIGH);
 digitalWrite(50, LOW);
    TotalDegrees = 0;
  }

    Robot.parar();
}
