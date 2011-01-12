#include "Board.h"

#include <stdio.h>

#include <crtdbg.h>

int (*gPrintFn)( const char * format, ... ) = 0;

int main()
{
	gPrintFn = printf;

	char boardLetters [] = { 'y', 'o', 'x',
							 'r', 'b', 'a',
							 'y', 'e', 'd' 
							};
	
	Board* board = new Board("words.txt", 3, 3, boardLetters);
	board->ProcessAllWords();

	delete board;
	_CrtMemDumpAllObjectsSince(0);
	return 1;
}