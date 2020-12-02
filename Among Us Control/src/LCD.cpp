#include <LiquidCrystal_I2C.h>     //For future inpementatoin of 12C LCD
#include <LCD.h>

//Define LCD stuff
#define ADDRESS 0X00
#define LENGTH 16
#define WIDTH 2

// LCD object
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(ADDRESS, LENGTH, WIDTH);

void initLCD()
{
    lcd.begin(LENGTH, WIDTH);
}

void print(char* message)
{
  lcd.setCursor(0, 0);
  lcd.print(message);
}

void print(char* message, int xPos, int yPos)
{
    if (xPos < LENGTH && xPos >= 0)
    {
        if (yPos < WIDTH && yPos >= 0)
        {
            lcd.setCursor(xPos, yPos);
            lcd.print(message);
        }
    }
}

void clear()
{
    lcd.clear();
}