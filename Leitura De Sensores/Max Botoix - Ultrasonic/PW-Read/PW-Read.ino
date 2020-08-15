

const int pwPin = 2;
long pulse, inches, cm;

void setup()
{
  Serial.begin(9600); 
  pinMode(pwPin, INPUT);
}



void loop()

{

 

  //pulse = 0; 

  //147uS per inch - inch = polegada 

  pulse = pulseIn(pwPin, HIGH);

   inches = pulse / 147;

  //change inches to centimetres
  // cm = pulse / 58;

  cm = inches * 2.54; 

 /* for(int i = 0; i < 5; i++)
  {
    pulse += pulseIn(pwPin, HIGH);
  }

  cm = (pulse / 5) / 58; 
*/

  Serial.print(cm);
  Serial.println("cm");


  delay(200);

}
