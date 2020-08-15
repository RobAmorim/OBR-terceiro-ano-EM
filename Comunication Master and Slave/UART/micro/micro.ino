#include <communication.h>
#include <uart/microUART.h>
#include <digital/microDIGITAL.h>

Check Check; 
Slave Micro;


void setup() {
  Serial.begin(115200);

  Check.begin(); 
  Micro.begin();
}

void loop() {

  while(Check.condition_1() == true)
  {
    Micro.send(10);
  }

  while(Check.condition_2() == true)
  {
    Micro.send(20);
  }

  while(Check.condition_3() == true)
  {
    Micro.send(30);
  }

  while(Check.condition_4() == true)
  {
    Micro.send(40);
  }

  while(Check.condition_5() == true)
  {
    Micro.send(50);
  }
   while(Check.condition_6() == true)
  {
    Micro.send(60);
  }
   while(Check.condition_7() == true)
  {
    Micro.send(70);
  }
   while(Check.condition_8() == true)
  {
    Micro.send(80);
  }
   while(Check.condition_9() == true)
  {
    Micro.send(90);
  }
   while(Check.condition_10() == true)
  {
    Micro.send(100);
  }
   while(Check.condition_11() == true)
  {
    Micro.send(110);
  }
   while(Check.condition_12() == true)
  {
    Micro.send(120);
  }
   while(Check.condition_13() == true)
  {
    Micro.send(130);
  }
   while(Check.condition_14() == true)
  {
    Micro.send(140);
  }
   while(Check.condition_15() == true)
  {
    Micro.send(150);
  }

  while(Check.condition_16() == true)
  {
    Micro.send(160);
  }
  
}
