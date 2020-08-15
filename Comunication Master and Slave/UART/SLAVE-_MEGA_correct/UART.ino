

void Mega_begin(long speed)
{
  Mega.begin(speed); 
}

void Mega_send(int value)
{
      delayMicroseconds(200);
      Mega.write(value); 
}

int Mega_receive()
{
  int received = 0; 
       if (Serial3.available() > 0){
      received = Mega.read(); 
    }

    return received; 
}

