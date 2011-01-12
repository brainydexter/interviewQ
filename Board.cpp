#include "Board.h"

#include "Trie_Node.h"

extern int (*gPrintFn)( const char * format, ... );

Board::Board(void)
{
	/*matrix[0] = 'h'; matrix[1] = 'a'; matrix[2] = 'p';
	matrix[3] = 'b'; matrix[4] = 'p'; matrix[5] = 'y';
	matrix[6] = 'e'; matrix[7] = 'y'; matrix[8] = 'e';*/

	matrix[0] = 'y'; matrix[1] = 'o'; matrix[2] = 'x';
	matrix[3] = 'r'; matrix[4] = 'b'; matrix[5] = 'a';
	matrix[6] = 'y'; matrix[7] = 'e'; matrix[8] = 'd';

	m_Dictionary = new Trie_Node('\0');
	/*
	bred, yore, byre, abed, oread, bore, orby, robed, broad, byroad, robe
	bored, derby, bade, aero, read, orbed, verb, aery, bead, bread, very, road

	*/

	m_Dictionary->Insert(std::string("bred"));
	m_Dictionary->Insert(std::string("yore"));
	m_Dictionary->Insert(std::string("byre"));
	m_Dictionary->Insert(std::string("abed"));
	m_Dictionary->Insert(std::string("oread"));
	m_Dictionary->Insert(std::string("bore"));
	m_Dictionary->Insert(std::string("orby"));
	m_Dictionary->Insert(std::string("robed"));
	m_Dictionary->Insert(std::string("broad"));
	m_Dictionary->Insert(std::string("byroad"));
	m_Dictionary->Insert(std::string("robe"));
	m_Dictionary->Insert(std::string("bored"));
	m_Dictionary->Insert(std::string("derby"));
	m_Dictionary->Insert(std::string("bade"));
	m_Dictionary->Insert(std::string("aero"));
	m_Dictionary->Insert(std::string("read"));
	m_Dictionary->Insert(std::string("orbed"));
	m_Dictionary->Insert(std::string("verb"));
	m_Dictionary->Insert(std::string("aery"));
	m_Dictionary->Insert(std::string("bead"));
	m_Dictionary->Insert(std::string("bread"));
	m_Dictionary->Insert(std::string("very"));
	m_Dictionary->Insert(std::string("road"));


	m_Cols = 3;
	m_Rows = 3;
}


Board::~Board(void)
{
	delete m_Dictionary;
}


void Board::ProcessAllWords()
{
	for(int i = 0; i < 9; i++)
	{
		Traverse(string(1, matrix[i]), i, NONE, BoardSet());
	}
}

void Board::Traverse(std::string a_str, int index, Direction incoming, BoardSet prevIndices)
{
	string currentStr = a_str;

	if( m_Dictionary->Search(currentStr, true) == false)
		return;

	for( Direction DIR = RIGHT; DIR <= TOP_RIGHT; DIR = (Direction)(DIR + 1))
	{
		// process right node
		if( incoming != DIR ) // if traverse was called from the node that is right to this node
		{
			int rightIndex = GetIndex(index, DIR);

			if( rightIndex != -1 && prevIndices.count(rightIndex) == 0 )
			{
				string l_string = currentStr + matrix[rightIndex];
				while( m_Dictionary->Search(l_string, true) )	// see if pattern exists in Dictionary
				{
					prevIndices.insert(index);
					Traverse(l_string, rightIndex, IncomingDirection( DIR ), prevIndices );

					// when control reaches here, tree is at its leaf
					if(m_Dictionary->Search(l_string) == true)
					{
						gPrintFn(" %s \n", l_string.c_str() );
					}
					break;	// we are done with this pattern, exit out of the while loop searching for l_string pattern
				}
			}
		}
	}

	/*
	// process right node
		if( incoming != RIGHT ) // if traverse was called from the node that is right to this node
		{
			int rightIndex = GetIndex(RIGHT);

			if( rightIndex != -1 && prevIndices.count(rightIndex) == 0 )
			{
				string l_string = currentStr.append(1, matrix[rightIndex]);
				while( m_Dictionary->Search(l_string, true) )	// see if pattern exists in Dictionary
				{
					if(m_Dictionary->Search(l_string) == true)
					{
						gPrintFn(" %s \n", l_string.c_str() );
					}

					currentStr = l_string;
					prevIndices.insert(index);
					Traverse(currentStr, rightIndex, IncomingDirection( RIGHT ), prevIndices );
				}
			}
		}
	*/
}

// returns index in matrix for given direction; if the new index is legal; else -1
// TODO: tidy this function by using different value for enums. Come back to this after Bungie submission
int Board::GetIndex(int index, Direction direction)
{
	int val = -1;

	const int MAX_INDEX = (m_Rows * m_Cols) - 1; // index is 0 based

	switch(direction)
	{
	case RIGHT: 
		{
			val = index + 1;
			if( val % m_Cols == 0 )		// if right element falls off the edge
				return -1;
			else
				return val;
			break;
		}
	case BOTTOM_RIGHT: 
		{
			val = index + m_Cols + 1;
			if( ( val % m_Cols == 0) || // falls of right edge
				( val > MAX_INDEX )		// beyond maxIndices
				)
				return -1;
			else
				return val;
		}
	case BOTTOM: 
		{
			val = index + m_Cols;
			if( val > MAX_INDEX )		// beyond maxIndices
				return -1;
			
			return val;
		}
	case BOTTOM_LEFT: 
		{
			val = index + m_Cols - 1;
			if( ( val > MAX_INDEX ) || // bottom index
				( index % m_Cols == 0 )		// left index
				)
				return -1;
			else
				return val;
		}
	case LEFT: 
		{
			val = index - 1;
			if( ( val < 0) ||
				( index % m_Cols == 0 )
				)
				return -1;
				
			return val;
		}
	case TOP_LEFT: 
		{
			val = index - m_Cols - 1;

			if( (val < 0) ||	// top
				( index % m_Cols == 0) // left
				)
				return -1;

			return val;
		}
	case TOP: 
		{
			val = index - m_Cols;
			if( val < 0 )		// beyond maxIndices
				return -1;
			
			return val;
		}
	case TOP_RIGHT: 
		{
			val = index - m_Cols + 1;

			if( val <= 0 ||
				(val % m_Cols == 0)
				)
				return -1;

			return val;
		}
	}

	return index;
}


Direction Board::IncomingDirection(Direction direction)
{
	switch(direction)
	{
	case RIGHT: 
		{
			return LEFT;
		}
	case BOTTOM_RIGHT: 
		{
			return TOP_LEFT;
		}
	case BOTTOM: 
		{
			return TOP;
		}
	case BOTTOM_LEFT: 
		{
			return TOP_RIGHT;
		}
	case LEFT: 
		{
			return RIGHT;
		}
	case TOP_LEFT: 
		{
			return BOTTOM_RIGHT;
		}
	case TOP: 
		{
			return BOTTOM;
		}
	case TOP_RIGHT: 
		{
			return BOTTOM_LEFT;
		}
	}

	return NONE;
}