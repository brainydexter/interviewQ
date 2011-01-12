#ifndef DICTIONARYWORDS_H
#define DICTIONARYWORDS_H

#include <string>

class Trie_Node;

class DictionaryWords
{
public:
	DictionaryWords(const char* fileName);
	~DictionaryWords(void);

	bool Search(const std::string &ar_Word, bool pattern = false);

private:
	Trie_Node* mp_Dictionary;
};

#endif