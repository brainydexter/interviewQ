#include "Board.h"

#include <stdio.h>

int (*gPrintFn)( const char * format, ... ) = 0;

int main()
{
	gPrintFn = printf;

	Board board;

	board.ProcessAllWords();

	return 1;
}