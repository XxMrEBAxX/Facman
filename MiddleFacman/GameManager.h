#pragma once
#include "PacMap.h"

#define INIT_POS_X 24
#define INIT_POS_Y 14
class GameManager
{
	PacMap m_map;

public:
	GameManager();
	~GameManager();

	// ���� ���� �ʱ�ȭ
	void InitGame();
};

