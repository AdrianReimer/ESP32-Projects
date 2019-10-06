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
    int p1Score;
    int p2Score;
    
    int checkHorizontal();
    int checkVertical();
    void cleanWorld(int y1, int y2);
    void printScore();
    void resetWorld();
  public:
    TetrisWorld(TFT_eSPI *tft);
    void initFrame();
    void drawWorld(Shape *shape);
    void checkWorld();
    World* getWorld();
    void setShape(Shape shape);
    Shape* getShape();
};

#endif
