#if !defined(LCD_H)
#define LCD_H

void initLCD();

void print(char* message);

void print(char* message, int xPos, int yPos);

void clear();

#endif
