
#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050_6Axis_MotionApps20.h>
#include <ControlMotorsMaxII.h>
#include <LedMaxII.h>
#include <ReadMaxII.h>

Motors Robot; 
Led Led; 
Servos Servos; 
Read Read;

//===============================================================================  
                      //SETTING REFLECTANCE SENSOR 
                      
int cutoffValue = 120; //Cuttoff value of reflective sensor 

int _leftLine = 0;
int _rightLine = 0; 
int _leftCorner = 0;
int _rightCorner = 0;
int _leftEx = 0;
int _rightEx = 0;
int _rightSuper = 0;
int _leftSuper = 0;
//====================================================================================================
                                       // MPU SETTING  
//====================================================================================================
MPU6050 mpu;
#define INTERRUPT_IMU       2

// IMU state variables
bool newImuData;
float ypr[3];
Quaternion q;
VectorFloat gravity;

float getYPR(int n) {
  return (ypr[n] * (180.0 / M_PI)) + 180;
}

// Global flag that must be set to `true` when interrupt occurs
bool imuInterrupted = false;

void onIMURead() {
  imuInterrupted = true;
}

bool IMU_init() {
  bool devStatus;

  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed");
    return false;
  }

  mpu.setDMPEnabled(false);
  mpu.resetDMP();
  // Reset IMU
  mpu.reset();
  delay(50);

  // Activate MPU6050
  mpu.setSleepEnabled(false);

  // load and configure the DMP
  devStatus = mpu.dmpInitialize();

  // supply your own gyro offsets here, scaled for min sensitivity
  mpu.setXGyroOffset(83);
  mpu.setYGyroOffset(-3);
  mpu.setZGyroOffset(48);
  mpu.setZAccelOffset(1974); // 1688 factory default for my test chip

  // make sure it worked (returns 0 if so)
  if (devStatus != 0) {
    // ERROR!
    // 1 = initial memory load failed
    // 2 = DMP configuration updates failed
    // (if it's going to break, usually the code will be 1)
    Serial.print("DMP Initialization failed (code ");
    Serial.print(devStatus);
    Serial.println(")");
  }

  // Enable Digital Motion Procesing
  mpu.setDMPEnabled(true);

  return true;
}

int took;
int outOfSyncs;
int interruptStatus;
uint8_t packet[64];
bool IMU_read() {
  static int fifoCount = 0;

  // Check for interrupt
  if (!imuInterrupted && fifoCount < 42)
    return false;

  // Clear interrupt flag
  imuInterrupted = false;

  // Check for new Packet
  delayMicroseconds(500);
  interruptStatus = mpu.getIntStatus();
  delayMicroseconds(50);
  fifoCount = mpu.getFIFOCount();

  if ((interruptStatus & 0x10) || fifoCount == 1024 || fifoCount % 42 > 0) {
    // reset so we can continue cleanly
    delayMicroseconds(50);
    mpu.resetFIFO();
    delayMicroseconds(50);
    fifoCount = 0;
    return false;
  }

  // Check if new data available
  bool run = (interruptStatus & 0x02);

  // Don't read if not ready
  if (!run)
    return false;

  unsigned long start = millis();

  // read a packet from FIFO
  delayMicroseconds(50);
  mpu.getFIFOBytes(packet, 42);
  fifoCount -= 42;

  // Convert and save state to Object
  mpu.dmpGetQuaternion(&q, packet);
  mpu.dmpGetGravity(&gravity, &q);
  mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

  newImuData = true;

  took = millis() - start;
}


void mover(int a, int b) {
  if (a > 0) {
    //a=a*2.55;
    //a=a+compensacao;
    //analogWrite(MotorEsquerdoFrente, a);
    //analogWrite(MotorEsquerdoTras, 0);
  }
  else if (a == 0) {
  //  analogWrite(MotorEsquerdoFrente, 0);
  //  analogWrite(MotorEsquerdoTras, 0);
  }
  else {

    //a=a*-2.55;
    //analogWrite(MotorEsquerdoFrente, 0);
    //analogWrite(MotorEsquerdoTras, abs(a));
  }
  if (b > 0) {
    // b=b*2.55;
   // analogWrite(MotorDireitoFrente, b);
   // analogWrite(MotorDireitoTras, 0);
  }
  else if (b == 0) {
   // analogWrite(MotorDireitoFrente, 0);
   // analogWrite(MotorDireitoTras, 0);
  }
  else {
    //b=b*-2.55;
    //analogWrite(MotorDireitoFrente, 0);
    //analogWrite(MotorDireitoTras, abs(b));
  }
};
int count = 0;
float gyroInicial = 0;
class PID {
  public:

    double error;
    double sample;
    double lastSample;
    double kP, kI, kD;
    double P, I, D;
    double pid;

    double setPoint;
    long lastProcess;

    PID(double _kP, double _kI, double _kD) {
      kP = _kP;
      kI = _kI;
      kD = _kD;
    }

    void addNewSample(double _sample) {
      sample = _sample;
    }

    void setSetPoint(double _setPoint) {
      setPoint = _setPoint;
    }


