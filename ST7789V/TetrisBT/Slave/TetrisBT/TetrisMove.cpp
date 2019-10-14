#include "TetrisMove.h"
#include "TetrisShape.h"


bool
TetrisMove::moveDownShape(Shape *shape, World *world)
{
  shape->pos[0].x -= BOX_SCALE;
  shape->pos[1].x -= BOX_SCALE;
  shape->pos[2].x -= BOX_SCALE;
  shape->pos[3].x -= BOX_SCALE;
  
  if(world->grid[shape->pos[0].x / BOX_SCALE][shape->pos[0].y / BOX_SCALE] != BACKGROUND_COLOR ||
     world->grid[shape->pos[1].x / BOX_SCALE][shape->pos[1].y / BOX_SCALE] != BACKGROUND_COLOR ||
     world->grid[shape->pos[2].x / BOX_SCALE][shape->pos[2].y / BOX_SCALE] != BACKGROUND_COLOR ||
     world->grid[shape->pos[3].x / BOX_SCALE][shape->pos[3].y / BOX_SCALE] != BACKGROUND_COLOR)
     {
        shape->pos[0].x += BOX_SCALE;
        shape->pos[1].x += BOX_SCALE;
        shape->pos[2].x += BOX_SCALE;
        shape->pos[3].x += BOX_SCALE;
        world->grid[shape->pos[0].x / BOX_SCALE][shape->pos[0].y / BOX_SCALE] = shape->color;
        world->grid[shape->pos[1].x / BOX_SCALE][shape->pos[1].y / BOX_SCALE] = shape->color;
        world->grid[shape->pos[2].x / BOX_SCALE][shape->pos[2].y / BOX_SCALE] = shape->color;
        world->grid[shape->pos[3].x / BOX_SCALE][shape->pos[3].y / BOX_SCALE] = shape->color;
        return false;
   }
  return true;
}

void
TetrisMove::moveLeftShape(Shape *shape, World *world)
{
  shape->pos[0].y -= BOX_SCALE;
  shape->pos[1].y -= BOX_SCALE;
  shape->pos[2].y -= BOX_SCALE;
  shape->pos[3].y -= BOX_SCALE;
  
  if(world->grid[shape->pos[0].x / BOX_SCALE][shape->pos[0].y / BOX_SCALE] != BACKGROUND_COLOR ||
     world->grid[shape->pos[1].x / BOX_SCALE][shape->pos[1].y / BOX_SCALE] != BACKGROUND_COLOR ||
     world->grid[shape->pos[2].x / BOX_SCALE][shape->pos[2].y / BOX_SCALE] != BACKGROUND_COLOR ||
     world->grid[shape->pos[3].x / BOX_SCALE][shape->pos[3].y / BOX_SCALE] != BACKGROUND_COLOR)
     {
        shape->pos[0].y += BOX_SCALE;
        shape->pos[1].y += BOX_SCALE;
        shape->pos[2].y += BOX_SCALE;
        shape->pos[3].y += BOX_SCALE;
   }
}

void
TetrisMove::moveRightShape(Shape *shape, World *world)
{
  shape->pos[0].y += BOX_SCALE;
  shape->pos[1].y += BOX_SCALE;
  shape->pos[2].y += BOX_SCALE;
  shape->pos[3].y += BOX_SCALE;
  
  if(world->grid[shape->pos[0].x / BOX_SCALE][shape->pos[0].y / BOX_SCALE] != BACKGROUND_COLOR ||
     world->grid[shape->pos[1].x / BOX_SCALE][shape->pos[1].y / BOX_SCALE] != BACKGROUND_COLOR ||
     world->grid[shape->pos[2].x / BOX_SCALE][shape->pos[2].y / BOX_SCALE] != BACKGROUND_COLOR ||
     world->grid[shape->pos[3].x / BOX_SCALE][shape->pos[3].y / BOX_SCALE] != BACKGROUND_COLOR)
     {
        shape->pos[0].y -= BOX_SCALE;
        shape->pos[1].y -= BOX_SCALE;
        shape->pos[2].y -= BOX_SCALE;
        shape->pos[3].y -= BOX_SCALE;
   }
}
