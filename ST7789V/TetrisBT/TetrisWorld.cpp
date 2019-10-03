#include "TetrisWorld.h"
#include "TetrisShape.h"

static Shape FRAME_SHAPE;

TetrisWorld::TetrisWorld(TFT_eSPI *tft)
{
  TetrisWorld::tft = tft;
}

void
TetrisWorld::initFrame()
{
  for(int i = 1; i <= MAX_BOX_X - 2; i++) {
    world.grid[i][0] = &FRAME_SHAPE;
    world.grid[i][11] = &FRAME_SHAPE;
    world.grid[i][22] = &FRAME_SHAPE;
  }
  for(int i = 0; i <= MAX_BOX_Y; i++)
    world.grid[0][i] = &FRAME_SHAPE;
}

void
TetrisWorld::drawWorld()
{
  for(int x = 0; x <= MAX_BOX_X - 1; x++) {
    for(int y = 0; y <= MAX_BOX_Y; y++) {
      if(world.grid[x][y])
        tft->fillRect(x * BOX_SCALE, y * BOX_SCALE, BOX_SCALE, BOX_SCALE, world.grid[x][y]->color);
      else
        tft->fillRect(x * BOX_SCALE, y * BOX_SCALE, BOX_SCALE, BOX_SCALE, BLACK);
    }
  }
}

World*
TetrisWorld::getWorld()
{
  return &world;
}
