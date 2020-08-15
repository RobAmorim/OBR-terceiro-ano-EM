#include <Encoder.h>

#include <ControlMotorsRobot.h>

Motors Robot; 

Encoder MotorDir(19, 17);     //Pinagem do interrupitor do MotoDir    
Encoder MotorEsq(18, 16);   //Pinagem do interrupitor do MotoDir 


long Pulsos_Dir = 0;
long Pulsos_Esq = 0; 
long SpeedDir = 0; 
long SpeedEsq = 0; 

#define SpeedBase  180

long lastProcess = 0.0; 

double error = 0.0;
double lastError = 0.0; 

double P = 0.0; 
double I = 0.0;
double D = 0.0; 

double kp = 0.1; 
double ki = 0.01; 
double kd = 2.0;  

double PID = 0;  

void setup()

{

  Serial3.begin(9600);
  Serial.begin(9600);

  delay(5000); 

  Serial3.println("--------------- GO GO GO GO GO GO GO GO GO GO GO GO GO GO GO GO GO GO -------------------");
  
}

void loop()

{

  
  
Pulsos_Dir = MotorDir.read();
Pulsos_Esq = MotorEsq.read(); 

error = Pulsos_Dir - Pulsos_Esq; 

float deltaTime = (millis() - lastProcess) / 1000.0;
     lastProcess = millis();

  P = error * kp; 

  I = I + (error * ki) * deltaTime; 

  D = (lastError - error) * kd / deltaTime; 
  lastError = error; 


  PID = P + I + D;  
  
SpeedDir = SpeedBase - PID; 
SpeedEsq = SpeedBase + PID; 


  Robot.forward(SpeedEsq, SpeedDir); 
  
/*
Serial3.print("Pulsos_Dir:"); Serial3.print(Pulsos_Dir);  
Serial3.print("\t");
Serial3.print("Pulsos_Esq:"); Serial3.print(Pulsos_Esq); 
Serial3.print("\t");
Serial3.print("error:"); Serial3.print(error);
Serial3.print("\t");
Serial3.print("Speed Dir:"); Serial3.print(SpeedDir);
Serial3.print("\t");
Serial3.print("Speed Esq:"); Serial3.print(SpeedEsq);
Serial3.print("\t");
Serial3.print("P:"); Serial3.print(P);
Serial3.print("\t");
Serial3.print("I:"); Serial3.print(I);
Serial3.print("\t");
Serial3.print("D:"); Serial3.print(D);
Serial3.print("\t");
Serial3.print("PID:"); Serial3.println(PID);*/




}
