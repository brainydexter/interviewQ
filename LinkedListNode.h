/*
The functions are based off the following places:
- http://cslibrary.stanford.edu/103/LinkedListBasics.pdf
- http://cslibrary.stanford.edu/105/LinkedListProblems.pdf
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct LinkedListNode
{
    LinkedListNode* next;
    int data;
};

LinkedListNode* Create123_LinkedList();

//************************************
// Method:    LinkedList_Length
// FullName:  LinkedList_Length
// Access:    public 
// Returns:   Number of nodes in the list
// Qualifier:
// Parameter: LinkedListNode * head
//************************************
unsigned int Length_LinkedList(LinkedListNode* head);

//************************************
// Method:    LinkedList_Insert
// FullName:  Inserts a new element to the list and replaces the new element to be the current element referenced by head
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: LinkedListNode * * head
// Parameter: int value
//************************************
void Insert_LinkedList(LinkedListNode** headRef, int value);

inline void InsertAtHead_LinkedList(LinkedListNode** headRef, int value)
{
    Insert_LinkedList(headRef, value);
}

// Appends a node at the end of the linked list
void InsertAtTail_LinkedList(LinkedListNode** headRef, int value);

// Copies a list using InsertAtTail_LinkedList
LinkedListNode* Copy_LinkedList(LinkedListNode* head);

// Copies a list
LinkedListNode* Copy0_LinkedList(LinkedListNode* head);

// Copies a list recursively
LinkedListNode* CopyRecursive_LinkedList(LinkedListNode* head);

void Print_LinkedList(LinkedListNode* head);

#endif
