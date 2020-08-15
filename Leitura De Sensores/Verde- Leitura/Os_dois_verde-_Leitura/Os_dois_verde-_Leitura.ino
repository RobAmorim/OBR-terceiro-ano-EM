// Programa : Detector de cores usando modulo TCS230  
// Alteracoes e comentarios : Arduino e Cia  
//  
// Baseado no programa original de Martin Mason  
   
//Pinos de conexao do modulo TCS230 DIREITO 
#define Dir_out 44
#define Dir_s0  46
#define Dir_s1  48  
#define Dir_s2  50
#define Dir_s3  52  

//Pinos de conexao do modulo TCS230 ESQUERDO 
#define Esq_out 45
#define Esq_s0  47
#define Esq_s1  49 
#define Esq_s2  51
#define Esq_s3  53 

//Variaveis que armazenam o valor das cores  

int Dir_green = 0;  
int Esq_green = 0;  

void color(); 

    
void setup()  


{  
  
  pinMode(Dir_s0, OUTPUT);  //PINOS DO SENSOR DE COR DA DIREITA
  pinMode(Dir_s1, OUTPUT);  
  pinMode(Dir_s2, OUTPUT);  
  pinMode(Dir_s3, OUTPUT);  
  pinMode(Dir_out, INPUT);  
//================================================================
  pinMode(Esq_s0, OUTPUT);  //PINOS DO SENSOR DE COR DA ESQUERDA  
  pinMode(Esq_s1, OUTPUT);  
  pinMode(Esq_s2, OUTPUT);  
  pinMode(Esq_s3, OUTPUT);  
  pinMode(Esq_out, INPUT);  
 
  Serial.begin(9600);  
  //============================================================================   
  digitalWrite(Dir_s0, HIGH);  //CONDIÇÃO DE FREQUÊNCIA DO SENSOR DE COR DIREITO
  digitalWrite(Dir_s1, LOW);
  //============================================================================
  digitalWrite(Esq_s0, HIGH);  //CONDIÇÃO DE FREQUÊNCIA DO SENSOR DE COR ESQUERDO
  digitalWrite(Esq_s1, LOW);

  
}  
    
void loop() 
{  
  color(); //Chama a rotina que le as cores  
  
  //Mostra no serial monitor os valores detectados  
 //=================================================================================
  Serial.print(" Verde Dir : ");  //PRINTA O VALOR LIDO PELO SENSOR DE COR DIREITO
  Serial.print(Dir_green);  
 //================================================================================ 
  Serial.print(" ======  Verde Esq: ");   //PRINTA O VALOR LIDO PELO SENSOR DE COR ESQUERDO 
  Serial.println(Esq_green);  
  //=================================================================================
  
  delay(200); 
 }  
    
void color()  
{  
  //Rotina que le o valor das cores  
  
 digitalWrite(Dir_s2, HIGH);  // CONDIÇÃO QUE ACIONA OS FOTOTRANSISTORS PARA VERDE DO DIREITO
 digitalWrite(Dir_s3, HIGH);   
//===============================
 digitalWrite(Esq_s2, HIGH);  // CONDIÇÃO QUE ACIONA OS FOTOTRANSISTORS PARA VERDE DO ESQUERDO
 digitalWrite(Esq_s3, HIGH);
   
 //count OUT, pGreen, GREEN  
 
  Dir_green = pulseIn(Dir_out, digitalRead(Dir_out) == HIGH ? LOW : HIGH); 
  Esq_green = pulseIn(Esq_out, digitalRead(Esq_out) == HIGH ? LOW : HIGH);   

}

