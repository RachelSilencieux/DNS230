#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();

}

int seuilMin = 50; // sombre faible
int seuilMax = 100; // sombre intense
int luminosite = 0; // pour l'intensité de lumière

void loop() {
  CircuitPlayground.clearPixels();
  luminosite = CircuitPlayground.lightSensor();
  for (int i = 0; i < 10; i++) {
    if (luminosite < seuilMin){
      CircuitPlayground.setPixelColor(i, 255, 0, 255);
    } else if (luminosite < seuilMax){
      CircuitPlayground.setPixelColor(i, 30, 0, 30);
    } else {
      CircuitPlayground.setPixelColor(i, 0, 0, 0);
    }
  }
}

/*
* Une veilleuse automatique qui utilise le capteur de lumière. l'orsqu'il fait très sombre, elle produit un éclairage violet intense
* Lorsqu'il fait un peu sombre, l'éclairage est plus faible. 
* Quand il y a suffisamment de lumière, elle s'éteint. 
* Les deux seuils permettent de choisir la réaction selon la luminosité détectée.
*/