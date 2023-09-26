#include "arduino_secrets.h"
#include "thingProperties.h"

int statopulsante1 = LOW;
int statopresa1 = LOW;
int statopulsante2 = LOW;
int statopresa2 = LOW;
int statopulsante3 = LOW;
int statopresa3 = LOW;
int statopulsante4 = LOW;
int statopresa4 = LOW;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  Serial.begin(9600);
  delay(1500);
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(3);
  ArduinoCloud.printDebugInfo();
 }

void loop() {
  ArduinoCloud.update();
  int  pulsante1 = digitalRead(2);
  int  pulsante2 = digitalRead(3);
  int  pulsante3 = digitalRead(4);
  int  pulsante4 = digitalRead(5);

  if (pulsante1 != statopulsante1 and pulsante1 == LOW) {
    statopresa1 = !statopresa1;
    digitalWrite(6, statopresa1);
    presa1 = statopresa1;
  }
  if (pulsante2 != statopulsante2 and pulsante2 == LOW) {
    statopresa2 = !statopresa2;
    digitalWrite(7, statopresa2);
    presa2  = statopresa2;
  }
  if (pulsante3 != statopulsante3 and pulsante3 == LOW) {
    statopresa3 = !statopresa3;
    digitalWrite(8, statopresa3);
    presa3 = statopresa3;
  }
  if (pulsante4 != statopulsante4 and pulsante4 == LOW) {
    statopresa4 = !statopresa4;
    digitalWrite(9, statopresa4);
    presa4 = statopresa4;
  }

  statopulsante1 = pulsante1;
  statopulsante2 = pulsante2;
  statopulsante3 = pulsante3;
  statopulsante4 = pulsante4;
  delay(10);
}


void onPresa1Change() {
  statopresa1 = presa1;
  digitalWrite(6, statopresa1);
}

void onPresa2Change() {
  statopresa2 = presa2;
  digitalWrite(7, statopresa2);
}

void onPresa3Change() {
  statopresa3 = presa3;
  digitalWrite(8, statopresa3);
}

void onPresa4Change() {
  statopresa4 = presa4;
  digitalWrite(9, statopresa4);
}
