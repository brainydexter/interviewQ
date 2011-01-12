#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <set>

typedef std::set<int> BoardSet;

enum Direction
{
	NONE = 0,
	RIGHT,
	BOTTOM_RIGHT,
	BOTTOM,
	BOTTOM_LEFT,
	LEFT,
	TOP_LEFT,
	TOP,
	TOP_RIGHT
};

class DictionaryWords;

class Board
{
public:
	Board(const char* dictionaryFile, int rows, int cols, char boardLetters[]);
	~Board(void);

	void ProcessAllWords();
	void Traverse(std::string a_str, int index, Direction direction, BoardSet prevIndices);

private:
	// MEMBER DATA
	DictionaryWords* mp_Dictionary;

	// 1-D array
	char matrix[9];	// 3x3
	int m_Cols, m_Rows;

	// HELPER FUNCTIONS

	// returns index in matrix for given direction; if the new index is legal; else -1
	int GetIndex(int index, Direction direction);
	
	// Traversing into newNode from direction, thus the newNode should not consider this node (which is pointed by opposite of DIR)
	Direction IncomingDirection(Direction direction);
};

#endif