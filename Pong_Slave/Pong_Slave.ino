#include <Wire.h>
#include <Gamebuino-Meta.h>

//////////////////I2C parameters
#define NET_PADDLEPOS1_X 1
#define NET_PADDLEPOS1_Y 2
#define NET_PADDLEPOS2_X 3
#define NET_PADDLEPOS2_Y 4
#define NET_BALPOS_X 5
#define NET_BALPOS_Y 6
#define NET_SCORE_1 7
#define NET_SCORE_2 8

// ball attributes
int ball_posX = 20;
int ball_posY = 20;
int ball_speedX = 1;
int ball_speedY = 1;
int ball_size = 4;

// paddle1 attributes
int paddle1_posX = 10;
int paddle1_posY = 30;

// paddle2 attributes
int paddle2_posX = gb.display.width() - 13;
int paddle2_posY = 30;

// Dimension of both paddles
int paddle_height = 10;
int paddle_width = 3;

// Scores
int score1;  // Player 1 score
int score2;  // Player 2 score


void setup() {
  gb.begin();
  Wire.begin(1);        // join i2c bus

}

void loop() {

  while (!gb.update());
  gb.display.clear();

  game_display();
  Wire.onReceive(receiveEvent);
  update_game();  
  Wire.onRequest(requestEvent);
  update_game();  



}
