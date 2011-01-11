#ifndef TRIE_NODE_H
#define TRIE_NODE_H

#include <string>

// Trie Node for inserting and Searching a word / pattern
class Trie_Node
{
public:
	// creates a node with m_Value: c
	Trie_Node(char a_c);
	~Trie_Node(void);

	// HELPER Functions
	
	// Returns the child of this with value char c
	Trie_Node* SubNode(char c);

	// Inserts the word in Trie
	void Insert(const std::string &ar_Word);

	// Searches for Word/Pattern in Trie
	bool Search(const std::string &ar_Word, bool pattern = false);

private:
	// MEMBER Data
	char m_Value;
	bool m_EOW;		// end of word
	Trie_Node* m_Children[26];		// can only contain a-z : 26 lowercase alphabets
};

#endif