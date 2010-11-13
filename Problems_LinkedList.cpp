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

// Merges nodes from two list to return one list
LinkedListNode* ShuffleMerge_LinkedList( LinkedListNode* Alist, LinkedListNode* Blist )
{
    LinkedListNode dummy;

    LinkedListNode *current = &dummy;
    current->next = 0;      // initializing to 0 :: in case both A & B are empty => 

    while (Alist != 0 || Blist != 0)        // run till both A & B are not empty
    {
        if (Alist != 0)
        {
            current->next = Alist;
            current = current->next;

            Alist = Alist->next;
        }

        if (Blist != 0)
        {
            current->next = Blist;
            current = current->next;

            Blist = Blist->next;
        }
    }

    return dummy.next;
}

// Given 2 lists in increasing order
// Returns a sorted merge list
LinkedListNode* SortedMerge_LinkedList( LinkedListNode* Alist, LinkedListNode* Blist )
{
    LinkedListNode dummy;
    dummy.next = 0;

    LinkedListNode* current = &dummy;

    while( Alist != 0 && Blist != 0)
    {
            while( ( Alist != 0 && Blist != 0) &&       // need to check for null since lists are incremented in top most loop
                    ( Alist->data >= Blist->data )
                )
            {
                current->next = Blist;
                current = current->next;

                Blist = Blist->next;
            }

            while ( ( Alist != 0 && Blist != 0) &&      // need to check for null since lists are incremented in top most loop
                ( Blist->data >= Alist->data )
                  )
            {
                current->next = Alist;
                current = current->next;

                Alist = Alist->next;
            }
    }

    if(Alist != 0)
    {
        current->next = Alist;
    }

    if(Blist != 0)
    {
        current->next = Blist;
    }

    return dummy.next;
}

// returns true if the given list is sorted in creasing order
bool IsSorted_LinkedList( LinkedListNode* head ) 
{
    if(head == 0)               // list has no elements
        return false;

    if (head->next == 0)        // list has only 1 element
        return true;

    // list has atleast two elements

    while (
        (head->next != 0) &&
        (head->data < head->next->data)
        )
    {
        head = head->next;
    }
    // control reached here if tail is reached or list is not sorted

    if(head->next == 0)
        return true;
    else
        return false;
}

// given a list => split the list into two smaller lists and merge them into a single sorted list
void MergeSort_LinkedList( LinkedListNode** headRef )
{
    if (*headRef == 0 || (*headRef)->next == 0) // list is empty or only 1 element :: nothing much to do
    {
        return;
    }

    if(!IsSorted_LinkedList(*headRef))
    {
        LinkedListNode* Alist, *Blist;
        Alist = Blist = 0;

        FrontBackSplit_LinkedList(headRef, &Alist, &Blist);

        MergeSort_LinkedList(&Alist);
        MergeSort_LinkedList(&Blist);

        *headRef = SortedMerge_LinkedList(Alist, Blist);
    }
}

// Returns a linked list representing intersection of two linked lists: Alist and Blist, where Alist and Blist are sorted
LinkedListNode* SortedIntersect_LinkedList(LinkedListNode* Alist, LinkedListNode* Blist)
{
	LinkedListNode dummyNode;
	LinkedListNode* tail = &dummyNode;

	dummyNode.next = 0;

	while( Alist != 0 && Blist != 0)
	{
		if( Alist->data > Blist->data )
			Blist = Blist->next;
		else if ( Blist->data > Alist->data )
			Alist = Alist->next;
		else if( Alist->data == Blist->data )
		{
			// push data onto tail of new list
			LinkedListNode* newNode = new LinkedListNode();
			newNode->data = Alist->data;
			newNode->next = 0;

			tail->next = newNode;
			tail = tail->next;

			Alist = Alist->next;
			Blist = Blist->next;
		}
	}

	return dummyNode.next;
}

// reverses a given linked list iteratively in place; by rearranging pointers
void ReverseIterative_LinkedList(LinkedListNode** headRef)
{
	LinkedListNode* current = *headRef;
	LinkedListNode* head = 0;

	LinkedListNode* currentNext = 0;
	while( current != 0 )
	{
		currentNext = current->next;

		current->next = head;
		head = current;

		current = currentNext;
	}

	*headRef = head;
}

// reverses a given linked list recursively in place; by rearranging pointers
// http://stackoverflow.com/questions/354875/reversing-a-linked-list-in-java-recursively
// using method of induction
void ReverseRecursive_LinkedList(LinkedListNode** headRef)
{
	// if the list is empty
	if( *headRef == 0 )
		return;

	LinkedListNode* current = *headRef;

	// if the list contains only one element => reverse(list) = the element itself
	if( current->next == 0 )
		return;

	LinkedListNode* currentNext = current->next;
	// if the list contains more than 1 element => (1 = A) (set of N Elements = B) => (A) (B) 
	// => reverse(list) = (reverse(B)) (A) = (B') (A)
	ReverseRecursive_LinkedList( &currentNext);		// reverse(B)

	// placing (A) after (B')
	current->next->next = current;

	// making (A) the new tail
	current->next = 0;

	// making (B') the new head
	*headRef = currentNext;
}

// returns the Nth node from end of the linked list
// N = 0 => last element of the list
LinkedListNode* NFromEnd_LinkedList( LinkedListNode* head, int N)
{
	LinkedListNode* current = head;
	
	// advance current to N elements
	int i = 0;
	while( i < N )
	{
		if(current == 0)
			return 0;		// index N is smaller than the total length of the linked list
							// or the list is empty
		else
		{
			i++;
			current = current->next;
		}
	}

	if(current == 0)	// index N is greater than the total length of the linked list
		return 0;

	LinkedListNode* NfromEnd = head; // NfromEnd is exactly N elements behind current

	//update both NfromEnd and current till end of linked list is reached
	// At end, nFromEnd will be the answer
	while(current->next != 0)
	{
		NfromEnd = NfromEnd->next;
		current = current->next;
	}

	return NfromEnd;
}