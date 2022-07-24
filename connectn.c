#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "connectn.h"
#include "connectn_board.h"
#include "CheckForWin.h"
#include "inputValid.h"

void setupGame(int rows, int columns, char blank_char, char*** board, int* cur_player_turn) {
    *board = setupBoard(rows, columns, blank_char);
    *cur_player_turn = choose_who_goes_first();
}

int choose_who_goes_first(){
    return 0;
}

void play_game(int rows, int cols, char blank_char, char** board, 
			int cur_player_turn, int num_pieces_to_win, char* playerPieces) {
	int col_played;
	const int num_players = 2;
	while (true){
		display_current_game_state(board, rows, cols);
		get_valid_move(&col_played, board, rows, cols, blank_char);
		make_move(col_played, blank_char, board, rows, cols, playerPieces[cur_player_turn]);
		if(GameOver(board, rows, cols, blank_char, num_pieces_to_win, playerPieces[cur_player_turn])){
			break;
		}
		changeTurn(&cur_player_turn, num_players);
	}
	displayResults(board, rows, cols, blank_char, cur_player_turn, num_pieces_to_win, playerPieces[cur_player_turn]);
}

void display_current_game_state(char** board, int rows, int cols) {
	printBoard(rows, cols, board);
}

void get_valid_move(int* columnPlayed, char** board, int rows, int columns, char blank_char) {
	int num_args_read;
	do {
		printf("Enter a column between 0 and %d to play in: ", (columns-1));
		num_args_read = scanf("%d", columnPlayed);
	}while(!validMove(*columnPlayed, board, rows, columns, blank_char, num_args_read));
}
// for the empty array
bool validInput(int num) {
  if (num > 0){
    return true;
  }
  return false;
}

// every time we input stuff for the move
bool validMove(int move, char** board, int rows, int cols, char blankChar, int num_args_read) {
  const int num_args_needed = 1;

  return isValidFormat(num_args_read, num_args_needed) &&
		is_inside_board(move, cols) && spot_is_empty (board, move, rows, cols, blankChar);
}

void make_move(int move, char blankChar, char** board, int rows, int col, char playerPiece){
	// for loop to go through each row in the column (from the bottom up) to see if it's empty
		// first one that's empty just assign that r/c to the move
	for (int i = (rows - 1); i >= 0; --i) {
		if(board[i][move] == blankChar) {
			board[i][move] = playerPiece;
			// board[i][move] = playerSymbol(currentPlayerTurn);
			break;
		} else {
			continue;
		}
	}
}

// char playerSymbol(int currentPlayerTurn) {
// 	if(currentPlayerTurn == 0) {
// 		return 'X';
// 	}
// 	return 'O';
// }

void changeTurn(int* currentPlayerTurn, int numPlayers) {
	*currentPlayerTurn = (*currentPlayerTurn + 1) % numPlayers;
}

int GameOver(char** board, int rows, int cols, char blankChar, int numPiecesToWin, char playerPiece) {
	return someone_won(rows, cols, blankChar, board, numPiecesToWin, playerPiece) ||
		tie_game(board, rows, cols, blankChar);
}

void displayResults(char** board, int rows, int cols, char blank_char, int cur_player_turn, int numPiecesToWin, char playerPiece){
	printBoard(rows, cols, board);
	if (someone_won(rows, cols, blank_char, board, numPiecesToWin, playerPiece)) {
		printf("Player %d Won!\n", cur_player_turn + 1);
	} else {
		printf("Tie game!\n");
	}
}

void deleteBoard(char*** board, int row, int col) {
    for(int i = 0; i < row; i++) {
        free((*board)[i]);
        }
        free (*board);
        *board = NULL;
}