/*
  Blink pin 13
 */
 
void setup() {
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);
  delay(1000);              // one second
  digitalWrite(13, LOW);
  delay(1000);
}
