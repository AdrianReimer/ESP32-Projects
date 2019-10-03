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

void
TetrisShape::rotShape(Shape *shape,
                      World *world)
{
  switch(shape->tet) {
    case I:
      rotIShape(shape, world);
      break;
    case J:
      rotJShape(shape, world);
      break;
    case L:
      rotLShape(shape, world);
      break;
    case S:
      rotSShape(shape, world);
      break;
    case T:
      rotTShape(shape, world);
      break;
    case Z:
      rotZShape(shape, world);
      break;
  }
}

void
TetrisShape::rotIShape(Shape *iShape,
                       World *world)
{
  switch(iShape->shapeRot)
  {
    case deg0:
      if(!world->grid[iShape->pos[1].x / BOX_SCALE + 1][iShape->pos[1].y / BOX_SCALE + 1] &&
         !world->grid[iShape->pos[2].x / BOX_SCALE - 1][iShape->pos[2].y / BOX_SCALE - 1] &&
         !world->grid[iShape->pos[3].x / BOX_SCALE - 2][iShape->pos[3].y / BOX_SCALE - 2])
           {
             iShape->shapeRot = deg90;
             iShape->pos[1].x += BOX_SCALE;
             iShape->pos[1].y += BOX_SCALE;
             iShape->pos[2].x -= BOX_SCALE;
             iShape->pos[2].y -= BOX_SCALE;
             iShape->pos[3].x -= BOX_SCALE * 2;
             iShape->pos[3].y -= BOX_SCALE * 2;
      }
      break;
    case deg90:
      if(!world->grid[iShape->pos[1].x / BOX_SCALE - 1][iShape->pos[1].y / BOX_SCALE + 1] &&
         !world->grid[iShape->pos[2].x / BOX_SCALE + 1][iShape->pos[2].y / BOX_SCALE - 1] &&
         !world->grid[iShape->pos[3].x / BOX_SCALE + 2][iShape->pos[3].y / BOX_SCALE - 2])
           {
             iShape->shapeRot = deg180;
             iShape->pos[1].x -= BOX_SCALE;
             iShape->pos[1].y += BOX_SCALE;
             iShape->pos[2].x += BOX_SCALE;
             iShape->pos[2].y -= BOX_SCALE;
             iShape->pos[3].x += BOX_SCALE * 2;
             iShape->pos[3].y -= BOX_SCALE * 2;
      }
      break;
    case deg180:
      if(!world->grid[iShape->pos[1].x / BOX_SCALE - 1][iShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[iShape->pos[2].x / BOX_SCALE + 1][iShape->pos[2].y / BOX_SCALE + 1] &&
         !world->grid[iShape->pos[3].x / BOX_SCALE + 2][iShape->pos[3].y / BOX_SCALE + 2])
           {
             iShape->shapeRot = deg270;
             iShape->pos[1].x -= BOX_SCALE;
             iShape->pos[1].y -= BOX_SCALE;
             iShape->pos[2].x += BOX_SCALE;
             iShape->pos[2].y += BOX_SCALE;
             iShape->pos[3].x += BOX_SCALE * 2;
             iShape->pos[3].y += BOX_SCALE * 2;
      }
      break;
    case deg270:
      if(!world->grid[iShape->pos[1].x / BOX_SCALE + 1][iShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[iShape->pos[2].x / BOX_SCALE - 1][iShape->pos[2].y / BOX_SCALE + 1] &&
         !world->grid[iShape->pos[3].x / BOX_SCALE - 2][iShape->pos[3].y / BOX_SCALE + 2])
           {
             iShape->shapeRot = deg0;
             iShape->pos[1].x += BOX_SCALE;
             iShape->pos[1].y -= BOX_SCALE;
             iShape->pos[2].x -= BOX_SCALE;
             iShape->pos[2].y += BOX_SCALE;
             iShape->pos[3].x -= BOX_SCALE * 2;
             iShape->pos[3].y += BOX_SCALE * 2;
      }
      break;
  }
}

void
TetrisShape::rotLShape(Shape *lShape,
                       World *world)
{
  switch(lShape->shapeRot)
  {
    case deg0:
      if(!world->grid[lShape->pos[1].x / BOX_SCALE + 1][lShape->pos[1].y / BOX_SCALE + 1] &&
         !world->grid[lShape->pos[2].x / BOX_SCALE][lShape->pos[2].y / BOX_SCALE + 2] &&
         !world->grid[lShape->pos[3].x / BOX_SCALE - 1][lShape->pos[3].y / BOX_SCALE - 1])
           {
             lShape->shapeRot = deg90;
             lShape->pos[1].x += BOX_SCALE;
             lShape->pos[1].y += BOX_SCALE;
             lShape->pos[2].y += BOX_SCALE * 2;
             lShape->pos[3].x -= BOX_SCALE;
             lShape->pos[3].y -= BOX_SCALE;
      }
      break;
    case deg90:
      if(!world->grid[lShape->pos[1].x / BOX_SCALE - 1][lShape->pos[1].y / BOX_SCALE + 1] &&
         !world->grid[lShape->pos[2].x / BOX_SCALE - 2][lShape->pos[2].y / BOX_SCALE] &&
         !world->grid[lShape->pos[3].x / BOX_SCALE + 1][lShape->pos[3].y / BOX_SCALE - 1])
           {
             lShape->shapeRot = deg180;
             lShape->pos[1].x -= BOX_SCALE;
             lShape->pos[1].y += BOX_SCALE;
             lShape->pos[2].x -= BOX_SCALE * 2;
             lShape->pos[3].x += BOX_SCALE;
             lShape->pos[3].y -= BOX_SCALE;
      }
      break;
    case deg180:
      if(!world->grid[lShape->pos[1].x / BOX_SCALE - 1][lShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[lShape->pos[2].x / BOX_SCALE][lShape->pos[2].y / BOX_SCALE - 2] &&
         !world->grid[lShape->pos[3].x / BOX_SCALE + 1][lShape->pos[3].y / BOX_SCALE + 1])
           {
             lShape->shapeRot = deg270;
             lShape->pos[1].x -= BOX_SCALE;
             lShape->pos[1].y -= BOX_SCALE;
             lShape->pos[2].y -= BOX_SCALE * 2;
             lShape->pos[3].x += BOX_SCALE;
             lShape->pos[3].y += BOX_SCALE;
      }
      break;
    case deg270:
      if(!world->grid[lShape->pos[1].x / BOX_SCALE + 1][lShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[lShape->pos[2].x / BOX_SCALE + 2][lShape->pos[2].y / BOX_SCALE] &&
         !world->grid[lShape->pos[3].x / BOX_SCALE - 1][lShape->pos[3].y / BOX_SCALE + 1])
           {
             lShape->shapeRot = deg0;
             lShape->pos[1].x += BOX_SCALE;
             lShape->pos[1].y -= BOX_SCALE;
             lShape->pos[2].x += BOX_SCALE * 2;
             lShape->pos[3].x -= BOX_SCALE;
             lShape->pos[3].y += BOX_SCALE;
      }
      break;
  }
}
    
void
TetrisShape::rotJShape(Shape *jShape,
                       World *world)
{
  switch(jShape->shapeRot)
  {
    case deg0:
      if(!world->grid[jShape->pos[1].x / BOX_SCALE - 1][jShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[jShape->pos[2].x / BOX_SCALE - 2][jShape->pos[2].y / BOX_SCALE] &&
         !world->grid[jShape->pos[3].x / BOX_SCALE + 1][jShape->pos[3].y / BOX_SCALE + 1])
           {
             jShape->shapeRot = deg90;
             jShape->pos[1].x -= BOX_SCALE;
             jShape->pos[1].y -= BOX_SCALE;
             jShape->pos[2].x -= BOX_SCALE * 2;
             jShape->pos[3].x += BOX_SCALE;
             jShape->pos[3].y += BOX_SCALE;
      }
      break;
    case deg90:
      if(!world->grid[jShape->pos[1].x / BOX_SCALE + 1][jShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[jShape->pos[2].x / BOX_SCALE][jShape->pos[2].y / BOX_SCALE - 2] &&
         !world->grid[jShape->pos[3].x / BOX_SCALE - 1][jShape->pos[3].y / BOX_SCALE + 1])
           {
             jShape->shapeRot = deg180;
             jShape->pos[1].x += BOX_SCALE;
             jShape->pos[1].y -= BOX_SCALE;
             jShape->pos[2].y -= BOX_SCALE * 2;
             jShape->pos[3].x -= BOX_SCALE;
             jShape->pos[3].y += BOX_SCALE;
      }
      break;
    case deg180:
      if(!world->grid[jShape->pos[1].x / BOX_SCALE + 1][jShape->pos[1].y / BOX_SCALE + 1] &&
         !world->grid[jShape->pos[2].x / BOX_SCALE + 2][jShape->pos[2].y / BOX_SCALE] &&
         !world->grid[jShape->pos[3].x / BOX_SCALE - 1][jShape->pos[3].y / BOX_SCALE - 1])
           {
             jShape->shapeRot = deg270;
             jShape->pos[1].x += BOX_SCALE;
             jShape->pos[1].y += BOX_SCALE;
             jShape->pos[2].x += BOX_SCALE * 2;
             jShape->pos[3].x -= BOX_SCALE;
             jShape->pos[3].y -= BOX_SCALE;
      }
      break;
    case deg270:
      if(!world->grid[jShape->pos[1].x / BOX_SCALE - 1][jShape->pos[1].y / BOX_SCALE + 1] &&
         !world->grid[jShape->pos[2].x / BOX_SCALE][jShape->pos[2].y / BOX_SCALE + 2] &&
         !world->grid[jShape->pos[3].x / BOX_SCALE + 1][jShape->pos[3].y / BOX_SCALE - 1])
           {
             jShape->shapeRot = deg0;
             jShape->pos[1].x -= BOX_SCALE;
             jShape->pos[1].y += BOX_SCALE;
             jShape->pos[2].y += BOX_SCALE * 2;
             jShape->pos[3].x += BOX_SCALE;
             jShape->pos[3].y -= BOX_SCALE;
      }
      break;
  }
}

void
TetrisShape::rotSShape(Shape *sShape,
                       World *world)
{
    switch(sShape->shapeRot)
  {
    case deg0:
      if(!world->grid[sShape->pos[1].x / BOX_SCALE + 1][sShape->pos[1].y / BOX_SCALE + 1] &&
         !world->grid[sShape->pos[2].x / BOX_SCALE - 1][sShape->pos[2].y / BOX_SCALE + 1] &&
         !world->grid[sShape->pos[3].x / BOX_SCALE - 2][sShape->pos[3].y / BOX_SCALE])
           {
             sShape->shapeRot = deg90;
             sShape->pos[1].x += BOX_SCALE;
             sShape->pos[1].y += BOX_SCALE;
             sShape->pos[2].x -= BOX_SCALE;
             sShape->pos[2].y += BOX_SCALE;
             sShape->pos[3].x -= BOX_SCALE * 2;
      }
      break;
    case deg90:
      if(!world->grid[sShape->pos[1].x / BOX_SCALE - 1][sShape->pos[1].y / BOX_SCALE + 1] &&
         !world->grid[sShape->pos[2].x / BOX_SCALE - 1][sShape->pos[2].y / BOX_SCALE - 1] &&
         !world->grid[sShape->pos[3].x / BOX_SCALE][sShape->pos[3].y / BOX_SCALE - 2])
           {
             sShape->shapeRot = deg180;
             sShape->pos[1].x -= BOX_SCALE;
             sShape->pos[1].y += BOX_SCALE;
             sShape->pos[2].x -= BOX_SCALE;
             sShape->pos[2].y -= BOX_SCALE;
             sShape->pos[3].y -= BOX_SCALE * 2;
      }
      break;
    case deg180:
      if(!world->grid[sShape->pos[1].x / BOX_SCALE - 1][sShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[sShape->pos[2].x / BOX_SCALE + 1][sShape->pos[2].y / BOX_SCALE - 1] &&
         !world->grid[sShape->pos[3].x / BOX_SCALE + 2][sShape->pos[3].y / BOX_SCALE])
           {
             sShape->shapeRot = deg270;
             sShape->pos[1].x -= BOX_SCALE;
             sShape->pos[1].y -= BOX_SCALE;
             sShape->pos[2].x += BOX_SCALE;
             sShape->pos[2].y -= BOX_SCALE;
             sShape->pos[3].x += BOX_SCALE * 2;
      }
      break;
    case deg270:
      if(!world->grid[sShape->pos[1].x / BOX_SCALE + 1][sShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[sShape->pos[2].x / BOX_SCALE + 1][sShape->pos[2].y / BOX_SCALE + 1] &&
         !world->grid[sShape->pos[3].x / BOX_SCALE][sShape->pos[3].y / BOX_SCALE + 2])
           {
             sShape->shapeRot = deg0;
             sShape->pos[1].x += BOX_SCALE;
             sShape->pos[1].y -= BOX_SCALE;
             sShape->pos[2].x += BOX_SCALE;
             sShape->pos[2].y += BOX_SCALE;
             sShape->pos[3].y += BOX_SCALE * 2;
      }
      break;
  }
}

void
TetrisShape::rotTShape(Shape *tShape,
                       World *world)
{
  switch(tShape->shapeRot)
  {
    case deg0:
      if(!world->grid[tShape->pos[1].x / BOX_SCALE + 1][tShape->pos[1].y / BOX_SCALE + 1] &&
         !world->grid[tShape->pos[2].x / BOX_SCALE - 1][tShape->pos[2].y / BOX_SCALE + 1] &&
         !world->grid[tShape->pos[3].x / BOX_SCALE - 1][tShape->pos[3].y / BOX_SCALE - 1])
           {
             tShape->shapeRot = deg90;
             tShape->pos[1].x += BOX_SCALE;
             tShape->pos[1].y += BOX_SCALE;
             tShape->pos[2].x -= BOX_SCALE;
             tShape->pos[2].y += BOX_SCALE;
             tShape->pos[3].x -= BOX_SCALE;
             tShape->pos[3].y -= BOX_SCALE;
      }
      break;
    case deg90:
      if(!world->grid[tShape->pos[1].x / BOX_SCALE - 1][tShape->pos[1].y / BOX_SCALE + 1] &&
         !world->grid[tShape->pos[2].x / BOX_SCALE - 1][tShape->pos[2].y / BOX_SCALE - 1] &&
         !world->grid[tShape->pos[3].x / BOX_SCALE + 1][tShape->pos[3].y / BOX_SCALE - 1])
           {
             tShape->shapeRot = deg180;
             tShape->pos[1].x -= BOX_SCALE;
             tShape->pos[1].y += BOX_SCALE;
             tShape->pos[2].x -= BOX_SCALE;
             tShape->pos[2].y -= BOX_SCALE;
             tShape->pos[3].x += BOX_SCALE;
             tShape->pos[3].y -= BOX_SCALE;
      }
      break;
    case deg180:
      if(!world->grid[tShape->pos[1].x / BOX_SCALE - 1][tShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[tShape->pos[2].x / BOX_SCALE + 1][tShape->pos[2].y / BOX_SCALE - 1] &&
         !world->grid[tShape->pos[3].x / BOX_SCALE + 1][tShape->pos[3].y / BOX_SCALE + 1])
           {
             tShape->shapeRot = deg270;
             tShape->pos[1].x -= BOX_SCALE;
             tShape->pos[1].y -= BOX_SCALE;
             tShape->pos[2].x += BOX_SCALE;
             tShape->pos[2].y -= BOX_SCALE;
             tShape->pos[3].x += BOX_SCALE;
             tShape->pos[3].y += BOX_SCALE;
      }
      break;
    case deg270:
      if(!world->grid[tShape->pos[1].x / BOX_SCALE + 1][tShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[tShape->pos[2].x / BOX_SCALE + 1][tShape->pos[2].y / BOX_SCALE + 1] &&
         !world->grid[tShape->pos[3].x / BOX_SCALE - 1][tShape->pos[3].y / BOX_SCALE + 1])
           {
             tShape->shapeRot = deg0;
             tShape->pos[1].x += BOX_SCALE;
             tShape->pos[1].y -= BOX_SCALE;
             tShape->pos[2].x += BOX_SCALE;
             tShape->pos[2].y += BOX_SCALE;
             tShape->pos[3].x -= BOX_SCALE;
             tShape->pos[3].y += BOX_SCALE;
      }
      break;
  }
}

void
TetrisShape::rotZShape(Shape *zShape,
                       World *world)
{
  switch(zShape->shapeRot)
  {
    case deg0:
      if(!world->grid[zShape->pos[1].x / BOX_SCALE - 1][zShape->pos[1].y / BOX_SCALE + 1] &&
         !world->grid[zShape->pos[2].x / BOX_SCALE][zShape->pos[2].y / BOX_SCALE + 2] &&
         !world->grid[zShape->pos[3].x / BOX_SCALE - 1][zShape->pos[3].y / BOX_SCALE - 1])
           {
             zShape->shapeRot = deg90;
             zShape->pos[1].x -= BOX_SCALE;
             zShape->pos[1].y += BOX_SCALE;
             zShape->pos[2].y += BOX_SCALE * 2;
             zShape->pos[3].x -= BOX_SCALE;
             zShape->pos[3].y -= BOX_SCALE;
      }
      break;
    case deg90:
      if(!world->grid[zShape->pos[1].x / BOX_SCALE - 1][zShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[zShape->pos[2].x / BOX_SCALE - 2][zShape->pos[2].y / BOX_SCALE] &&
         !world->grid[zShape->pos[3].x / BOX_SCALE + 1][zShape->pos[3].y / BOX_SCALE - 1])
           {
             zShape->shapeRot = deg180;
             zShape->pos[1].x -= BOX_SCALE;
             zShape->pos[1].y -= BOX_SCALE;
             zShape->pos[2].x -= BOX_SCALE * 2;
             zShape->pos[3].x += BOX_SCALE;
             zShape->pos[3].y -= BOX_SCALE;
      }
      break;
    case deg180:
      if(!world->grid[zShape->pos[1].x / BOX_SCALE + 1][zShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[zShape->pos[2].x / BOX_SCALE][zShape->pos[2].y / BOX_SCALE - 2] &&
         !world->grid[zShape->pos[3].x / BOX_SCALE + 1][zShape->pos[3].y / BOX_SCALE + 1])
           {
             zShape->shapeRot = deg270;
             zShape->pos[1].x += BOX_SCALE;
             zShape->pos[1].y -= BOX_SCALE;
             zShape->pos[2].y -= BOX_SCALE * 2;
             zShape->pos[3].x += BOX_SCALE;
             zShape->pos[3].y += BOX_SCALE;
      }
      break;
    case deg270:
      if(!world->grid[zShape->pos[1].x / BOX_SCALE + 1][zShape->pos[1].y / BOX_SCALE + 1] &&
         !world->grid[zShape->pos[2].x / BOX_SCALE + 2][zShape->pos[2].y / BOX_SCALE] &&
         !world->grid[zShape->pos[3].x / BOX_SCALE - 1][zShape->pos[3].y / BOX_SCALE + 1])
           {
             zShape->shapeRot = deg0;
             zShape->pos[1].x += BOX_SCALE;
             zShape->pos[1].y += BOX_SCALE;
             zShape->pos[2].x += BOX_SCALE * 2;
             zShape->pos[3].x -= BOX_SCALE;
             zShape->pos[3].y += BOX_SCALE;
      }
      break;
  }
}

bool
TetrisShape::moveDownShape(Shape *shape, World *world)
{
  bool canMove = false;
  switch(shape->tet) {
    case I:
      canMove = moveDownIShape(shape, world);
      break;
    case J:
      canMove = moveDownJShape(shape, world);
      break;
    case L:
      canMove = moveDownLShape(shape, world);
      break;
    case O:
      canMove = moveDownOShape(shape, world);
      break;
    case S:
      canMove = moveDownSShape(shape, world);
      break;
    case T:
      canMove = moveDownTShape(shape, world);
      break;
    case Z:
      canMove = moveDownZShape(shape, world);
      break;
  }
  if(canMove) {
    shape->pos[0].x -= BOX_SCALE;
    shape->pos[1].x -= BOX_SCALE;
    shape->pos[2].x -= BOX_SCALE;
    shape->pos[3].x -= BOX_SCALE;
  } else {
    world->grid[shape->pos[0].x / BOX_SCALE][shape->pos[0].y / BOX_SCALE] = shape;
    world->grid[shape->pos[1].x / BOX_SCALE][shape->pos[1].y / BOX_SCALE] = shape;
    world->grid[shape->pos[2].x / BOX_SCALE][shape->pos[2].y / BOX_SCALE] = shape;
    world->grid[shape->pos[3].x / BOX_SCALE][shape->pos[3].y / BOX_SCALE] = shape;
  }
  return canMove;
}

bool
TetrisShape::moveDownIShape(Shape *iShape, World *world)
{
  bool canMove = false;
  switch(iShape->shapeRot)
  {
    case deg180:
    case deg0:
      if(!world->grid[iShape->pos[0].x / BOX_SCALE - 1][iShape->pos[0].y / BOX_SCALE] &&
         !world->grid[iShape->pos[1].x / BOX_SCALE - 1][iShape->pos[1].y / BOX_SCALE] &&
         !world->grid[iShape->pos[2].x / BOX_SCALE - 1][iShape->pos[2].y / BOX_SCALE] &&
         !world->grid[iShape->pos[3].x / BOX_SCALE - 1][iShape->pos[3].y / BOX_SCALE])
             canMove = true;
      break;
    case deg90:
      if(!world->grid[iShape->pos[3].x / BOX_SCALE - 1][iShape->pos[3].y / BOX_SCALE])
             canMove = true;
      break;
    case deg270:
      if(!world->grid[iShape->pos[1].x / BOX_SCALE - 1][iShape->pos[1].y / BOX_SCALE])
             canMove = true;
      break;
  }
  return canMove;
}

bool
TetrisShape::moveDownLShape(Shape *lShape, World *world)
{
  bool canMove = false;
  switch(lShape->shapeRot)
  {
    case deg0:
      if(!world->grid[lShape->pos[0].x / BOX_SCALE - 1][lShape->pos[0].y / BOX_SCALE] &&
         !world->grid[lShape->pos[1].x / BOX_SCALE - 1][lShape->pos[1].y / BOX_SCALE] &&
         !world->grid[lShape->pos[3].x / BOX_SCALE - 1][lShape->pos[3].y / BOX_SCALE])
             canMove = true;
      break;
    case deg90:
      if(!world->grid[lShape->pos[2].x / BOX_SCALE - 1][lShape->pos[2].y / BOX_SCALE] &&
         !world->grid[lShape->pos[3].x / BOX_SCALE - 1][lShape->pos[3].y / BOX_SCALE])
             canMove = true;
      break;
    case deg180:
      if(!world->grid[lShape->pos[0].x / BOX_SCALE - 1][lShape->pos[0].y / BOX_SCALE] &&
         !world->grid[lShape->pos[2].x / BOX_SCALE - 1][lShape->pos[2].y / BOX_SCALE] &&
         !world->grid[lShape->pos[3].x / BOX_SCALE - 1][lShape->pos[3].y / BOX_SCALE])
             canMove = true;
      break;
    case deg270:
      if(!world->grid[lShape->pos[1].x / BOX_SCALE - 1][lShape->pos[1].y / BOX_SCALE] &&
         !world->grid[lShape->pos[2].x / BOX_SCALE - 1][lShape->pos[2].y / BOX_SCALE])
             canMove = true;
      break;
  }
  return canMove;
}

bool
TetrisShape::moveDownJShape(Shape *jShape, World *world)
{
  bool canMove = false;
  switch(jShape->shapeRot)
  {
    case deg0:
      if(!world->grid[jShape->pos[0].x / BOX_SCALE - 1][jShape->pos[0].y / BOX_SCALE] &&
         !world->grid[jShape->pos[1].x / BOX_SCALE - 1][jShape->pos[1].y / BOX_SCALE] &&
         !world->grid[jShape->pos[3].x / BOX_SCALE - 1][jShape->pos[3].y / BOX_SCALE])
             canMove = true;
      break;
    case deg90:
      if(!world->grid[jShape->pos[1].x / BOX_SCALE - 1][jShape->pos[1].y / BOX_SCALE] &&
         !world->grid[jShape->pos[2].x / BOX_SCALE - 1][jShape->pos[2].y / BOX_SCALE])
             canMove = true;
      break;
    case deg180:
      if(!world->grid[jShape->pos[0].x / BOX_SCALE - 1][jShape->pos[0].y / BOX_SCALE] &&
         !world->grid[jShape->pos[2].x / BOX_SCALE - 1][jShape->pos[2].y / BOX_SCALE] &&
         !world->grid[jShape->pos[3].x / BOX_SCALE - 1][jShape->pos[3].y / BOX_SCALE])
             canMove = true;
      break;
    case deg270:
      if(!world->grid[jShape->pos[2].x / BOX_SCALE - 1][jShape->pos[2].y / BOX_SCALE] &&
         !world->grid[jShape->pos[3].x / BOX_SCALE - 1][jShape->pos[3].y / BOX_SCALE])
             canMove = true;
      break;
  }
  return canMove;
}

bool
TetrisShape::moveDownOShape(Shape *oShape, World *world)
{
  bool canMove = false;
  if(!world->grid[oShape->pos[0].x / BOX_SCALE - 1][oShape->pos[0].y / BOX_SCALE] &&
     !world->grid[oShape->pos[2].x / BOX_SCALE - 1][oShape->pos[2].y / BOX_SCALE])
         canMove = true;
  return canMove;
}

bool
TetrisShape::moveDownSShape(Shape *sShape, World *world)
{
  bool canMove = false;
  switch(sShape->shapeRot)
  {
    case deg0:
      if(!world->grid[sShape->pos[0].x / BOX_SCALE - 1][sShape->pos[0].y / BOX_SCALE] &&
         !world->grid[sShape->pos[1].x / BOX_SCALE - 1][sShape->pos[1].y / BOX_SCALE] &&
         !world->grid[sShape->pos[3].x / BOX_SCALE - 1][sShape->pos[3].y / BOX_SCALE])
             canMove = true;
      break;
    case deg90:
      if(!world->grid[sShape->pos[0].x / BOX_SCALE - 1][sShape->pos[0].y / BOX_SCALE] &&
         !world->grid[sShape->pos[3].x / BOX_SCALE - 1][sShape->pos[3].y / BOX_SCALE])
             canMove = true;
      break;
    case deg180:
      if(!world->grid[sShape->pos[1].x / BOX_SCALE - 1][sShape->pos[1].y / BOX_SCALE] &&
         !world->grid[sShape->pos[2].x / BOX_SCALE - 1][sShape->pos[2].y / BOX_SCALE] &&
         !world->grid[sShape->pos[3].x / BOX_SCALE - 1][sShape->pos[3].y / BOX_SCALE])
             canMove = true;
      break;
    case deg270:
      if(!world->grid[sShape->pos[1].x / BOX_SCALE - 1][sShape->pos[1].y / BOX_SCALE] &&
         !world->grid[sShape->pos[2].x / BOX_SCALE - 1][sShape->pos[2].y / BOX_SCALE])
             canMove = true;
      break;
  }
  return canMove;
}

bool
TetrisShape::moveDownTShape(Shape *tShape, World *world)
{
  bool canMove = false;
  switch(tShape->shapeRot)
  {
    case deg0:
      if(!world->grid[tShape->pos[0].x / BOX_SCALE - 1][tShape->pos[0].y / BOX_SCALE] &&
         !world->grid[tShape->pos[1].x / BOX_SCALE - 1][tShape->pos[1].y / BOX_SCALE] &&
         !world->grid[tShape->pos[3].x / BOX_SCALE - 1][tShape->pos[3].y / BOX_SCALE])
             canMove = true;
      break;
    case deg90:
      if(!world->grid[tShape->pos[2].x / BOX_SCALE - 1][tShape->pos[2].y / BOX_SCALE] &&
         !world->grid[tShape->pos[3].x / BOX_SCALE - 1][tShape->pos[3].y / BOX_SCALE])
             canMove = true;
      break;
    case deg180:
      if(!world->grid[tShape->pos[1].x / BOX_SCALE - 1][tShape->pos[1].y / BOX_SCALE] &&
         !world->grid[tShape->pos[2].x / BOX_SCALE - 1][tShape->pos[2].y / BOX_SCALE] &&
         !world->grid[tShape->pos[3].x / BOX_SCALE - 1][tShape->pos[3].y / BOX_SCALE])
             canMove = true;
      break;
    case deg270:
      if(!world->grid[tShape->pos[1].x / BOX_SCALE - 1][tShape->pos[1].y / BOX_SCALE] &&
         !world->grid[tShape->pos[2].x / BOX_SCALE - 1][tShape->pos[2].y / BOX_SCALE])
             canMove = true;
      break;
  }
  return canMove;
}

bool
TetrisShape::moveDownZShape(Shape *zShape, World *world)
{
  bool canMove = false;
  switch(zShape->shapeRot)
  {
    case deg0:
      if(!world->grid[zShape->pos[0].x / BOX_SCALE - 1][zShape->pos[0].y / BOX_SCALE] &&
         !world->grid[zShape->pos[2].x / BOX_SCALE - 1][zShape->pos[2].y / BOX_SCALE] &&
         !world->grid[zShape->pos[3].x / BOX_SCALE - 1][zShape->pos[3].y / BOX_SCALE])
             canMove = true;
      break;
    case deg90:
      if(!world->grid[zShape->pos[1].x / BOX_SCALE - 1][zShape->pos[1].y / BOX_SCALE] &&
         !world->grid[zShape->pos[3].x / BOX_SCALE - 1][zShape->pos[3].y / BOX_SCALE])
             canMove = true;
      break;
    case deg180:
      if(!world->grid[zShape->pos[1].x / BOX_SCALE - 1][zShape->pos[1].y / BOX_SCALE] &&
         !world->grid[zShape->pos[2].x / BOX_SCALE - 1][zShape->pos[2].y / BOX_SCALE] &&
         !world->grid[zShape->pos[3].x / BOX_SCALE - 1][zShape->pos[3].y / BOX_SCALE])
             canMove = true;
      break;
    case deg270:
      if(!world->grid[zShape->pos[0].x / BOX_SCALE - 1][zShape->pos[0].y / BOX_SCALE] &&
         !world->grid[zShape->pos[2].x / BOX_SCALE - 1][zShape->pos[2].y / BOX_SCALE])
             canMove = true;
      break;
  }
  return canMove;
}
