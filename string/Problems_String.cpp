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

// Deletes characters in str that belong to remove[]
// O(n) time and O(256) space
void RemoveChars(char str[], char remove[])
{
    /*
     - for each char in str
     - if ch is a part of remove[]
     - remove ch

     deleting elements from str:
     - readIndex = writeIndex = 0
     - readIndex++ => ch
     - if ch is not part of remove:
      - write ch at writeIndex
      - writeIndex++
     - else // part of remove
      - dont write ch or increment writeIndex
     */
    bool blackListChars[256];
    for (int i = 0; i < 256; ++i)
        blackListChars[i] = false;

    while(*remove)
    {
        blackListChars[ *remove] = true;
        remove++;
    }

    int writeIndex = 0;
    for(int readIndex = 0; str[readIndex] != '\0'; readIndex++)
    {
        char ch = str[readIndex];
        if(blackListChars[ch] == false)
        {
            str[writeIndex] = ch;
            writeIndex++;
        }
    }
    str[writeIndex] = '\0';
}