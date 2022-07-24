#include <stdio.h>
#include "CheckForWin.h"
#include "connectn.h"
// #include "connectn_board.h"


// code inspiration from Professor Butner's Google Drive,
bool someone_won(int rows, int cols, char blank_char, char** board, int numPiecesToWin, char playerPieces){
	return someone_won_horizontally(board, rows, cols, blank_char, numPiecesToWin, playerPieces) ||
				 someone_won_vertically(board, rows, cols, blank_char, numPiecesToWin, playerPieces) ||
				 someone_won_diagonally(board, rows, cols, blank_char, numPiecesToWin, playerPieces);
}

bool someone_won_horizontally(char** board, int rows, int cols, char blank_char, int numPiecesToWin, char playerPieces){
	int count = 0;
	for (int i = 0; i < rows; ++i) {
		count = 0;
		for(int j = 0; j < cols; ++j) {
			if (board[i][j] == playerPieces) {
				++count;
				if (count == numPiecesToWin) {
					return true;
				}
			} else {
				count = 0;
			}
			}
		}
	return false;
}

bool someone_won_vertically(char** board, int rows, int cols, char blank_char, int numPiecesToWin, char playerPiece){
	int count = 0;
	for (int i = 0; i < cols; ++i) {
		count = 0;
		for(int j = 0; j < rows; ++j) {
			if (board[j][i] == playerPiece) {
				++count;
				if (count == numPiecesToWin) {
					return true;
				}
			} else {
				count = 0;
			}
			}
		}
	return false;
}

bool someone_won_diagonally(char** board, int rows, int cols, char blank_char, int numPiecesToWin, char piece){
	return someone_won_right_main_diagonal(board, rows, cols, blank_char, numPiecesToWin, piece) ||
				 someone_won_left_main_diagonal(board, rows, cols, blank_char, numPiecesToWin, piece);
}

bool someone_won_right_main_diagonal(char** board, int rows, int cols, char blank_char, int numPiecesToWin, char piece){
	/*Look for this type of win
	  2 1 0
	2 X	    
	1	X  
	0     X
	*/
// PROBLEM

	// start from main diagonal and work way up
	int count = 0;
	for(int startRow = 0; startRow < rows; ++startRow) {
		int curRow, curCol;
		for(curRow = startRow, curCol = 0; curRow < (rows - 1) && curCol < cols; ++curRow, ++curCol) {
			if(board[curRow][curCol] == piece) {
				++count;
				if(count == numPiecesToWin) {
					return true;
				}
			} else {
				count = 0;
			}
		}
	}

	// work way down
	count = 0;
	for(int startCol = 1; startCol < (cols - 1); ++startCol){
		int curRow, curCol;
		for(curRow = 0, curCol = startCol; curRow < rows && curCol < cols; ++curRow, ++curCol) {
			if(board[curRow][curCol] == piece) {
				++count;
				if(count == numPiecesToWin) {
					return true;
				}
			} else {
				count = 0;
			}
		}
	}

	// int count = 0;
	// for (int i = 0; i < (rows -1); ++i) {
	// 	int row, col;
	// 	for(row = i, col = 0; row < rows && col < cols; ++row, ++col) {
	// 		if(board[row][col] == piece) {
	// 			++count;
	// 			if(count == numPiecesToWin) {
	// 				return true;
	// 			}
	// 		} else {
	// 			count = 0;
	// 		}

	// 	}
	// }

	// count = 0;
	// for (int j = 0; j < (cols - 1); ++j){
	// 	int row, col;
	// 	for(row = 0, col = j; row < rows && col < cols; ++row, ++col) {
	// 		if(board[row][col] == piece) {
	// 			++count;
	// 			if(count == numPiecesToWin) {
	// 				return true;
	// 			}
	// 		} else {
	// 			count = 0;
	// 		}
	// 	}
	// }

	return false;
}

bool someone_won_left_main_diagonal(char** board, int rows, int cols, char blank_char, int numPiecesToWin, char piece){
	/*Look for this type of win
	  2 1 0
	2	  X
	1	X
	0 X
	*/
	int count = 0;
	for(int StartRow = 0; StartRow < (rows - 1); ++StartRow) {
		int CurrentRow, CurrentCol;
		for(CurrentRow = StartRow, CurrentCol = (cols - 1); CurrentRow < rows && CurrentCol >= 0; ++CurrentRow, --CurrentCol) {
			if(board[CurrentRow][CurrentCol] == piece) {
				++count;
				if(count == numPiecesToWin) {
					return true;
				}
			} else {
				count = 0;
			}
		}
	}	

	count = 0;
	for(int startCol = (cols -2); startCol >= 0; --startCol) {
		int curRow, curCol;
		for(curRow = 0, curCol = startCol; curRow < rows && curCol >= 0; ++curRow, --curCol) {
			if(board[curRow][curCol] == piece) {
				++count;
				if(count == numPiecesToWin) {
					return true;
				}
			} else {
				count = 0;
			}
		}
	}

// going from left to right (r+1, c + 1, r = c)
// going from right to left (r+1, c-1, )
	return 0;
}


bool tie_game(char** board, int rows, int cols, int blank_char){
	//only call this function after checking for a win
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(board[i][j] == blank_char) {
				return false;
			}
		}
	}
	return true;
}