#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3c

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); 

const int pinLM35 = A0;            // pin analógico donde está conectado LM35 Vout
const unsigned long intervalo = 1000; // intervalo de actualización en ms
unsigned long ultimaMillis = 0;

void setup() {
  Serial.begin(9600);            // velocidad del Monitor Serial
  delay(250);
  while (!Serial) { /* espera en algunas placas */ }
  delay(50);
  Serial.println("LM35 - Lectura simple");

  display.begin(i2c_Address, true);
  display.setContrast (255);
  display.clearDisplay();
  display.display();
}

void loop() {
  display.setTextSize(1); 
  display.setTextColor(SH110X_WHITE); 
  display.setCursor(0, 0);
  unsigned long ahora = millis();
  if (ahora - ultimaMillis >= intervalo) {
    ultimaMillis = ahora;

    int lectura = analogRead(pinLM35);              // 0..1023
    const float Vref = 5.0;                         // ajustar si tu referencia ADC es distinta
    float voltaje = lectura * (Vref / 1023.0);      // voltaje en V
    float tempC = voltaje * 100.0;

    Serial.print("Temperatura: ");
    Serial.print(tempC, 2);   // 2 decimales
    Serial.println(" °C");

    display.print("Temperatura: ");
    display.print(tempC, 2);   // 2 decimales
    display.print(" C");

    display.display();
    display.clearDisplay();
  }

}