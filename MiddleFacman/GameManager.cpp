#include "GameManager.h"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::InitGame()
{
	m_map.GetPlayer().SetPos(POSITION(INIT_POS_X - 1, INIT_POS_Y - 1));
	m_map.InitMap();
}
