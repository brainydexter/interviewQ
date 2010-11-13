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

// insert element with value at index (0 .. length) (inclusive of both 0 and length)
void InsertNth_LinkedList(LinkedListNode** headRef, int index, int value);

// list is in increasing order, this function inserts newNode in it at the correct sorted position in the list
void SortedInsert_LinkedList(LinkedListNode** headRef, LinkedListNode* newNode);

// Given a list; rearranges its nodes so they are sorted in the increasing order
void InsertSort_LinkedList(LinkedListNode** headRef);

// Appends b list onto the end of a. Sets b to NULL
void Append_LinkedList(LinkedListNode** AHeadRef, LinkedListNode** BHeadRef);

// Given a list, split it into two sublists
// if number of elements is odd, extra element should go in front list
void FrontBackSplit_LinkedList(LinkedListNode** headRef, LinkedListNode** Alist, LinkedListNode** Blist);

// Remove/delete Duplicates from sorted (increasing) list
// traverse only once
void RemoveDuplicates_SortedLinkedList(LinkedListNode** headRef);

// Remove B's head => Push B's Head onto front of A
// assert if the sources are empty
void MoveNode_LinkedList(LinkedListNode** aHeadRef, LinkedListNode** bHeadRef);

// splits original list into two lists where each child list contains alternating elements from original list
void AlternatingSplit_LinkedList(LinkedListNode** headRef, LinkedListNode** Alist, LinkedListNode** Blist);

// Merges nodes from two list to return one list
LinkedListNode* ShuffleMerge_LinkedList(LinkedListNode* Alist, LinkedListNode* Blist);

// Given 2 lists in increasing order
// Returns a sorted merge list
LinkedListNode* SortedMerge_LinkedList(LinkedListNode* Alist, LinkedListNode* Blist);

// given a list => split the list into two smaller lists and merge them into a single sorted list
void MergeSort_LinkedList(LinkedListNode** headRef);

// Returns a linked list representing intersection of two linked lists: Alist and Blist, where Alist and Blist are sorted
LinkedListNode* SortedIntersect_LinkedList(LinkedListNode* Alist, LinkedListNode* Blist);

// reverses a given linked list iteratively in place; by rearranging pointers
void ReverseIterative_LinkedList(LinkedListNode** headRef);

// reverses a given linked list recursively in place; by rearranging pointers
void ReverseRecursive_LinkedList(LinkedListNode** headRef);

// returns the Nth node from end of the linked list
LinkedListNode* NFromEnd_LinkedList( LinkedListNode* head, int N);
#endif
