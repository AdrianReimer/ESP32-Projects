#include <TFT_eSPI.h>
#include <SPI.h>
#include "TetrisShape.h"
#include "TetrisWorld.h"


TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h
TetrisShape tetrisShape = TetrisShape();
TetrisWorld tetrisWorld = TetrisWorld(&tft);
Shape *shape = tetrisShape.createShape(S, GREEN, P1);

void
setup()
{
  tft.init();
  tft.fillScreen(TFT_BLACK);
  tetrisWorld.initFrame();
}

void
loop()
{
  tetrisShape.rotShape(shape,tetrisWorld.getWorld());
  if(!tetrisShape.moveDownShape(shape,tetrisWorld.getWorld()))
    shape = tetrisShape.createShape(S, GREEN, P1);
  tetrisWorld.drawWorld();
  tft.fillRect(shape->pos[0].x, shape->pos[0].y, BOX_SCALE, BOX_SCALE, shape->color);
  tft.fillRect(shape->pos[1].x, shape->pos[1].y, BOX_SCALE, BOX_SCALE, shape->color);
  tft.fillRect(shape->pos[2].x, shape->pos[2].y, BOX_SCALE, BOX_SCALE, shape->color);
  tft.fillRect(shape->pos[3].x, shape->pos[3].y, BOX_SCALE, BOX_SCALE, shape->color);
  delay(2000);
}
