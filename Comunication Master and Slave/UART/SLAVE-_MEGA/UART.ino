

void Mega_begin(long speed)
{
 Serial2.begin(speed); 
}

void Mega_send(int value)
{
      delayMicroseconds(200);
      Serial2.write(value); 
}

int Mega_receive()
{
  int received = 0; 
       if (Serial2.available() > 0){
      received = Serial2.read(); 
    }

    return received; 
}

