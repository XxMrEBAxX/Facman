#pragma once
#include "Subject.h"
#include "PacMan.h"
#include <vector>
#include <iostream>
using namespace std;
// 요거 추가 안하면 뭔지 모를 오류 뜸

class GhostManager : public Subject
{
	vector<Observer*> observers;
	POSITION m_playerPos;
public:
	GhostManager() : m_playerPos(0,0) {}
	~GhostManager()
	{
		observers.empty();
	}
	void registerObserver(Observer* ob)
	{
		observers.push_back(ob);
	}
	void removeObserver(Observer* ob)
	{
		vector<Observer*>::iterator iter;
		for (iter = observers.begin(); iter != observers.end(); iter++)
		{
			if (*iter == ob)
			{
				break;
			}
		}
		observers.erase(iter);
	}
	void notifyObserver()
	{
		for (vector<Observer*>::iterator iter = observers.begin(); iter != observers.end(); iter++)
		{
			Observer* ob = *iter;
			ob->updata(this);
		}
	}
	void PlayerPosChanged()
	{
		notifyObserver();
	}
	void setPlayerPos(POSITION pos)
	{
		m_playerPos = pos;
		PlayerPosChanged();
	}
	POSITION getPlayerPos()
	{
		return m_playerPos;
	}
};