
#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050_6Axis_MotionApps20.h>
#include <ControlMotorsRobot.h>

Motors Robot;

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

int forca_Curva = 120; // forca da curva no obstaculo
int forca = 110;
#define ESQUERDA -1
#define DIREITA   1
#define ST_PRINCIPAL 2
#define ST_RAMPA     4
#define CIMA 1
#define BAIXO 0
#define IDDLE   0
#define OBS 1
#define LIN   0
#define angulo_rampa_subida -21
#define angulo_rampa_descida 20


#define angulo_curva_direita 78
#define angulo_curva_esquerda 78
#define angulo_curva_direita_obs 70
#define angulo_curva_esquerda_obs 76

unsigned long lastRun = 0;

// Motor ESQUERDO DIANETEIRO
#define MotorEsquerdoFrente 6
#define MotorEsquerdoTras 5

// Motor DIREITO DIANTEIRO
#define MotorDireitoFrente 3
#define MotorDireitoTras 4



void ligarMotores() {
  // MOTOR ESQUERDO DIANTEIRO
  pinMode(MotorEsquerdoFrente, OUTPUT);
  pinMode(MotorEsquerdoTras, OUTPUT);


  // MOTOR DIREITO DIANTEIRO
  pinMode(MotorDireitoFrente, OUTPUT);
  pinMode(MotorDireitoTras, OUTPUT);

}
/*
   Stop all motors
*/
void pararMotores() {
  analogWrite(MotorEsquerdoFrente, 0);
  analogWrite(MotorEsquerdoTras, 0);

  /*** direita ***/
  analogWrite(MotorDireitoFrente, 0);
  analogWrite(MotorDireitoTras, 0);
}


/*
  Engine control
  left-to-right engine power, respectively
*/
void mover(int a, int b) {
  if (a > 0) {
    //a=a*2.55;
    //a=a+compensacao;
    analogWrite(MotorEsquerdoFrente, a);
    analogWrite(MotorEsquerdoTras, 0);
  }
  else if (a == 0) {
    analogWrite(MotorEsquerdoFrente, 0);
    analogWrite(MotorEsquerdoTras, 0);
  }
  else {

    //a=a*-2.55;
    analogWrite(MotorEsquerdoFrente, 0);
    analogWrite(MotorEsquerdoTras, abs(a));
  }
  if (b > 0) {
    // b=b*2.55;
    analogWrite(MotorDireitoFrente, b);
    analogWrite(MotorDireitoTras, 0);
  }
  else if (b == 0) {
    analogWrite(MotorDireitoFrente, 0);
    analogWrite(MotorDireitoTras, 0);
  }
  else {
    //b=b*-2.55;
    analogWrite(MotorDireitoFrente, 0);
    analogWrite(MotorDireitoTras, abs(b));
  }
};
void Curva90Graus(int lado, int tipo) {
  IMU_init();

  // robo anda para frente antes de fazer a curva
  if (lado == ESQUERDA && tipo == LIN) {

    pararMotores();
    delay(250);
    mover(forca, forca);
    delay(270);
    pararMotores();

  } else if (lado == DIREITA && tipo == LIN) {

    pararMotores();
    delay(250);
    mover(forca, forca);
    delay(270);
    pararMotores();
  }

  // inicializa a mpu

  // faz a curva dependendo do lado passado no parametro
  if (lado == ESQUERDA) {

    //    LED4.turnOn();

    // Gira até o angulo do giroscopio for maior que o solicitado
    if (tipo == OBS) {
      while (getYPR(0) >= angulo_curva_esquerda_obs * -1) {
        IMU_read();
        Serial.print(getYPR(0));
        mover(forca_Curva * -1, forca_Curva);
      }
    }
    if (tipo == LIN) {
      while (getYPR(0) >= angulo_curva_esquerda * -1) {
        IMU_read();
        mover(forca_Curva * -1, forca_Curva);
      }
    }

    //LED4.turnOff();

    if (tipo == LIN) {
      // andada para tras depois de fazer a curva
      pararMotores();
      mover(forca * -1, forca * -1);
      delay(100);
      pararMotores();
    }

  }
  else if (lado == DIREITA) {

    // LED4.turnOn();

    // Gira pra direita ate o angular for menor que o solicitado
    if (tipo == OBS) {
      while (getYPR(0) <= angulo_curva_direita_obs) {
        IMU_read();
        mover(forca_Curva, forca_Curva * -1);
      }
    }
    if (tipo == LIN) {
      while (getYPR(0) <= angulo_curva_direita) {
        IMU_read();
        mover(forca_Curva, forca_Curva * -1);
      }
    }

    // LED4.turnOff();

    if (tipo == LIN) {
      // andada para tras depois de fazer a curva
      pararMotores();
      mover(forca * -1, forca * -1);
      delay(100);
      pararMotores();
    }
  }

  pararMotores();


}

void setup() {

  Serial.begin(115200);
  // put your setup code here, to run once:
  Wire.begin();
  TWBR = ((16000000L / 400000L) - 16) / 2;
  delay(1);
  ligarMotores();
  IMU_init();


  // Link IMU Interrupt to method
  attachInterrupt(INTERRUPT_IMU, onIMURead, RISING);

    delay(100);
  IMU_read();

 float realTime = millis() + 20000;
while(millis() < realTime)
{
   IMU_read();
   
  Serial.print("first\t");
  Serial.print(getYPR(0));
  Serial.print("\t");
  Serial.print(ypr[1] * 180 / M_PI);
  Serial.print("\t");
  Serial.println(ypr[2] * 180 / M_PI);
}

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


PID meuPid(25.0, 0, 8.0);

double motorB; double motorC;
double tP = 0;
double output = 0;

void loop() {

   IMU_read();



   int realAngle = getYPR(0); 
   int angle = getYPR(0) + 75; 

   while(getYPR(0) < angle)
   {
    Serial.println(getYPR(0));
    IMU_read();
    Robot.speed(200, 200); 
    Robot.right(); 
   }
   Robot.stop(50000); 


  
  gyroInicial = getYPR(0) + 95;
  if (gyroInicial > 360.0) {
    gyroInicial = gyroInicial - 360.0;
  }

  
  meuPid.setSetPoint(gyroInicial);
  Serial.print("Angulo Final: ");
  Serial.print(gyroInicial);
  // Manda pro objeto PID!
  delay(2000);
  // Converte para controle

  unsigned long tempoinicial = millis() + 3000;
  while (millis() <= tempoinicial) { 
    IMU_read();
    meuPid.addNewSample(getYPR(0));
    output = tP + meuPid.process();
    motorB = output;
    motorC = output * -1;

    int speedRight = 150 + output; 
    int speedLeft = 150 - output; 
    
    Robot.speed(speedLeft, speedRight); 
    Robot.forward(); 
  }
  pararMotores();
  while(1) {
    
  }
  // Saída do controle

  //Curva90Graus(ESQUERDA, OBS);
  //Curva90Graus(DIREITA, OBS);
*/

}
