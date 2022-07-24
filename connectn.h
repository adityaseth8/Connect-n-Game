#ifndef CONNECTN_H
  #define CONNECTN_H
    #include <stdbool.h>
  void setupGame(int rows, int columns, char blank_char, char*** board, int* cur_player_turn);
  int choose_who_goes_first();
  void play_game(int rows, int cols, char blank_char, char** board, 
			int cur_player_turn, int num_pieces_to_win, char* playerPieces);
  void display_current_game_state(char** board, int rows, int cols);
  void get_valid_move(int* columnPlayed, char** board, int rows, int columns, char blank_char);
  bool validInput(int num);
  bool validMove(int move, char** board, int rows, int cols, char blankChar, int num_args_reads);
  void make_move(int move, char blankChar, char** board, int rows, int col, char playerPiece);  
  void changeTurn(int* currentPlayerTurn, int numPlayers);
  int GameOver(char** board, int rows, int cols, char blankChar, int numPiecesToWin, char playerPiece);
  void displayResults(char** board, int rows, int cols, char blank_char, int cur_player_turn, int numPiecesToWin, char playerPiece);
  void deleteBoard(char*** board, int row, int col);
#endif