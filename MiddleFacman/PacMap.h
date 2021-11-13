#pragma once
#include <iostream>
#include <map>
#include "Position.h"
#include "PacMan.h"
#include "Ghost.h"
#include "GhostStates.h"
#include "AStar.h"

using namespace std;

// ������Ʈ ���� ENUM
enum Object
{
	None = 0,
	O_Player,
	O_Ghost,
	O_Item,
	O_BigItem,
};

// �Ѹ��� �� �����Դϴ�.
class PacMap
{
	static const int MAP_X = 28;
	static const int MAP_Y = 31;
	// bool�� ���� �� �� �ִ� ���ΰ� �ƴѰ��̴�. ( true : �ٴ�, false : �� )
	bool** TileMap;
	// Ÿ�Ͽ� �ִ� ������Ʈ ������ Map ���·� ���� ( 14 : PACMAN )
	map<POSITION, Object> ObjectMap;

	PacMan m_player;
	Ghost* m_ghosts[3];
	GhostManager m_gm;

	//A*
	int** m_map;
	bool** m_visitInfo;
public:
	PacMap();
	~PacMap();

	// �� ���� �ʱ�ȭ
	void InitMap();

	// �� �׸���
	void DrawMap();

	// ������Ʈ �� ������ ������Ʈ �ֱ�
	void SetObject(POSITION pos, Object obj);

	// ������ �� �ִ� �ٴ��ΰ� Ȯ���ϴ� �Լ�
	bool IsMoveAble(POSITION pos, int x, int y);

	// ������Ʈ �̵� �Լ�
	void MoveObject();

	void SetInBoxRelease();

	// Getter
	PacMan& GetPlayer()
	{
		return m_player;
	}
	int getHeight() { return MAP_Y; }
	int getWidth() { return MAP_X; }
	int getMapVal(int x, int y) { return m_map[y][x]; }
	bool getVisitInfo(int x, int y) { return m_visitInfo[y][x]; }
	bool** getTileMap() { return TileMap; }

	// Setter
	void setMapVal(int x, int y, int val) { m_map[y][x] = val; }
	void setVisitInfo(int x, int y, bool val) { m_visitInfo[y][x] = val; }
};

