#ifndef _TETRISBT_GAME_H
#define _TETRISBT_GAME_H

#include <TFT_eSPI.h>
#include <SPI.h>
#include "BluetoothSerial.h"
#include "TetrisShape.h"
#include "TetrisWorld.h"
#include "TetrisRot.h"
#include "TetrisMove.h"

#define BAUDRATE 115200
#define BUFFER_LEN 3
#define BUFFER_MOVE_IDX 0
#define BUFFER_SHAPE_IDX 1
#define BUFFER_COLOR_IDX 2
#define MY_NAME ("TTGO_T1_TETRIS_P2")
#define TARGET_NAME ("TTGO_T1_TETRIS_P1")
#define BT_TIME_MS 150
#define WAIT_TIME_MS 600
#define CONNECT_TIME_MS 10000
#define RND_NOISE_PIN 0
#define MOVE_LEFT_BTN_PIN 15
#define MOVE_RIGHT_BTN_PIN 12
#define ROT_BTN_PIN 13


class Game {
  private:
    BluetoothSerial SerialBT;
    String myName;
    String targetName;
    bool connected;
    uint8_t buffer[BUFFER_LEN] = {0};
    uint8_t bt_pakets[BUFFER_LEN] = {0};
    TFT_eSPI tft = TFT_eSPI();
    TetrisWorld tetrisWorld = TetrisWorld(&tft);
    TetrisShape tetrisShape;
    TetrisRot tetrisRot;
    TetrisMove tetrisMove;
  public:
    Game();
    void setupGame();
    void updateGame();
};

#endif
