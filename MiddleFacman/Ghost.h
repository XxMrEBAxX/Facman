#pragma once
#include "GhostManager.h"
#include "BaseGhost.h"
#include "BaseState.h"
using namespace std;

class AStar;
interface Observer;

interface DisplayObserver : public Observer
{
	GhostManager* ghostManager = nullptr;
public:
	virtual void updata(GhostManager* gm) = 0;
	virtual void display() = 0;
};

class Ghost : public DisplayObserver, public BaseGhost
{
	BaseState* m_curState;
	AStar* Astar;
	POSITION playerpos;

	// Astar 를 통해 목표 노드를 부여받고 움직이고 있는가?
	bool isMoving = false;
public:
	Ghost(GhostManager* gm, BaseState* state, AStar* astar) : m_curState(state), Astar(astar)
	{
		ghostManager = gm;
		gm->registerObserver(this);
	}
	~Ghost()
	{
		delete Astar;
	}
	void updata(GhostManager* gm) override
	{
		ghostManager = gm;
		playerpos = gm->getPlayerPos();
	}
	void StateUpdate() override
	{
		m_curState->Execute(this);
	}
	void display() override
	{

	}
	void changeState(BaseState* newState) override
	{
		m_curState->Exit(this);
		m_curState = newState;
		m_curState->Enter(this);
	}

	POSITION Move(int x, int y)
	{
		m_pos.X += x;
		m_pos.Y += y;

		return m_pos;
	}

	AStar* getAstar() override { return Astar; }
};