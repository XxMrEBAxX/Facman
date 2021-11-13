#pragma once
#include <iostream>
#include <map>
#include "Position.h"
#include "PacMan.h"
#include "Ghost.h"
#include "GhostStates.h"
#include "AStar.h"

using namespace std;

// 오브젝트 정보 ENUM
enum Object
{
	None = 0,
	O_Player,
	O_Ghost,
	O_Item,
	O_BigItem,
};

// 팩맨의 맵 정보입니다.
class PacMap
{
	static const int MAP_X = 28;
	static const int MAP_Y = 31;
	// bool의 값은 갈 수 있는 곳인가 아닌가이다. ( true : 바닥, false : 벽 )
	bool** TileMap;
	// 타일에 있는 오브젝트 정보를 Map 형태로 저장 ( 14 : PACMAN )
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

	// 맵 정보 초기화
	void InitMap();

	// 맵 그리기
	void DrawMap();

	// 오브젝트 맵 정보에 오브젝트 넣기
	void SetObject(POSITION pos, Object obj);

	// 움직일 수 있는 바닥인가 확인하는 함수
	bool IsMoveAble(POSITION pos, int x, int y);

	// 오브젝트 이동 함수
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

