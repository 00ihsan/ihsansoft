#include <Arduino.h>

int lastLedMillis;
#define intervalLed  1000

#define LEDpin B00100000 //pin 13
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
        
        PORTB &= ~B00000001;
        PORTD |=  B00000100;
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
  PORTD &= ~B00000100;
  PORTB |=  B00000001;
  count = 0;  
}

void setup()
{
  count = 0;
  lastLedMillis = 0;
  overrideState = false;
  Serial.begin(9600);
  //Select pin mode with DDR
  DDRB |= B10101001; //green LED and build in led and door and override
  DDRD |= B00000100; //red LED
  DDRC |= B00000001; //set buzzer


  tone(buzzerPin, 15000, 1000);
  Serial.println("Setup Complete!");
  lastLedMillis = millis();
  outputTone = true;
}

void loop()
{
  if (millis() - lastLedMillis > intervalLed)
  {
    PORTB ^= LEDpin;
    lastLedMillis = millis();
  }
  
  int overrideStatus = (PIND & B10000000) >> 7;
  int doorStatus = (PINB & B00001000) >> 3;

  if (overrideStatus)
  {
    Serial.println("Override!");
    overrideState = true;
    noTone(buzzerPin);
  }
  else if (doorStatus)
  {
    Serial.println("Door Opened!");
    DoorOpened();
  }
  else if (!doorStatus)
  {
    Serial.println("Door Closed!");
    DoorClosed();
  }
}