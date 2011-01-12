#include "DictionaryWords.h"

#include "Trie_Node.h"
#include <fstream>

extern int (*gPrintFn)( const char * format, ... );

DictionaryWords::DictionaryWords(const char* fileName)
{
	mp_Dictionary = new Trie_Node('\0');

	// Populate Dictionary with words from fileName
	std::string line;
	std::ifstream myfile (fileName);

	if (myfile.is_open())
	{
		while ( myfile.good() )
		{
			getline (myfile,line);
			//gPrintFn(" %s \n", line.c_str());
			mp_Dictionary->Insert(line);
		}
		myfile.close();
	}
	else // TODO: throw exception 
	{
		gPrintFn("Unable to open file\n"); 
	}
}


DictionaryWords::~DictionaryWords(void)
{
	delete mp_Dictionary;

	mp_Dictionary = 0;
}

bool DictionaryWords::Search(const std::string &ar_Word, bool pattern)
{
	return mp_Dictionary->Search(ar_Word, pattern);
}