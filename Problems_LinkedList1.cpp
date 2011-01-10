#include "Problems_LinkedList1.h"

#include <map>
typedef std::map<s_node*, s_node*> mapNodes;

struct s_node* Duplicate_list(struct s_node *old_List)
{
	mapNodes mapping;	// mapping between old node :: new constructed node
	//mapping.insert( std::pair<s_node*, s_node*>(0, 0) ); // if reference from original points to tail : new list node->reference should also poitn to tail

	s_node dummy;
	dummy.next = 0;
	dummy.reference = 0;

	s_node* newCurrent = &dummy;
	s_node* oldCurrent = old_List;

	// traversing along next and copy nodes into new list
	while(oldCurrent != 0)
	{
		s_node* newNode = 0;

		// populate if newNode exists or not
		mapNodes::iterator map_Iterator;
		map_Iterator = mapping.find(oldCurrent);
		if( map_Iterator != mapping.end() ) // old_Node found in map
		{
			newNode = map_Iterator->second;
		}
		else	// old_Node has not been added to map yet
		{
			newNode = new s_node();
			newNode->next = 0;
			newNode->reference = 0;
			newNode->data = oldCurrent->data;

			mapping.insert( std::pair<s_node*, s_node*>( oldCurrent, newNode ) );
		}

		// add newNode to tail of newCurrent
		newNode->next = newCurrent->next;
		newCurrent->next = newNode;

		// traverse to next
		oldCurrent = oldCurrent->next;
		newCurrent = newCurrent->next;
	}

	// traverse along reference pointers
	oldCurrent = old_List;
	newCurrent = dummy.next;

	while(oldCurrent != 0)
	{
		if( oldCurrent->reference != 0)
		{
			newCurrent->reference = mapping.find(oldCurrent->reference)->second;
		}
		else // reference points to tail
		{
			newCurrent->reference = 0;
		}

		oldCurrent = oldCurrent->next;
		newCurrent = newCurrent->next;
	}

	return dummy.next;
}