
                               // Porta analógicas dos sensores
#define sensorCantoDir A9
#define sensorCantoEsq A8

int valorCantoDir, valorCantoEsq = 0;  // Variáveis que guardará o valor lido pela porta



void setup() {

  Serial.begin(9600); // Comunicação Serial

}

void loop() {

    //Valor da variável é igual ao valor lido pela porta analógica
 valorCantoDir = analogRead(sensorCantoDir);
 valorCantoEsq = analogRead(sensorCantoEsq); 


//========================================================================================
 Serial.print("Distância Direita: "); // Printa distância
 Serial.print(valorCantoDir); // Printa em frente de distância o valor lido pelo sensor 
//===========================================================================================
 Serial.print("Distância Esquerda: "); // Printa distância
 Serial.println(valorCantoEsq); // Printa em frente de distância o valor lido pelo sensor e PULA LINHA
//=======================================================================================

 delay(200); // Espera para começar a leitura novamente
}
