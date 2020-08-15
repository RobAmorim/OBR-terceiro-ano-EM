void line()

{ 

  Led.blue(); 

  readReflectance();
  
//======================================================================================================================================= 
   if((_leftLine > cutoffValue)&&(_rightLine > cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of left extreme and 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))         // left corner  is in black
  {
    Robot.speed(135, 135);
   Robot.forward();     
  }
  
  else if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // ALL sensors is in White 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
    readReflectance();
    if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // ALL sensors is in White 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))
  {
    Robot.speed(135, 135);
    Robot.forward();  
  }  
  }
 
 else if((_leftLine < cutoffValue)&&(_rightLine > cutoffValue)) // Central sensor left is in whith and central sensor right is in black 
 {
  Robot.speed(130, 130);
  Robot.right(); 
  }
  
 else if((_leftLine > cutoffValue)&&(_rightLine < cutoffValue)) // Central sensor left is in black and central sensor right is in white
  {
  Robot.speed(130, 130); 
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
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx < cutoffValue))         // right corner  is in black
  {
    Robot.speed(210, 210);
    Robot.right();  
  }
    else if((_leftLine < cutoffValue)&&(_rightLine < cutoffValue)&&(_leftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme and 
  (_rightCorner < cutoffValue)&&(_leftEx < cutoffValue)&&(_rightEx > cutoffValue))         // right corner  is in black
  {
    Robot.speed(210, 210);
    Robot.right();  
  }
}
