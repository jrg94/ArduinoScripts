// Defines the red pin
const int RED_PIN = 9;

// Defines the green pin
const int GREEN_PIN = 10;

// Defines the blue pin
const int BLUE_PIN = 11;

// The length of time per color in milliseconds
int DISPLAY_TIME = 100; 

/**
 * Sets the color pins to output mode.
 */
void setup()
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}


/**
 * Runs a series of RGB logic.
 */
void loop()
{
  // Drives the RGB LED through the main colors
  mainColors();

  // Drives the RGB LED through a gradient of colors
  showSpectrum();
}

/**
 * Hard codes a series of colors to run with one
 * second delays between each color.
 */
void mainColors()
{
  
  // Off
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  delay(1000);

  // Red
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  delay(1000);

  // Green
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);

  delay(1000);

  // Blue
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);

  delay(1000);

  // Yellow
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);

  delay(1000);

  // Cyan
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);

  delay(1000);

  // Purple
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);

  delay(1000);

  // White
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);

  delay(1000);
}

/**
 * Generates a color spectrum on the RGB LED.
 */
void showSpectrum()
{

  // Loops over 768 values
  for (int i = 0; i < 768; i++)
  {
    // Uses the index as the current color value
    showRGB(i);

    // Delays 10 milliseconds
    delay(10);
  }
}

/**
 * Takes a color value and converts it to
 * the RGB values to be output to the
 * appropriate pins.
 */
void showRGB(int color)
{
  int redIntensity;
  int greenIntensity;
  int blueIntensity;

  // In this zone, we get a mix of red and green
  if (color <= 255)
  {
    redIntensity = 255 - color;
    greenIntensity = color;
    blueIntensity = 0;
  }

  // In this zone, we get a mix of green and blue
  else if (color <= 511)
  {
    redIntensity = 0;
    greenIntensity = 255 - (color - 256);
    blueIntensity = (color - 256);
  }

  // In this zone, we get a mix of red and blue
  else
  {
    redIntensity = (color - 512);
    greenIntensity = 0;
    blueIntensity = 255 - (color - 512);
  }

  // The computed color values are then written to the appropriate pins
  analogWrite(RED_PIN, redIntensity);
  analogWrite(BLUE_PIN, blueIntensity);
  analogWrite(GREEN_PIN, greenIntensity);
}
