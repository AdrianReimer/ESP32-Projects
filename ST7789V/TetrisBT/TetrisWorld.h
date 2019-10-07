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
    Shape shape;
    Shape enemyShape;
    uint32_t p1Score;
    uint32_t p2Score;
    
    uint32_t checkHorizontal();
    uint32_t checkVertical();
    void cleanWorld(uint32_t y1, uint32_t y2);
  public:
    TetrisWorld(TFT_eSPI *tft);
    void initFrame();
    void drawWorld();
    void checkWorld();
    World* getWorld();
    void setShape(Shape shape);
    Shape* getShape();
    Shape* getEnemyShape();
    void setEnemyShape(Shape shape);
};

#endif
