#include <OneWire.h>
#include <DallasTemperature.h>

const int PIR_PIN = 28;
const int FAN_PIN = 26;
const int TEMP_PIN = 27;

const float TEMP_LIMIT = 28.0;

OneWire oneWire(TEMP_PIN);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  pinMode(FAN_PIN, OUTPUT);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures(); 
  float currentTemp = sensors.getTempCByIndex(0);
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH && currentTemp > TEMP_LIMIT) {
    digitalWrite(FAN_PIN, HIGH);
  } else {
    digitalWrite(FAN_PIN, LOW);
  }

  delay(1000);
}