


boolean victimRight = false; 
boolean victimLeft = false; 

void triRight(){
  
  DistanceCm = 30; 
  int pulses = 0;
  pulses = DistanceCm * 360 / CircumferenceWheel;

  resetEncoders();
  readBegin();
  do {
    forward();
    readEnd();
    DeltaEncoders();

    if(Read.sharpRight() < 40cm)
    {
      victimRight = true; 
      Robot.stop(); 
      break; 
    }
    if(Read.sharpRight() > 40 cm)
    {
      continue; 
    }
  } while(Delta_RIGHT < pulses && Delta_LEFT < pulses);
  resetEncoders();
//==========================================================
  verificationVictim(); 
}
//===========================================================

void serchVictim()

{

  While((Read.sharpRight > 40)&&(Read.sharpLeft > 40))

    {
      Robot.forward(); 

      if((Read.sharpRight > 40)&&(Read.sharpLeft < 40)) //Victim Left
      {
        Robot.stop(); 
        victimLeft = true; 
        break; 
      }
       if((Read.sharpRight < 40)&&(Read.sharpLeft > 40)) //Victim Right 
      {
        Robot.stop(); 
        victimRight = true; 
        break; 
      }
      if((Read.sharpRight > 40)&&(Read.sharpLeft > 40)) //No have victim 
      {
        continue; 
      }
    }
}

//======================================================================
void verificationVictim()
{
  if(victimRight == true)&&(victimLeft == false)
  {
    victimRight(); 
    break; 
  }
  else 
    {
      if(victimRight == false)&&(victimLeft == true)
  {
    victimLeft(); 
    
  }
  else 
    {
      if(victimRight ==false)&&(victimLeft == false)
  {
    serchVictim();  
  }
} //Firt if
  } //First else 
    } //Second else 
//====================================================================