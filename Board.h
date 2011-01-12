#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <set>
using namespace std;

typedef set<int> BoardSet;

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

class Board
{
public:
	Board(void);
	~Board(void);

	void ProcessAllWords();
	void Traverse(std::string a_str, int index, Direction direction, BoardSet prevIndices);

private:
	// MEMBER DATA
	Trie_Node* m_Dictionary;

	// 1-D array
	char matrix[9];	// 3x3
};

#endif