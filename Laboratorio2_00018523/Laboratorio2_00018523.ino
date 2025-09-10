/*
int pinLDR = A0;
int Voltaje;
int LDRead;
*/
int redPin = 4;
int bluePin = 3;
int greenPin = 2;

void setup() {
  /*
  pinMode(pinLDR, INPUT);
  Serial.begin(9600);
  */
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  /*
  LDRead = analogRead(pinLDR);
  Voltaje = (LDRead / 1023)  * 5;
  Serial.print("Lectura RAW: ");
  Serial.println(LDRead);
  delay(1000);
  */
  int red = random(0, 256);
  int blue = random(0, 256);
  int green = random(0, 256);
  analogWrite(redPin, red);
  analogWrite(bluePin, blue);
  analogWrite(greenPin, green);
  Serial.print("Red: ");
  Serial.println(red);
  Serial.print("Blue: ");
  Serial.println(blue);
  Serial.print("Green: ");
  Serial.println(green);
  delay(2000);
}
