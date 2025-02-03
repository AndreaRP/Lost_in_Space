#include "Arduino.h"
// Our photoresistor will give us a reading of the current light level on this analog pin
const byte PHOTORESISTOR_PIN = A0;  // we pick an analog pin (defined in Arduino.h)

const unsigned int MIN_DELAY = 50;   // 50 ms shortest blink delay
const unsigned int MAX_DELAY = 500;  // 500 ms longest blink delay

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);       // output since we will control the built in LED
  pinMode(PHOTORESISTOR_PIN, INPUT);  // input value from analog pin connected to photoresistor
  Serial.begin(9600);  // This initializes the Serial Monitor and sets the speed to 9600 bits per second
}

void loop() {
  // First, read light value from photoresistor (more V, more light)
  unsigned int light_value = analogRead(PHOTORESISTOR_PIN);   // light value from 0 (0V) to 1024 (5V)
  // Start console output
  Serial.print("Light value: ");  // Display label string to serial monitor
  Serial.print(light_value);      // display the value read from our photoresistor
  // initialize the light value 
  static unsigned int darkest_light = light_value;    // this is the lowest value returned by the photoresistor
  static unsigned int brightest_light = light_value;  // this is the highest value returned by the photoresistor
  // update lowest and highest if it breaks the record. This will calibrate the range to adjust to the environment you are in
  if (light_value < darkest_light) {  // If value is LESS THAN ('<') the darkest...
    darkest_light = light_value;      // ...then save current value as our new darkest value
  }
  if (light_value > brightest_light) {  // If value is GREATER THAN ('>') the brightest...
    brightest_light = light_value;      // ...then save current value as our new brightest value
  }

  // make inbuilt led blink faster when there is more light and slower when there is less
  // Nifty little function, map
  unsigned int delay_value = map(light_value, darkest_light, brightest_light, MAX_DELAY, MIN_DELAY);
  Serial.print(", Delay value: ");  // display label after light_value
  Serial.println(delay_value);      // display delay_value returned by map() function with newline
 
  // now blink our built in LED using our delay_value.
  digitalWrite(LED_BUILTIN, HIGH);  // Turn on LED
  delay(delay_value);               // Leave on delay_value milliseconds
  digitalWrite(LED_BUILTIN, LOW);   // Turn off LED
  delay(delay_value);               // Leave off delay_value milliseconds
}
