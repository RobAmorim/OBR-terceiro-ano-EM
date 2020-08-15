
if(Speed > 250) Speed = 250; 
if(Speed < -250) Speed = -250; 

void Motors::move(uint8_t speedEsq, uint8_t speedDir)

{
  if(speedEsq > 0)&&(speedDir > 0)  
{
  mEsq.setSpeed(speedEsq);
  mDir.setSpeed(speedDir);
  mEsq.run(FRENTE);
  mDir.run(FRENTE);
}
  if(speedEsq > 0)&&(speedDir < 0)
{
  speedRight = speedDir * -1; 
  
  mEsq.setSpeed(speedEsq);
  mDir.setSpeed(speedDir);
  mEsq.run(FRENTE);
  mDir.run(PRA_TRAS);
}
   if(speedEsq < 0)&&(speedDir > 0)

   {
    speedLeft = speedEsq * -1; 
    
  mEsq.setSpeed(speedEsq);
  mDir.setSpeed(speedDir);
  mEsq.run(PRA_TRAS);
  mDir.run(FRENTE);
  
   }

}



