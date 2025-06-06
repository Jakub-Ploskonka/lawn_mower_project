// Author: Jakub Ploskonka
// Date: 06 2025
// Handling of limit switch with straight lever - WK315

const int pinCzujnika = 2;
const int pinLed = 3;
volatile bool stanCzujnika = false;

void setup() {
  pinMode(pinCzujnika, INPUT_PULLUP);  // aktywacja wewnętrznego rezystora pull-up
  pinMode(pinLed, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pinCzujnika), czujnikZmiana, CHANGE);

  Serial.begin(9600);
}

void loop() {

    if (stanCzujnika) {
      Serial.println("Czujnik ON!");
      digitalWrite(pinLed, HIGH);
    } else {
      Serial.println("Czujnik OFF!");
      digitalWrite(pinLed, LOW);
    }
}

void czujnikZmiana() {
  stanCzujnika = digitalRead(pinCzujnika) == LOW;
}
