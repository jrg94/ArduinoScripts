int sensorPin = 0;    // The potentiometer is connected to analog pin 0                      
int ledPin = 13;      // The LED is connected to digital pin 13

/**
 * Sets up the LED pin as output
 */
void setup()
{ 
  pinMode(ledPin, OUTPUT);
}

/**
 * Loops LED blinking using the voltage value on the
 * sensor pin as the blink interval.
 */
void loop() 
{
  // Reads a value between 0 and 1023
  int sensorValue = analogRead(sensorPin);    

  // Turns on the LED
  digitalWrite(ledPin, HIGH);

  // Delays by the sensor value in milliseconds
  delay(sensorValue);

  // Turns the LED off
  digitalWrite(ledPin, LOW);

  // Delays by the sensor value in milliseconds
  delay(sensorValue);
}

