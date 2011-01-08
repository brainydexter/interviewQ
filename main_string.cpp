#include "Problems_String.h"

#include <stdio.h>
#include <string.h>		// C string operations
#include <string>		// c++ string operations

int (*gPrintFn)( const char * format, ... ) = NULL;

int main()
{
	gPrintFn = printf;

	char p_str[] = "Now is the winter of our discontent made glorious summer by this son of York";

	gPrintFn("Old string %s \n", p_str);

	ReverseWordsOrder_Sentence_String(p_str);

	gPrintFn("New string %s \n", p_str);

	return 1;
}