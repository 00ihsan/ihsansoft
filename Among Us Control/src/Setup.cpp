#include <Arduino.h>
#include <Setup.h>
#include <Sounds.h>
#include <LED.H>

void initPins(int* inputs, int* outputs)
{
  for (int i = 0; i < 4; i++)
  {
    pinMode(outputs[i], OUTPUT);
  }
  for (int i = 0; i < 3; i++)
  {
    pinMode(inputs[i], INPUT);
  }
}

void testIO()
{
  Serial.println("Starting Test...");
  setColor(RED);
  delay(300);
  testSound();
  setColor(GREEN);
  delay(300);
  setColor(BLUE);
  delay(300);
  LEDOff();
}
