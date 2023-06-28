#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Pin assignments
const int oxygenDeliveryPin = 13;

// Create an instance of the BME280 sensor
Adafruit_BME280 bme;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize the oxygen delivery pin
  pinMode(oxygenDeliveryPin, OUTPUT);

  // Initialize the BME280 sensor
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  // Measure oxygen level
  float oxygenLevel = measureOxygenLevel();

  // Deliver oxygen if necessary
  if (oxygenLevel < 95.0) {
    deliverOxygen();
  } else {
    stopOxygenDelivery();
  }

  // Display oxygen level
  displayOxygenLevel(oxygenLevel);

  // Wait for a second before measuring again
  delay(1000);
}

float measureOxygenLevel() {
  // Simulate measuring oxygen level using BME280 sensor
  return bme.readTemperature();
}

void deliverOxygen() {
  // Simulate delivering oxygen by turning on the delivery pin
  digitalWrite(oxygenDeliveryPin, HIGH);
}

void stopOxygenDelivery() {
  // Stop delivering oxygen by turning off the delivery pin
  digitalWrite(oxygenDeliveryPin, LOW);
}

void displayOxygenLevel(float level) {
  // Display oxygen level on the serial monitor
  Serial.print("Oxygen Level: ");
  Serial.print(level);
  Serial.println(" %");
}
