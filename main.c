#include <stdio.h>
#include <stdlib.h>
#include "connectn.h"
#include "inputValid.h"


int main(int argc, char** argv) {
	
	int num_rows;
	int num_cols;
	int num_pieces_to_win;
	CmdLineInputVal(argc, argv, &num_rows, &num_cols, &num_pieces_to_win);
	char** board;
	int cur_player_turn;
	char playerPieces[] = "XO";
	char blank_char = '*';
	setupGame(num_rows, num_cols, blank_char, &board, &cur_player_turn);
	play_game(num_rows, num_cols, blank_char, board, 
					cur_player_turn, num_pieces_to_win, playerPieces);
	deleteBoard(&board, num_rows, num_cols);
}