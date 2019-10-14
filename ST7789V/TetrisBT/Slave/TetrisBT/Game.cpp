#include "Game.h"

#define MOVE_LEFT_MASK  0b00000001
#define MOVE_RIGHT_MASK 0b00000010
#define ROT_MASK        0b00000100
#define COLOR_MASK      0b00001111
#define SHAPE_MASK      0b11110000


Game::Game()
{
  myName = MY_NAME;
  targetName = TARGET_NAME;
  tetrisShape = TetrisShape();
  tetrisRot = TetrisRot();
  tetrisMove = TetrisMove();
}

void
Game::setupGame()
{
  tft.init();
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(0, TFT_WIDTH / 2);
  tft.setRotation(1);
  tft.print("Searching for \n" + targetName + "\n[~10sec]");
  
  Serial.begin(BAUDRATE);
  SerialBT.begin(myName, false);
  connected = SerialBT.connect(targetName);
  if(connected) {
    Serial.println("Connected Succesfully!");
  } else {
    while(!SerialBT.connected(CONNECT_TIME_MS)) {
      Serial.println("Failed to connect. Make sure remote device is available and in range, then restart app."); 
    }
  }
  
  tft.setRotation(0);
  tetrisWorld.initFrame();
  tetrisWorld.setShape(tetrisShape.createRndShape(P1, buffer));
  SerialBT.write(buffer, sizeof(buffer) / sizeof(buffer[0]));
  delay(BT_TIME_MS); // wait for packets
  
  for(uint32_t i = 0; i < BUFFER_LEN; i++) {
    bt_pakets[i] = SerialBT.read();
  } // grab packets
  tetrisWorld.setEnemyShape(tetrisShape.createShape((Tetromino)bt_pakets[BUFFER_SHAPE_IDX],
                                                    tetrisShape.numToColor(bt_pakets[BUFFER_COLOR_IDX]), P2));
}

void
Game::updateGame()
{
  if(digitalRead(MOVE_LEFT_BTN_PIN) == HIGH) {
    tetrisMove.moveLeftShape(tetrisWorld.getShape(), tetrisWorld.getWorld());
    buffer[BUFFER_MOVE_IDX] |= MOVE_LEFT_MASK;
  }
  if(digitalRead(MOVE_RIGHT_BTN_PIN) == HIGH) {
    tetrisMove.moveRightShape(tetrisWorld.getShape(), tetrisWorld.getWorld());
    buffer[BUFFER_MOVE_IDX] |= MOVE_RIGHT_MASK;
  }
  if(digitalRead(ROT_BTN_PIN) == HIGH) {
    tetrisRot.rotShape(tetrisWorld.getShape(), tetrisWorld.getWorld());
    buffer[BUFFER_MOVE_IDX] |= ROT_MASK;
  }
  if(!tetrisMove.moveDownShape(tetrisWorld.getShape(), tetrisWorld.getWorld())) {
    tetrisWorld.checkWorld();
    tetrisWorld.setShape(tetrisShape.createRndShape(P1, buffer));
  }
  SerialBT.write(buffer, sizeof(buffer) / sizeof(buffer[0]));
  delay(BT_TIME_MS); // wait for packets
  
  for(uint32_t i = 0; i < BUFFER_LEN; i++) {
    bt_pakets[i] = SerialBT.read();
  } // grab packets
  if(bt_pakets[BUFFER_MOVE_IDX] & MOVE_LEFT_MASK) {
    tetrisMove.moveLeftShape(tetrisWorld.getEnemyShape(), tetrisWorld.getWorld());
  }
  if(bt_pakets[BUFFER_MOVE_IDX] & MOVE_RIGHT_MASK) {
    tetrisMove.moveRightShape(tetrisWorld.getEnemyShape(), tetrisWorld.getWorld());
  }
  if(bt_pakets[BUFFER_MOVE_IDX] & ROT_MASK) {
    tetrisRot.rotShape(tetrisWorld.getEnemyShape(), tetrisWorld.getWorld());
  }
  if(!tetrisMove.moveDownShape(tetrisWorld.getEnemyShape(), tetrisWorld.getWorld())) {
    tetrisWorld.checkWorld();
    tetrisWorld.setEnemyShape(tetrisShape.createShape((Tetromino)bt_pakets[BUFFER_SHAPE_IDX],
                                                      tetrisShape.numToColor(bt_pakets[BUFFER_COLOR_IDX]), P2));
  }
  tetrisWorld.drawWorld();

  for(uint32_t i = 0; i < BUFFER_LEN; i++) {
    buffer[i] = 0;
  } // clear Buffer for next Communication
}
