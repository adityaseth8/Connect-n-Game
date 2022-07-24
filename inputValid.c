#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "inputValid.h"

//code from Prof Butner
bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character;
  do{
    scanf("%c", &character); 
		if(!isspace(character)){ 
			formatIsGood = false;
		}
	}while(character != '\n'); 
  return formatIsGood;
}

void CmdLineInputVal(int argc, char** argv, int* num_rows, 
            int* num_cols, int* num_pieces_to_win) {
  if (argc == 4) {
    sscanf(argv[1], "%d", num_rows);
		sscanf(argv[2], "%d", num_cols);
		sscanf(argv[3], "%d", num_pieces_to_win);
  } else if (argc < 4) {
      printf("Not enough arguments entered\n");
		  printf("Usage connectn.out num_rows num_columns"
		  " number_of_pieces_in_a_row_needed_to_win\n");
		  exit(0);
  } else {
    printf("Too many arguments entered\n");
		printf("Usage connectn.out num_rows num_columns"
		" number_of_pieces_in_a_row_needed_to_win\n");
    exit(0);
  }

}