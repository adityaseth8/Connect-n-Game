#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "connectn_board.h"

char** setupBoard(int rows, int columns, char blankChar){
    char** board = (char**)calloc(rows, sizeof(*board));
    for(int rowCounter = 0; rowCounter < rows; ++rowCounter){
        board[rowCounter] = (char*)calloc(columns, sizeof(*board[rowCounter]));
        for(int colCounter = 0; colCounter < columns; ++colCounter){
            board[rowCounter][colCounter] = blankChar;
        }
    }
    return board;
}

void printBoard(int rows, int columns, char** board){
    for(int i = 0; i < rows; ++i) {
        printf("%d ", rows - i -1);
        for(int j = 0; j < columns; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("  ");

    for(int i = 0; i < columns; ++i){
        printf("%d ", i);
    }

    printf("\n");
}

bool is_inside_board(int columnPlayed, int col) {
	return is_between(columnPlayed, 0, col - 1);
}

bool is_between(int columnValue, int minValidNumber, int maxValidNumber) {
	return columnValue >= minValidNumber && columnValue <= maxValidNumber; 
}

bool spot_is_empty(char** board, int columnPlayed, int rows, int cols, char blankChar) {
	for (int i = (rows - 1); i >= 0 ; --i) {
		if(board[i][columnPlayed] == blankChar){
			return true;
		} else {
			continue;
		}
	}
	return false;
}