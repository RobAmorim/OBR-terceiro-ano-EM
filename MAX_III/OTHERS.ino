void rescueVictim()

{
     Servos.claw(0); 
    Robot.stop(300);
    Robot.backwardCM(4);
    Robot.stop(200); 
    Servos.center(0); 
    Robot.stop(300); 

}

