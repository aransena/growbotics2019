// Aran Sena 2019
// Naughts & Crosses

// Board size declared here so we can easily change it
// Also makes code more readable
const int num_rows = 3;
const int num_cols = 3;

// Board tokens declared here so we can easily change them.
const char empty = ' ';
const char p1 = 'x';
const char p2 = 'o';

// Board memory declared globally for ease of access in functions
char board[num_rows][num_cols]; 

// Function to draw current board state
void boardDraw() {
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      Serial.print(board[i][j]);
      if (j != num_cols - 1) {
        Serial.print('|');
      }
    }
    Serial.print("\n");
    if (i != num_rows - 1) {
      Serial.print("- - -");
      Serial.print("\n");
    }
  }
  Serial.print("\n");
}

// Function to update board state for a move
// Verifies move is legal
void place(String cmd, char player){
  int i = (int)cmd[1]-48; // Convert from char to int (ASCII)
  int j = (int)cmd[2]-48; // Convert from char to int (ASCII)
  if(board[i][j]!=empty){
    Serial.println("Illegal Move, occupied");
  }
  else{
    if(i<num_rows && i>=0 && j>=0 && j<num_cols){
      board[i][j] = player;
    }
    else{
      Serial.println("Illegal Move, out of bounds");
    }
  }
  
}

// Check to see if there has been a draw
// Checks to see if there are no more possible moves
bool checkDraw(){
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      if(board[i][j] == empty){
        return false;
      }
    }
  }
  return true;
}

// Checks to see if there has been a win
// Looks for 3 of the player's tokens along any row, column,
// or either of the two diagonals
bool checkWin(char player){
  bool win = false;
  int win_count = 3;
  // Check rows
  int row_chk = 0;
  for(int i=0; i<num_rows; i++){
    for(int j=0; j<num_cols; j++){
      if(board[i][j] == player){
        row_chk++;
      }
    }
    if(row_chk == 3){ // If 3 player tokens found in the row
        win = true;
        break; // Break out of the loop, we've found what we want
    }
    row_chk = 0;
  }
  // Check columns
  int col_chk = 0;
  for(int j=0; j<num_cols; j++){
    for(int i=0; i<num_rows; i++){
      if(board[i][j] == player){
        col_chk++;
      }
    }
    if(col_chk == 3){
      win=true;
      break;
    }
    col_chk = 0;
  }
  // Check diagonal 1
  int diag_chk = 0;
  for(int i=0; i<num_rows; i++){
      if(board[i][i] == player){
        diag_chk++;
      }else{
        break;
      }
  }
  if(diag_chk == win_count){
    win = true;
  }
  diag_chk = 0;
  
  // Check diagonal 2
  for(int j=num_cols-1; j>=0; j--){
    if(board[num_rows-j-1][j] == player){
      diag_chk++;
    }
  }
  if(diag_chk == win_count){
    win = true;
  }
  diag_chk = 0;
  return win;
}

void boardReset(){
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      board[i][j] = empty;
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Initialise the board
  boardReset();
  boardDraw();

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    // Read the player command
    String cmd = Serial.readStringUntil(13);
    char player;
    if(cmd[0] == '1'){
      player = p1;
    }else{
      player = p2;
    }
    // Could add code here to verify that the correct
    // player has taken a turn.
    // Execute the players action
    place(cmd, player);
    // Redraw board
    boardDraw();
    // Check for a win
    if(checkWin(player)){
      Serial.print(player);
      Serial.println(" has won!\n");
      boardReset();
      boardDraw();
    }else if(checkDraw()){ // Check for a draw if not a win
      Serial.println("Draw!\n");
      boardReset();
      boardDraw();
    }
    // If neither win or draw, play continues.
  }

}
