#include "LinkedListNode.h"

extern int (*gPrintFn)( const char * format, ... );

LinkedListNode* Create123_LinkedList()
{
    LinkedListNode* head = 0;

    Insert_LinkedList(&head, 3);
    Insert_LinkedList(&head, 2);
    Insert_LinkedList(&head, 1);

    return head;
}

unsigned int Length_LinkedList( LinkedListNode* head )
{
    LinkedListNode* current = head;

    int length = 0;

    while (current != 0)
    {
        length++;

        current = current->next;
    }

    return length;
}

void Insert_LinkedList( LinkedListNode** headRef, int value )
{
    LinkedListNode* node = new LinkedListNode();
    node->data = value;
    node->next = *headRef;

    *headRef = node;

    gPrintFn("New Element inserted. Head is %d \n", (*headRef)->data);
}

void Print_LinkedList( LinkedListNode* head )
{
    LinkedListNode* current = head;

    while(current != 0)
    {
        gPrintFn(" %d ", current->data);

        // print slew
        if(current->next != 0)
            gPrintFn("->");

        current = current->next;
    }

    gPrintFn("\n");
}

void InsertAtTail_LinkedList( LinkedListNode** headRef, int value )
{
    LinkedListNode* current = *headRef;

    if (current == 0)       // special case if Linked list is empty
    {
        Insert_LinkedList(headRef, value);
    } 
    else
    {
        while (current->next != 0)
        {
            current = current->next;
        }

        Insert_LinkedList(&(current->next), value);
    }
}

LinkedListNode* Copy_LinkedList( LinkedListNode* head )
{
    LinkedListNode* current = head;

    LinkedListNode* newHead = 0;

    while (current != 0)
    {
        InsertAtTail_LinkedList(&newHead, current->data);

        current = current->next;
    }

    return newHead;
}

LinkedListNode* Copy0_LinkedList( LinkedListNode* head )
{
    LinkedListNode* current = head;

    LinkedListNode* newHead = 0;
    LinkedListNode* tail = 0;

    while (current != 0)
    {
        if(newHead == 0)
        {
            newHead = new LinkedListNode();
            newHead->data = current->data;
            newHead->next = 0;

            tail = newHead;
        }
        else        // add rest of the elements to the tail of list so that elements are not added in reverse
        {
            tail->next = new LinkedListNode();
            tail->next->data = current->data;
            tail->next->next = 0;

            tail = tail->next;
        }

        current = current->next;
    }

    return newHead;
}

LinkedListNode* CopyRecursive_LinkedList( LinkedListNode* head )
{
    LinkedListNode* node = 0;

    if (head != 0)
    {
        node = new LinkedListNode();
        node->data = head->data;
        node->next = CopyRecursive_LinkedList(head->next);
    }

    return node;
}

