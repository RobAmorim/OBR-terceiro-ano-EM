

void Micro_begin(long speed)
{
  Micro.begin(speed); 
}

void Micro_send(int value)
{
      delayMicroseconds(200);
      Micro.write(value); 
}

int Micro_receive()
{
  int received = 0; 
       if (Serial1.available() > 0){
      received = Micro.read(); 
    }

    return received; 
}

