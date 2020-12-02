//To keep things organized.
#include <Arduino.h>              //Default
#include <Setup.h>                //Init methods
#include <LED.h>                  //LED controls
#include <Pins.h>                 //Pins used by this project
#include <GameState.h>            //Enum states
#include <LCD.h>                  //Custom I2C LCD 
#include <Sounds.h>               //Sounds used
#include <Senarios.h>             //The game senarios

// pinarrays to init easier
int outputs[] = {BUZZERPIN, REDPIN, GREENPIN, BLUEPIN};
int inputs[] = {EMERBTNPIN, SABOTAGEBTNPIN, CLEARBTNPIN};

//The state of the game
State gameState = OK;
Color currentLED = GREEN;

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting...");
  initPins(inputs, outputs);
  Serial.println("Pins initialized.");
  gameState = OK;
  testIO();
  //initLCD();
  //print("Starting...");
  //clear();
  Serial.println("Test Complete!");
  Serial.println("\nWelcome To Among Us!\n");
}

void loop()
{
  State oldState = gameState;
  Color oldLED = currentLED;
  // handle accordingly
  switch (gameState)
  {
  case OK:
    //print("OK");
    if (setColor(BLUE)) {currentLED = BLUE;}
    noTone(BUZZERPIN);
    break;
  
  case SABOTAGE:
    sabotage();
    break;

  case EMERGENCY:
    emergency();
    break;

  case REPORT:
    report();
    break;

  case GAMEOVER:
    gameOver();
    break;

  case WIN:
    win();
    break;

  default:
    gameState = OK;
    break;
  }
  //change states with buttons
  if (gameState == OK)
  {
    if (digitalRead(EMERBTNPIN)) 
    {
      gameState = EMERGENCY;
      Serial.println("Emergency button pressed.");
    }
    else if (digitalRead(SABOTAGEBTNPIN)) 
    {
      gameState = SABOTAGE;
      Serial.println("Sabotage button pressed.");
    }
  }
  if (digitalRead(CLEARBTNPIN)) 
  {
    gameState = OK;
    Serial.println("Clear button pressed.");
  }
  //check game status
  if (oldState != gameState) // check state change
  {
    Serial.print("New state: ");
    if (gameState == OK) {Serial.println("OK"); }
    if (gameState == SABOTAGE) {Serial.println("SABOTAGE"); }
    if (gameState == EMERGENCY) {Serial.println("EMERGENCY"); }
    if (gameState == REPORT) {Serial.println("REPORT"); }
    if (gameState == GAMEOVER) {Serial.println("GAMEOVER"); }
    if (gameState == REPORT) {Serial.println("REPORT"); }
  }
  if (oldLED != currentLED) //  check LED change
  {
    Serial.print("LED:");
    if (currentLED == RED   )  { Serial.println("RED");   }
    if (currentLED == BLUE  )  { Serial.println("BLUE");  }
    if (currentLED == GREEN )  { Serial.println("GREEN"); }
  }
}