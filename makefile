connectn.out: main.o connectn.o connectn_board.o CheckForWin.o inputValid.o
	gcc -g -Wall -Werror -o connectn.out main.o connectn.o connectn_board.o CheckForWin.o inputValid.o

main.o: main.c connectn.h inputValid.h
	gcc -g -Wall -Werror -c main.c

connectn.o: connectn.c connectn.h connectn_board.h CheckForWin.h inputValid.h
	gcc -g -Wall -Werror -c connectn.c

connectn_board.o: connectn_board.c connectn_board.h
	gcc -g -Wall -Werror -c connectn_board.c

CheckForWin.o: CheckForWin.c CheckForWin.h connectn.h
	gcc -g -Wall -Werror -c CheckForWin.c

inputValid.o: inputValid.c inputValid.h
	gcc -g -Wall -Werror -c inputValid.c

clean:
	rm -rf *.o *.out