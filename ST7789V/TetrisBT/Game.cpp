#include "Game.h"

#define MOVE_LEFT_MASK 0b00000001
#define MOVE_RIGHT_MASK 0b00000010
#define ROT_MASK 0b00000100
#define COLOR_MASK 0b00001111
#define SHAPE_MASK 0b11110000


Game::Game()
{
  myName = MY_NAME;
  targetName = TARGET_NAME;
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
  Serial.begin(115200);
  SerialBT.begin(myName, true);
  connected = SerialBT.connect(targetName);
  if(connected) {
    Serial.println("Connected Succesfully!");
  } else {
    while(!SerialBT.connected(10000)) {
      Serial.println("Failed to connect. Make sure remote device is available and in range, then restart app."); 
    }
  }
  tft.setRotation(0);
  tetrisWorld.initFrame();
  tetrisWorld.setShape(tetrisShape.createRndShape(P1, buffer));
  SerialBT.write(buffer, 3);
  delay(BT_TIME);
  bt_pakets[0] = SerialBT.read();
  bt_pakets[1] = SerialBT.read();
  bt_pakets[2] = SerialBT.read();
  tetrisWorld.setEnemyShape(tetrisShape.createShape((Tetromino)bt_pakets[1],
                                                    tetrisShape.numToColor(bt_pakets[2]), P2));
}

void
Game::updateGame()
{
  if(digitalRead(MOVE_LEFT_BTN_PIN) == HIGH) {
    tetrisMove.moveLeftShape(tetrisWorld.getShape(), tetrisWorld.getWorld());
    buffer[0] |= MOVE_LEFT_MASK;
  }
  if(digitalRead(MOVE_RIGHT_BTN_PIN) == HIGH) {
    tetrisMove.moveRightShape(tetrisWorld.getShape(), tetrisWorld.getWorld());
    buffer[0] |= MOVE_RIGHT_MASK;
  }
  if(digitalRead(ROT_BTN_PIN) == HIGH) {
    tetrisRot.rotShape(tetrisWorld.getShape(), tetrisWorld.getWorld());
    buffer[0] |= ROT_MASK;
  }
  if(!tetrisMove.moveDownShape(tetrisWorld.getShape(), tetrisWorld.getWorld())) {
    tetrisWorld.checkWorld();
    tetrisWorld.setShape(tetrisShape.createRndShape(P1, buffer));
  }
  SerialBT.write(buffer, 3);
  delay(BT_TIME);
  bt_pakets[0] = SerialBT.read();
  bt_pakets[1] = SerialBT.read();
  bt_pakets[2] = SerialBT.read();
  if(bt_pakets[0] & MOVE_LEFT_MASK)
    tetrisMove.moveLeftShape(tetrisWorld.getEnemyShape(), tetrisWorld.getWorld());
  if(bt_pakets[0] & MOVE_RIGHT_MASK)
    tetrisMove.moveRightShape(tetrisWorld.getEnemyShape(), tetrisWorld.getWorld());
  if(bt_pakets[0] & ROT_MASK)
    tetrisRot.rotShape(tetrisWorld.getEnemyShape(), tetrisWorld.getWorld());
  if(!tetrisMove.moveDownShape(tetrisWorld.getEnemyShape(), tetrisWorld.getWorld())) {
    tetrisWorld.checkWorld();
    tetrisWorld.setEnemyShape(tetrisShape.createShape((Tetromino)bt_pakets[1],
                                                      tetrisShape.numToColor(bt_pakets[2]), P2));
  }
  tetrisWorld.drawWorld();
  buffer[0] = 0;
  buffer[1] = 0;
  buffer[2] = 0;
}
