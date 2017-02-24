/*
* @Author: Priyank Jain
* @Date:   2017-02-23 20:14:22
* @Last Modified by:   Priyank Jain
* @Last Modified time: 2017-02-23 20:17:09
*/

#include <iostream>
using namespace std;

#include "LinkedListUtil.h"

int main() {
	int ar[] = {2, 3, 4};
	Node* head = ConvertArToList(ar, 3);
	DisplayList(head);

	Reverse(&head);
	DisplayList(head);

	return 0;
}