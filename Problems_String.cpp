#include "Problems_String.h"

extern int (*gPrintFn)( const char * format, ... );

//void InPlaceReverse_String( char *pCharBuf )
//{
//	// find length
//	unsigned int length = Length_String(pCharBuf);
//
//	for (int i = 0; i < length/2; i++)
//	{
//		// swap i and length - i - 1
//		char temp = pCharBuf[i];
//		pCharBuf[i] = pCharBuf[length - i - 1];
//		pCharBuf[length -i -1]  = temp;
//	}
//	pCharBuf[length]='\0';
//}

void InPlaceReverse_String( char *pCharBuf, int len )
{
	unsigned int length = len == 0 ? Length_String(pCharBuf) : len;
	
	for (int i = 0; i < length/2; i++)
	{
		// swap i and length - i - 1
		char temp = pCharBuf[i];
		pCharBuf[i] = pCharBuf[length - i - 1];
		pCharBuf[length -i -1]  = temp;
	}
}

void ReverseWordsOrder_Sentence_String(char *pCharBuf)
{
	InPlaceReverse_String(pCharBuf, 0);

	//gPrintFn("Reversed String %s\n", pCharBuf);

	char *newSentence = pCharBuf;

	while(*pCharBuf != '\0')
	{
		char *current = pCharBuf;
		// skip all extra whitespaces in between
		while( *current == ' ')
		{
			current++;
		}

		int length = 0;
		char *word = current;

		while(*current != ' ' && *current != '\0')
		{
			current++;
			length++;
		}

		//Reverse word with length(does not include terminating NULL character since the word is most likely a part of sentence)
		InPlaceReverse_String(word, length);

		

		pCharBuf = current;
	}

	pCharBuf = newSentence;
}

unsigned int Length_String(char *pCharBuf)
{
	int length = 0;

	while(*pCharBuf != '\0')
	{
		length++;
		pCharBuf++;
	}

	return length;
}