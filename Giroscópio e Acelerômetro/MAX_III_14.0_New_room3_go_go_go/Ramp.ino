//======================================================================================================================
                                             //RAMP UP  
//======================================================================================================================
void rampUp()
{
  readReflectance(); 
  Led.yellow(); 
//======================================================================================================================
                                         // Basic - Line Following 
//======================================================================================================================

 if((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)) //Central Sensors is in black
  {
   Robot.speed(190, 190);
   Robot.forward();     
  }
  
 if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // ALL sensors is in White 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
    Robot.speed(190, 190);
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
    Robot.backward(200, 200, 50); //Parar robô
    Robot.stop(500); 
    //Robot.stop(100);
    Led.red();
    Serial3.println("CURVA DE 90° ESQ"); 
    Robot.speed(110, 110); 
    Robot.forwardCM(4);
    Robot.backward(250, 250, 50);
    Robot.stop(500);
    Robot.turnLeft90();
    Robot.stop();
    Robot.speed(140, 140); 
  }


//=======================================================================================================================================  
   else if((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)&&(_leftCorner < cutoffValue)  // 90º Curver - Right
 &&(_rightCorner > cutoffValue) && (_leftEx < cutoffValue)&&(_rightEx > cutoffValue))
  
  {
    Robot.backward(250, 250, 50); //Parar robô
    Robot.stop(500);
    Led.red();
    Serial3.println("CURVA DE 90° DIR"); 
    Robot.speed(140, 140); 
    Robot.forwardCM(4);
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
   Robot.speed(130, 130);
   Robot.forward(); 
   delay(10);
   Robot.backward(50, 50, 3);

  
  }
  
 if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // ALL sensors is in White 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
   Robot.speed(130, 130);
   Robot.forward(); 
   delay(10);
   Robot.backward(50, 50, 3);

  }
 
 if((_leftLine < cutoffValue)&&(_rightLine > cutoffValue)) // Central sensor left is in whith and central sensor right is in black 
 {
Robot.speed(130, 130);
   Robot.forward();  
   delay(10);
   Robot.backward(50, 50, 3);
  }
  
 if((_leftLine > cutoffValue)&&(_rightLine < cutoffValue)) // Central sensor left is in black and central sensor right is in white
  {
   Robot.speed(130, 130);
   Robot.forward(); 
   delay(10);
   Robot.backward(50, 50, 3);

  }
//============================================================================================================================
                                          //Corner and Extreme - Line following 
//=======================================================================================================================
    if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner > cutoffValue)&&  //All sensors is in whith and the sensor of left corner is in black 
  (_rightCorner < cutoffValue )&&(_leftEx < cutoffValue )&&(_rightEx < cutoffValue ))
  {
 Robot.speed(130, 130);
   Robot.forward();  
   delay(10);
   Robot.backward(50, 50, 3);

  }
    if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of left extreme is in black
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx < cutoffValue))
  {
Robot.speed(130, 130);
  Robot.forward(); 
   delay(10);
   Robot.backward(50, 50, 3);
  }
  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner > cutoffValue)&&  // All sensors is in whith and the sensor of left extreme and 
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx < cutoffValue))         // left corner  is in black
  {
 Robot.speed(130, 130);
   Robot.forward();  
   delay(10);
   Robot.backward(50, 50, 3);

  }
  
  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  //All sensors is in whith and the sensor of right corner is in black 
  (_rightCorner > cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
   Robot.speed(130, 130);
   Robot.forward(); 
   delay(10);
   Robot.backward(50, 50, 3);

  }
  
  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme is in black
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx > cutoffValue))
  { 
   Robot.speed(130, 130);
  Robot.forward(); 
   delay(10);
   Robot.backward(50, 50, 3);
  }
  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme and 
  (_rightCorner > cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx > cutoffValue))         // right corner  is in black
  {
  Robot.speed(130, 130);
   Robot.forward();  
   delay(10);
   Robot.backward(50, 50, 3);

  }

  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right super in black 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue)&&(_leftSuper < cutoffValue)&&(_rightSuper > cutoffValue))         
  {
    Robot.speed(130, 130);
    Robot.right();  
    delay(10);
    Robot.backward(50, 50, 3);
  }

  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of left super in black 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue)&&(_leftSuper > cutoffValue)&&(_rightSuper < cutoffValue))         
  {
    Robot.speed(130, 130);
    Robot.left();  
     delay(10);
    Robot.backward(50, 50, 3);
  }
}

//======================================================================================================================
                                             //RAMP DOWN
//======================================================================================================================
void rampUnderground(){ 
 

  //float timeLine = millis(); 
  //Robot.speed(speedRobot, speedRobot); 
  //Led.blue(); 
  readReflectance();
  

//======================================================================================================================================= 
   if((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of left extreme and 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))         // left corner  is in black
  {
    Robot.speed(120, 120);
   Robot.forward();     
  }
  
  else if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // ALL sensors is in White 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
    Robot.speed(120, 120);
    Robot.forward();   
  }
 
 else if((_leftLine < cutoffValue)&&(_rightLine > cutoffValue)) // Central sensor left is in whith and central sensor right is in black 
 {
  Robot.speed(150, 150);
  Robot.right(); 
  }
  
 else if((_leftLine > cutoffValue)&&(_rightLine < cutoffValue)) // Central sensor left is in black and central sensor right is in white
  {
  Robot.speed(150, 150); 
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
 
  else if((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)&&(_leftCorner > cutoffValue)&&  // 90º Curver - Left
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx <  cutoffValue))
  
  {
    Robot.backward(200, 200, 50); //Parar robô
    //Robot.stop(100);
    Led.red();
    Serial3.println("CURVA DE 90° ESQ"); 
    Robot.speed(speedRobot, speedRobot); 

    Robot.stop(500); 

    Robot.forwardCM(2); 
    Robot.stop(500); 
    Robot.speed(140, 140); 
    Robot.turnLeft90();
    Robot.stop(500); 
    Robot.forwardCM(3);
    Robot.stop(500);  
    

    /*
     while(Read.leftCorner() < 200)
   {
    Robot.speed(140, 140); 
    Robot.left(140, 140);
   }
   Robot.stop(500); 
   */
    
    
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

    Robot.stop(500); 

    Robot.forwardCM(2); 
    Robot.stop(500); 
    Robot.speed(140, 140); 
    Robot.turnRight90();
    Robot.stop(500);
    Robot.forwardCM(3);
    Robot.stop(500);  



}
}