    double process() {
      // Implementação P ID
      error = setPoint - sample;
      float deltaTime = (millis() - lastProcess) / 1000.0;
      lastProcess = millis();

      //P
      P = error * kP;

      //I
      I = I + (error * kI) * deltaTime;

      //D
      D = (lastSample - sample) * kD / deltaTime;
      lastSample = sample;

      // Soma tudo
      pid = P + I + D;

      return pid;
    }
};


PID meuPid(1.5, 0.0, 0.0);

double motorB; double motorC;
double output = 0;

//====================================================================================================
                                        //VOID SETUP
//====================================================================================================

void setup() {

  Servos.begin(); 
  Led.begin();

  Serial.begin(115200);
  // put your setup code here, to run once:
  Wire.begin();
  TWBR = ((16000000L / 400000L) - 16) / 2;
  delay(1);
 // ligarMotores();
  IMU_init();


  // Link IMU Interrupt to method
  attachInterrupt(INTERRUPT_IMU, onIMURead, RISING);
}

//====================================================================================================
                                        //VOID LOOP
//====================================================================================================

float realTime; 
float time; 
int CorrectSpeedRight;
int CorrectSpeedLeft;
int CorrectSpeed;
int speedBase = 120;

void loop() {
  delay(100);
  

time = millis() + 20000; 

while(millis() < time)
{
  IMU_read();
  Serial.print("first\t");
  Serial.print(getYPR(0));
  Serial.print("\t");
  Serial.print(ypr[1] * 180 / M_PI);
  Serial.print("\t");
  Serial.println(ypr[2] * 180 / M_PI);
}
  gyroInicial = getYPR(0);

  meuPid.setSetPoint(gyroInicial);
  
  Serial.print("Angulo Final: ");
  Serial.print(gyroInicial);
  // Manda pro objeto PID!
  delay(2000);
  // Converte para controle

  time = millis() + 1000000; 
int ii = 0; 
while(millis() < time)
{   
   delayMicroseconds(800); 
    IMU_read();
    float valueY = ypr[1] * 180 / M_PI;
    
   if(valueY < -8)
   { 
    ii = ii + 1; 
    if(ii == 1)

    {
    Servos.clawDownRamp();
   // Robot.stop(1000);  
    } 
    
    while(valueY < -8)
    {
      delayMicroseconds(800); 
    IMU_read();
    Led.red();
    Robot.speed(200, 200);
    Robot.forward();
    valueY = ypr[1] * 180 / M_PI;
    Serial.println(valueY);
    if(valueY == 0.00)
    {
      valueY = -9; 
    }

     if(valueY > -8)
    {
      valueY = ypr[1] * 180 / M_PI;
       if(valueY > -8)
    {
       valueY = ypr[1] * 180 / M_PI;
       if(valueY > -8)
    {
       valueY = ypr[1] * 180 / M_PI;
       if(valueY > -8)
    {
       valueY = ypr[1] * 180 / M_PI;
      
    }
    }
      
    }

      
    }
    
    }
    
   }
   else
   {
   if(valueY  > 12)
   {
       // Robot.stop(500);
       // Servos.begin();
        //Robot.stop(500); 
    
     while(valueY  > 12)
    {
      delayMicroseconds(800); 
    IMU_read();
    Led.green();
    Robot.speed(100, 100);
    Robot.forward();
    delay(100);
    Robot.backward(100, 100, 100);
    valueY = ypr[1] * 180 / M_PI;
    Serial.println(valueY);
     if(valueY == 0.00)
    {
      valueY = 13; 
    }
    }
   }
   else
   {
    if((valueY  < 12)&&(valueY  > -8))
    {
        Robot.stop(500);
        Servos.begin();
        Robot.stop(500); 
        
      while((valueY  < 12)&&(valueY  > -8))
      {
        Led.blue(); 
        delayMicroseconds(800); 
         IMU_read();
         Robot.speed(130, 150);
         Robot.forward();
         valueY = ypr[1] * 180 / M_PI;
         Serial.println(ypr[1] * 180 / M_PI);
      }
   }
   }
     //delayMicroseconds(800); 
     //IMU_read();
  }
}

  /*
  while(true) 
  {
    IMU_read();
    meuPid.addNewSample(getYPR(0));
    output = meuPid.process();

    //if process (-) --> turn Left
    //if process (+) --> turnRight 
    //if process (0) --> forward 
    
    CorrectSpeedRight = speedBase - output; 
    CorrectSpeedLeft = speedBase + output; 
/*
    if(output < 0)
    {
      Robot.speed(140, 140);
      Robot.right();
    }
    if(output > 0)
    {
      Robot.speed(140, 140);
      Robot.left();
    }
    

    if(CorrectSpeedRight >= 255)
    CorrectSpeedRight = 255;

    if(CorrectSpeedRight <= 100)
    CorrectSpeedRight = 100; 

    if(CorrectSpeedLeft >= 255)
    CorrectSpeedLeft = 255;
    
    if(CorrectSpeedLeft <= 100)
    CorrectSpeedLeft = 100;
    
   // Robot.speed(CorrectSpeedLeft, CorrectSpeedRight);
   // Robot.forward(); 
    
    Serial.print("Angle:\t");
    Serial.print(getYPR(0));
    Serial.print("output:\t");
    Serial.println(output);
  
 }*/
}
