// Cria uma serial em software 
 #define Micro Serial1

void setup() {

  pinMode(0, INPUT_PULLUP); 
  Serial.begin(115200);
  Micro_begin(115200);
}

int received; 
void loop() 

{

     //  long time = micros(); 

      


      /*  received = Micro_receive(); 
    
  Serial.print("Micro Value:");
  Serial.print(received); 
  Serial.print("\t");*/

  Micro_send(80); 


    
}

