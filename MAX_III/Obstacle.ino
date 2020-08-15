

/*----------------------------------------------------------------------------
 * Oficial championsship Programing (function -> void Obstacle) 
 * ---------------------------------------------------------------------------
 * $Author Roboson Vincius Amorim Silva
 * $Date 2016-07 (July 2015) $
 * ---------------------------------------------------------------------------
 */

int distanceObject = 10; 

  void verificationObstacleSide()
  {
    /*
    Robot.turnRightVerificationObstacle();
    
    int distanceRight = Read.sharpRightMiddle();

    Robot.turLeftVerificationObstacle();
    Robot.turLeftVerificationObstacle();
    Robot.stop(500); 
    
    int distanceRight = Read.sharpRightMiddle();

    */
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
      Robot.forwardCM(3); 
      Robot.stop(500);
//===============================================================================================
  Robot.speed(180, 180);
  Robot.turnLeft90();
//===================================================================================================
  Robot.backward(200, 200, 100);
  Robot.speed(180, 180);
  

  
while(Read.sharpLeftMiddle() > distanceObject) //while robot is nearby of obstacle. Go forward! 
  {

    
     Robot.forward();
   }
    Robot.stop(500); 
//=================================================================================================
 
 while(Read.sharpLeftMiddle() < distanceObject) //while robot is nearby of obstacle. Go forward!
 {

      Robot.forward(); 
 }

    Robot.stop(500); 
//==================================================================================================
    Robot.forwardCM(3);
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
   Robot.backwardCM(1); 
   
  }
 void LeftObstacle()


  {
 //Divert from all sizes of obstacles 

 Robot.stop(500);  //Stop when found the obstacle 
  Robot.turnLeft90();
//====================================================================================


while(Read.sharpRightMiddle() < 10)//while robot is nearby of obstacle. Go forward! 
  { 
     Robot.forward(); 
  }
      Robot.stop(500);
 //======================================================================================= 
     Robot.forwardCM(5); 
      Robot.stop(1000);
//===============================================================================================
 Robot.turnRight90();
//===================================================================================================
 
while(Read.sharpRightMiddle() > 10)    //while robot is nearby of obstacle. Go forward!
  {
     Robot.forward();
   }
    Robot.stop(500); 
//=================================================================================================
   
 while(Read.sharpRightMiddle() < 10)   //while robot is nearby of obstacle. Go forward!

 {
      Robot.forward(); 
 }

    Robot.stop(500); 
//==================================================================================================
    Robot.forwardCM(7);
    Robot.stop(500); 
//===========================================================================================================
   Robot.turnRight90();
//================================================================================================================

    
while(Read.sharpRightMiddle() > 10)//while reflectance sensor is in white. Turn Right! 
   {
      Robot.forward(); 
   }
      Robot.stop(600);
      
//==================================================================================================================
     // Robot.forwardCM(1);
      Robot.stop(300);
//==================================================================================================================  

/*while((Read.leftLine() < cutoffValue)&&(Read.rightLine() < cutoffValue)) //while reflectance sensor is in white. Turn Left!  
   {
        Robot.left();
  }*/
  
  Robot.turnLeft90();
  Robot.stop(500); 
  Robot.backwardCM(2); 
  Robot.stop(400); 
  
    
  }

