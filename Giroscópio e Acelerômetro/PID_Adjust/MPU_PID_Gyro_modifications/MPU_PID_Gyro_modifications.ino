
#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050_6Axis_MotionApps20.h>
#include <ControlMotorsMaxIII.h>
#include <LedMaxIII.h>

Motors Robot; 
Led Led; 

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
 gyro();
}

 Gyro_turnRight90(); 
 Gyro_turnLeft90(); 
 Gyro_turnRight90(); 
 Gyro_turnLeft90(); 
 Gyro_turnRight90(); 
 Gyro_turnLeft90(); 

}
