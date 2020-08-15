//======================================================================================================================
                                              //Basic - Line following 
//======================================================================================================================

void line()

{ 

  Led.blue(); 

  //float timeLine = millis(); 
  //Robot.speed(speedRobot, speedRobot); 
  //Led.blue(); 
  readReflectance();
  

//======================================================================================================================================= 
   if((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of left extreme and 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))         // left corner  is in black
  {
    Robot.speed(130, 130);
   Robot.forward();     
  }
  
  else if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // ALL sensors is in White 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
    readReflectance();
     Robot.resetEncodersRoom3(); 
    while((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // ALL sensors is in White 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
     if(Robot.forwardCM_Room3() >= 25)
      {
        Led.yellow(); 
        Robot.backward(200, 200, 50); //Parar robô
        Robot.stop(2000);
        room3();
      }
    readReflectance();
    Robot.speed(150, 150);
    Robot.forward();  
  }  
  }
 
 else if((_leftLine < cutoffValue)&&(_rightLine > cutoffValue)) // Central sensor left is in whith and central sensor right is in black 
 {
  Robot.speed(125, 125);
  Robot.right(); 
  }
  
 else if((_leftLine > cutoffValue)&&(_rightLine < cutoffValue)) // Central sensor left is in black and central sensor right is in white
  {
  Robot.speed(125, 125); 
  Robot.left(); 
  }
//============================================================================================================================
                                         //Corner and Extreme - Line following 
//=======================================================================================================================
    else if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner > cutoffValue)&&  //All sensors is in whith and the sensor of left corner is in black 
  (_rightCorner < cutoffValue )&&(_leftEx < cutoffValue )&&(_rightEx < cutoffValue ))
  {
  Robot.speed(200, 200);
  Robot.left(); 
  }
    else if((_leftLine > cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner > cutoffValue)&&  //All sensors is in whith and the sensor of left corner is in black 
  (_rightCorner < cutoffValue )&&(_leftEx < cutoffValue )&&(_rightEx < cutoffValue ))
  {
  Robot.speed(200, 200);
  Robot.left(); 
  }
    else if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of left extreme is in black
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx < cutoffValue))
  {
    Robot.speed(200, 200);
   Robot.left(); 
  }
    else if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner > cutoffValue)&&  // All sensors is in whith and the sensor of left extreme is in black
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx < cutoffValue))
  {
    Robot.speed(200, 200);
   Robot.left(); 
  }
  else if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of left extreme and 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))         // left corner  is in black
  {
    Robot.speed(210, 210);
   Robot.left(); 
  }
   else if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of left extreme and 
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx < cutoffValue))         // left corner  is in black
  {
    Robot.speed(210, 210);
   Robot.left(); 
  }
  else if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme and 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue)&&(_leftSuper > cutoffValue)&&(_rightSuper < cutoffValue))         // right corner  is in black
  {
    Robot.speed(210, 210);
    Robot.right();  
  }
 //=====================================================================================================================================================================================
  
  else if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  //All sensors is in whith and the sensor of right corner is in black 
  (_rightCorner > cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
    Robot.speed(170, 170);
    Robot.right(); 
  }
    else if((_leftLine < cutoffValue)&&(_rightLine > cutoffValue)&&(_leftCorner < cutoffValue)&&  //All sensors is in whith and the sensor of right corner is in black 
  (_rightCorner > cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
    Robot.speed(170, 170);
    Robot.right(); 
  }
  
  else if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme is in black
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx > cutoffValue))
  {
    Robot.speed(190, 190);
    Robot.right(); 
  }
   else if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme is in black
  (_rightCorner > cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx > cutoffValue))
  {
    Robot.speed(190, 190);
    Robot.right(); 
  }
   else if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme is in black
  (_rightCorner > cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx > cutoffValue))
  {
    Robot.speed(190, 190);
    Robot.right(); 
  }
     else if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme and 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx > cutoffValue))         // right corner  is in black
  {
    Robot.speed(210, 210);
    Robot.right();  
  }

    else if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme and 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue)&&(_leftSuper < cutoffValue)&&(_rightSuper > cutoffValue))         // right corner  is in black
  {
    Robot.speed(210, 210);
    Robot.right();  
  }
  //=================================================================================================================================
                                               //CROSSROAD 
//=================================================================================================================================
  else if((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)&&(_leftCorner > cutoffValue)  //All sensors is in black 
  &&(_rightCorner > cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx > cutoffValue)) 
  {
    Robot.backward(200, 200, 50); //Parar robô
    readReflectance();

    //Robot.stop(100);
    Led.red();
    Serial3.println("ENCRUZILHADA TOTAL"); 
    Robot.speed(speedRobot, speedRobot); 
    Crossroad();
  } 
 
 
  else if((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)&&(_leftCorner > cutoffValue)&&  // 90º Curver - Left
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx <  cutoffValue))
  
  {
    Robot.backward(200, 200, 50); //Parar robô
    //Robot.stop(100);
    Led.red();
    Serial3.println("CURVA DE 90° ESQ"); 
    Robot.speed(speedRobot, speedRobot); 
    CrossroadLeft();
  }

  else if((_leftLine > cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner > cutoffValue)&&  // 90º Curver - Left
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx <  cutoffValue))
  
  {
    Robot.backward(200, 200, 50); //Parar robô
    //Robot.stop(100);
    Led.red();
    Serial3.println("CURVA DE 90° ESQ"); 
    Robot.speed(speedRobot, speedRobot); 
    CrossroadLeft();
  
  }

//=======================================================================================================================================  
   else if((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)&&(_leftCorner < cutoffValue)  // 90º Curver - Right
 &&(_rightCorner > cutoffValue) && (_leftEx < cutoffValue)&&(_rightEx > cutoffValue))
  
  {
    Robot.backward(200, 200, 50); //Parar robô
    //Robot.stop(100);
    Led.red();
    Serial3.println("CURVA DE 90° DIR"); 
    Robot.speed(speedRobot, speedRobot); 
    CrossroadRight();
  }
    else if((_leftLine < cutoffValue)&&(_rightLine > cutoffValue)&&(_leftCorner < cutoffValue)  // 90º Curver - Right
 &&(_rightCorner > cutoffValue) && (_leftEx < cutoffValue)&&(_rightEx > cutoffValue))
  
  {
    Robot.backward(200, 200, 50); //Parar robô
    //Robot.stop(100);
    Led.red();
    Serial3.println("CURVA DE 90° DIR"); 
    Robot.speed(speedRobot, speedRobot); 
    CrossroadRight();
  }
/*  float finalTimeLine = millis(); 

  float realTime = timeLine - finalTimeLine; 
  Serial3.print("realTime:"); 
  Serial3.println(realTime); */
  
}
