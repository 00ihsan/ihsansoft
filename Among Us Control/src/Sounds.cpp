#include <Arduino.h>
#include <Sounds.h>
#include <Pins.h>

void winSound()
{
    for(uint8_t nLoop = 0;nLoop < 2;nLoop ++)
    {
        tone(BUZZERPIN,NOTE_A5);
        delay(NOTE_SUSTAIN);
        tone(BUZZERPIN,NOTE_B5);
        delay(NOTE_SUSTAIN);
        tone(BUZZERPIN,NOTE_C5);
        delay(NOTE_SUSTAIN);
        tone(BUZZERPIN,NOTE_B5);
        delay(NOTE_SUSTAIN);
        tone(BUZZERPIN,NOTE_C5);
        delay(NOTE_SUSTAIN);
        tone(BUZZERPIN,NOTE_D5);
        delay(NOTE_SUSTAIN);
        tone(BUZZERPIN,NOTE_C5);
        delay(NOTE_SUSTAIN);
        tone(BUZZERPIN,NOTE_D5);
        delay(NOTE_SUSTAIN);
        tone(BUZZERPIN,NOTE_E5);
        delay(NOTE_SUSTAIN);
        tone(BUZZERPIN,NOTE_D5);
        delay(NOTE_SUSTAIN);
        tone(BUZZERPIN,NOTE_E5);
        delay(NOTE_SUSTAIN);
        tone(BUZZERPIN,NOTE_E5);
        delay(NOTE_SUSTAIN);
    }
    noTone(BUZZERPIN);
}

void loseSound()
{
    tone(BUZZERPIN,NOTE_G4);
    delay(250);
    tone(BUZZERPIN,NOTE_C4);
    delay(500);
    noTone(BUZZERPIN);
}

void testSound()
{
    tone(BUZZERPIN,NOTE_C4);
    delay(250);
    tone(BUZZERPIN,NOTE_G4);
    delay(500);
    tone(BUZZERPIN,NOTE_C4);
    delay(250);
    noTone(BUZZERPIN);
}