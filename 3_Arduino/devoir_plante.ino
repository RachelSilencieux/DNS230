#include <Adafruit_CircuitPlayground.h>

int hydratation = 50;  // quantité d'eau par défaut
bool boutonAvant = false;
unsigned long derniereDiminution = 0;


void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  bool boutonGauche = CircuitPlayground.leftButton();

  if (hydratation < 30) {
    CircuitPlayground.setPixelColor(0, 50, 0, 0);  // rouge
  } else if (hydratation >= 30 && hydratation <= 70) {
    CircuitPlayground.setPixelColor(0, 0, 50, 0);  // vert
  } else {
      CircuitPlayground.setPixelColor(0, 0, 0, 50);  // bleu
  }

  if (boutonGauche && !boutonAvant && hydratation < 100) {
    hydratation++;
  } 
  boutonAvant = boutonGauche; // Garde en mémoire le bouton précédent

  if (millis() - derniereDiminution >= 5000) {
    if (hydratation > 0) {
      hydratation--;
    }
    derniereDiminution = millis();
  }
}
