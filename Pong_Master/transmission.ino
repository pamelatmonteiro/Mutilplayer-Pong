////////////////////////////////////// Sends the infos to the Slave

void Master_write () {

  Wire.beginTransmission(1);

  //change the paddle position
  Wire.write(4);
  Wire.write(paddle2_posY);

  //change the ball position
  Wire.write(5);
  Wire.write(ball_posX);
  Wire.write(6);
  Wire.write(ball_posY);

  //change the score
  Wire.write(7);
  Wire.write(score1);
  Wire.write(8);
  Wire.write(score2);


  Wire.endTransmission();


}

////////////////////////////////////// Request infos from Slave
int i = 0;

void Master_read () {

  Wire.requestFrom(1, 2);
  int c[2] = {0, 0};


  while (1 <= Wire.available()) { // loop through all but the last
    c[i] = Wire.read(); // receive byte as a character
    i++;
  }

  if (c[0] == 2) {
    paddle1_posY = c[1];
  }
  else {
    gb.display.clear();
    gb.display.print("ERROR");
    gb.display.print(c[1]);
  }

  //    i=0;
  //
  //    switch (c[0]) {
  //      case NET_PADDLEPOS1_Y :
  //        paddle1_posY = c[1]; // The padlle position is sent
  //        break;
  //    }




}
