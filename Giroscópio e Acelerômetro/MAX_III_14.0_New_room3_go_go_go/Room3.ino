
void room3()
{

//==================================================================================================
                                      //Adjust the robot on the south wall of room 3 
//================================================================================================== 

    //Servos.clawAfterRamp();
  //  Robot.stop(500);
    Robot.speed(130, 130);
    Robot.forwardCM(25); 
    Robot.backward(200, 200, 50); //Parar robô
    Robot.turnRight90();
    Robot.speed(130, 130);
    Robot.backward(3000);
  //  Robot.stop(1000000); 
 
//==================================================================================================
                                  //Check if have rescue area in tri Corner 
//==================================================================================================

 //============================================================================
                      //VERIFICATION TRI CORNER 
 //===========================================================================
 
   if(Read.verificationTriCorner() == true)
   {

    triCorner = true; 
    Led.green(); 
    Servos.clawDown(); 
    Robot.stop(500); 
    Robot.speed(110, 110); 
    Robot.forwardCM(25);
    Robot.backward(200, 200, 50); 


 //============================================================================
                      //FIRST STEP - SEARCHING VICTIMS 
 //============================================================================

//============================================================================
           //First Step - searching the victims in the middle of rescue area
//===========================================================================
  bool point1 = false; 
  
  while(point1 == false)
  {
  
    Robot.speed(110, 110);
    Robot.forward(); 
    
    //Verification if the robot is in the North wall 
    if(Read.verificationNorthWall() == true)
    {
      Robot.stop(2000);
      point1 = true;
    }

   else
   {

    //Verification if have victim in the right side with ultrasonic 
    if(Read.verificationVictimRightUltra() == true)
    {    
         Led.red(); 
         victimRightUltra();
         Led.yellow(); 
    }

    //Verification if have victim in the right side with sharp 
    if(Read.verificationVictimRightSharp() == true)
    {    
         Led.blue();
         victimRightSharp();
         Led.yellow(); 
    }

    //Verification if have victim in the left side with ultrasonic 
    if(Read.verificationVictimLeftUltra() == true)
    {   
        Led.red(); 
        victimLeftUltra();
        Led.yellow();
    }

    //Verification if have victim in the left side with sharp
     if(Read.verificationVictimLeftSharp() == true)
    {
      Led.blue();
      victimLeftSharp();
      Led.yellow(); 
    }
     }
      }

//==============================================================================
           //second Step - searching the victims in the back of room - claw wall
//==============================================================================

      bool point2 = false; 
      long lastTime = millis(); 
      long correctTime = lastTime + 3000; 
      Led.red(); 
      
  
  while(point2 == false)
  {
  
    Robot.speed(120, 120);
    Robot.forward(); 
    
    //Verification if the robot is in the North wall 
    if(millis() >= correctTime)
    {
      Servos.clawClimbWall(); 
      Robot.stop(2000);
      point2 = true; 
      
    }

   else
   {

    //Verification if have victim in the right side with ultrasonic 
    if(Read.verificationVictimRightUltra() == true)
    {    
         Servos.clawClimb();
         victimRightEnd();
         lastTime = millis(); 
         correctTime = lastTime + 3000; 
    }

    //Verification if have victim in the right side with sharp 
    if(Read.verificationVictimRightSharp() == true)
    {
          Servos.clawClimb();
          victimRightEnd();
           lastTime = millis(); 
           correctTime = lastTime + 3000; 
    }

    //Verification if have victim in the left side with ultrasonic 
    if(Read.verificationVictimLeftUltra() == true)
    {    
         Servos.clawClimb();
         victimLeftEnd();
          lastTime = millis(); 
          correctTime = lastTime + 3000; 
    }

    //Verification if have victim in the left side with sharp
     if(Read.verificationVictimLeftSharp() == true)
    {

      Servos.clawClimb();
      victimLeftEnd();
       lastTime = millis(); 
      correctTime = lastTime + 3000; 
    }
     }
      }
 
//==============================================================================
           //Third Step - searching the victims in the back of room - robot wall
//==============================================================================
      bool point3 = false; 
      lastTime = millis(); 
      correctTime = lastTime + 5000; 
      Led.blue(); 
  
  while(point3 == false)
  {
  
    Robot.speed(120, 120);
    Robot.forward(); 
    
    //Verification if the robot is in the North wall 
    if(millis() >= correctTime)
    {
      //Servos.clawClimbWall(); 
      Robot.stop(2000);
      triangloCorner();
      while(1)
          {
            line();
          }
      
      
    }

   else
   {

    //Verification if have victim in the right side with ultrasonic 
    if(Read.verificationVictimRightUltra() == true)
    {
         victimRightEnd();
         lastTime = millis(); 
         correctTime = lastTime + 3000; 
    }

    //Verification if have victim in the right side with sharp 
    if(Read.verificationVictimRightSharp() == true)
    {
         victimRightEnd();
         lastTime = millis(); 
         correctTime = lastTime + 3000; 
    }

    //Verification if have victim in the left side with ultrasonic 
    if(Read.verificationVictimLeftUltra() == true)
    {
       victimLeftEnd(); 
       lastTime = millis(); 
       correctTime = lastTime + 3000; 
    }

    //Verification if have victim in the left side with sharp
     if(Read.verificationVictimLeftSharp() == true)
    {
      victimLeftEnd(); 
      lastTime = millis(); 
      correctTime = lastTime + 3000; 
    }
     }
      }
//==============================================================================
           //Forth Step - put the victims inside of trianglo 
//==============================================================================



   }
   else
   {


//============================================================================================================================================================
                           //Searching Victims - RIGHT AND LEFT RIGHT AND LEFT RIGHT AND LEFT RIGHT AND LEFT TRI
//============================================================================================================================================================

    Led.purple();
    
 bool point1 = false; 
 Servos.clawDown(); 
 delay(1000);


 //============================================================================
    //First Step - searching the victims in the middle of rescue area
 //===========================================================================
  while(point1 == false)
  {
  
    Robot.speed(120, 120);
    Robot.forward(); 
    
    //Verification if the robot is in the North wall 
    if(Read.verificationNorthWall() == true)
    {
      Robot.backward(200, 200, 50); 
      Robot.speed(110, 110); 
      Robot.forward(3000); 
      Robot.stop(500);
      Servos.clawClimbWall(); 
      Robot.stop(500);
      Robot.forward(1500); 
      Robot.stop(500);
      
      point1 = true; 
      Robot.stop(1000);
      Robot.speed(110, 110);
      Robot.backwardCM(3);
      Robot.forward(200, 200, 50); 
      Robot.stop(1000);
      
    }

   else
   {

    //Verification if have victim in the right side with ultrasonic 
    if(Read.verificationVictimRightUltra() == true)
    {    
         Led.red(); 
         victimRightUltra();
         Led.yellow(); 
    }

    //Verification if have victim in the right side with sharp 
    if(Read.verificationVictimRightSharp() == true)
    {    
         Led.blue();
         victimRightSharp();
         Led.yellow(); 
    }

    //Verification if have victim in the left side with ultrasonic 
    if(Read.verificationVictimLeftUltra() == true)
    {   
        Led.red(); 
        victimLeftUltra();
        Led.yellow();
    }

    //Verification if have victim in the left side with sharp
     if(Read.verificationVictimLeftSharp() == true)
    {
      Led.blue();
      victimLeftSharp();
      Led.yellow(); 
    }
     }
      }
 //==============================================================================
           //Second Step - verification What is the side that the trianglo is
 //==============================================================================

     bool triRight = false; 
     bool triLeft = false; 
     
     //If trianglo to be in the right side 
     if((Read.verificationTriRight() == true)&&(Read.verificationTriLeft() == false))
     {
        Led.red();
        triRight = true; 
        Robot.stop(2000);
     }

     else
     {

      //If trianglo to be in the left side 
      if((Read.verificationTriRight() == false)&&(Read.verificationTriLeft() == true))
     {
      Led.blue(); 
      triLeft = true; 
      Robot.stop(2000);
     }
    }
 //==============================================================================
           //Third Step - searching victims in the area opposite the trianglo 
 //==============================================================================
        bool point2 = false; 
        Robot.resetEncodersRoom3(); 

 //If the triangle to be in the right side - To search in the left side

      if(triRight == true)
      {
        while(point2 == false)
        {
          Robot.speed(110, 110); 
          Robot.backward();

          if(Robot.forwardCM_Room3() <= -25)
         {
          point2 = true;

          Robot.backward(200, 200, 50);
          Robot.speed(110, 110); 
          Robot.forward(4000);
          Robot.stop(500);
         }
         
          else
          {
            //Verification if have victim in the right side with ultrasonic 
            if(Read.verificationVictimLeftUltra() == true)
            {
                 victimLeftOpposite();
                 point2 = true; 
            }
             //Verification if have victim in the right side with sharp 
            if(Read.verificationVictimLeftSharp() == true)
            {
                victimLeftOpposite();
                 point2 = true; 
            }
            
        } 
        }
      }
 //=====================================
      else
      {
  //If the triangle to be in the left side - To search in the right side
  
         if(triLeft == true)
      {
        while(point2 == false)
        {
          Robot.speed(110, 110); 
          Robot.backward();

          if(Robot.forwardCM_Room3() <= -25)
         {
          point2 = true;
          Robot.forward(3000);
          Robot.stop(500);
         }

         else
         {
          
           //Verification if have victim in the right side with ultrasonic 
            if(Read.verificationVictimRightUltra() == true)
            {
                 victimRightOpposite();
                 point2 = true; 
            }
             //Verification if have victim in the left side with sharp 
            if(Read.verificationVictimRightSharp() == true)
            {
                 victimRightOpposite();
                 point2 = true; 
            }
        }
        }
      }
      }

      Robot.stop(2000);
 //==============================================================================
           //fourth Step - To put the victims in the trianglo and go to follow line 
 //==============================================================================
        
        if(triRight == true)
        {
          triangloRight();
          while(1)
          {
            line();
          }
        }
        else
        {
          if(triLeft == true)
          {
            triangloLeft();
            while(1)
          {
            line();
          }
          }
          
        }

        Robot.stop(50000);
 //=============================================================================  
     
   }

    }

