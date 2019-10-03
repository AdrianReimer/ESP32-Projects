#ifndef _TETRISBT_TETRISSHAPE
#define _TETRISBT_TETRISSHAPE

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
    Shape* createShape(Tetromino tet, ShapeColor color, Player player);
    void rotShape(Shape *shape, World *world);
    bool moveDownShape(Shape *shape, World *world);
  private:
    void createIShape(Shape *iShape, Player player);
    void createLShape(Shape *lShape, Player player);
    void createJShape(Shape *jShape, Player player);
    void createOShape(Shape *oShape, Player player);
    void createSShape(Shape *sShape, Player player);
    void createTShape(Shape *tShape, Player player);
    void createZShape(Shape *zShape, Player player);
    void rotIShape(Shape *iShape, World *world);
    void rotLShape(Shape *lShape, World *world);
    void rotJShape(Shape *jShape, World *world);
    void rotSShape(Shape *sShape, World *world);
    void rotTShape(Shape *tShape, World *world);
    void rotZShape(Shape *zShape, World *world);
    bool moveDownIShape(Shape *iShape, World *world);
    bool moveDownLShape(Shape *lShape, World *world);
    bool moveDownJShape(Shape *jShape, World *world);
    bool moveDownOShape(Shape *oShape, World *world);
    bool moveDownSShape(Shape *sShape, World *world);
    bool moveDownTShape(Shape *tShape, World *world);
    bool moveDownZShape(Shape *zShape, World *world);
};

#endif
