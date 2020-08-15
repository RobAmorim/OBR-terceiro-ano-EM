

/*----------------------------------------------------------------------------
 * Oficial championsship Programing (function -> void Obstacle) 
 * ---------------------------------------------------------------------------
 * $Author Roboson Vincius Amorim Silva
 * $Date 2016-07 (July 2015) $
 * ---------------------------------------------------------------------------
 */

int distanceObject = 15; 

  void verificationObstacleSide()
  {
     Robot.stop(2000);  
     bool wayRight = false; 
     bool wayLeft = false; 

 //====================================
     //Verification if have wall
 //====================================

     if(Read.verificationRightWallObstacle() == true)
     {
      wayRight = false; 
      wayLeft = true; 

      Led.blue(); 
      Robot.stop(1000); 
      
        }
  
    else
    {
     if(Read.verificationLeftWallObstacle() == true)
     {
       wayRight = true; 
       wayLeft = false; 

      Led.red(); 
      Robot.stop(1000); 
      
     }
     else
     {
     bool verificationSide = false; 
     
      while(verificationSide == false)
      {
      if((wayRight == false)&&(wayLeft == false))
      {
        Robot.turnRight30();
        Robot.stop(500);
//=========================================================

        //Right Side 
        if(Read.verificationLeftWayObstacle() == true)
        {
           if(Read.verificationLeftWayObstacle() == true)
        {
            if(Read.verificationLeftWayObstacle() == true)
        {
        
          wayRight = false; 
          wayLeft = true; 
          
          Robot.turnLeft30(); 
          Robot.stop(500);
          Led.yellow();
          verificationSide = true; 
        }
        }
        }
      
//========================================================
        else
        {  
          wayRight = true; 
          wayLeft = false; 
          
          Robot.turnLeft30();
          Robot.stop(500);
          Led.green();
          verificationSide = true; 
          
         
        }

  //========================================================
      }
      }
     }
    }
      if((wayRight == true)&&(wayLeft == false))
      {
      RightObstacle(); 
      }
      else
      {
        if((wayRight == false)&&(wayLeft == true))
      {
       LeftObstacle(); 
      }
      }
  }
      
            
void RightObstacle()

  {
 
 //Divert from all sizes of obstacles 

 Robot.backward(200, 200, 50);  //Stop when found the obstacle 
// Robot.speed(180, 180);


 Robot.stop(500); 
 Robot.turnRight90();

 
//====================================================================================

while(Read.sharpLeftMiddle() < distanceObject) //while robot is nearby of obstacle. Go forward! 
  { 
     Robot.forward(); 
  }
      Robot.stop(500);
 //======================================================================================= 
      Robot.forwardCM(5); 
      Robot.stop(500);
//===============================================================================================
  Robot.speed(180, 180);
  Robot.turnLeft90();
//===================================================================================================
  Robot.backward(200, 200, 100);
  Robot.speed(180, 180);
  
bool sharp = false; 
  
while(sharp == false) //while robot is nearby of obstacle. Go forward! 
  {

   if(Read.sharpLeftBack() > distanceObject)
   {
    if(Read.sharpLeftBack() > distanceObject)
   {
    if(Read.sharpLeftBack() > distanceObject)
   {
    sharp = true; 
   }
   }
   }
    
     Robot.forward();
   }
    Robot.stop(500); 
//=================================================================================================

 sharp = false;
 
 while(sharp == false) //while robot is nearby of obstacle. Go forward!
 {
     if(Read.sharpLeftBack() < distanceObject)
   {
    if(Read.sharpLeftBack() < distanceObject)
   {
    if(Read.sharpLeftBack() < distanceObject)
   {
    sharp = true; 
   }
   }
   }
      Robot.forward(); 
 }

    Robot.stop(500); 
//==================================================================================================
    Robot.forwardCM(7);
    Robot.stop(500); 
//===========================================================================================================
    Robot.turnLeft90();
    Robot.stop(200); 
  
      Robot.speed(180, 180);
//================================================================================================================
while(Read.leftEx() < 150)//while reflectance sensor is in white. Go forward! 
   {
      Robot.forward(); 
   }
      Robot.backward(200, 200, 50);
      Robot.stop(200); 
//==================================================================================================================
       Robot.forwardCM(2);
      //Robot.stop();
//==================================================================================================================  
Robot.speed(180, 180);

  
   Robot.turnRight90();
   Robot.stop(200); 
   //Robot.backwardCM(1); 

   Robot.backward(500);
   Robot.stop(1000); 
   
  }
 void LeftObstacle()


  {
 //Divert from all sizes of obstacles 

 Robot.backward(200, 200, 50);  //Stop when found the obstacle 
// Robot.speed(180, 180);


 Robot.stop(500); 
 Robot.turnLeft90();

 
//====================================================================================

while(Read.sharpRightMiddle() < distanceObject) //while robot is nearby of obstacle. Go forward! 
  { 
     Robot.forward(); 
  }
      Robot.stop(500);
 //======================================================================================= 
      Robot.forwardCM(5); 
      Robot.stop(500);
//===============================================================================================
  Robot.speed(180, 180);
  Robot.turnRight90();
//===================================================================================================
  Robot.backward(200, 200, 100);
  Robot.speed(180, 180);
  
bool sharp = false; 
  
while(sharp == false) //while robot is nearby of obstacle. Go forward! 
  {

   if(Read.sharpRightBack() > distanceObject)
   {
    if(Read.sharpRightBack() > distanceObject)
   {
    if(Read.sharpRightBack() > distanceObject)
   {
    sharp = true; 
   }
   }
   }
    
     Robot.forward();
   }
    Robot.stop(500); 
//=================================================================================================

 sharp = false;
 
 while(sharp == false) //while robot is nearby of obstacle. Go forward!
 {
     if(Read.sharpRightBack() < distanceObject)
   {
    if(Read.sharpRightBack() < distanceObject)
   {
    if(Read.sharpRightBack() < distanceObject)
   {
    sharp = true; 
   }
   }
   }
      Robot.forward(); 
 }

    Robot.stop(500); 
//==================================================================================================
    Robot.forwardCM(7);
    Robot.stop(500); 
//===========================================================================================================
    Robot.turnRight90();
    Robot.stop(200); 
  
      Robot.speed(180, 180);
//================================================================================================================
while(Read.rightSuper() < 150)//while reflectance sensor is in white. Go forward! 
   {
      Robot.forward(); 
   }
      Robot.backward(200, 200, 50);
      Robot.stop(200); 
//==================================================================================================================
       Robot.forwardCM(2);
      //Robot.stop();
//==================================================================================================================  
Robot.speed(180, 180);

  
   Robot.turnLeft90();
   Robot.stop(200); 
  // Robot.backwardCM(1); 

   Robot.backward(500);
   Robot.stop(1000); 
  
    
  }

