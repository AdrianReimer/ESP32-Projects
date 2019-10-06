#include <TFT_eSPI.h>
#include <SPI.h>
#include "TetrisShape.h"
#include "TetrisWorld.h"
#include "TetrisRot.h"
#include "TetrisMove.h"

#define WAIT_TIME 500
#define RND_NOISE_PIN 0
#define MOVE_LEFT_BTN_PIN 15
#define MOVE_RIGHT_BTN_PIN 12
#define ROT_BTN_PIN 13


TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h
TetrisShape tetrisShape = TetrisShape();
TetrisWorld tetrisWorld = TetrisWorld(&tft);
TetrisRot tetrisRot = TetrisRot();
TetrisMove tetrisMove = TetrisMove();

void
setup()
{
  tft.init();
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tetrisWorld.initFrame();
  tetrisWorld.setShape(tetrisShape.createRndShape(P1));
  randomSeed(analogRead(RND_NOISE_PIN));
  pinMode(MOVE_LEFT_BTN_PIN, INPUT);
  pinMode(MOVE_RIGHT_BTN_PIN, INPUT);
  pinMode(ROT_BTN_PIN, INPUT);
}

void
loop()
{
  unsigned long t1 = millis();
  if(digitalRead(MOVE_LEFT_BTN_PIN) == HIGH)
    tetrisMove.moveLeftShape(tetrisWorld.getShape(), tetrisWorld.getWorld());
  if(digitalRead(MOVE_RIGHT_BTN_PIN) == HIGH)
    tetrisMove.moveRightShape(tetrisWorld.getShape(), tetrisWorld.getWorld());
  if(digitalRead(ROT_BTN_PIN) == HIGH)
    tetrisRot.rotShape(tetrisWorld.getShape(), tetrisWorld.getWorld());
  if(!tetrisMove.moveDownShape(tetrisWorld.getShape(), tetrisWorld.getWorld())) {
    tetrisWorld.checkWorld();
    tetrisWorld.setShape(tetrisShape.createRndShape(P1));
  }
  tetrisWorld.drawWorld(tetrisWorld.getShape());
  unsigned long t2 = millis();
  delay((WAIT_TIME - (t2 - t1)) % WAIT_TIME);
}
