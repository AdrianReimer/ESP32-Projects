#include "Game.h"


static Game tetrisGame = Game();

void
setup()
{
  randomSeed(analogRead(RND_NOISE_PIN));
  pinMode(MOVE_LEFT_BTN_PIN, INPUT);
  pinMode(MOVE_RIGHT_BTN_PIN, INPUT);
  pinMode(ROT_BTN_PIN, INPUT);
  tetrisGame.setupGame();
}

void
loop()
{
  unsigned long t1 = millis();
  tetrisGame.updateGame();
  unsigned long t2 = millis();
  delay((WAIT_TIME_MS - (t2 - t1)) % WAIT_TIME_MS);
}
