#include "TetrisMove.h"
#include "TetrisShape.h"


bool
TetrisMove::moveDownShape(Shape *shape, World *world)
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
TetrisMove::moveDownIShape(Shape *iShape, World *world)
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
TetrisMove::moveDownLShape(Shape *lShape, World *world)
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
TetrisMove::moveDownJShape(Shape *jShape, World *world)
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
TetrisMove::moveDownOShape(Shape *oShape, World *world)
{
  bool canMove = false;
  if(!world->grid[oShape->pos[0].x / BOX_SCALE - 1][oShape->pos[0].y / BOX_SCALE] &&
     !world->grid[oShape->pos[2].x / BOX_SCALE - 1][oShape->pos[2].y / BOX_SCALE])
         canMove = true;
  return canMove;
}

bool
TetrisMove::moveDownSShape(Shape *sShape, World *world)
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
TetrisMove::moveDownTShape(Shape *tShape, World *world)
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
TetrisMove::moveDownZShape(Shape *zShape, World *world)
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

void
TetrisMove::moveLeftShape(Shape *shape, World *world)
{
  bool canMove = false;
  switch(shape->tet) {
    case I:
      canMove = moveLeftIShape(shape, world);
      break;
    case J:
      canMove = moveLeftJShape(shape, world);
      break;
    case L:
      canMove = moveLeftLShape(shape, world);
      break;
    case O:
      canMove = moveLeftOShape(shape, world);
      break;
    case S:
      canMove = moveLeftSShape(shape, world);
      break;
    case T:
      canMove = moveLeftTShape(shape, world);
      break;
    case Z:
      canMove = moveLeftZShape(shape, world);
      break;
  }
  if(canMove) {
    shape->pos[0].y -= BOX_SCALE;
    shape->pos[1].y -= BOX_SCALE;
    shape->pos[2].y -= BOX_SCALE;
    shape->pos[3].y -= BOX_SCALE;
  }
}

