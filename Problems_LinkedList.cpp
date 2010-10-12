#include "Problems_LinkedList.h"


unsigned int CountN_LinkedList( LinkedListNode* head, int value )
{
    LinkedListNode* current = head;
    unsigned int count = 0;

    while (current != 0)
    {
        if(current->data == value)
            count++;

        current = current->next;
    }

    return count;
}

int GetNth_LinkedList( LinkedListNode* head, unsigned int index )
{
    // assert if index is not between 0 and length - 1
    
    LinkedListNode* current = head;
    int i = 0;
    int returnValue;

    while (current != 0)
    {
        if (i == index)
        {
            returnValue = current->data;
            break;
        }

        current = current->next;
        i++;
    }

    return returnValue;
}

void Delete_LinkedList( LinkedListNode** headRef )
{
    LinkedListNode* current = *headRef;

    while (current != 0)
    {
        LinkedListNode* nextNode = current->next;

        delete current;

        current = nextNode;
    }

    *headRef = 0;
}

// input is a non-empty list. Deletes head node. Return head node's data
int Pop_LinkedList( LinkedListNode** headRef )
{
    // assert if list is empty

    LinkedListNode* currentHead = *headRef;
    int returnValue = currentHead->data;

    *headRef = currentHead->next;

    delete currentHead;

    return returnValue;
}
