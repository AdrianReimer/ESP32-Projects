#include "TetrisShape.h"
#include "TetrisWorld.h"


Shape*
TetrisShape::createShape(Tetromino tet, ShapeColor color, Player player)
{
  Shape *shape = (Shape *)malloc(sizeof(Shape));;
  shape->tet = tet;
  shape->color = color;
  shape->shapeRot = deg0;
  switch(tet) {
    case I:
      createIShape(shape, player);
      break;
    case L:
      createLShape(shape, player);
      break;
    case J:
      createJShape(shape, player);
      break;
    case O:
      createOShape(shape, player);
      break;
    case S:
      createSShape(shape, player);
      break;
    case T:
      createTShape(shape, player);
      break;
    case Z:
      createZShape(shape, player);
      break;
  }
  return shape;
}

inline void
TetrisShape::createIShape(Shape *iShape, Player player)
{
  if(player == P1) {
    iShape->pos[0].x = ROOT_POS_X;
    iShape->pos[0].y = P1_ROOT_POS_Y;
    iShape->pos[1].x = ROOT_POS_X;
    iShape->pos[1].y = P1_ROOT_POS_Y - BOX_SCALE;
    iShape->pos[2].x = ROOT_POS_X;
    iShape->pos[2].y = P1_ROOT_POS_Y + BOX_SCALE;
    iShape->pos[3].x = ROOT_POS_X;
    iShape->pos[3].y = P1_ROOT_POS_Y + BOX_SCALE * 2;
  } else {
    iShape->pos[0].x = ROOT_POS_X;
    iShape->pos[0].y = P2_ROOT_POS_Y;
    iShape->pos[1].x = ROOT_POS_X;
    iShape->pos[1].y = P2_ROOT_POS_Y - BOX_SCALE;
    iShape->pos[2].x = ROOT_POS_X;
    iShape->pos[2].y = P2_ROOT_POS_Y + BOX_SCALE;
    iShape->pos[3].x = ROOT_POS_X;
    iShape->pos[3].y = P2_ROOT_POS_Y + BOX_SCALE * 2;
  }
}

inline void
TetrisShape::createLShape(Shape *lShape, Player player)
{
  if(player == P1) {
    lShape->pos[0].x = ROOT_POS_X;
    lShape->pos[0].y = P1_ROOT_POS_Y;
    lShape->pos[1].x = ROOT_POS_X;
    lShape->pos[1].y = P1_ROOT_POS_Y - BOX_SCALE;
    lShape->pos[2].x = ROOT_POS_X + BOX_SCALE;
    lShape->pos[2].y = P1_ROOT_POS_Y - BOX_SCALE;
    lShape->pos[3].x = ROOT_POS_X;
    lShape->pos[3].y = P1_ROOT_POS_Y + BOX_SCALE;
  } else {
    lShape->pos[0].x = ROOT_POS_X;
    lShape->pos[0].y = P2_ROOT_POS_Y;
    lShape->pos[1].x = ROOT_POS_X;
    lShape->pos[1].y = P2_ROOT_POS_Y - BOX_SCALE;
    lShape->pos[2].x = ROOT_POS_X + BOX_SCALE;
    lShape->pos[2].y = P2_ROOT_POS_Y - BOX_SCALE;
    lShape->pos[3].x = ROOT_POS_X;
    lShape->pos[3].y = P2_ROOT_POS_Y + BOX_SCALE;
  }
}

inline void
TetrisShape::createJShape(Shape *jShape, Player player)
{
  if(player == P1) {
    jShape->pos[0].x = ROOT_POS_X;
    jShape->pos[0].y = P1_ROOT_POS_Y;
    jShape->pos[1].x = ROOT_POS_X;
    jShape->pos[1].y = P1_ROOT_POS_Y + BOX_SCALE;
    jShape->pos[2].x = ROOT_POS_X + BOX_SCALE;
    jShape->pos[2].y = P1_ROOT_POS_Y + BOX_SCALE;
    jShape->pos[3].x = ROOT_POS_X;
    jShape->pos[3].y = P1_ROOT_POS_Y - BOX_SCALE;
  } else {
    jShape->pos[0].x = ROOT_POS_X;
    jShape->pos[0].y = P2_ROOT_POS_Y;
    jShape->pos[1].x = ROOT_POS_X;
    jShape->pos[1].y = P2_ROOT_POS_Y + BOX_SCALE;
    jShape->pos[2].x = ROOT_POS_X + BOX_SCALE;
    jShape->pos[2].y = P2_ROOT_POS_Y + BOX_SCALE;
    jShape->pos[3].x = ROOT_POS_X;
    jShape->pos[3].y = P2_ROOT_POS_Y - BOX_SCALE;
  }
}

