# Day 1 

- Install [Arduino IDE](https://www.arduino.cc/en/software)
- Connect board to PC and
    - select the correct Board (UNO) and
    - Port. If you don0t know which it is just disconnect and see which disappears.
- Load the [blink sketch](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink) (Sketc>Examples>01.Basics>Blink)

## basic functions

```console
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN (in UNO pin 14) as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level; HIGH == 5V)
  delay(6000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW (LOW == 0V)
  delay(1000);                      // wait for a second
}
```
