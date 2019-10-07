#ifndef _TETRISBT_TETRIS
#define _TETRISBT_TETRIS

#include <TFT_eSPI.h>

#define MAX_BOX_X 13
#define MAX_BOX_Y 22
#define SHAPE_DEST_X 5
#define SHAPE_DEST_Y 5
#define BACKGROUND_COLOR BLACK
#define FRAME_COLOR WHITE


typedef enum {
  I, J, L, O, S, T, Z
} Tetromino;

typedef enum {
  RED=TFT_RED,
  GREEN=TFT_GREEN,
  BLUE=TFT_BLUE,
  CYAN=TFT_CYAN,
  MAGENTA=TFT_MAGENTA,
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
  ShapeColor color = WHITE;
  ShapeRot shapeRot = deg0;
} Shape;

typedef struct {
  ShapeColor grid[MAX_BOX_X][MAX_BOX_Y] = {{BLACK}};
} World;

#endif
