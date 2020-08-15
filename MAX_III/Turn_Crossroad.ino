void Turn_Right_Crossroad() //Turn robot for right in crossroad 

  {
    
    Robot.turnRight90();
    //Robot.stop(300);
    Robot.speed(180, 180);
    Robot.backwardCM(5);
    
    //if((valueLeftLine > cutoffValue)||(valueLineRight > cutoffValue)||(valueLeftCorner > cutoffValue)||(valueRightCorner > cutoffValue)) 
 //{
   
   //Robot.stop(1000);
    while(Read.rightEx() < 100) //Reflectance sensor 
 {
     Robot.backward();
 }

     Robot.forward(200, 200, 50);
     Robot.stop(100);
     Robot.speed(180, 180);
     Robot.forwardCM(2); 
     

     
 // }

/*else {
  
  if((valueLeftLine < cutoffValue)&&(valueLineRight < cutoffValue)&&(valueLeftCorner < cutoffValue)&&  // Todos no Branco 
  (valueRightCorner < cutoffValue))
  
{
     Robot.forward();
 }
 
}*/

}
      

//====================================================================================
  

//=============================================================================

  void Turn_Left_Crossroad() //Turn robot for left in crossroad 

  {

      Robot.turnLeft90();
     // Robot.stop(300);
      Robot.backwardCM(5);
      
//=======================================================================================================================

//if((valueLeftLine > cutoffValue)||(valueLineRight > cutoffValue)||(valueLeftCorner > cutoffValue)||(valueRightCorner > cutoffValue))   //UM DOS SENSORES CENTRAIS NO PRETO (INDCA UMA LINHA EM FRENTE)

    //{
      // Robot.stop(1000);
  while(Read.leftEx()  < 100) //Reflectance sensor  
   {
     Robot.backward();
   }   
       Robot.forward(200, 200, 50);
       Robot.stop(10);
       Robot.speed(180, 180);
       Robot.forwardCM(1); 
       Robot.stop(100);

       
       
//}

/*else
{
if((valueLeftLine < cutoffValue)&&(valueLineRight < cutoffValue)&&(valueLeftCorner < cutoffValue)&&(valueRightCorner < cutoffValue))
{
     Robot.forward();
 }
   }
 */
    }

