#include <Arduino.h>

int lastLedMillis;
bool ledState;
#define intervalLed  1000

#define buzzerPin A0
#define doorPin 11
#define overridePin 7
#define redStatusLed 2
#define greenStatusLed 8

#define interval 1000
#define delayTime 4000

#define frequencyOpened 10000 
#define soundTimeOpened 1500
#define soundTimeClosed 400
#define frequencyClosed 1200

unsigned long lastMillisOpened = millis();
unsigned long lastMillis = millis();

bool overrideState;
bool outputTone;

unsigned long previousMillisBeep = millis();

int count;

void TripleBeepSound()
{
  if (outputTone)
  {
    if (millis() - previousMillisBeep >= interval) 
    {
      previousMillisBeep = millis();
      noTone(buzzerPin);
      count++;
      outputTone = false;
    }
  }
  else
  {
    if (millis() - previousMillisBeep >= interval)
    {
      previousMillisBeep = millis();
      tone(buzzerPin, frequencyOpened, soundTimeOpened);
      outputTone = true;
    }
  }
}

void DoorOpened()
{
  if (millis() - lastMillisOpened > delayTime)
  {
    if (!overrideState)
    {
      Serial.println("Alarm Triggert!");
      if (millis() - lastMillis > interval)
      {
        if (count < 5)
        {
          TripleBeepSound();
        }
        else
        {
          tone(buzzerPin, frequencyOpened, soundTimeOpened);
        }
        
        digitalWrite(greenStatusLed, LOW);
        digitalWrite(redStatusLed, HIGH);
        lastMillis = millis();
      }
    }
  }
}

void DoorClosed()
{
  lastMillisOpened = millis();
  noTone(buzzerPin);
  overrideState = false;
  digitalWrite(redStatusLed, LOW);
  digitalWrite(greenStatusLed, HIGH);
  count = 0;  
}

void setup()
{
  count = 0;
  lastLedMillis = 0;
  ledState = false;
  overrideState = false;
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(greenStatusLed, OUTPUT);
  pinMode(redStatusLed, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(doorPin, INPUT);
  pinMode(overridePin, INPUT);
  tone(buzzerPin, 15000, 1000);
  Serial.println("Setup Complete!");
  lastLedMillis = millis();
  outputTone = true;
}

void loop()
{
  if (millis() - lastLedMillis > intervalLed)
  {
    if (!ledState)
    {
      digitalWrite(LED_BUILTIN, HIGH);
      ledState = true;
    }
    else if (ledState)
    {
      digitalWrite(LED_BUILTIN, LOW);
      ledState = false;
    }
    lastLedMillis = millis();
  }


  if (digitalRead(overridePin))
  {
    Serial.println("Override!");
    overrideState = true;
    noTone(buzzerPin);
  }
  else if (digitalRead(doorPin))
  {
    Serial.println("Door Opened!");
    DoorOpened();
  }
  else if (!digitalRead(doorPin))
  {
    Serial.println("Door Closed!");
    DoorClosed();
  }
}