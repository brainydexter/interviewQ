#include "LinkedListNode.h"

#include <stdio.h>
#include <iostream>
using namespace std;

int (*gPrintFn)( const char * format, ... ) = NULL;

int main()
{
    gPrintFn = printf;

    LinkedListNode* node = Create123_LinkedList();
     InsertAtTail_LinkedList(&node, 4);

    gPrintFn("Length of Linked List is: %d \n", Length_LinkedList(node));

    gPrintFn("Old Linked list: ");
    Print_LinkedList(node);

    LinkedListNode* copyList = CopyRecursive_LinkedList(node);
    gPrintFn("New linked list: ");
    Print_LinkedList(copyList);

    return 1;
}