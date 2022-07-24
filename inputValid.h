#ifndef INPUTVALID_H
	#define INPUTVALID_H
	bool isValidFormat(const int numArgsRead, const int numArgsNeed);
	void CmdLineInputVal(int argc, char** argv, int* num_rows, 
            int* num_cols, int* num_pieces_to_win);

#endif