
#include <Comunication.h>

/*     combinations with 4 digits 

    1-     0000
    2-     1000
    3-     0100   
    4-     0010
    5-     0001
    6-     1111
    7-     0111
    8-     1011
    9-     1101
    10-    1110
    11-    1100
    12-    1010
    13-    1001
    14-    0011
    15-    0101
    16-    0110

*/
void Check::begin()
{
  pinMode(Check_pin1, INPUT_PULLUP); 
  pinMode(Check_pin2, INPUT_PULLUP); 
  pinMode(Check_pin3, INPUT_PULLUP); 
  pinMode(Check_pin4, INPUT_PULLUP); 
}

bool Check::condition_1()
{
    if((digitalRead(Check_pin1) == 0)&&(digitalRead(Check_pin2) == 0)
      &&(digitalRead(Check_pin3) == 0)&&(digitalRead(Check_pin4) == 0))
    {
    	return true;
    }
    else
    {
    	return false; 
    }
}

bool Check::condition_2()
{
     if((digitalRead(Check_pin1) == 1)&&(digitalRead(Check_pin2) == 0)
      &&(digitalRead(Check_pin3) == 0)&&(digitalRead(Check_pin4) == 0))
    {
    	return true;
    }
    else
    {
    	return false; 
    }
}

bool Check::condition_3()
{
    if((digitalRead(Check_pin1) == 0)&&(digitalRead(Check_pin2) == 1)
      &&(digitalRead(Check_pin3) == 0)&&(digitalRead(Check_pin4) == 0))
    {
    	return true;
    }
    else
    {
    	return false; 
    }
}

bool Check::condition_4()
{
    if((digitalRead(Check_pin1) == 0)&&(digitalRead(Check_pin2) == 0)
      &&(digitalRead(Check_pin3) == 1)&&(digitalRead(Check_pin4) == 0))
    {
    	return true;
    }
    else
    {
    	return false; 
    }
}

bool Check::condition_5()
{
    if((digitalRead(Check_pin1) == 0)&&(digitalRead(Check_pin2) == 0)
      &&(digitalRead(Check_pin3) == 0)&&(digitalRead(Check_pin4) == 1))
    {
    	return true;
    }
    else
    {
    	return false; 
    }
}

bool Check::condition_6()
{
    if((digitalRead(Check_pin1) == 1)&&(digitalRead(Check_pin2) == 1)
      &&(digitalRead(Check_pin3) == 1)&&(digitalRead(Check_pin4) == 1))
    {
    	return true;
    }
    else
    {
    	return false; 
    }
}

