#ifndef CONNECTN_BOARD_H
  #define CONNECTN_BOARD_H
    #include <stdbool.h>
  char** setupBoard(int rows, int columns, char blankChar);
  void printBoard(int rows, int columns, char** board);
  bool is_inside_board(int columnPlayed, int col);
  bool is_between(int columnValue, int minValidNumber, int maxValidNumber);
  bool spot_is_empty(char** board, int columnPlayed, int rows, int cols, char blankChar);
  

#endif