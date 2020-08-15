// Cria uma serial em software 
 #define Micro Serial1

void setup() {

  pinMode(11, INPUT_PULLUP); 
  
  Serial.begin(115200);
  Micro_begin(115200);
  
}

int received; 
void loop() 

{

     if(digitalRead(11) == 0)      
    {
   
   received = Micro_receive(); 
    
  Serial.print("Micro Value:");
  Serial.print(received); 
  Serial.println("\t");
    }

    if(digitalRead(11) == 1)
    {
      Micro_send(50); 
     // Serial.println("SEND SEND SEND SEND SEND SEND");
    }
    
}

