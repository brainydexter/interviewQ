#include "Trie_Node.h"


Trie_Node::Trie_Node(char a_c)
	: m_Value(a_c), m_EOW(false)
{
	for(int i = 0; i < 26; i++)
	{
		m_Children[i] = 0;
	}
}

Trie_Node::~Trie_Node(void)
{
	for(int i = 0; i < 26; i++)
	{
		if (m_Children[i] != 0)
			delete m_Children[i];

		m_Children[i] = 0;
	}
}

// Returns the child of this with value char c
Trie_Node* Trie_Node::SubNode(char c)
{
	return m_Children[c - 'a'];
}

// Inserts the word in Trie
 // O(strlen(word)) :: O(1)
void Trie_Node::Insert(const std::string &ar_Word)
{
	Trie_Node* current = this;

	for(std::size_t i = 0; i < ar_Word.length(); i++)
	{
		char ch = ar_Word[i];

		Trie_Node* child = current->SubNode(ch);
		if(child == 0)
		{
			child = new Trie_Node(ch);
			current->m_Children[ch - 'a'] = child;
		}

		current = child;
	}

	// current right now points to the last letter of word in trie
	current->m_EOW = true;
}

// Searches for Word/Pattern in Trie
// O(strlen(word) ) :: O(1)
bool Trie_Node::Search(const std::string &ar_Word, bool patternOnly)
{
	Trie_Node* current = this;

	for(std::size_t i = 0; i < ar_Word.length(); i++)
	{
		char ch = ar_Word[i];

		Trie_Node* child = current->SubNode(ch);

		if(child == 0)
			return false;

		current = child;
	}

	if(patternOnly)
		return true;

	return current->m_EOW;
}