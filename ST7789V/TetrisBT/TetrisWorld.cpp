#include "TetrisWorld.h"
#include "TetrisShape.h"

static Shape FRAME_SHAPE;

TetrisWorld::TetrisWorld(TFT_eSPI *tft)
{
  TetrisWorld::tft = tft;
}

void
TetrisWorld::drawFrame()
{
  for(int i = 1; i <= MAX_BOX_X - 4; i++) {
    tft->fillRect(i * BOX_SCALE, 0, BOX_SCALE, BOX_SCALE, FRAME_BOX_COLOR);
    world.grid[i][0] = &FRAME_SHAPE;
    tft->fillRect(i * BOX_SCALE, 110, BOX_SCALE, BOX_SCALE, FRAME_BOX_COLOR);
    world.grid[i][11] = &FRAME_SHAPE;
    tft->fillRect(i * BOX_SCALE, 220, BOX_SCALE, BOX_SCALE, FRAME_BOX_COLOR);
    world.grid[i][22] = &FRAME_SHAPE;
  }
  for(int i = 0; i <= MAX_BOX_Y; i++) {
    tft->fillRect(0, i * BOX_SCALE, BOX_SCALE, BOX_SCALE, FRAME_BOX_COLOR);
    world.grid[0][i] = &FRAME_SHAPE;
  }
}

World*
TetrisWorld::getWorld()
{
  return &world;
}
