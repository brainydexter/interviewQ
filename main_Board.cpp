#include "Board.h"

#include <stdio.h>

#include <crtdbg.h>

int (*gPrintFn)( const char * format, ... ) = 0;

const int MAX_CAPACITY = 9;

int main()
{
	gPrintFn = printf;

	char boardLetters [MAX_CAPACITY] = { 'y', 'o', 'x',
							 'r', 'b', 'a',
							 'y', 'e', 'd' 
							};

	int numRows = 3;
	int numCols = 3;
	
	if( numRows * numCols == MAX_CAPACITY)
	{
		Board* board = new Board("words.txt", numRows, numCols, boardLetters);
		board->ProcessAllWords();

		delete board;
	}
	else
	{
		gPrintFn("Board dimensions don't match to the board letters provided");
	}

	_CrtMemDumpAllObjectsSince(0);
	return 1;
}