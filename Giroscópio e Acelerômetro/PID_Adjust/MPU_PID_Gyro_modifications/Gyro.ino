
  void gyro()
  {
 // IMU_read();
  Serial.print("first\t");
  Serial.print(gyroHorinzontal());
  Serial.print("\t");
  Serial.print(gyroVertical());
  Serial.print("\t");
  Serial.println(gyroDiagonal());
  }
  
  int gyroHorinzontal()
  {
    IMU_read();
    return getYPR(0); 
  }
  
  int gyroVertical()
  {
    IMU_read();
    return ypr[1] * 180 / M_PI; 
  }

   int gyroDiagonal()
  {
    IMU_read();
    return ypr[2] * 180 / M_PI; 
  }

  void Gyro_turnRight90()
  {
    double startValue = gyroHorinzontal();
    double totalGyro = startValue + 82; 

    if(totalGyro > 360) 
    {
    totalGyro = totalGyro - 360; 

    while(gyroHorinzontal() != totalGyro)
    {
      Robot.speed(220, 220);
      Robot.right(); 
    }
    Robot.stop(2000); 
    }

    else if(totalGyro < 360) 
    {

    while(gyroHorinzontal() != totalGyro)
    {
      Robot.speed(220, 220);
      Robot.right(); 
    }
    Robot.stop(2000); 
    }

    
  }

   void Gyro_turnLeft90()
  {
    double startValue = gyroHorinzontal();
    double totalGyro = startValue - 80; 

    if(totalGyro < 0) 
    {
    totalGyro = totalGyro * -1; 

    while(gyroHorinzontal() != totalGyro)
    {
      Robot.speed(220, 220);
      Robot.left(); 
    }
    Robot.stop(2000); 
    }

    else if(totalGyro > 0) 
    {

    while(gyroHorinzontal() != totalGyro)
    {
      Robot.speed(220, 220);
      Robot.left(); 
    }
    Robot.stop(2000); 
    }

    
  }