bool Check::condition_7()
{
     if((digitalRead(Check_pin1) == 0)&&(digitalRead(Check_pin2) == 1)
      &&(digitalRead(Check_pin3) == 1)&&(digitalRead(Check_pin4) == 1))
    {
    	return true;
    }
    else
    {
    	return false; 
    }
}
bool Check::condition_8()
{
   if((digitalRead(Check_pin1) == 1)&&(digitalRead(Check_pin2) == 0)
    &&(digitalRead(Check_pin3) == 1)&&(digitalRead(Check_pin4) == 1))
    {
      return true;
    }
    else
    {
      return false; 
    }
}
bool Check::condition_9()
{
   if((digitalRead(Check_pin1) == 1)&&(digitalRead(Check_pin2) == 1)
    &&(digitalRead(Check_pin3) == 0)&&(digitalRead(Check_pin4) == 1))
    {
    	return true;
    }
    else
    {
    	return false; 
    }
}
bool Check::condition_10()
{
   if((digitalRead(Check_pin1) == 1)&&(digitalRead(Check_pin2) == 1)
    &&(digitalRead(Check_pin3) == 1)&&(digitalRead(Check_pin4) == 0))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool Check::condition_11()
{
   if((digitalRead(Check_pin1) == 1)&&(digitalRead(Check_pin2) == 1)
    &&(digitalRead(Check_pin3) == 0)&&(digitalRead(Check_pin4) == 0))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool Check::condition_12()
{
   if((digitalRead(Check_pin1) == 1)&&(digitalRead(Check_pin2) == 0)
    &&(digitalRead(Check_pin3) == 1)&&(digitalRead(Check_pin4) == 0))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool Check::condition_13()
{
   if((digitalRead(Check_pin1) == 1)&&(digitalRead(Check_pin2) == 0)
    &&(digitalRead(Check_pin3) == 0)&&(digitalRead(Check_pin4) == 1))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool Check::condition_14()
{
   if((digitalRead(Check_pin1) == 0)&&(digitalRead(Check_pin2) == 0)
    &&(digitalRead(Check_pin3) == 1)&&(digitalRead(Check_pin4) == 1))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool Check::condition_15()
{
   if((digitalRead(Check_pin1) == 0)&&(digitalRead(Check_pin2) == 1)
    &&(digitalRead(Check_pin3) == 0)&&(digitalRead(Check_pin4) == 1))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

bool Check::condition_16()
{
   if((digitalRead(Check_pin1) == 0)&&(digitalRead(Check_pin2) == 1)
    &&(digitalRead(Check_pin3) == 1)&&(digitalRead(Check_pin4) == 0))
    {
      return true;
    }
    else
    {
      return false; 
    }
}

//==============================================

void Trigger::begin() 
{
  pinMode(Trigger_pin1, OUTPUT); 
  pinMode(Trigger_pin2, OUTPUT); 
  pinMode(Trigger_pin3, OUTPUT); 
  pinMode(Trigger_pin4, OUTPUT);
}

void Trigger::condition_1()
{
 digitalWrite(Trigger_pin1, LOW);  //1
 digitalWrite(Trigger_pin2, LOW);
 digitalWrite(Trigger_pin3, LOW);
 digitalWrite(Trigger_pin4, LOW);

}

void Trigger::condition_2()
{
 digitalWrite(Trigger_pin1, HIGH);  //2
 digitalWrite(Trigger_pin2, LOW);
 digitalWrite(Trigger_pin3, LOW);
 digitalWrite(Trigger_pin4, LOW);
}

void Trigger::condition_3()
{
  digitalWrite(Trigger_pin1, LOW);  //3
  digitalWrite(Trigger_pin2, HIGH);
  digitalWrite(Trigger_pin3, LOW);
  digitalWrite(Trigger_pin4, LOW);
}

void Trigger::condition_4()
{
 digitalWrite(Trigger_pin1, LOW);  //4
 digitalWrite(Trigger_pin2, LOW);
 digitalWrite(Trigger_pin3, HIGH);
 digitalWrite(Trigger_pin4, LOW);
}

void Trigger::condition_5()
{
 digitalWrite(Trigger_pin1, LOW);  //5
 digitalWrite(Trigger_pin2, LOW);
 digitalWrite(Trigger_pin3, LOW);
 digitalWrite(Trigger_pin4, HIGH);
}
void Trigger::condition_6()
{
   digitalWrite(Trigger_pin1, HIGH);  //6
	 digitalWrite(Trigger_pin2, HIGH);
	 digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, HIGH);
}

void Trigger::condition_7()
{
	 	 digitalWrite(Trigger_pin1, LOW);  //7
		 digitalWrite(Trigger_pin2, HIGH);
		 digitalWrite(Trigger_pin3, HIGH);
     digitalWrite(Trigger_pin4, HIGH);

}

void Trigger::condition_8()
{
	 digitalWrite(Trigger_pin1, HIGH);  //8
	 digitalWrite(Trigger_pin2, LOW);
	 digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, HIGH);
}

void Trigger::condition_9()
{
   digitalWrite(Trigger_pin1, HIGH);  //8
   digitalWrite(Trigger_pin2, HIGH);
   digitalWrite(Trigger_pin3, LOW);
   digitalWrite(Trigger_pin4, HIGH);
}

void Trigger::condition_10()
{
   digitalWrite(Trigger_pin1, HIGH);  //9
   digitalWrite(Trigger_pin2, HIGH);
   digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, LOW);
}

void Trigger::condition_11()
{
   digitalWrite(Trigger_pin1, HIGH);  //10
   digitalWrite(Trigger_pin2, HIGH);
   digitalWrite(Trigger_pin3, LOW);
   digitalWrite(Trigger_pin4, LOW);
}

void Trigger::condition_12()
{
   digitalWrite(Trigger_pin1, HIGH);  //11
   digitalWrite(Trigger_pin2, LOW);
   digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, LOW);
}

void Trigger::condition_13()
{
   digitalWrite(Trigger_pin1, HIGH);  //12
   digitalWrite(Trigger_pin2, LOW);
   digitalWrite(Trigger_pin3, LOW);
   digitalWrite(Trigger_pin4, HIGH);
}
void Trigger::condition_14()
{
   digitalWrite(Trigger_pin1, LOW);  //13
   digitalWrite(Trigger_pin2, LOW);
   digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, HIGH);
}

void Trigger::condition_15()
{
   digitalWrite(Trigger_pin1, LOW);  //14
   digitalWrite(Trigger_pin2, HIGH);
   digitalWrite(Trigger_pin3, LOW);
   digitalWrite(Trigger_pin4, HIGH);
}

void Trigger::condition_16()
{
   digitalWrite(Trigger_pin1, LOW);  //15
   digitalWrite(Trigger_pin2, HIGH);
   digitalWrite(Trigger_pin3, HIGH);
   digitalWrite(Trigger_pin4, LOW);
}

//==========================================================================



