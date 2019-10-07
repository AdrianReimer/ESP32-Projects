#ifndef _TETRISBT_GAME
#define _TETRISBT_GAME

#include <TFT_eSPI.h>
#include <SPI.h>
#include "BluetoothSerial.h"
#include "TetrisShape.h"
#include "TetrisWorld.h"
#include "TetrisRot.h"
#include "TetrisMove.h"

#define MY_NAME "TTGO_T1_TETRIS_P1"
#define TARGET_NAME "TTGO_T1_TETRIS_P2"
#define BT_TIME 150
#define WAIT_TIME 600
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
    uint8_t buffer[3] = {0};
    uint8_t bt_pakets[3] = {0};
    TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h
    TetrisShape tetrisShape = TetrisShape();
    TetrisWorld tetrisWorld = TetrisWorld(&tft);
    TetrisRot tetrisRot = TetrisRot();
    TetrisMove tetrisMove = TetrisMove();
  public:
    Game();
    void setupGame();
    void updateGame();
};

#endif
