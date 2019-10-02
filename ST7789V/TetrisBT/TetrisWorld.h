#ifndef _TETRISBT_TETRISWORLD
#define _TETRISBT_TETRISWORLD

#include <TFT_eSPI.h>
#include "Tetris.h"

#define ROOT_POS_X 110
#define P1_ROOT_POS_Y 50
#define P2_ROOT_POS_Y 160

class TetrisWorld {
  private:
    TFT_eSPI *tft;
    World world;
  public:
    TetrisWorld(TFT_eSPI *tft);
    void drawFrame();
    World* getWorld();
};


#endif
