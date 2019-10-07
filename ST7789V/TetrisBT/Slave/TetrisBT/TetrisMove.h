#ifndef _TETRISBT_TETRISMOVE
#define _TETRISBT_TETRISMOVE

#include "Tetris.h"


class TetrisMove {
  public:
    bool moveDownShape(Shape *shape, World *world);
    void moveLeftShape(Shape *shape, World *world);
    void moveRightShape(Shape *shape, World *world);
  private:
    bool moveDownIShape(Shape *iShape, World *world);
    bool moveDownLShape(Shape *lShape, World *world);
    bool moveDownJShape(Shape *jShape, World *world);
    bool moveDownOShape(Shape *oShape, World *world);
    bool moveDownSShape(Shape *sShape, World *world);
    bool moveDownTShape(Shape *tShape, World *world);
    bool moveDownZShape(Shape *zShape, World *world);
    bool moveLeftIShape(Shape *iShape, World *world);
    bool moveLeftLShape(Shape *lShape, World *world);
    bool moveLeftJShape(Shape *jShape, World *world);
    bool moveLeftOShape(Shape *oShape, World *world);
    bool moveLeftSShape(Shape *sShape, World *world);
    bool moveLeftTShape(Shape *tShape, World *world);
    bool moveLeftZShape(Shape *zShape, World *world);
    bool moveRightIShape(Shape *iShape, World *world);
    bool moveRightLShape(Shape *lShape, World *world);
    bool moveRightJShape(Shape *jShape, World *world);
    bool moveRightOShape(Shape *oShape, World *world);
    bool moveRightSShape(Shape *sShape, World *world);
    bool moveRightTShape(Shape *tShape, World *world);
    bool moveRightZShape(Shape *zShape, World *world);
};

#endif
