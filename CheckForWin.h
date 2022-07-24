#ifndef CHECKFORWIN_H
  #define CHECKFORWIN_H
	#include <stdbool.h>
	bool someone_won(int rows, int cols, char blank_char, char** board, int numPiecesToWin, char playerPieces);
	bool someone_won_horizontally(char** board, int rows, int cols, char blank_char, int numPiecesToWin, char playerPieces);
	bool someone_won_vertically(char** board, int rows, int cols, char blank_char, int numPiecesToWin, char playerPiece);
	bool someone_won_diagonally(char** board, int rows, int cols, char blank_char, int numPiecesToWin, char piece);
	bool someone_won_right_main_diagonal(char** board, int rows, int cols, char blank_char, int numPiecesToWin, char piece);
	bool someone_won_left_main_diagonal(char** board, int rows, int cols, char blank_char, int numPiecesToWin, char piece);
	bool tie_game(char** board, int rows, int cols, int blank_char);
#endif