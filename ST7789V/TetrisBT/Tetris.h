#ifndef _TETRISBT_TETRIS
#define _TETRISBT_TETRIS

#include <TFT_eSPI.h>

#define MAX_BOX_X 13
#define MAX_BOX_Y 22

typedef enum {
  I, J, L, O, S, T, Z
} Tetromino;

typedef enum {
  RED=TFT_RED,
  GREEN=TFT_GREEN,
  BLUE=TFT_BLUE,
  WHITE=TFT_WHITE,
  BLACK=TFT_BLACK
} ShapeColor;

typedef enum {
  deg0, deg90, deg180, deg270
} ShapeRot;

typedef struct {
  int x;
  int y;
} Pos;

typedef struct {
  Tetromino tet;
  Pos pos[4];
  unsigned int color = WHITE;
  ShapeRot shapeRot = deg0;
} Shape;

typedef struct {
  Shape *grid[MAX_BOX_X][MAX_BOX_Y] = {};
} World;

#endif
