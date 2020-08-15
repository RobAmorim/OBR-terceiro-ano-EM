void room_3()
{

//==================================================================================================
                                      //Adjust the robot on the east wall of room 3 
//================================================================================================== 
  ReadSharp();
  while(Distance_Sharp_Right > 70) 
{
    ReadSharp();
    Robot.left();
     ReadSharp();
}
  Robot.stop(500);
  TurnLeftAdjust();
  Robot.stop(500);
  Robot.backward(2000);
  Robot.stop(500);
  Distance1 = sharpRight.read(); 
//==================================================================================================
                                    //Leading the robot for North wall of room 3 
//================================================================================================== 

  Robot.forwardCM(26);
  Robot.stop(500); 
  turnRight();
  Robot.stop(500); 
  Robot.backward(1500); 
  Robot.stop(500); 
  Distance2 = sharpLeft.read();  
  //================================================================================================
                                         //Detect rescue area 
  //=================================================================================================

  if(Distance1 > 50cm)&&(Distance2 < 15cm)

  {

    //RescuePlace (North)
     TriNorth();
 
  }

  else if(Distance1 < 50cm)&&(Distance2 > 15cm)

  {
      TriEast(); 
    //RescuePlace (east)
  }


  else if(Distance1 > 50cm)&&(Distance2 > 15cm)

  {
     
     TriWest(); 
    //RescuePlace (west)

  }

  //================================================================================================
                                         //TriNorth
  //=================================================================================================


void TriNorth()

{
   

}

void TriEast()
{


}


void TriWest()

{


}