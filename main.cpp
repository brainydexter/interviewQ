#include "LinkedListNode.h"
#include "Problems_LinkedList.h"

#include <stdio.h>
#include <iostream>
using namespace std;

int (*gPrintFn)( const char * format, ... ) = NULL;

int main()
{
    gPrintFn = printf;

     LinkedListNode* node = Create123_LinkedList();

//#define N 2
//     int array[N] = {0, 1};
//
//     for(int i = 0; i < N; i++)
//         InsertAtTail_LinkedList(&node, array[i]);

     gPrintFn("Old Linked list: "); Print_LinkedList(node);

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

	/*LinkedListNode* node = 0;

	InsertNth_LinkedList(&node, 0, 13);
	InsertNth_LinkedList(&node, 1, 42);
	InsertNth_LinkedList(&node, 1, 5);*/

     /*LinkedListNode* newNode = new LinkedListNode();
     newNode->data = 4;
     newNode->next = 0;

     SortedInsert_LinkedList(&node, newNode);*/

     //InsertSort_LinkedList(&node);
     
     /*LinkedListNode* list2 = Create123_LinkedList();
     Append_LinkedList(&node, &list2);*/

     /*LinkedListNode* a, *b; a = b =0;

     FrontBackSplit_LinkedList(&node, &a, &b);
     gPrintFn("A Linked list: "); Print_LinkedList(a);
     gPrintFn("B Linked list: "); Print_LinkedList(b);*/

     //RemoveDuplicates_SortedLinkedList(&node);

     /*LinkedListNode* list2 = Create123_LinkedList();

     MoveNode_LinkedList(&node, &list2);
     gPrintFn("New Linked list: "); Print_LinkedList(list2);*/

     /*LinkedListNode *a, *b; a= b= 0;
     AlternatingSplit_LinkedList(&node, &a, &b);

     gPrintFn("New A Linked list: "); Print_LinkedList(a);
     gPrintFn("New B Linked list: "); Print_LinkedList(b);*/

     gPrintFn("New Linked list: "); Print_LinkedList(node);
     

     return 1;
}