//======================================================================================================================
                                             //RAMP UP  
//======================================================================================================================
void rampUp()
{
  readReflectance(); 
//======================================================================================================================
                                         // Basic - Line Following 
//======================================================================================================================

 if((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)) //Central Sensors is in black
  {
   Robot.speed(200, 200);
   Robot.forward();     
  }
  
 if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // ALL sensors is in White 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
    Robot.speed(200, 200);
    Robot.forward();   
  }
 
 if((_leftLine < cutoffValue)&&(_rightLine > cutoffValue)) // Central sensor left is in whith and central sensor right is in black 
 {
  Robot.speed(speedRampUp, speedRampUp);
  Robot.right(); 
  }
  
 if((_leftLine > cutoffValue)&&(_rightLine < cutoffValue)) // Central sensor left is in black and central sensor right is in white
  {
     Robot.speed(speedRampUp, speedRampUp);
  Robot.left(); 
  }
//============================================================================================================================
                                          //Corner and Extreme - Line following 
//=======================================================================================================================
    if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner > cutoffValue)&&  //All sensors is in whith and the sensor of left corner is in black 
  (_rightCorner < cutoffValue )&&(_leftEx < cutoffValue )&&(_rightEx < cutoffValue ))
  {
     Robot.speed(speedRampUp, speedRampUp);
  Robot.left(); 
  }
    if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of left extreme is in black
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx < cutoffValue))
  {
     Robot.speed(speedRampUp, speedRampUp);
   Robot.left();  
  }
  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner > cutoffValue)&&  // All sensors is in whith and the sensor of left extreme and 
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx < cutoffValue))         // left corner  is in black
  {
     Robot.speed(speedRampUp, speedRampUp);
   Robot.left(); 
  }
  
  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  //All sensors is in whith and the sensor of right corner is in black 
  (_rightCorner > cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
     Robot.speed(speedRampUp, speedRampUp);
    Robot.right(); 
  }
  
  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme is in black
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx > cutoffValue))
  { 
    Robot.speed(speedRampUp, speedRampUp);
  
    Robot.right(); 
  }
  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme and 
  (_rightCorner > cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx > cutoffValue))         // right corner  is in black
  {
     Robot.speed(speedRampUp, speedRampUp);
    Robot.right(); 
  }
//=================================================================================================================================
 //=================================================================================================================================
                                               //CROSSROAD 
//=================================================================================================================================
 
  
  else if((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)&&(_leftCorner > cutoffValue)&&  // 90º Curver - Left
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx <  cutoffValue))
  
  {
    Robot.backward(250, 250, 50); //Parar robô
    Robot.stop(500); 
    //Robot.stop(100);
    Led.red();
    Serial3.println("CURVA DE 90° ESQ"); 
    Robot.speed(110, 110); 
    Robot.forwardCM(3);
    Robot.backward(250, 250, 50);
    Robot.stop(500);
    Robot.turnLeft90();
    Robot.stop();
  //  CrossroadLeft();
  }


//=======================================================================================================================================  
   else if((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)&&(_leftCorner < cutoffValue)  // 90º Curver - Right
 &&(_rightCorner > cutoffValue) && (_leftEx < cutoffValue)&&(_rightEx > cutoffValue))
  
  {
    Robot.backward(250, 250, 50); //Parar robô
    Robot.stop(500);
    Led.red();
    Serial3.println("CURVA DE 90° DIR"); 
    Robot.speed(110, 110); 
    Robot.forwardCM(3);
    Robot.backward(250, 250, 50);
    Robot.stop(500);
    Robot.turnRight90();
    Robot.stop(500);

    Robot.speed(140, 140); 
  }
 
  


}

//======================================================================================================================
                                             //RAMP DOWN
//======================================================================================================================
void rampDown(){
  
  readReflectance(); 
  
//======================================================================================================================
                                        //Basic - Line Following 
//======================================================================================================================

 if((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)) //Central Sensors is in black
  {
   Robot.speed(100, 100);
   Robot.forward();     
  }
  
 if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // ALL sensors is in White 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
    Robot.speed(100, 100);
    Robot.forward();   
  }
 
 if((_leftLine < cutoffValue)&&(_rightLine > cutoffValue)) // Central sensor left is in whith and central sensor right is in black 
 {
  Robot.speed(speedRampDown, speedRampDown);
  Robot.right(); 
  }
  
 if((_leftLine > cutoffValue)&&(_rightLine < cutoffValue)) // Central sensor left is in black and central sensor right is in white
  {
     Robot.speed(speedRampDown, speedRampDown);
  Robot.left(); 
  }
//============================================================================================================================
                                          //Corner and Extreme - Line following 
//=======================================================================================================================
    if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner > cutoffValue)&&  //All sensors is in whith and the sensor of left corner is in black 
  (_rightCorner < cutoffValue )&&(_leftEx < cutoffValue )&&(_rightEx < cutoffValue ))
  {
     Robot.speed(speedRampDown, speedRampDown);
  Robot.left(); 
  }
    if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of left extreme is in black
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx < cutoffValue))
  {
     Robot.speed(speedRampDown, speedRampDown);
   Robot.left();  
  }
  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner > cutoffValue)&&  // All sensors is in whith and the sensor of left extreme and 
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx < cutoffValue))         // left corner  is in black
  {
     Robot.speed(speedRampDown, speedRampDown);
   Robot.left(); 
  }
  
  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  //All sensors is in whith and the sensor of right corner is in black 
  (_rightCorner > cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
     Robot.speed(speedRampDown, speedRampDown);
    Robot.right(); 
  }
  
  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme is in black
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx > cutoffValue))
  { 
    Robot.speed(speedRampDown, speedRampDown);
  
    Robot.right(); 
  }
  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme and 
  (_rightCorner > cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx > cutoffValue))         // right corner  is in black
  {
     Robot.speed(speedRampDown, speedRampDown);
    Robot.right(); 
  }
//=================================================================================================================================
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
