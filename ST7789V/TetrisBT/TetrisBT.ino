#include <TFT_eSPI.h>
#include <SPI.h>
#include "TetrisShape.h"
#include "TetrisWorld.h"
#include "TetrisRot.h"
#include "TetrisMove.h"


TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h
TetrisShape tetrisShape = TetrisShape();
TetrisWorld tetrisWorld = TetrisWorld(&tft);
TetrisRot tetrisRot = TetrisRot();
TetrisMove tetrisMove = TetrisMove();
Shape *shape = tetrisShape.createShape(I, GREEN, P1);

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
  tetrisRot.rotShape(shape,tetrisWorld.getWorld());
  if(!tetrisMove.moveDownShape(shape,tetrisWorld.getWorld()))
    shape = tetrisShape.createShape(I, GREEN, P1);
  tetrisMove.moveLeftShape(shape,tetrisWorld.getWorld());
  tetrisWorld.drawWorld();
  tft.fillRect(shape->pos[0].x, shape->pos[0].y, BOX_SCALE, BOX_SCALE, shape->color);
  tft.fillRect(shape->pos[1].x, shape->pos[1].y, BOX_SCALE, BOX_SCALE, shape->color);
  tft.fillRect(shape->pos[2].x, shape->pos[2].y, BOX_SCALE, BOX_SCALE, shape->color);
  tft.fillRect(shape->pos[3].x, shape->pos[3].y, BOX_SCALE, BOX_SCALE, shape->color);
  delay(2000);
}
