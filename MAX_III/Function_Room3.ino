//===================================================
           //VICTIM LEFT end - tri Corner 
//===================================================

 void victimLeftEnd()
 {
     Robot.backward(200, 200, 50); 
     
     Robot.turnLeft90();
      Robot.stop(500);

      Servos.clawDown();
      Robot.speed(110, 110); 
     // Robot.forwardCM(28);
      Robot.speed(110, 110); 
      Robot.forward(4000);
      
      Servos.clawClimbWall();
      Robot.forward(1500);
      Robot.stop(500);
      Robot.backwardCM(40);
      Robot.stop(500);
      Robot.turnRight90();
      Robot.stop(500);
    
 }





//===================================================
           //VICTIM LEFT OPPOSITE - tri right and left 
//===================================================

 void victimLeftOpposite()
 {
     Robot.backward(200, 200, 50); 
     
     Robot.turnLeft90();
      Robot.stop(500);

      Servos.clawDown();
      Robot.speed(110, 110); 
     // Robot.forwardCM(28);
      Robot.speed(110, 110); 
      Robot.forward(4000);
      
      Servos.clawClimbWall();
      Robot.forward(1500);
      Robot.stop(500);
      Robot.backwardCM(40);
      Robot.stop(500);
      Robot.turnRight90();
      Robot.stop(500);

      Robot.speed(110, 110); 
      Robot.forward(4000);
    
 }
//===================================================
           //VICTIM LEFT ULTRA
//===================================================
 void victimLeftUltra()
 {
        Robot.backward(200, 200, 50); 
        Servos.clawClimb(); 
        Robot.stop(1000); 

      if(triCorner == false)
      {
        if(Read.verificationNorthWallBefore() == true)
       {
        Robot.speed(110, 110); 
        Robot.backwardCM(5);
        Robot.backward(200, 200, 50); 
        
       }
       else
       {
  
      Robot.forwardCM(5); 
      Robot.backward(200, 200, 50); 
      Robot.stop(500); 
       }
      }

      if(triCorner == true)
      {
       Robot.forwardCM(5); 
      Robot.backward(200, 200, 50); 
      Robot.stop(500); 
      
      }

      
      Robot.turnLeft90();
      Robot.stop(500);

      Servos.clawDown();
      Robot.speed(110, 110); 
      //Robot.forwardCM(28);
      //Robot.speed(110, 110); 
      Robot.forward(3000);
      
      Servos.clawClimbWall();
      Robot.forward(1500);
      Robot.stop(500);
      Robot.backwardCM(40);
      Robot.stop(500);
      Robot.turnRight90();
      Robot.stop(500);
      Servos.clawDown();
      Robot.stop(500);

      Robot.speed(110, 110); 
      Robot.backwardCM(3);
      Robot.backward(200, 200, 50); 
      Robot.stop(100);
      
    
 }


//===================================================
           //VICTIM LEFT SHARP
//===================================================
    void victimLeftSharp()
    { 
      Robot.backward(200, 200, 50); 
      Servos.clawClimb(); 
      Robot.stop(1000); 

       if(triCorner == false)
      {
       if(Read.verificationNorthWallBefore() == true)
       {
        Robot.speed(110, 110); 
        Robot.backwardCM(2);
        Robot.backward(200, 200, 50); 
        
       }
      }
        
      Robot.turnLeft90();
      Robot.stop(500);

      Servos.clawDown();
      Robot.speed(110, 110); 
      Robot.forwardCM(28);
      Robot.speed(110, 110); 
      Robot.forward(1000);
      
      Servos.clawClimbWall();
      Robot.forward(1500);
      Robot.stop(500);
      Robot.backwardCM(40);
      Robot.stop(500);
      Robot.turnRight90();
      Robot.stop(500);
      Servos.clawDown();
      Robot.stop(500);

      Robot.speed(110, 110); 
      Robot.backwardCM(3);
      Robot.backward(200, 200, 50); 
      Robot.stop(100);
    }


//===================================================
           //VICTIM Right end - tri Corner 
//===================================================

 void victimRightEnd()
 {
     Robot.backward(200, 200, 50); 
     
     Robot.turnRight90();
      Robot.stop(500);

      Servos.clawDown();
      Robot.speed(110, 110); 
     // Robot.forwardCM(28);
      Robot.speed(110, 110); 
      Robot.forward(4000);
      
      Servos.clawClimbWall();
      Robot.forward(1500);
      Robot.stop(500);
      Robot.backwardCM(40);
      Robot.stop(500);
      Robot.turnLeft90();
      Robot.stop(500);
    
 }
 
//===================================================
           //VICTIM Right OPPOSITE - tri right and left 
//===================================================

 void victimRightOpposite()
 {
     Robot.backward(200, 200, 50); 
     
     Robot.turnRight90();
      Robot.stop(500);

      Servos.clawDown();
      Robot.speed(110, 110); 
     // Robot.forwardCM(28);
      Robot.speed(110, 110); 
      Robot.forward(4000);
      
      Servos.clawClimbWall();
      Robot.forward(1500);
      Robot.stop(500);
      Robot.backwardCM(40);
      Robot.stop(500);
      Robot.turnLeft90();
      Robot.stop(500);

      Robot.speed(110, 110); 
      Robot.forward(4000);
    
 }


//===================================================
           //VICTIM RIGHT ULTRA
