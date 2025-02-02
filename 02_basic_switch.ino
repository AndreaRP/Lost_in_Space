#include "Arduino.h"  // include information about our HERO
 
#define CABIN_LIGHTS_PIN 12        // Control our lander's lights using the HERO's pin 12
#define CABIN_LIGHTS_SWITCH_PIN 2  // Connect our light switch to pin 2

void setup() {
  // put your setup code here, to run once:
  pinMode(CABIN_LIGHTS_PIN, OUTPUT);        // Set light control pin as an OUTPUT
  pinMode(CABIN_LIGHTS_SWITCH_PIN, INPUT);  // Since we read from the switch, this pin is an INPUT
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(CABIN_LIGHTS_SWITCH_PIN) == HIGH) {
    digitalWrite(CABIN_LIGHTS_PIN, HIGH);  // Switch is ON, turn on our lander's light
  } else {
    digitalWrite(CABIN_LIGHTS_PIN, LOW);  // Switch is OFF, turn off lander's light
  }
}
