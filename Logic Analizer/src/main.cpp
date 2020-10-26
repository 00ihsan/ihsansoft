#include <Arduino.h>
#define CLOCK_PIN 2
#define BUZZER_PIN A1
unsigned int clocknr = 0;

void ScanData()
{
  if (clocknr % 10 == false)
  {
    tone(BUZZER_PIN, 440, 200);
    tone(BUZZER_PIN, 1440, 200);
  }
  Serial.print("clock: ");
  Serial.println(clocknr);
  clocknr++;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(CLOCK_PIN, INPUT);
  pinMode(BUZZER_PIN, INPUT);
  Serial.begin(115200);
  Serial.println("System started");
  attachInterrupt(digitalPinToInterrupt(CLOCK_PIN), ScanData, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
}