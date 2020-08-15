
void Crossroad()

{
   Robot.speed(speedRobot, speedRobot); 
  
//===============================================================================================================
                                    // ALL SENSOR IS IN BLACK  
//===============================================================================================================                                       

  Serial3.println("ENCRUZILHADA TOTAL - TRUE");
//=========================================================================
 if((Read.verificationColorRight()  == true)&&(Read.verificationColorLeft()  == true)) //Checking color sensor left
  {
    if((Read.verificationColorRight()  == true)&&(Read.verificationColorLeft()  == true)) //Checking color sensor left
  {
   Led.green(); 
   Robot.stop(200);
   Robot.turnRight90(); 
   //Robot.turnRight90(); 
   while(Read.rightCorner() < 100) //Reflectance sensor 
 {
     Robot.right();
 }

   Robot.stop(200);
  }
     
  }
  else{
     
  if(Read.verificationColorLeft()  == true)  //Checking color sensor right 
  {
     if(Read.verificationColorLeft()  == true)  //Checking color sensor right 
{   
 
    
    Serial3.print("VERDE ESQ TRUE");
    Serial3.print("\t");
    Serial3.print("Color Right:");
    Serial3.print(Read.colorRight()); 
    Serial3.print("\t");
    Serial3.print("Color Left:");
    Serial3.println(Read.colorLeft()); 
    
  Led.green();
  
    
  Robot.speed(110, 110); 
  Robot.forwardCM(A);
  Robot.stop(100); 
  Turn_Left_Crossroad();
  
}
  }
  else
  {
//=====================================================================
  if(Read.verificationColorRight()  == true) //Checking color sensor left
  { 
    if(Read.verificationColorRight()  == true) //Checking color sensor left
    {
      Serial3.print("VERDE DIR TRUE");
     Serial3.print("\t");
    Serial3.print("Color Right:");
    Serial3.print(Read.colorRight()); 
    Serial3.print("\t");
    Serial3.print("Color Left:");
    Serial3.println(Read.colorLeft()); 
    
 Led.green();
 Robot.speed(110, 110); 
 Robot.forwardCM(A);
 Robot.stop(100); 
 Turn_Right_Crossroad(); 
    }
}
//=======================================================================
 else
{
  Serial3.print("VERDE FALSE");
      Serial3.print("\t");
    Serial3.print("Color Right:");
    Serial3.print(Read.colorRight()); 
    Serial3.print("\t");
    Serial3.print("Color Left:");
    Serial3.println(Read.colorLeft()); 
  if((Read.verificationColorRight()  == false)&&(Read.verificationColorLeft()  == false)) //Checking color sensor left
  {
    Robot.speed(110, 110); 
    Robot.forwardCM(2);
    
  }
   } // else
    } //esle
     } //else
      }// If

void CrossroadLeft()

{
   Robot.speed(speedRobot, speedRobot); 
  
//===============================================================================================================
                                    // ALL SENSOR IS IN BLACK  
//===============================================================================================================                                       

//=========================================================================
 if((Read.verificationColorRight()  == true)&&(Read.verificationColorLeft()  == true)) //Checking color sensor left
  {
    if((Read.verificationColorRight()  == true)&&(Read.verificationColorLeft()  == true)) //Checking color sensor left
  {
   Led.green(); 
   Robot.stop(200);
   Robot.turnRight90(); 
   //Robot.turnRight90(); 
   while(Read.rightCorner() < 100) //Reflectance sensor 
 {
     Robot.right();
 }

   Robot.stop(200);
  }
     
  }
  else{
    
  if((Read.verificationColorLeft()  == true)&&(Read.verificationColorRight()  == false))  //Checking color sensor right 
  {
     if((Read.verificationColorLeft()  == true)&&(Read.verificationColorRight()  == false))  //Checking color sensor right 
{
     
    
    Serial3.print("VERDE ESQ TRUE");
    Serial3.print("\t");
    Serial3.print("Color Right:");
    Serial3.print(Read.colorRight()); 
    Serial3.print("\t");
    Serial3.print("Color Left:");
    Serial3.println(Read.colorLeft()); 
    
  Led.green();
  
    
  Robot.speed(110, 110); 
  Robot.forwardCM(A);
  Robot.stop(100); 
  Turn_Left_Crossroad();
  
}
  }
  else
  {
//=====================================================================
  if((Read.verificationColorRight()  == true)&&(Read.verificationColorLeft()  == false)) //Checking color sensor left
  { 
    if((Read.verificationColorRight()  == true)&&(Read.verificationColorLeft()  == false)) //Checking color sensor left
    {
      Serial3.print("VERDE DIR TRUE");
     Serial3.print("\t");
    Serial3.print("Color Right:");
    Serial3.print(Read.colorRight()); 
    Serial3.print("\t");
    Serial3.print("Color Left:");
    Serial3.println(Read.colorLeft()); 
    
 Led.green();
 Robot.speed(110, 110); 
 Robot.forwardCM(A);
 Robot.stop(100); 
 Turn_Right_Crossroad(); 
    }
}
//=======================================================================
 else
{
  Serial3.print("VERDE Right FALSE");
    Serial3.print("\t");
    Serial3.print("Color Right:");
    Serial3.print(Read.colorRight()); 
    Serial3.print("\t");
    Serial3.print("Color Left:");
    Serial3.println(Read.colorLeft()); 

  Robot.speed(110, 110); 
  Robot.forwardCM(5);
  Robot.stop(100); 
   
 if((Read.leftLine() < cutoffValue)&&(Read.rightLine() < cutoffValue)&&(Read.leftCorner() < cutoffValue)&&  // ALL sensors is in White 
  (Read.rightCorner() < cutoffValue)&&(Read.leftEx() < cutoffValue)&&(Read.rightEx() < cutoffValue))
  
  {
    if((Read.leftLine() < cutoffValue)&&(Read.rightLine() < cutoffValue)&&(Read.leftCorner() < cutoffValue)&&  // ALL sensors is in White 
  (Read.rightCorner() < cutoffValue)&&(Read.leftEx() < cutoffValue)&&(Read.rightEx() < cutoffValue))
  {
   // Robot.forwardCM(1, speedRobot, speedRobot);
   // Robot.stop(200);
    Turn_Left_Crossroad();
  }
  }
   else
   {
   if((Read.leftLine() > cutoffValue)||(Read.rightLine() > cutoffValue))

   {
     
     Robot.forward(); 
     
    
   }
   }

   }// If
    }
     }
      }
      
