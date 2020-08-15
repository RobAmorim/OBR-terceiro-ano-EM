//======================================================================================================================
                                              //Basic - Line following 
//======================================================================================================================

void line()

{

  float timeLine = micros(); 
  //Robot.speed(speedRobot, speedRobot); 
  //Led.blue(); 
  readReflectance();
  

//======================================================================================================================================= 
   if ((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)) //Central Sensors is in black
  {
           digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(1); 
           digitalWrite(ssPin, HIGH);
  }
 else if  ((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // ALL sensors is in White 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
          digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(2); 
           digitalWrite(ssPin, HIGH);
  }
 
 else if ((_leftLine < cutoffValue)&&(_rightLine > cutoffValue)) // Central sensor left is in whith and central sensor right is in black 
 {
   digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(3); 
           digitalWrite(ssPin, HIGH);
  }
  
 else if ((_leftLine > cutoffValue)&&(_rightLine < cutoffValue)) // Central sensor left is in black and central sensor right is in white
  {
 digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(4); 
           digitalWrite(ssPin, HIGH);
  }
//============================================================================================================================
                                         //Corner and Extreme - Line following 
//=======================================================================================================================
    else if ((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner > cutoffValue)&&  //All sensors is in whith and the sensor of left corner is in black 
  (_rightCorner < cutoffValue )&&(_leftEx < cutoffValue )&&(_rightEx < cutoffValue ))
  {
   digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(50); 
           digitalWrite(ssPin, HIGH);
  }
    else if ((_leftLine > cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner > cutoffValue)&&  //All sensors is in whith and the sensor of left corner is in black 
  (_rightCorner < cutoffValue )&&(_leftEx < cutoffValue )&&(_rightEx < cutoffValue ))
  {
  digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(51); 
           digitalWrite(ssPin, HIGH);
  }
    else if ((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of left extreme is in black
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx < cutoffValue))
  {
           digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(52); 
           digitalWrite(ssPin, HIGH);
  }
    else if ((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner > cutoffValue)&&  // All sensors is in whith and the sensor of left extreme is in black
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx < cutoffValue))
  {
           digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(53); 
           digitalWrite(ssPin, HIGH);
  }

 //=====================================================================================================================================================================================
  
  else if ((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  //All sensors is in whith and the sensor of right corner is in black 
  (_rightCorner > cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
           digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(54); 
           digitalWrite(ssPin, HIGH);
  }
    else if ((_leftLine < cutoffValue)&&(_rightLine > cutoffValue)&&(_leftCorner < cutoffValue)&&  //All sensors is in whith and the sensor of right corner is in black 
  (_rightCorner > cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
   digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(55); 
           digitalWrite(ssPin, HIGH);
  }
  
  else if ((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme is in black
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx > cutoffValue))
  {
    digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(56); 
           digitalWrite(ssPin, HIGH);
  }
   else if ((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme is in black
  (_rightCorner > cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx > cutoffValue))
  {
   digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(57); 
           digitalWrite(ssPin, HIGH);
  }
   else if ((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme is in black
  (_rightCorner > cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx > cutoffValue))
  {
    digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(58); 
           digitalWrite(ssPin, HIGH);
  }

  //=================================================================================================================================
                                               //CROSSROAD 
//=================================================================================================================================
    else if ((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)&&(_leftCorner > cutoffValue)  //All sensors is in black 
  &&(_rightCorner > cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx > cutoffValue)) 
  {
           digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(100); 
           digitalWrite(ssPin, HIGH);
   
  } 
 
 
  else if ((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)&&(_leftCorner > cutoffValue)&&  // 90º Curver - Left
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx <  cutoffValue))
  
  {

           digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(101); 
           digitalWrite(ssPin, HIGH);
   
  }


//=======================================================================================================================================  
   else if ((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)&&(_leftCorner < cutoffValue)  // 90º Curver - Right
 &&(_rightCorner > cutoffValue) && (_leftEx < cutoffValue)&&(_rightEx > cutoffValue))
  
  {

           digitalWrite(ssPin, LOW);  // coloca o pino seletor do slave em nivel alto
           SPI.transfer(102); 
           digitalWrite(ssPin, HIGH);
  }
  float finalTimeLine = micros(); 

  float realTime = timeLine - finalTimeLine; 
  Serial.print("realTime:"); 
  Serial.println(realTime); 
  
}
