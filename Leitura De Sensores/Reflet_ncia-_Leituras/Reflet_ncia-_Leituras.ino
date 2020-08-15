

//quanto menor o valor, mais luz infravermelha chega ao sensor

//=====================================================================
#define sensorLinhaDir  A13  //Portas dos sensores de refletância CENTRAIS
#define sensorLinhaEsq  A12
//======================================================================
#define sensorCantoEsq  A11 //Portas dos sensores de refletância CANTOS
#define sensorCantoDir  A14
//=======================================================================
#define sensorExEsq A10     //Portas dos sensores de refletância EXTREMOS
#define sensorExDir A15
//======================================================================
//=======================================================================
#define sensorSuperEsq A8     //Portas dos sensores de refletância Super EXTREMOS
#define sensorSuperDir A15
//======================================================================*/
int ledPin = 13;      // select the pin for the LED

int valorLinhaEsq, valorLinhaDir, valorCantoEsq, valorCantoDir, valorExDir, valorExEsq, valorSuperDir, valorSuperEsq = 0;  // variable to store the value coming from the sensor

void setup() {
    Serial.begin(115200);
}

void loop() {
  
  valorLinhaEsq = analogRead(sensorLinhaEsq);   // VALOR LIDO PELO SENSORES -CENTRAIS- GUARDADOS NAS VARIAVEIS  
  valorLinhaDir = analogRead(sensorLinhaDir);
  //========================================================================================================
  valorCantoEsq = analogRead(sensorCantoEsq);   // VALOR LIDO PELO SENSORES -CANTOS- GUARDADOS NAS VARIAVEIS  
  valorCantoDir = analogRead(sensorCantoDir);
  //==========================================================================================================
  valorExEsq = analogRead(sensorExEsq);         // VALOR LIDO PELO SENSORES -EXTREMOS- GUARDADOS NAS VARIAVEIS
  valorExDir = analogRead(sensorExDir);
  //==========================================================================================================
  valorSuperEsq = analogRead(sensorSuperEsq);         // VALOR LIDO PELO SENSORES -EXTREMOS- GUARDADOS NAS VARIAVEIS
  valorSuperDir = analogRead(sensorSuperDir);
    //==========================================================================================================

    //========================================================================================
  Serial.print("   Super Esq: "); //PRINTA OS VALORES DOS SENSORES DE REFLETÂNCIA EXTREMOS 
  Serial.print(valorSuperEsq);
  
  Serial.print("   Extremo Esq: ");
  Serial.print(valorExDir); 
  
   Serial.print("   Canto Esq: ");  //PRINTA OS VALORES DOS SENSORES DE REFLETÂNCIA DOS CANTOS
  Serial.print(valorCantoEsq);
  
    Serial.print("Linha Esq: ");     //PRINTA OS VALORES DOS SENSORES DE REFLETÂNCIA CENTRAIS
  Serial.print(valorLinhaEsq);
  
   Serial.print("   Linha Dir: ");
  Serial.print(valorLinhaDir);
  
    Serial.print("   Canto Dir: ");
  Serial.print(valorCantoDir);
  
   Serial.print("   Extremo Dir: "); //PRINTA OS VALORES DOS SENSORES DE REFLETÂNCIA EXTREMOS 
  Serial.println(valorExDir);
  
  Serial.print("   Super Dir: ");
  Serial.println(valorSuperDir); 
  //==========================================================================================
  delay(250);
}
