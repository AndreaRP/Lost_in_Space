#include "Arduino.h";

#define GREEN_LIGHT 10
#define RED_LIGHT 11
#define BLUE_LIGHT 12
#define SWITCH_1 4
#define SWITCH_2 3
#define SWITCH_3 2


void setup() {
  // put your setup code here, to run once:
  pinMode(GREEN_LIGHT, OUTPUT);
  pinMode(RED_LIGHT, OUTPUT);
  pinMode(BLUE_LIGHT, OUTPUT);
  pinMode(SWITCH_1, INPUT);
  pinMode(SWITCH_2, INPUT);
  pinMode(SWITCH_3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(SWITCH_1) == HIGH) {
    digitalWrite(GREEN_LIGHT, HIGH);  // Switch is ON, turn on our lander's light
  } else {
    digitalWrite(GREEN_LIGHT, LOW);  // Switch is OFF, turn off lander's light
  }

  if (digitalRead(SWITCH_2) == HIGH) {
    digitalWrite(RED_LIGHT, HIGH);  // Switch is ON, turn on our lander's light
  } else {
    digitalWrite(RED_LIGHT, LOW);  // Switch is OFF, turn off lander's light
  }

  if (digitalRead(SWITCH_3) == HIGH) {
    digitalWrite(BLUE_LIGHT, HIGH);  // Switch is ON, turn on our lander's light
  } else {
    digitalWrite(BLUE_LIGHT, LOW);  // Switch is OFF, turn off lander's light
  }
}
