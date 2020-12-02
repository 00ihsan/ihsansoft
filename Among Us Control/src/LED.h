#ifndef LED_H
#define LED_H

enum Color
{
    RED,
    GREEN,
    BLUE
};

void LEDOff();

int setColor(Color color);

#endif