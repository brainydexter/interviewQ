#include "Board.h"

#include "Trie_Node.h"

Board::Board(void)
{
	matrix[0] = 'h'; matrix[1] = 'a'; matrix[2] = 'p';
	matrix[3] = 'b'; matrix[4] = 'p'; matrix[5] = 'y';
	matrix[6] = 'e'; matrix[7] = 'y'; matrix[8] = 'e';

	//m_Dictionary = new 
}


Board::~Board(void)
{
}


void Board::ProcessAllWords()
{
	for(int i = 0; i < 9; i++)
	{
		Traverse(string(1, matrix[i]), i, NONE, BoardSet());
	}
}

void Board::Traverse(std::string a_str, int index, Direction direction, BoardSet prevIndices)
{

}