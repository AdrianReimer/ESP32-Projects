#include "TetrisRot.h"
#include "TetrisShape.h"


void
TetrisRot::rotShape(Shape *shape,
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
TetrisRot::rotIShape(Shape *iShape,
                       World *world)
{
  switch(iShape->shapeRot)
  {
    case deg0:
      if(world->grid[iShape->pos[1].x / BOX_SCALE + 1][iShape->pos[1].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[iShape->pos[2].x / BOX_SCALE - 1][iShape->pos[2].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[iShape->pos[3].x / BOX_SCALE - 2][iShape->pos[3].y / BOX_SCALE - 2] == BACKGROUND_COLOR)
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
      if(world->grid[iShape->pos[1].x / BOX_SCALE - 1][iShape->pos[1].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[iShape->pos[2].x / BOX_SCALE + 1][iShape->pos[2].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[iShape->pos[3].x / BOX_SCALE + 2][iShape->pos[3].y / BOX_SCALE - 2] == BACKGROUND_COLOR)
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
      if(world->grid[iShape->pos[1].x / BOX_SCALE - 1][iShape->pos[1].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[iShape->pos[2].x / BOX_SCALE + 1][iShape->pos[2].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[iShape->pos[3].x / BOX_SCALE + 2][iShape->pos[3].y / BOX_SCALE + 2] == BACKGROUND_COLOR)
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
      if(world->grid[iShape->pos[1].x / BOX_SCALE + 1][iShape->pos[1].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[iShape->pos[2].x / BOX_SCALE - 1][iShape->pos[2].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[iShape->pos[3].x / BOX_SCALE - 2][iShape->pos[3].y / BOX_SCALE + 2] == BACKGROUND_COLOR)
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
TetrisRot::rotLShape(Shape *lShape,
                       World *world)
{
  switch(lShape->shapeRot)
  {
    case deg0:
      if(world->grid[lShape->pos[1].x / BOX_SCALE + 1][lShape->pos[1].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[lShape->pos[2].x / BOX_SCALE][lShape->pos[2].y / BOX_SCALE + 2] == BACKGROUND_COLOR &&
         world->grid[lShape->pos[3].x / BOX_SCALE - 1][lShape->pos[3].y / BOX_SCALE - 1] == BACKGROUND_COLOR)
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
      if(world->grid[lShape->pos[1].x / BOX_SCALE - 1][lShape->pos[1].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[lShape->pos[2].x / BOX_SCALE - 2][lShape->pos[2].y / BOX_SCALE] == BACKGROUND_COLOR &&
         world->grid[lShape->pos[3].x / BOX_SCALE + 1][lShape->pos[3].y / BOX_SCALE - 1] == BACKGROUND_COLOR)
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
      if(world->grid[lShape->pos[1].x / BOX_SCALE - 1][lShape->pos[1].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[lShape->pos[2].x / BOX_SCALE][lShape->pos[2].y / BOX_SCALE - 2] == BACKGROUND_COLOR &&
         world->grid[lShape->pos[3].x / BOX_SCALE + 1][lShape->pos[3].y / BOX_SCALE + 1] == BACKGROUND_COLOR)
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
      if(world->grid[lShape->pos[1].x / BOX_SCALE + 1][lShape->pos[1].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[lShape->pos[2].x / BOX_SCALE + 2][lShape->pos[2].y / BOX_SCALE] == BACKGROUND_COLOR &&
         world->grid[lShape->pos[3].x / BOX_SCALE - 1][lShape->pos[3].y / BOX_SCALE + 1] == BACKGROUND_COLOR)
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
TetrisRot::rotJShape(Shape *jShape,
                       World *world)
{
  switch(jShape->shapeRot)
  {
    case deg0:
      if(world->grid[jShape->pos[1].x / BOX_SCALE - 1][jShape->pos[1].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[jShape->pos[2].x / BOX_SCALE - 2][jShape->pos[2].y / BOX_SCALE] == BACKGROUND_COLOR &&
         world->grid[jShape->pos[3].x / BOX_SCALE + 1][jShape->pos[3].y / BOX_SCALE + 1] == BACKGROUND_COLOR)
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
      if(world->grid[jShape->pos[1].x / BOX_SCALE + 1][jShape->pos[1].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[jShape->pos[2].x / BOX_SCALE][jShape->pos[2].y / BOX_SCALE - 2] == BACKGROUND_COLOR &&
         world->grid[jShape->pos[3].x / BOX_SCALE - 1][jShape->pos[3].y / BOX_SCALE + 1] == BACKGROUND_COLOR)
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
      if(world->grid[jShape->pos[1].x / BOX_SCALE + 1][jShape->pos[1].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[jShape->pos[2].x / BOX_SCALE + 2][jShape->pos[2].y / BOX_SCALE] == BACKGROUND_COLOR &&
         world->grid[jShape->pos[3].x / BOX_SCALE - 1][jShape->pos[3].y / BOX_SCALE - 1] == BACKGROUND_COLOR)
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
      if(world->grid[jShape->pos[1].x / BOX_SCALE - 1][jShape->pos[1].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[jShape->pos[2].x / BOX_SCALE][jShape->pos[2].y / BOX_SCALE + 2] == BACKGROUND_COLOR &&
         world->grid[jShape->pos[3].x / BOX_SCALE + 1][jShape->pos[3].y / BOX_SCALE - 1] == BACKGROUND_COLOR)
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
TetrisRot::rotSShape(Shape *sShape,
                       World *world)
{
    switch(sShape->shapeRot)
  {
    case deg0:
      if(world->grid[sShape->pos[1].x / BOX_SCALE + 1][sShape->pos[1].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[sShape->pos[2].x / BOX_SCALE - 1][sShape->pos[2].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[sShape->pos[3].x / BOX_SCALE - 2][sShape->pos[3].y / BOX_SCALE] == BACKGROUND_COLOR)
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
      if(world->grid[sShape->pos[1].x / BOX_SCALE - 1][sShape->pos[1].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[sShape->pos[2].x / BOX_SCALE - 1][sShape->pos[2].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[sShape->pos[3].x / BOX_SCALE][sShape->pos[3].y / BOX_SCALE - 2] == BACKGROUND_COLOR)
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
      if(world->grid[sShape->pos[1].x / BOX_SCALE - 1][sShape->pos[1].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[sShape->pos[2].x / BOX_SCALE + 1][sShape->pos[2].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[sShape->pos[3].x / BOX_SCALE + 2][sShape->pos[3].y / BOX_SCALE] == BACKGROUND_COLOR)
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
      if(world->grid[sShape->pos[1].x / BOX_SCALE + 1][sShape->pos[1].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[sShape->pos[2].x / BOX_SCALE + 1][sShape->pos[2].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[sShape->pos[3].x / BOX_SCALE][sShape->pos[3].y / BOX_SCALE + 2] == BACKGROUND_COLOR)
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
TetrisRot::rotTShape(Shape *tShape,
                       World *world)
{
  switch(tShape->shapeRot)
  {
    case deg0:
      if(world->grid[tShape->pos[1].x / BOX_SCALE + 1][tShape->pos[1].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[tShape->pos[2].x / BOX_SCALE - 1][tShape->pos[2].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[tShape->pos[3].x / BOX_SCALE - 1][tShape->pos[3].y / BOX_SCALE - 1] == BACKGROUND_COLOR)
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
      if(world->grid[tShape->pos[1].x / BOX_SCALE - 1][tShape->pos[1].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[tShape->pos[2].x / BOX_SCALE - 1][tShape->pos[2].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[tShape->pos[3].x / BOX_SCALE + 1][tShape->pos[3].y / BOX_SCALE - 1] == BACKGROUND_COLOR)
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
      if(world->grid[tShape->pos[1].x / BOX_SCALE - 1][tShape->pos[1].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[tShape->pos[2].x / BOX_SCALE + 1][tShape->pos[2].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[tShape->pos[3].x / BOX_SCALE + 1][tShape->pos[3].y / BOX_SCALE + 1] == BACKGROUND_COLOR)
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
      if(world->grid[tShape->pos[1].x / BOX_SCALE + 1][tShape->pos[1].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[tShape->pos[2].x / BOX_SCALE + 1][tShape->pos[2].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[tShape->pos[3].x / BOX_SCALE - 1][tShape->pos[3].y / BOX_SCALE + 1] == BACKGROUND_COLOR)
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
TetrisRot::rotZShape(Shape *zShape,
                       World *world)
{
  switch(zShape->shapeRot)
  {
    case deg0:
      if(world->grid[zShape->pos[1].x / BOX_SCALE - 1][zShape->pos[1].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[zShape->pos[2].x / BOX_SCALE][zShape->pos[2].y / BOX_SCALE + 2] == BACKGROUND_COLOR &&
         world->grid[zShape->pos[3].x / BOX_SCALE - 1][zShape->pos[3].y / BOX_SCALE - 1] == BACKGROUND_COLOR)
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
      if(world->grid[zShape->pos[1].x / BOX_SCALE - 1][zShape->pos[1].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[zShape->pos[2].x / BOX_SCALE - 2][zShape->pos[2].y / BOX_SCALE] == BACKGROUND_COLOR &&
         world->grid[zShape->pos[3].x / BOX_SCALE + 1][zShape->pos[3].y / BOX_SCALE - 1] == BACKGROUND_COLOR)
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
      if(world->grid[zShape->pos[1].x / BOX_SCALE + 1][zShape->pos[1].y / BOX_SCALE - 1] == BACKGROUND_COLOR &&
         world->grid[zShape->pos[2].x / BOX_SCALE][zShape->pos[2].y / BOX_SCALE - 2] == BACKGROUND_COLOR &&
         world->grid[zShape->pos[3].x / BOX_SCALE + 1][zShape->pos[3].y / BOX_SCALE + 1] == BACKGROUND_COLOR)
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
      if(world->grid[zShape->pos[1].x / BOX_SCALE + 1][zShape->pos[1].y / BOX_SCALE + 1] == BACKGROUND_COLOR &&
         world->grid[zShape->pos[2].x / BOX_SCALE + 2][zShape->pos[2].y / BOX_SCALE] == BACKGROUND_COLOR &&
         world->grid[zShape->pos[3].x / BOX_SCALE - 1][zShape->pos[3].y / BOX_SCALE + 1] == BACKGROUND_COLOR)
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
