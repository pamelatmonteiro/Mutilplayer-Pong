/*The slave receives these informations from the master :
  - the paddle position of player2
  - the ball position
  - the score update */

////////////////////////////////////// Sends the infos to the Master

void requestEvent() {

  Wire.write(2);
  Wire.write(paddle1_posY);
}

////////////////////////////////////// Receives the infos from the Master
int i = 0;

void receiveEvent(int HowMany) {

  int c[2] = {0, 0};


  while (1 <= Wire.available()) { // loop through all but the last
    c[i] = Wire.read(); // receive byte as a character
    i++;
  }
  i = 0;

  gb.display.print(c[1]);

  if (c[0] == 4) {
    paddle2_posY = c[1];
  }
  else if (c[0] == 5) {
    ball_posX = c[1];
  }
  else if (c[0] == 6) {
    ball_posY = c[1];
  }
  else if (c[0] == 7) {
    score1 = c[1];
  }
  else if (c[0] == 8) {
    score2 = c[1];
  }
  else {
    gb.display.clear();
    gb.display.print("ERROR");
  }

  //  switch (c[0]) {
  //    case NET_PADDLEPOS2_Y  :
  //      paddle2_posY = c[1]; // The padlle position is sent
  //      break;
  //
  //    case NET_BALPOS_X :
  //      ball_posX = c[1]; // The X position of the ball is sent
  //      break;
  //
  //    case NET_BALPOS_Y :
  //      ball_posY = c[1]; // The Y position of the ball is sent
  //      break;
  //
  //    case NET_SCORE_1 :
  //      score1 = c[1]; // The Y position of the ball is sent
  //      break;
  //
  //    case NET_SCORE_2 :
  //      score2 = c[1]; // The Y position of the ball is sent
  //      break;
  //
  //
  //
  //
  //  }
}
