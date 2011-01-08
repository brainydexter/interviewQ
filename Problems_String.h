#ifndef PROBLEMS_STRING_H
#define PROBLEMS_STRING_H

// reverses the string in place : Hello => olleH
void InPlaceReverse_String( char *pCharBuf, int len = 0 );	// len = 0 => string is Null terminated otherwise not

// reverses the order of words in a sentence: This is it => it is This
void ReverseWordsOrder_Sentence_String(char *pCharBuf);

// Returns the length of the string
unsigned int Length_String(char *pCharBuf);


#endif