// Programa : Detector de cores usando modulo TCS230  
// Alteracoes e comentarios : Arduino e Cia  
//  
// Baseado no programa original de Martin Mason  
   
//Pinos de conexao do modulo TCS230 
#define Pino_s0 22 
#define Pino_s1 23  
#define Pino_s2 24  
#define Pino_s3 25  
#define Pino_out A14 

 
int green = 0;  

    
void setup()  


{  
  
  pinMode(Pino_s0, OUTPUT);  //PINOS DO SENSOR DE COR 
  pinMode(Pino_s1, OUTPUT);  
  pinMode(Pino_s2, OUTPUT);  
  pinMode(Pino_s3, OUTPUT);  
  pinMode(Pino_out, INPUT);  

  Serial.begin(9600);  
  //============================================================================   
  digitalWrite(Pino_s0, HIGH);  //CONDIÇÃO DE FREQUÊNCIA DO SENSOR DE COR DIREITO
  digitalWrite(Pino_s1, LOW);
  //============================================================================
 

  
}  
    
void loop() 
{  
  color(); //Chama a rotina que le as cores  
  
  //Mostra no serial monitor os valores detectados  
 //=================================================================================
  Serial.print(" Valor Cor : ");  //PRINTA O VALOR LIDO PELO SENSOR DE COR DIREITO
  Serial.println(green, DEC);  
 //================================================================================ 
 
  
  delay(200); 
 }  
    
void color()  
{  
  //Rotina que le o valor das cores  
  
 digitalWrite(Pino_s2, HIGH);  // CONDIÇÃO QUE ACIONA OS FOTOTRANSISTORS PARA VERDE DO DIREITO
 digitalWrite(Pino_s3, HIGH);   
//===============================

 //count OUT, pGreen, GREEN  
 
 green = pulseIn(Pino_out, digitalRead(Pino_out) == HIGH ? LOW : HIGH); 
   
}

