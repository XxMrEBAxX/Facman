#include "PacMap.h"

PacMap::PacMap()
{
	TileMap = new bool*[MAP_Y];
	for (int i = 0; i < MAP_Y; i++)
	{
		TileMap[i] = new bool[MAP_X];
	}
#define ¤± false
#define ¤· true
	bool tempMap[MAP_Y][MAP_X] = {
	//   1   2   3   4   5   6  7   8   9  10  11  12  13  14  15 16  17  18  19  20 21  22  23  24  25 26  27  28
		{¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±},// 1
		{¤±, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤±, ¤±, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤±},// 2
		{¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±},// 3
		{¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±},// 4
		{¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±},// 5
		{¤±, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤±},// 6
		{¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±},// 7
		{¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±},// 8
		{¤±, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤±, ¤±, ¤·, ¤·, ¤·, ¤·, ¤±, ¤±, ¤·, ¤·, ¤·, ¤·, ¤±, ¤±, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤±},// 9
		{¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±},// 10
		{¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±},// 11
		{¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±},// 12
		{¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤·, ¤·, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±},// 13
		{¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤·, ¤·, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±},// 14
		{¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤±, ¤±, ¤·, ¤·, ¤·, ¤·, ¤±, ¤±, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·},// 15
		{¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤·, ¤·, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±},// 16
		{¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±},// 17
		{¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±},// 18
		{¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±},// 19
		{¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±},// 20
		{¤±, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤±, ¤±, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤±},// 21
		{¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±},// 22
		{¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±},// 23
		{¤±, ¤·, ¤·, ¤·, ¤±, ¤±, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤±, ¤±, ¤·, ¤·, ¤·, ¤±},// 24
		{¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±},// 25
		{¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±},// 26
		{¤±, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤±, ¤±, ¤·, ¤·, ¤·, ¤·, ¤±, ¤±, ¤·, ¤·, ¤·, ¤·, ¤±, ¤±, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤±},// 27
		{¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±},// 28
		{¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±, ¤±, ¤·, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤·, ¤±},// 29
		{¤±, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤·, ¤±},// 30
		{¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±, ¤±} // 31
	};

	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			TileMap[i][j] = tempMap[i][j];
		}
	}

	m_map = new int* [MAP_Y];
	m_visitInfo = new bool* [MAP_Y];
	for (int i = 0; i < MAP_Y; i++)
	{
		m_map[i] = new int[MAP_X];
		m_visitInfo[i] = new bool[MAP_X];
	}

	m_ghosts[0] = new Ghost(&m_gm, InBoxState::getInstance(), new AStar(this));
	m_ghosts[1] = new Ghost(&m_gm, InBoxState::getInstance(), new AStar(this));
	m_ghosts[2] = new Ghost(&m_gm, InBoxState::getInstance(), new AStar(this));
}

PacMap::~PacMap()
{
	for (int i = 0; i < MAP_Y; i++)
	{
		delete[] TileMap[i];
	}
	delete[] TileMap;

	delete[] m_ghosts;
}

void PacMap::InitMap()
{
	ObjectMap.clear();

	// InBOX »óÅÂ ´ÝÈû
	TileMap[13 - 1][14 - 1] = ¤±;
	TileMap[13 - 1][15 - 1] = ¤±;

	m_player.SetPos(POSITION(14 - 1, 24 - 1));
	SetObject(m_player.GetPos(), Object::O_Player);

	for (int i = 0; i < 3; i++)
	{
		m_ghosts[i]->SetPos(POSITION(13 + i - 1, 15 - 1));
		SetObject(m_ghosts[i]->GetPos(), Object::O_Ghost);
	}

	//A*
	for (int y = 0; y < MAP_Y; y++)
	{
		for (int x = 0; x < MAP_X; x++)
		{
			m_map[y][x] = 1000;
			m_visitInfo[y][x] = false;
		}
	}
}

