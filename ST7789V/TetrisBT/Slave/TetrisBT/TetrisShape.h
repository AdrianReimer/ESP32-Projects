#ifndef _TETRISBT_TETRISSHAPE_H
#define _TETRISBT_TETRISSHAPE_H

#include <TFT_eSPI.h>
#include "Tetris.h"

#define BOX_SCALE 10
#define FRAME_BOX_COLOR WHITE


typedef enum {
  P1, P2
} Player;

class TetrisShape
{
  public:
    Shape createShape(Tetromino tet, ShapeColor color, Player player);
    Shape createRndShape(Player player, uint8_t *buffer);
    ShapeColor numToColor(uint8_t num);
  private:
    void createIShape(Shape *iShape, Player player);
    void createLShape(Shape *lShape, Player player);
    void createJShape(Shape *jShape, Player player);
    void createOShape(Shape *oShape, Player player);
    void createSShape(Shape *sShape, Player player);
    void createTShape(Shape *tShape, Player player);
    void createZShape(Shape *zShape, Player player);
};

#endif