void CrossroadRight()

{
   Robot.speed(speedRobot, speedRobot); 
  
//===============================================================================================================
                                    // ALL SENSOR IS IN BLACK  
//===============================================================================================================                                       
  //=========================================================================
 if((Read.verificationColorRight()  == true)&&(Read.verificationColorLeft()  == true)) //Checking color sensor left
  {
    if((Read.verificationColorRight()  == true)&&(Read.verificationColorLeft()  == true)) //Checking color sensor left
  {
   Led.green(); 
   Robot.stop(200);
   Robot.turnRight90(); 
   //Robot.turnRight90(); 
   while(Read.rightCorner() < 100) //Reflectance sensor 
 {
     Robot.right();
 }

   Robot.stop(200);
  }
     
  }
  else{
    
  if((Read.verificationColorLeft()  == true)&&(Read.verificationColorRight()  == false))  //Checking color sensor right 
  {
     if((Read.verificationColorLeft()  == true)&&(Read.verificationColorRight()  == false))  //Checking color sensor right 
{
   
    
    Serial3.print("VERDE ESQ TRUE");
    Serial3.print("\t");
    Serial3.print("Color Right:");
    Serial3.print(Read.colorRight()); 
    Serial3.print("\t");
    Serial3.print("Color Left:");
    Serial3.println(Read.colorLeft()); 
    
  Led.green();

    
  Robot.speed(110, 110); 
  Robot.forwardCM(A);
  Robot.stop(100); 
  Turn_Left_Crossroad();
  
}
  }
  else
  {
//=====================================================================
  if((Read.verificationColorRight()  == true)&&(Read.verificationColorLeft()  == false)) //Checking color sensor left
  { 
    if((Read.verificationColorRight()  == true)&&(Read.verificationColorLeft()  == false)) //Checking color sensor left
    {
      Serial3.print("VERDE DIR TRUE");
     Serial3.print("\t");
    Serial3.print("Color Right:");
    Serial3.print(Read.colorRight()); 
    Serial3.print("\t");
    Serial3.print("Color Left:");
    Serial3.println(Read.colorLeft()); 
    
 Led.green();
 Robot.speed(110, 110); 
 Robot.forwardCM(A);
 Robot.stop(100); 
 Turn_Right_Crossroad(); 
    }
}
//=======================================================================
 else
{
  Serial3.print("VERDE FALSE");
    Serial3.print("\t");
    Serial3.print("Color Right:");
    Serial3.print(Read.colorRight()); 
    Serial3.print("\t");
    Serial3.print("Color Left:");
    Serial3.println(Read.colorLeft()); 

  Robot.speed(110, 110); 
  Robot.forwardCM(5);
  Robot.stop(100); 

if((Read.leftLine() < cutoffValue)&&(Read.rightLine() < cutoffValue)&&(Read.leftCorner() < cutoffValue)&&  // ALL sensors is in White 
  (Read.rightCorner() < cutoffValue)&&(Read.leftEx() < cutoffValue)&&(Read.rightEx() < cutoffValue))

  {
    if((Read.leftLine() < cutoffValue)&&(Read.rightLine() < cutoffValue)&&(Read.leftCorner() < cutoffValue)&&  // ALL sensors is in White 
  (Read.rightCorner() < cutoffValue)&&(Read.leftEx() < cutoffValue)&&(Read.rightEx() < cutoffValue))
  {
    //Robot.forwardCM(1, speedRobot, speedRobot);
    //Robot.stop(100);
    Turn_Right_Crossroad();
  }
  }
     else
   {
   if((Read.leftLine() > cutoffValue)||(Read.rightLine() > cutoffValue))

   {
     
     Robot.forward();
    
   }
   
//===========================================================================================================

   }
    }    
     }
      }
       }// If
