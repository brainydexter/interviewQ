#include "LinkedListNode.h"
#include "Problems_LinkedList.h"

#include <stdio.h>
#include <iostream>
using namespace std;

int (*gPrintFn)( const char * format, ... ) = NULL;

int main()
{
    gPrintFn = printf;

    // LinkedListNode* node = Create123_LinkedList();
    
    // gPrintFn("Old Linked list: "); Print_LinkedList(node);

    /*
    InsertAtTail_LinkedList(&node, 1);

    gPrintFn("Length of Linked List is: %d \n", Length_LinkedList(node));

    gPrintFn("Old Linked list: ");
    Print_LinkedList(node);

    LinkedListNode* copyList = CopyRecursive_LinkedList(node);
    gPrintFn("New linked list: ");
    Print_LinkedList(copyList);

    gPrintFn("1 occurs %d times in list \n", CountN_LinkedList(node, 1));

    for(int i = 0; i < Length_LinkedList(node); i++)
    {
        gPrintFn("Index %d :: Element in list: %d \n", i, GetNth_LinkedList(node, i) );
    }

    Delete_LinkedList(&node);
    

    int val = Pop_LinkedList(&node);

    gPrintFn("New Linked list: "); Print_LinkedList(node);
	*/

	LinkedListNode* node = 0;

	InsertNth_LinkedList(&node, 0, 13);
	InsertNth_LinkedList(&node, 1, 42);
	InsertNth_LinkedList(&node, 1, 5);

    return 1;
}