void PacMap::DrawMap()
{
	for (int i = 0; i < MAP_Y; i++)
	{
		for (int j = 0; j < MAP_X; j++)
		{
			if (TileMap[i][j]) // ¹Ù´Ú
			{
				POSITION pos = POSITION(j, i);
				Object obj = ObjectMap[pos];
				if (obj == Object::O_Player)
				{
					switch (m_player.GetDir())
					{
					case PacManDirection::DIR_LEFT:
						cout << "¢¸";
						break;
					case PacManDirection::DIR_RIGHT:
						cout << "¢º";
						break;
					case PacManDirection::DIR_UP:
						cout << "¡ã";
						break;
					case PacManDirection::DIR_DOWN:
						cout << "¡å";
						break;
					default:
						break;
					}
				}
				else if (obj == Object::O_Ghost)
				{
					// FSM ¿¡ µû¸¥ Æ¯¼ö¹®ÀÚ º¯°æ
					cout << "£À";
				}
				else
					cout << "  ";
			}
			else if (!TileMap[i][j]) // º®
			{
				if (i == 13 - 1 && ((j == 14 - 1) || (j == 15 - 1)))
				{
					cout << "¡à";
				}
				else
					cout << "¡á";
			}
		}
		cout << endl;
	}
}

void PacMap::SetObject(POSITION pos, Object obj)
{
	//ObjectMap.insert({ pos, obj });
	ObjectMap[pos] = obj;
}

bool PacMap::IsMoveAble(POSITION pos, int x, int y)
{
	int moveX = pos.X + x;
	int moveY = pos.Y + y;

	if ((moveX >= MAP_X || moveX < 0) || (moveY >= MAP_Y || moveY < 0))
		return false;

	return TileMap[moveY][moveX];
}

void PacMap::MoveObject()
{
	int x = 0, y = 0;

	// PacMan
	if (m_player.GetDir() == PacManDirection::DIR_LEFT)
	{
		x = -1;
	}
	else if (m_player.GetDir() == PacManDirection::DIR_RIGHT)
	{
		x = 1;
	}
	else if (m_player.GetDir() == PacManDirection::DIR_UP)
	{
		y = -1;
	}
	else if (m_player.GetDir() == PacManDirection::DIR_DOWN)
	{
		y = 1;
	}

	if (IsMoveAble(m_player.GetPos(), x, y))
	{
		ObjectMap.erase(m_player.GetPos());
		m_player.Move(x, y);
		SetObject(m_player.GetPos(), Object::O_Player);
		// ¸¸¾à ÀÌµ¿ À§Ä¡¿¡ ¿ÀºêÁ§Æ®°¡ °í½ºÆ®³ª ¾ÆÀÌÅÛÀÌ¸é ±¸ÇöÇØ¾ßÇÔ
	}

	// Ghost
	for (int i = 0; i < 3; i++)
	{
		x = 0; y = 0;
		m_ghosts[i]->StateUpdate();

		if (m_ghosts[i]->GetDir() == Ghost_Dir::DIR_LEFT)
		{
			x = -1;
		}
		else if (m_ghosts[i]->GetDir() == Ghost_Dir::DIR_RIGHT)
		{
			x = 1;
		}
		else if (m_ghosts[i]->GetDir() == Ghost_Dir::DIR_UP)
		{
			y = -1;
		}
		else if (m_ghosts[i]->GetDir() == Ghost_Dir::DIR_DOWN)
		{
			y = 1;
		}

		if (IsMoveAble(m_ghosts[i]->GetPos(), x, y))
		{
			ObjectMap.erase(m_ghosts[i]->GetPos());
			m_ghosts[i]->Move(x, y);
			SetObject(m_ghosts[i]->GetPos(), Object::O_Ghost);
		}
	}
}

void PacMap::SetInBoxRelease()
{
	TileMap[13 - 1][14 - 1] = ¤·;
	TileMap[13 - 1][15 - 1] = ¤·;
}
