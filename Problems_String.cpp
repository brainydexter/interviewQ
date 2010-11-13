#include "Problems_String.h"

#include <string.h>

void InPlaceReverse_String( char *pCharBuf )
{
	char * current = pCharBuf;

	// find length
	int length = 0;

	while( *current != '\0' )
	{
		length++;
		current++;
	}

	for (int i = 0; i < length/2; i++)
	{
		// swap i and length - i - 1
		char temp = pCharBuf[i];
		pCharBuf[i] = pCharBuf[length - i - 1];
		pCharBuf[length -i -1]  = temp;
	}
	pCharBuf[length]='\0';
}
