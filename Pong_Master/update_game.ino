void update_game() {

  //////////////////////////////////////// Change the paddle position of player 2
  if (gb.buttons.repeat(BUTTON_UP, 0)) {
    paddle2_posY = paddle2_posY - 1;
  }

  if (gb.buttons.repeat(BUTTON_DOWN, 0)) {
    paddle2_posY = paddle2_posY + 1;

  }
  /////////////////////////////////////// Update ball position
  ball_posX = ball_posX + ball_speedX;
  ball_posY = ball_posY + ball_speedY;


  ////////////////////////////////////// Collisions with walls
  if (ball_posY < 0) {
    ball_speedY = 1;
  }
  if (ball_posY > gb.display.height() - ball_size) {
    ball_speedY = -1;
  }


  ///////////////////////////////////// Ball-paddle1 collisions
  if ( (ball_posX == paddle1_posX + paddle_width)
       && (ball_posY + ball_size >= paddle1_posY)
       && (ball_posY <= paddle1_posY + paddle_height) ) {
    ball_speedX = 1;
  }


  ////////////////////////////////////// Ball-paddle2 collisions
  if ( (ball_posX + ball_size == paddle2_posX)
       && (ball_posY + ball_size >= paddle2_posY)
       && (ball_posY <= paddle2_posY + paddle_height) ) {
    ball_speedX = -1;
  }

  //////////////////////////////////// Check if the ball left the screen
  if (ball_posX < 0) {
    // Reset ball
    ball_posX = 20;
    ball_posY = 20;
    ball_speedX = 1;
    ball_speedY = 1;
    //  Increment player2's score
    score2 = score2 + 1;
  }

  if (ball_posX > gb.display.width()) {
    // Reset ball
    ball_posX = 20;
    ball_posY = 20;
    ball_speedX = 1;
    ball_speedY = 1;
    //Increment player1's score
    score1 = score1 + 1;
  }
}
