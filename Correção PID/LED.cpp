//Estruturas - LED.cpp

/*---------------------
- --- Construtores ---
---------------------/
LED::LED (int led) {
  init (led);
}

/*--------------------------
- --- Metodos Publicos ---
---------------------------/
// Reconfigura.
void LED::begin(int led) {
}

// Liga o LED.
void LED::liga() {
    digitalWrite(_led< low);
}

/*------------------------
- --- MEtodos privados ---
-------------------------/
// Configura atributos.
void LED::init(int led) {
_led = led;
pinMode (_led, OUPUT) ;
}

muito menos eu