// Cria uma serial em software 
 #define Micro Serial1

void setup() {

  pinMode(0, INPUT_PULLUP); 
  Serial.begin(9600);
  Micro_begin(9600);
}

int received; 
void loop() 

{

     //  long time = micros(); 

      


  /*      received = Micro_receive(); 
    
  Serial.print("Micro Value:");
  Serial.print(received); 
  Serial.print("\t");*/

  Micro_send(80); 


    
}

