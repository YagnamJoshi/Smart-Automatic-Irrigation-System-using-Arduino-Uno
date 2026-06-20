#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

Adafruit_SH1106G display(128, 64, &Wire, -1);

const int moisturePin = A0;
const int relayPin = 7;

const int dryValue = 850;   // CHANGE
const int wetValue = 350;   // CHANGE

bool pumpState = false;

void setup() {

  pinMode(relayPin, OUTPUT);

  // Active LOW relay
  digitalWrite(relayPin, HIGH);

  Serial.begin(9600);

  display.begin(0x3C, true);

  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);

  display.setTextSize(2);
  display.setCursor(5, 20);
  display.println("SMART");
  display.display();

  delay(1500);
}

void loop() {

  int raw = analogRead(moisturePin);

  int moisture =
      map(raw, dryValue, wetValue, 0, 100);

  moisture = constrain(moisture, 0, 100);

  // Start watering
  if (moisture < 30 && !pumpState) {
    pumpState = true;
    digitalWrite(relayPin, LOW);
  }

  // Stop watering
  if (moisture > 40 && pumpState) {
    pumpState = false;
    digitalWrite(relayPin, HIGH);
  }

  display.clearDisplay();

  display.setTextSize(1);

  display.setCursor(0, 0);
  display.println("AUTOMATIC IRRIGATION");

  display.drawRect(0, 15, 100, 10, SH110X_WHITE);

  int barWidth = map(moisture, 0, 100, 0, 98);
  display.fillRect(1, 16, barWidth, 8, SH110X_WHITE);

  display.setCursor(105, 15);
  display.print(moisture);
  display.print("%");

  display.setCursor(0, 35);

  if (pumpState)
    display.println("Pump: ON");
  else
    display.println("Pump: OFF");

  display.setCursor(0, 50);
  display.print("Raw: ");
  display.println(raw);

  display.display();

  delay(1000);
}
