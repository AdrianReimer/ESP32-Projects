#include "TetrisWorld.h"
#include "TetrisShape.h"

#define SCORE_TIME 5000


static Shape FRAME_SHAPE;

TetrisWorld::TetrisWorld(TFT_eSPI *tft)
{
  TetrisWorld::tft = tft;
  p1Score = 0;
  p2Score = 0;
}

void
TetrisWorld::initFrame()
{
  for(int i = 1; i <= MAX_BOX_X - 1; i++) {
    world.grid[i][0] = FRAME_COLOR;
    world.grid[i][11] = FRAME_COLOR;
    world.grid[i][22] = FRAME_COLOR;
  }
  for(int i = 0; i <= MAX_BOX_Y; i++)
    world.grid[0][i] = FRAME_COLOR;
}

void
TetrisWorld::drawWorld(Shape *shape)
{
  for(int x = 0; x <= MAX_BOX_X - 1; x++) {
    for(int y = 0; y <= MAX_BOX_Y; y++) {
      if(world.grid[x][y])
        tft->fillRect(x * BOX_SCALE, y * BOX_SCALE, BOX_SCALE, BOX_SCALE, world.grid[x][y]);
      else
        tft->fillRect(x * BOX_SCALE, y * BOX_SCALE, BOX_SCALE, BOX_SCALE, BACKGROUND_COLOR);
      tft->drawRect(x * BOX_SCALE, y * BOX_SCALE, BOX_SCALE, BOX_SCALE, FRAME_COLOR);
    }
  }
  tft->fillRect(shape->pos[0].x, shape->pos[0].y, BOX_SCALE, BOX_SCALE, shape->color);
  tft->fillRect(shape->pos[1].x, shape->pos[1].y, BOX_SCALE, BOX_SCALE, shape->color);
  tft->fillRect(shape->pos[2].x, shape->pos[2].y, BOX_SCALE, BOX_SCALE, shape->color);
  tft->fillRect(shape->pos[3].x, shape->pos[3].y, BOX_SCALE, BOX_SCALE, shape->color);
}

void
TetrisWorld::checkWorld()
{
  while(checkHorizontal() || checkVertical()) {}
  for(int y = 1; y < 11; y++) {
    if(world.grid[ROOT_POS_X / BOX_SCALE][y] != BACKGROUND_COLOR) {
      ++p2Score;
      printScore();
    }
  }
  for(int y = 12; y < 22; y++) {
    if(world.grid[ROOT_POS_X / BOX_SCALE][y] != BACKGROUND_COLOR) {
      ++p1Score;
      printScore();
    }
  }
}

void
TetrisWorld::printScore()
{
  tft->setCursor(0, TFT_WIDTH / 2);
  tft->setRotation(1);
  tft->fillScreen(TFT_BLACK);
  tft->print("|You| ");
  tft->print(p1Score);
  tft->print(" - ");
  tft->print(p2Score);
  tft->print(" |Enemy|");
  resetWorld();
  delay(SCORE_TIME);
  tft->setRotation(0);
}

inline void
TetrisWorld::resetWorld()
{
  for(int x = 0; x <= MAX_BOX_X - 1; x++) {
    for(int y = 0; y <= MAX_BOX_Y; y++) {
      world.grid[x][y] = BACKGROUND_COLOR;
    }
  }
  initFrame();
}

int
TetrisWorld::checkHorizontal()
{
  ShapeColor color = world.grid[0][0];
  int colorCnt = 0;
  int shapeDestCnt = 0;
  for(int x = 0; x <= MAX_BOX_X - 1; x++) {
    for(int y = 0; y <= MAX_BOX_Y; y++) {
      if(world.grid[x][y] != BACKGROUND_COLOR &&
         world.grid[x][y] != FRAME_COLOR) {
          if(world.grid[x][y] == color) {
              colorCnt++;
              if(colorCnt == SHAPE_DEST_Y) {
                colorCnt = 0;
                world.grid[x][y] = BACKGROUND_COLOR;
                int y1 = y;
                int y2 = y;
                while(world.grid[x][--y1] == color)
                  world.grid[x][y1] = BACKGROUND_COLOR;
                while(world.grid[x][++y2] == color)
                  world.grid[x][y2] = BACKGROUND_COLOR;
                shapeDestCnt++;
                cleanWorld(y1, y2);
            }
          } else {
            colorCnt = 0;
            color = world.grid[x][y];
          }
      } else {
          colorCnt = 0;
      }
    }
  }
  return shapeDestCnt;
}

int
TetrisWorld::checkVertical()
{
  ShapeColor color = world.grid[0][0];
  int colorCnt = 0;
  int shapeDestCnt = 0;
  for(int y = 0; y <= MAX_BOX_Y; y++) {
    for(int x = 0; x <= MAX_BOX_X - 1; x++) {
      if(world.grid[x][y] != BACKGROUND_COLOR &&
         world.grid[x][y] != FRAME_COLOR) {
          if(world.grid[x][y] == color) {
              colorCnt++;
              if(colorCnt == SHAPE_DEST_Y) {
                colorCnt = 0;
                world.grid[x][y] = BACKGROUND_COLOR;
                int x1 = x;
                int x2 = x;
                while(world.grid[--x1][y] == color)
                  world.grid[x1][y] = BACKGROUND_COLOR;
                while(world.grid[++x2][y] == color)
                  world.grid[x2][y] = BACKGROUND_COLOR;
                shapeDestCnt++;
                cleanWorld(y - 1, y + 1);
            }
          } else {
            colorCnt = 0;
            color = world.grid[x][y];
          }
      } else {
          colorCnt = 0;
      }
    }
  }
  return shapeDestCnt;
}

void
TetrisWorld::cleanWorld(int y1, int y2)
{
  for(int y = y1; y <= y2; y++) {
    for(int x = 0; x <= MAX_BOX_X - 1; x++) {
     if(world.grid[x][y] != BACKGROUND_COLOR &&
        world.grid[x][y] != FRAME_COLOR) {
          if(world.grid[x - 1][y] == BACKGROUND_COLOR) {
            int x1 = x - 1;
            while(world.grid[x1][y] == BACKGROUND_COLOR)
              x1--;
            world.grid[++x1][y] = world.grid[x][y];
            world.grid[x][y] = BACKGROUND_COLOR;
          }
      }
    }
  }
}

World*
TetrisWorld::getWorld()
{
  return &world;
}

void
TetrisWorld::setShape(Shape shape)
{
  TetrisWorld::shape = shape;
}

Shape*
TetrisWorld::getShape()
{
  return &shape;
}
