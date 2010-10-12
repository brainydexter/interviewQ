/*
The functions are based off the following places:
- http://cslibrary.stanford.edu/105/LinkedListProblems.pdf
*/

#ifndef PROBLEMS_LINKEDLIST_H
#define PROBLEMS_LINKEDLIST_H

#include "LinkedListNode.h"

// Counts the number of times a given value occurs in a list
unsigned int CountN_LinkedList(LinkedListNode* head, int value);

// Returns the data stored in node at index position ( 0 <= index <= Length - 1)
int GetNth_LinkedList(LinkedListNode* head, unsigned int index);

// deallocates all of its memory and set its head pointer to 0
void Delete_LinkedList(LinkedListNode** headRef);

// input is a non-empty list. Deletes head node. Return head node's data
int Pop_LinkedList(LinkedListNode** headRef);

#endif
