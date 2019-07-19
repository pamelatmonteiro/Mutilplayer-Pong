void game_display(){

  // Display ball
  gb.display.fillRect(ball_posX, ball_posY, ball_size, ball_size);

  
  // Display paddle1
  gb.display.fillRect(paddle1_posX, paddle1_posY, paddle_width, paddle_height);

  
  // Display paddle2
  gb.display.fillRect(paddle2_posX, paddle2_posY, paddle_width, paddle_height);


  // Display scores
  gb.display.setCursor(35, 5);
  gb.display.print(score1);
  gb.display.setCursor(42, 5);
  gb.display.print(score2);
}
  
