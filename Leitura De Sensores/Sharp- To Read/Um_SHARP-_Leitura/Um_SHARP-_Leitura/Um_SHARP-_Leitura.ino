
#define sensorSharp A0
// Porta analógia do sensor


int valorSharp = 0;  // Variável que guardará o valor lido pela porta



void setup() {

  Serial.begin(9600); // Comunicação Serial

}

void loop() {

 valorSharp = analogRead(sensorSharp); //Valor da variável é igual ao valor lido pela porta analógica

  Serial.print("Distância: "); // Printa distância
 Serial.println(valorSharp); // Printa em frente de distância o valor lido pelo sensor 

 delay(200); // Espera para começar a leitura novamente
}