bool
TetrisMove::moveLeftIShape(Shape *iShape, World *world)
{
  bool canMove = false;
  switch(iShape->shapeRot)
  {
    case deg0:
      if(!world->grid[iShape->pos[1].x / BOX_SCALE][iShape->pos[1].y / BOX_SCALE - 1])
             canMove = true;
      break;
    case deg90:
    case deg270:
      if(!world->grid[iShape->pos[0].x / BOX_SCALE][iShape->pos[0].y / BOX_SCALE - 1] &&
         !world->grid[iShape->pos[1].x / BOX_SCALE][iShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[iShape->pos[2].x / BOX_SCALE][iShape->pos[2].y / BOX_SCALE - 1] &&
         !world->grid[iShape->pos[3].x / BOX_SCALE][iShape->pos[3].y / BOX_SCALE - 1])
             canMove = true;
      break;
    case deg180:
      if(!world->grid[iShape->pos[3].x / BOX_SCALE][iShape->pos[3].y / BOX_SCALE - 1])
             canMove = true;
      break;
  }
  return canMove;
}

bool
TetrisMove::moveLeftLShape(Shape *lShape, World *world)
{
  bool canMove = false;
  switch(lShape->shapeRot)
  {
    case deg0:
      if(!world->grid[lShape->pos[1].x / BOX_SCALE][lShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[lShape->pos[2].x / BOX_SCALE][lShape->pos[2].y / BOX_SCALE - 1])
             canMove = true;
      break;
    case deg90:
      if(!world->grid[lShape->pos[0].x / BOX_SCALE][lShape->pos[0].y / BOX_SCALE - 1] &&
         !world->grid[lShape->pos[1].x / BOX_SCALE][lShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[lShape->pos[3].x / BOX_SCALE][lShape->pos[3].y / BOX_SCALE - 1])
             canMove = true;
      break;
    case deg180:
      if(!world->grid[lShape->pos[2].x / BOX_SCALE][lShape->pos[2].y / BOX_SCALE - 1] &&
         !world->grid[lShape->pos[3].x / BOX_SCALE][lShape->pos[3].y / BOX_SCALE - 1])
             canMove = true;
      break;
    case deg270:
      if(!world->grid[lShape->pos[0].x / BOX_SCALE][lShape->pos[0].y / BOX_SCALE - 1] &&
         !world->grid[lShape->pos[2].x / BOX_SCALE][lShape->pos[2].y / BOX_SCALE - 1] &&
         !world->grid[lShape->pos[3].x / BOX_SCALE][lShape->pos[3].y / BOX_SCALE - 1])
             canMove = true;
      break;
  }
  return canMove;
}

bool
TetrisMove::moveLeftJShape(Shape *jShape, World *world)
{
  bool canMove = false;
  switch(jShape->shapeRot)
  {
    case deg0:
      if(!world->grid[jShape->pos[2].x / BOX_SCALE][jShape->pos[2].y / BOX_SCALE - 1] &&
         !world->grid[jShape->pos[3].x / BOX_SCALE][jShape->pos[3].y / BOX_SCALE - 1])
             canMove = true;
      break;
    case deg90:
      if(!world->grid[jShape->pos[0].x / BOX_SCALE][jShape->pos[0].y / BOX_SCALE - 1] &&
         !world->grid[jShape->pos[1].x / BOX_SCALE][jShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[jShape->pos[3].x / BOX_SCALE][jShape->pos[3].y / BOX_SCALE - 1])
             canMove = true;
      break;
    case deg180:
      if(!world->grid[jShape->pos[1].x / BOX_SCALE][jShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[jShape->pos[2].x / BOX_SCALE][jShape->pos[2].y / BOX_SCALE - 1])
             canMove = true;
      break;
    case deg270:
      if(!world->grid[jShape->pos[0].x / BOX_SCALE][jShape->pos[0].y / BOX_SCALE - 1] &&
         !world->grid[jShape->pos[2].x / BOX_SCALE][jShape->pos[2].y / BOX_SCALE - 1] &&
         !world->grid[jShape->pos[3].x / BOX_SCALE][jShape->pos[3].y / BOX_SCALE - 1])
             canMove = true;
      break;
  }
  return canMove;
}

bool
TetrisMove::moveLeftOShape(Shape *oShape, World *world)
{
  bool canMove = false;
  switch(oShape->shapeRot)
  {
    case deg0:
    case deg90:
    case deg180:
    case deg270:
      if(!world->grid[oShape->pos[0].x / BOX_SCALE][oShape->pos[0].y / BOX_SCALE - 1] &&
         !world->grid[oShape->pos[1].x / BOX_SCALE][oShape->pos[1].y / BOX_SCALE - 1])
             canMove = true;
      break;
  }
  return canMove;
}

bool
TetrisMove::moveLeftSShape(Shape *sShape, World *world)
{
  bool canMove = false;
  switch(sShape->shapeRot)
  {
    case deg0:
      if(!world->grid[sShape->pos[1].x / BOX_SCALE][sShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[sShape->pos[2].x / BOX_SCALE][sShape->pos[2].y / BOX_SCALE - 1])
             canMove = true;
      break;
    case deg90:
      if(!world->grid[sShape->pos[0].x / BOX_SCALE][sShape->pos[0].y / BOX_SCALE - 1] &&
         !world->grid[sShape->pos[1].x / BOX_SCALE][sShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[sShape->pos[3].x / BOX_SCALE][sShape->pos[3].y / BOX_SCALE - 1])
             canMove = true;
      break;
    case deg180:
      if(!world->grid[sShape->pos[0].x / BOX_SCALE][sShape->pos[0].y / BOX_SCALE - 1] &&
         !world->grid[sShape->pos[3].x / BOX_SCALE][sShape->pos[3].y / BOX_SCALE - 1])
             canMove = true;
      break;
    case deg270:
      if(!world->grid[sShape->pos[1].x / BOX_SCALE][sShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[sShape->pos[2].x / BOX_SCALE][sShape->pos[2].y / BOX_SCALE - 1] &&
         !world->grid[sShape->pos[3].x / BOX_SCALE][sShape->pos[3].y / BOX_SCALE - 1])
             canMove = true;
      break;
  }
  return canMove;
}

bool
TetrisMove::moveLeftTShape(Shape *tShape, World *world)
{
  bool canMove = false;
  switch(tShape->shapeRot)
  {
    case deg0:
      if(!world->grid[tShape->pos[1].x / BOX_SCALE][tShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[tShape->pos[2].x / BOX_SCALE][tShape->pos[2].y / BOX_SCALE - 1])
             canMove = true;
      break;
    case deg90:
      if(!world->grid[tShape->pos[0].x / BOX_SCALE][tShape->pos[0].y / BOX_SCALE - 1] &&
         !world->grid[tShape->pos[1].x / BOX_SCALE][tShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[tShape->pos[3].x / BOX_SCALE][tShape->pos[3].y / BOX_SCALE - 1])
             canMove = true;
      break;
    case deg180:
      if(!world->grid[tShape->pos[2].x / BOX_SCALE][tShape->pos[2].y / BOX_SCALE - 1] &&
         !world->grid[tShape->pos[3].x / BOX_SCALE][tShape->pos[3].y / BOX_SCALE - 1])
             canMove = true;
      break;
    case deg270:
      if(!world->grid[tShape->pos[1].x / BOX_SCALE][tShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[tShape->pos[2].x / BOX_SCALE][tShape->pos[2].y / BOX_SCALE - 1] &&
         !world->grid[tShape->pos[3].x / BOX_SCALE][tShape->pos[3].y / BOX_SCALE - 1])
             canMove = true;
      break;
  }
  return canMove;
}

bool
TetrisMove::moveLeftZShape(Shape *zShape, World *world)
{
  bool canMove = false;
  switch(zShape->shapeRot)
  {
    case deg0:
      if(!world->grid[zShape->pos[0].x / BOX_SCALE][zShape->pos[0].y / BOX_SCALE - 1] &&
         !world->grid[zShape->pos[2].x / BOX_SCALE][zShape->pos[2].y / BOX_SCALE - 1])
             canMove = true;
      break;
    case deg90:
      if(!world->grid[zShape->pos[0].x / BOX_SCALE][zShape->pos[0].y / BOX_SCALE - 1] &&
         !world->grid[zShape->pos[2].x / BOX_SCALE][zShape->pos[2].y / BOX_SCALE - 1] &&
         !world->grid[zShape->pos[3].x / BOX_SCALE][zShape->pos[3].y / BOX_SCALE - 1])
             canMove = true;
      break;
    case deg180:
      if(!world->grid[zShape->pos[1].x / BOX_SCALE][zShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[zShape->pos[3].x / BOX_SCALE][zShape->pos[3].y / BOX_SCALE - 1])
             canMove = true;
      break;
    case deg270:
      if(!world->grid[zShape->pos[1].x / BOX_SCALE][zShape->pos[1].y / BOX_SCALE - 1] &&
         !world->grid[zShape->pos[2].x / BOX_SCALE][zShape->pos[2].y / BOX_SCALE - 1] &&
         !world->grid[zShape->pos[3].x / BOX_SCALE][zShape->pos[3].y / BOX_SCALE - 1])
             canMove = true;
      break;
  }
  return canMove;
}

void
TetrisMove::moveRightShape(Shape *shape, World *world)
{
  bool canMove = false;
  switch(shape->tet) {
    case I:
      canMove = moveRightIShape(shape, world);
      break;
    case J:
      canMove = moveRightJShape(shape, world);
      break;
    case L:
      canMove = moveRightLShape(shape, world);
      break;
    case O:
      canMove = moveRightOShape(shape, world);
      break;
    case S:
      canMove = moveRightSShape(shape, world);
      break;
    case T:
      canMove = moveRightTShape(shape, world);
      break;
    case Z:
      canMove = moveRightZShape(shape, world);
      break;
  }
  if(canMove) {
    shape->pos[0].y += BOX_SCALE;
    shape->pos[1].y += BOX_SCALE;
    shape->pos[2].y += BOX_SCALE;
    shape->pos[3].y += BOX_SCALE;
  }
}

bool
TetrisMove::moveRightIShape(Shape *iShape, World *world)
{
  
}

bool
TetrisMove::moveRightLShape(Shape *lShape, World *world)
{
  
}

bool
TetrisMove::moveRightJShape(Shape *jShape, World *world)
{
  
}

bool
TetrisMove::moveRightOShape(Shape *oShape, World *world)
{
  
}

bool
TetrisMove::moveRightSShape(Shape *sShape, World *world)
{
  
}

bool
TetrisMove::moveRightTShape(Shape *tShape, World *world)
{
  
}

bool
TetrisMove::moveRightZShape(Shape *zShape, World *world)
{
  
}
