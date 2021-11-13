#pragma once
#include "Position.h"
#include <stack>
#include <list>
using namespace std;

class PacMap;

class AStar
{
	PacMap* m_gameMap;
	stack<POSITION> m_path; // Path information with currentNode from startNode
	list<POSITION> m_spt;
	bool m_bFound;
public:
	AStar(PacMap* map) : m_gameMap(map), m_bFound(false) {}
	~AStar() {}

	void choose(POSITION& choicePos, POSITION ds); // Min Extract
	bool findPath(POSITION sp, POSITION ds); // sp : startNode, ds targetNode
	POSITION getNextNode();

	POSITION GetRandomPos();

	void SetInBoxRelease();
};

