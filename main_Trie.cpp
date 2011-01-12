//#include "Trie_Node.h"
//
//#include <iostream>
//#include <string>
//#include <crtdbg.h>
//using namespace std;
//
//
//int main()
//{
//	Trie_Node* root = new Trie_Node('\0');
//
//	root->Insert(std::string("apple"));
//	root->Insert(std::string("apt"));
//	root->Insert(std::string("ape"));
//
//	cout << "Found Apple: " << root->Search(std::string("apple")) << endl;
//	cout << "Found Ape: " << root->Search(std::string("ape")) << endl;
//	cout << "Found Apt: " << root->Search(std::string("apt")) << endl;
//	cout << "Found App: " << root->Search(std::string("app"), true) << endl;
//	cout << "Found Apc: " << root->Search(std::string("apc"), false) << endl;
//	
//	delete root;
//
//	_CrtMemDumpAllObjectsSince(0);
//	return 1;
//}