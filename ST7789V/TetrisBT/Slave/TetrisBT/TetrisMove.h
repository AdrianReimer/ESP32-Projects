#ifndef _TETRISBT_TETRISMOVE_H
#define _TETRISBT_TETRISMOVE_H

#include "Tetris.h"


class TetrisMove {
  public:
    bool moveDownShape(Shape *shape, World *world);
    void moveLeftShape(Shape *shape, World *world);
    void moveRightShape(Shape *shape, World *world);
};

#endif
