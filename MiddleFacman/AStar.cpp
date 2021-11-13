#include "AStar.h"
#include "PacMap.h"
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

void AStar::choose(POSITION& choicePos, POSITION ds)
{
	int m_min = INT_MAX; // least cost
	int width = m_gameMap->getWidth();
	int height = m_gameMap->getHeight();

	// Node Infomation to choose
	POSITION curPos(0, 0);
	list<POSITION>::reverse_iterator sptPos;
	for (sptPos = m_spt.rbegin(); sptPos != m_spt.rend(); sptPos++)
	{
		for (int ty = -1; ty <= 1; ty++)
		{
			if (ty == 0) continue;
			for (int tx = -1; tx <= 1; tx++)
			{
				if (tx == 0) continue;
				float heuristic = 0; // 피타고라스

				curPos.X = sptPos->X + tx;
				curPos.Y = sptPos->Y + ty;
				if (curPos.X < 0 || curPos.X > width - 1 || curPos.Y < 0 || curPos.Y > height - 1 || (tx == 0 && ty == 0))
				{
					continue;
				}
				if (m_gameMap->getTileMap()[curPos.Y][curPos.X] == false)
					continue;

				 //피타고라스
				int wx = pow((ds.X - curPos.X) * 10, 2);
				int wy = pow((ds.Y - curPos.Y) * 10, 2);
				heuristic = sqrt(wx + wy);
				float F = heuristic + m_gameMap->getMapVal(curPos.X, curPos.Y);

				if ((int)F < m_min && m_gameMap->getVisitInfo(curPos.X, curPos.Y) == false)
				{
					m_min = (int)F;
					choicePos = curPos;
				}
			}
		}
	}
}

bool AStar::findPath(POSITION sp, POSITION ds)
{
	// initialization
	m_bFound = false;
	int width = m_gameMap->getWidth();
	int height = m_gameMap->getHeight();

	POSITION** parent;
	parent = new POSITION* [height];
	for (int i = 0; i < height; i++)
		parent[i] = new POSITION[width];

	POSITION choicePos;
	m_gameMap->setMapVal(sp.X, sp.Y, 0);
	choicePos = sp;
	parent[sp.Y][sp.X] = choicePos;
	m_spt.push_back(choicePos);

	for (int i = 0; i < width * height; i++)
	{
		// extract min
		m_gameMap->setVisitInfo(choicePos.X, choicePos.Y, true);
		m_spt.push_back(choicePos);

		if (choicePos.X == ds.X && choicePos.Y == ds.Y) // find destination
		{
			m_bFound = true;
			break;
		}
		for (int ty = -1; ty <= 1; ty++)
		{
			if (ty == 0) continue;
			for (int tx = -1; tx <= 1; tx++)
			{
				if (tx == 0) continue;

				int nx = choicePos.X + tx;
				int ny = choicePos.Y + ty;
				int dist;
				if (nx <0 || nx > width - 1 || ny < 0 || ny > height - 1)
					continue;
				if (m_gameMap->getTileMap()[ny][nx] == false)
					continue;
				// relaxation of an Edge Algoritm
				if (m_gameMap->getVisitInfo(nx, ny) == false)
				{
					dist = (tx == 0 || ty == 0) ? 10 : 14;
					if (m_gameMap->getMapVal(choicePos.X, choicePos.Y) + dist < m_gameMap->getMapVal(nx, ny))
					{
						int val = m_gameMap->getMapVal(choicePos.X, choicePos.Y) + dist;
						m_gameMap->setMapVal(nx, ny, val);
						parent[ny][nx] = choicePos;

					}
				}
			}
		}
		choose(choicePos, ds);
	}

	// TargetNode from StartNode to Push in Stack
	if (m_bFound)
	{
		POSITION curPos = ds;
		m_path.push(curPos);
		while (curPos.X != sp.X || curPos.Y != sp.Y)
		{
			curPos = parent[curPos.X][curPos.X];
			m_path.push(curPos);
		}
		return true;
	}
	return false;
}

POSITION AStar::GetRandomPos()
{
	int x = rand() % m_gameMap->getWidth();
	int y = rand() % m_gameMap->getHeight();

	while (m_gameMap->getTileMap()[y][x] == false)
	{
		x = rand() % m_gameMap->getWidth();
		y = rand() % m_gameMap->getHeight();
	}
	return POSITION(x, y);
}

void AStar::SetInBoxRelease()
{
	m_gameMap->SetInBoxRelease();
}

POSITION AStar::getNextNode()
{
	if (m_bFound)
	{
		POSITION curPos;
		m_path.pop();
		curPos = m_path.top();

		return curPos;
	}
}