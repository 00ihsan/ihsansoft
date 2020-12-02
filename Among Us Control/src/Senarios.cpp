#include <Senarios.h>
#include <Sounds.h>
#include <LED.h>
#include <Arduino.h>

void gameOver()
{
    setColor(RED);
    //print("Crewmates lose!");
    loseSound();
    delay(800);
}

void win()
{
    setColor(GREEN);
    //print("Crewmates won!");
    winSound();
    delay(800);
}

void sabotage()
{

}

void emergency()
{

}

void report()
{

}

