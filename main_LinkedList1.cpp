//#include "Problems_LinkedList1.h"
//
//#include <stdio.h>
//
//int (*gPrintFn)( const char * format, ... ) = 0;
//
//int main()
//{
//	gPrintFn = printf;
//
//	s_node* list = CreateList1234();
//
//	gPrintFn("Old list: \n");
//	gPrintFn("Next: \n");
//	PrintList_Next(list);
//
//	gPrintFn("Address: \n");
//	PrintList_Address(list);
//
//
//	gPrintFn("Refs: \n");
//	PrintList_Ref(list);
//
//	gPrintFn("***********************************************\n");
//
//	s_node* newList = Duplicate_list(list);
//
//	gPrintFn("New list: \n");
//	gPrintFn("Next: \n");
//	PrintList_Next(newList);
//
//	gPrintFn("Address: \n");
//	PrintList_Address(newList);
//
//	gPrintFn("Refs: \n");
//	PrintList_Ref(newList);
//
//	gPrintFn("***********************************************\n");
//
//	return 1;
//}