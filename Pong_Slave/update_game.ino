// The slave only updates the paddle postition of player 1

void update_game() {

    //////////////////////////////////////// Change the paddle position of player 1
  if (gb.buttons.repeat(BUTTON_UP, 0)) {
    paddle1_posY = paddle1_posY - 1;
  }

  if (gb.buttons.repeat(BUTTON_DOWN, 0)) {
    paddle1_posY = paddle1_posY + 1;

  }
  
}
