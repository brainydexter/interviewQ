#ifndef LinkedList_Problems_h
#define LinkedList_Problems_h

#include "LinkedListUtil.h"

void Reverse(Node** head){
	Node* newHead = NULL;

	Node* current = *head;

	while(current){
		Node* next = current->next;

		current->next = newHead;
		newHead = current;

		current = next;
	}

	*head = newHead;
}

void RecursiveReverse(Node** head){
	if(*head == NULL)
		return;

	// A -> B -> 0
	Node* first = *head;

	Node* rest = first->next;

	if(rest == NULL) return;

	RecursiveReverse(&rest);

	// putting first at the end of the list
	first->next->next = first;

	// making it point to tail
	first->next = NULL;

	// rest becomes the new head
	*head = rest;
}
#endif