//===================================================

  void victimRightUltra()
  {   
      Robot.backward(200, 200, 50); 
      Servos.clawClimb(); 
      Robot.stop(500); 
       if(triCorner == false)
      {
      if(Read.verificationNorthWallBefore() == true)
       {
        Robot.speed(110, 110); 
        Robot.backwardCM(3);
        Robot.backward(200, 200, 50); 
        
       }
       else
       {
  
      Robot.forwardCM(5); 
      Robot.backward(200, 200, 50); 
      Robot.stop(500); 
       }
      }

       if(triCorner == true)
      {
       Robot.forwardCM(5); 
      Robot.backward(200, 200, 50); 
      Robot.stop(500); 
      
      }
      
      
       Robot.turnRight90();
      Robot.stop(500);

      Servos.clawDown();
      Robot.speed(110, 110); 
      Robot.forwardCM(28);
      Robot.speed(110, 110); 
      Robot.forward(1000);
      
      Servos.clawClimbWall();
      Robot.forward(1500);
      Robot.stop(500);
      Robot.backwardCM(40);
      Robot.stop(500);
      Robot.turnLeft90();
      Robot.stop(500);
      Servos.clawDown();
      Robot.stop(500);

      Robot.speed(110, 110); 
      Robot.backwardCM(3);
      Robot.backward(200, 200, 50); 
      Robot.stop(100);
      
   }

//===================================================
           //VICTIM RIGHT SHARP
//===================================================

 void victimRightSharp()
    {
      Robot.backward(200, 200, 50); 
      Servos.clawClimb(); 
      Robot.stop(1000); 

        if(triCorner == false)
      {
       if(Read.verificationNorthWallBefore() == true)
       {
        Robot.speed(110, 110); 
        Robot.backwardCM(2);
        Robot.backward(200, 200, 50); 
        
       }
      }
        
      Robot.turnRight90();
      Robot.stop(500);

      Servos.clawDown();
      Robot.speed(110, 110); 
      Robot.forwardCM(28);
      Robot.speed(110, 110); 
      Robot.forward(1000);
      
      Servos.clawClimbWall();
      Robot.forward(1500);
      Robot.stop(500);
      Robot.backwardCM(40);
      Robot.stop(500);
      Robot.turnLeft90();
      Robot.stop(500);
      Servos.clawDown();
      Robot.stop(500);

      Robot.speed(110, 110); 
      Robot.backwardCM(3);
      Robot.backward(200, 200, 50); 
      Robot.stop(100);
   }
//=======================================================================================================
//to put victims inside of trianglo
//=========================================================================================================


void triangloCorner()
{
  Robot.stop(500);
  Robot.speed(200, 200);
  Robot.backwardCM(100);
  Robot.stop(500);
  Robot.speed(110, 110); 
  Robot.backward(2000); 
  Robot.stop(500); 

  Robot.speed(140, 140);
  Robot.forwardCM(7);
  Robot.forward(200, 200, 50); 
  
  //Robot.stop(500); 

  Robot.turnRight90();
  Robot.stop(100); 
  
   
  Robot.speed(100, 100);
  Robot.backward(3000);

   Robot.turnLeft45();
 // Robot.stop(1000);

  Robot.backward(1000); 
  //Robot.stop(500);
  
  Servos.clawRescueArea();

  Robot.stop(500);

   Robot.turnRight45();
   Robot.stop(500); 

   Robot.speed(110, 110);
   Robot.forwardCM(50);
   Robot.stop(500);
   Robot.turnLeft90();
   Robot.backward(2000);
   Robot.stop(500); 
   Robot.forwardCM(7);
   Robot.stop(500); 
   Robot.turnRight90(); 
   Robot.stop(500); 
   Robot.forwardCM(20);

 

  

  

 // Robot.backwardCM(10);
 // Robot.stop(500); 
  
}
void triangloRight()
{
  Robot.speed(140, 140);
  Robot.backwardCM(15);
  Robot.forward(200, 200, 50); 
  
  Robot.stop(500); 

  Robot.turnLeft90();
  Robot.stop(100); 
  
   
  Robot.speed(110, 110);
  Robot.backward(2000);

  Robot.turnLeft45();
 // Robot.stop(1000);

  Robot.backward(1000); 
  //Robot.stop(500);
  
  Servos.clawRescueArea();

  Robot.stop(500);
  Robot.forwardCM(5); 
  Robot.stop(500); 
  Robot.turnLeft45();
  Robot.stop(500);
  Robot.speed(200, 200);
  Robot.forwardCM(80);
  Robot.stop(500);
  Robot.speed(110, 110); 
  Robot.forward(2000); 
  Robot.stop(500); 

  Robot.backwardCM(7);
  Robot.stop(500); 
  Robot.turnLeft90();
  Robot.stop(500); 

  Robot.forwardCM(35); 
  
  
}

void triangloLeft()
{

  Robot.speed(140, 140);
  Robot.backwardCM(15);
  Robot.forward(200, 200, 50); 
  
  //Robot.stop(500); 

  Robot.turnRight90();
  Robot.stop(100); 
  
   
  Robot.speed(110, 110);
  Robot.backward(2000);

  Robot.turnRight45();
 // Robot.stop(1000);

  Robot.backward(1000); 
  //Robot.stop(500);
  
  Servos.clawRescueArea();

  Robot.stop(500);
  Robot.forwardCM(5); 
  Robot.stop(500); 
  Robot.turnRight45();
  Robot.stop(500);
  Robot.speed(200, 200);
  Robot.forwardCM(80);
  Robot.stop(500);
  Robot.speed(110, 110); 
  Robot.forward(2000); 
  Robot.stop(500); 

  Robot.backwardCM(7);
  Robot.stop(500); 
  Robot.turnLeft90();
  Robot.stop(500); 

  Robot.forwardCM(65); 
  
}


