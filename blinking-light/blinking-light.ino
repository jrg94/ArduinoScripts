/** 
 *  Sets up pin 13 as output.
 */
void setup() {
  pinMode(13, OUTPUT);
}

/**
 * Toggles pin 13 on 1 second intervals.
 */
void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
