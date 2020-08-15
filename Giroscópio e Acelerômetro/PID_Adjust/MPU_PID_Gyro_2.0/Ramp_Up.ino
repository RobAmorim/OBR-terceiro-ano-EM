
void rampUp()

{

   int speedRamp = 110;
   
  readReflectance(); 
//======================================================================================================================
                                                 //Basic - Line Following 
//======================================================================================================================

 if((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)) //Central Sensors is in black
  {
   Robot.speed(240, 240);
   Robot.forward();     
  }
  
 if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // ALL sensors is in White 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
    Robot.speed(240, 240);
    Robot.forward();   
  }
 
 if((_leftLine < cutoffValue)&&(_rightLine > cutoffValue)) // Central sensor left is in whith and central sensor right is in black 
 {
  Robot.speed(speedRamp, speedRamp);
  Robot.right(); 
  }
  
 if((_leftLine > cutoffValue)&&(_rightLine < cutoffValue)) // Central sensor left is in black and central sensor right is in white
  {
     Robot.speed(speedRamp, speedRamp);
  Robot.left(); 
  }
//============================================================================================================================
                                          //Corner and Extreme - Line following 
//=======================================================================================================================
    if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner > cutoffValue)&&  //All sensors is in whith and the sensor of left corner is in black 
  (_rightCorner < cutoffValue )&&(_leftEx < cutoffValue )&&(_rightEx < cutoffValue ))
  {
     Robot.speed(speedRamp, speedRamp);
  Robot.left(); 
  }
    if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of left extreme is in black
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx < cutoffValue))
  {
     Robot.speed(speedRamp, speedRamp);
   Robot.left();  
  }
  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner > cutoffValue)&&  // All sensors is in whith and the sensor of left extreme and 
  (_rightCorner < cutoffValue)&&(_leftEx > cutoffValue)&&(_rightEx < cutoffValue))         // left corner  is in black
  {
     Robot.speed(speedRamp, speedRamp);
   Robot.left(); 
  }
  
  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  //All sensors is in whith and the sensor of right corner is in black 
  (_rightCorner > cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
     Robot.speed(speedRamp, speedRamp);
    Robot.right(); 
  }
  
  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme is in black
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx > cutoffValue))
  { 
    Robot.speed(speedRamp, speedRamp);
  
    Robot.right(); 
  }
  if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme and 
  (_rightCorner > cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx > cutoffValue))         // right corner  is in black
  {
     Robot.speed(speedRamp, speedRamp);
    Robot.right(); 
  }
//=================================================================================================================================


}
