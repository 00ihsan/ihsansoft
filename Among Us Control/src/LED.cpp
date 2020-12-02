#include <LED.h>
#include <Arduino.h>
#include <Pins.h>

void LEDOff()
{
    digitalWrite(REDPIN ,LOW);
    digitalWrite(GREENPIN ,LOW);
    digitalWrite(BLUEPIN ,LOW);
}

int setColor(Color color)
{
    LEDOff();
    if (color == RED)
    {
        digitalWrite(REDPIN, HIGH);
        return 1;
    }
    else if (color == GREEN)
    {
        digitalWrite(GREENPIN, HIGH);
        return 1;
    }
    else if (color == BLUE)
    {
        digitalWrite(BLUEPIN, HIGH);
        return 1;
    }
    return 0;   
}