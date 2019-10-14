#ifndef _TETRISBT_TETRISROT_H
#define _TETRISBT_TETRISROT_H

#include "Tetris.h"


class TetrisRot {
  public:
    void rotShape(Shape *shape, World *world);
  private:
    void rotIShape(Shape *iShape, World *world);
    void rotLShape(Shape *lShape, World *world);
    void rotJShape(Shape *jShape, World *world);
    void rotSShape(Shape *sShape, World *world);
    void rotTShape(Shape *tShape, World *world);
    void rotZShape(Shape *zShape, World *world);
};

#endif
