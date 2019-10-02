#ifndef _TETRISBT_TETRISSHAPE
#define _TETRISBT_TETRISSHAPE

#include <TFT_eSPI.h>
#include "Tetris.h"

#define BOX_SCALE 10
#define FRAME_BOX_COLOR TFT_WHITE

typedef enum {
  P1, P2
} Player;

class TetrisShape
{
  public:
    Shape* createShape(Tetromino tet, unsigned int color, Player player);
    void rotShape(Shape *shape, World *world);
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
    void rotOShape(Shape *oShape, World *world);
    void rotSShape(Shape *sShape, World *world);
    void rotTShape(Shape *tShape, World *world);
    void rotZShape(Shape *zShape, World *world);
};

#endif
