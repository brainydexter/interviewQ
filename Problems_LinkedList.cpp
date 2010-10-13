#include "Problems_LinkedList.h"

extern int (*gPrintFn)( const char * format, ... );

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

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	insert element with value at index (0 .. length) </summary>
/// <param name="index">	Zero-based index </param>
/// <param name="value">	Element's value. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertNth_LinkedList(LinkedListNode** headRef, int index, int value)
{
	// assert is index is not between 0..length (both inclusive => this is imp criterion)

	gPrintFn("Before inserting into Linked List:"); Print_LinkedList(*headRef);

	// PS: The same can be implemented using Insert_LinkedList(). I just wrote the complete raw version here
	if( index == 0 ) // Begininning of list
	{
		LinkedListNode* node = new LinkedListNode();
		node->data = value;
		node->next = *headRef;
		
		*headRef = node;
	}
	else
	{
		LinkedListNode* current = *headRef;
		int i = 0;

		while(current != 0)
		{
			if(i == index - 1)
			{
				LinkedListNode* node = new LinkedListNode();
				node->data = value;
				node->next = current->next;

				current->next = node;
				break;
			}

			current = current->next;
		}
	}

	gPrintFn("After inserting into Linked List:"); Print_LinkedList(*headRef);
}

// list is in increasing order, this function inserts newNode in it at the correct sorted position in the list
void SortedInsert_LinkedList( LinkedListNode** headRef, LinkedListNode* newNode )
{
    // using a dummy header enables to write a generic while loop
    LinkedListNode dummy;
    dummy.next = *headRef;

    LinkedListNode* current = &dummy;

    while (current->next != 0 && newNode->data > current->next->data)   //current->next since current is initialized with dummy
    {
        current = current->next;
    }

    //found location where to insert
    newNode->next = current->next;
    current->next = newNode;

    *headRef = dummy.next;
}

void InsertSort_LinkedList( LinkedListNode** headRef )
{
    LinkedListNode* result = 0;
    LinkedListNode* current = *headRef;
    LinkedListNode* nextNode = 0;

    while (current != 0)
    {
        nextNode = current->next;
        SortedInsert_LinkedList(&result, current);

        current = nextNode;
    }

    *headRef = result;
}

// Appends b list onto the end of a. Sets b to NULL
void Append_LinkedList( LinkedListNode** AHeadRef, LinkedListNode** BHeadRef )
{
    LinkedListNode dummyHA;
    dummyHA.next = *AHeadRef;

    LinkedListNode* currentA = &dummyHA;

    while (currentA->next != 0)
    {
        currentA = currentA->next;
    }

    // currentA now points to the last element of A
    // B should be appended to A here
    currentA->next = *BHeadRef;

    *AHeadRef = dummyHA.next;

    *BHeadRef = 0;
}

// Given a list, split it into two sublists
// if number of elements is odd, extra element should go in front list
void FrontBackSplit_LinkedList( LinkedListNode** headRef, LinkedListNode** Alist, LinkedListNode** Blist )
{
    int numElements = Length_LinkedList(*headRef);
    int i = 0;

    LinkedListNode* current = *headRef;
    LinkedListNode* Atail, *Acurrent = 0;
    LinkedListNode* Bcurrent = 0;

    *Alist = current;
    Acurrent = *Alist;
    Atail = Acurrent;

    while (i < (numElements/2) )
    {
        Atail = current;
        current = current->next;
        i++;
    }

    // Pointing BList to the right address
    *Blist = current;

    // cutting off list A
    while( Acurrent != Atail)
    {
        Acurrent = Acurrent->next;
    }
    Acurrent->next = 0;

    // if odd number of elements: move B's head to be A's tail
    // Acurrent is the tail of A
    if (numElements%2 != 0)
    {
        Bcurrent = *Blist;

        // updated B list
        *Blist = Bcurrent->next;

        Acurrent->next = Bcurrent;
        Bcurrent->next = 0;
    }
}

void RemoveDuplicates_SortedLinkedList( LinkedListNode** headRef )
{
    LinkedListNode* current = *headRef;

    while(current != 0)
    {
        while(current->next!= 0 && current->data == current->next->data)
        {
            LinkedListNode* node = current->next;
            current->next = current->next->next;

            delete node;
        }

        current = current->next;
    }
}

// Remove B's head => Push B's Head onto front of A
// assert if the sources are empty
void MoveNode_LinkedList( LinkedListNode** aHeadRef, LinkedListNode** bHeadRef )
{
// assert if a or b list is empty

    LinkedListNode* bHead = *bHeadRef;
    *bHeadRef = (*bHeadRef)->next;

    bHead->next = *aHeadRef;
    *aHeadRef = bHead;
}


// splits original list into two lists where each child list contains alternating elements from original list
void AlternatingSplit_LinkedList( LinkedListNode** headRef, LinkedListNode** Alist, LinkedListNode** Blist )
{
    int i = 0;

    while (*headRef != 0)
    {
        if ( i%2 == 0)
        {
            InsertAtTail_LinkedList(Alist, (*headRef)->data);
        } 
        else
        {
            InsertAtTail_LinkedList(Blist, (*headRef)->data);
        }

        *headRef = (*headRef)->next;
        i++;
    }
}

