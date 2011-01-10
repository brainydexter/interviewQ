#ifndef PROBLEMS_LINKEDLIST1_H
#define PROBLEMS_LINKEDLIST1_H

extern int (*gPrintFn)( const char * format, ... );

struct s_node
{
	int data;
	struct s_node *next;
	struct s_node *reference;
};

// input: a singly linked list that contains references to random nodes within the list
// output: a duplicate copy of the list with no dependency on the original
// PS: You may modify the input provided that it is restored before your function completes
struct s_node* Duplicate_list(struct s_node *list);

// Helper functions
inline void InitNode( struct s_node** nodeRef)
{
	(*nodeRef)->next = 0;
	(*nodeRef)->reference = 0;
}

inline void PrintList_Next( s_node* list)
{
	while(list != 0)
	{
		gPrintFn(" %d -> ", list->data);
		list = list->next;
	}

	gPrintFn(" . \n");
}

inline void PrintList_Address( s_node* list)
{
	while(list != 0)
	{
		gPrintFn(" %p -> ", list);
		list = list->next;
	}

	gPrintFn(" . \n");
}

inline void PrintList_Ref( s_node* list)
{
	while(list != 0)
	{
		int val = list->reference != 0 ? list->reference->data : 0;
		gPrintFn(" %d || ", val);
		list = list->next;
	}

	gPrintFn("\n");
}

inline s_node* CreateList1234()
{
	s_node* node1 = new s_node();	InitNode(&node1);
	s_node* node2 = new s_node();	InitNode(&node2);
	s_node* node3 = new s_node();	InitNode(&node3);
	s_node* node4 = new s_node();	InitNode(&node4);

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = 0;

	node1->reference = node3;
	node2->reference = 0;
	node3->reference = node4;
	node4->reference = node2;

	return node1;
}

#endif