inline void
TetrisShape::createOShape(Shape *oShape, Player player)
{
  if(player == P1) {
    oShape->pos[0].x = ROOT_POS_X;
    oShape->pos[0].y = P1_ROOT_POS_Y;
    oShape->pos[1].x = ROOT_POS_X + BOX_SCALE;
    oShape->pos[1].y = P1_ROOT_POS_Y;
    oShape->pos[2].x = ROOT_POS_X;
    oShape->pos[2].y = P1_ROOT_POS_Y + BOX_SCALE;
    oShape->pos[3].x = ROOT_POS_X + BOX_SCALE;
    oShape->pos[3].y = P1_ROOT_POS_Y + BOX_SCALE;
  } else {
    oShape->pos[0].x = ROOT_POS_X;
    oShape->pos[0].y = P2_ROOT_POS_Y;
    oShape->pos[1].x = ROOT_POS_X + BOX_SCALE;
    oShape->pos[1].y = P2_ROOT_POS_Y;
    oShape->pos[2].x = ROOT_POS_X;
    oShape->pos[2].y = P2_ROOT_POS_Y + BOX_SCALE;
    oShape->pos[3].x = ROOT_POS_X + BOX_SCALE;
    oShape->pos[3].y = P2_ROOT_POS_Y + BOX_SCALE;
  }
}

inline void
TetrisShape::createSShape(Shape *sShape, Player player)
{
  if(player == P1) {
    sShape->pos[0].x = ROOT_POS_X;
    sShape->pos[0].y = P1_ROOT_POS_Y;
    sShape->pos[1].x = ROOT_POS_X;
    sShape->pos[1].y = P1_ROOT_POS_Y - BOX_SCALE;
    sShape->pos[2].x = ROOT_POS_X + BOX_SCALE;
    sShape->pos[2].y = P1_ROOT_POS_Y;
    sShape->pos[3].x = ROOT_POS_X + BOX_SCALE;
    sShape->pos[3].y = P1_ROOT_POS_Y + BOX_SCALE;
  } else {
    sShape->pos[0].x = ROOT_POS_X;
    sShape->pos[0].y = P2_ROOT_POS_Y;
    sShape->pos[1].x = ROOT_POS_X;
    sShape->pos[1].y = P2_ROOT_POS_Y - BOX_SCALE;
    sShape->pos[2].x = ROOT_POS_X + BOX_SCALE;
    sShape->pos[2].y = P2_ROOT_POS_Y;
    sShape->pos[3].x = ROOT_POS_X + BOX_SCALE;
    sShape->pos[3].y = P2_ROOT_POS_Y + BOX_SCALE;
  }
}

inline void
TetrisShape::createTShape(Shape *tShape, Player player)
{
  if(player == P1) {
    tShape->pos[0].x = ROOT_POS_X;
    tShape->pos[0].y = P1_ROOT_POS_Y;
    tShape->pos[1].x = ROOT_POS_X;
    tShape->pos[1].y = P1_ROOT_POS_Y - BOX_SCALE;
    tShape->pos[2].x = ROOT_POS_X + BOX_SCALE;
    tShape->pos[2].y = P1_ROOT_POS_Y;
    tShape->pos[3].x = ROOT_POS_X;
    tShape->pos[3].y = P1_ROOT_POS_Y + BOX_SCALE;
  } else {
    tShape->pos[0].x = ROOT_POS_X;
    tShape->pos[0].y = P2_ROOT_POS_Y;
    tShape->pos[1].x = ROOT_POS_X;
    tShape->pos[1].y = P2_ROOT_POS_Y - BOX_SCALE;
    tShape->pos[2].x = ROOT_POS_X + BOX_SCALE;
    tShape->pos[2].y = P2_ROOT_POS_Y;
    tShape->pos[3].x = ROOT_POS_X;
    tShape->pos[3].y = P2_ROOT_POS_Y + BOX_SCALE;
  }
}

inline void
TetrisShape::createZShape(Shape *zShape, Player player)
{
  if(player == P1) {
    zShape->pos[0].x = ROOT_POS_X;
    zShape->pos[0].y = P1_ROOT_POS_Y;
    zShape->pos[1].x = ROOT_POS_X + BOX_SCALE;
    zShape->pos[1].y = P1_ROOT_POS_Y;
    zShape->pos[2].x = ROOT_POS_X + BOX_SCALE;
    zShape->pos[2].y = P1_ROOT_POS_Y - BOX_SCALE;
    zShape->pos[3].x = ROOT_POS_X;
    zShape->pos[3].y = P1_ROOT_POS_Y + BOX_SCALE;
  } else {
    zShape->pos[0].x = ROOT_POS_X;
    zShape->pos[0].y = P2_ROOT_POS_Y;
    zShape->pos[1].x = ROOT_POS_X + BOX_SCALE;
    zShape->pos[1].y = P2_ROOT_POS_Y;
    zShape->pos[2].x = ROOT_POS_X + BOX_SCALE;
    zShape->pos[2].y = P2_ROOT_POS_Y - BOX_SCALE;
    zShape->pos[3].x = ROOT_POS_X;
    zShape->pos[3].y = P2_ROOT_POS_Y + BOX_SCALE;
  }
}
