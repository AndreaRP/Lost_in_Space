# define cabin_light_pin 12

void setup() {
  // put your setup code here, to run once:
  pinMode(cabin_light_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(cabin_light_pin, HIGH);
  delay(1000);                          
  digitalWrite(cabin_light_pin, LOW);  
  delay(100); 
}
