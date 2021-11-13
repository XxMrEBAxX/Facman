#pragma once
#include "BaseState.h"
#include "Position.h"
#include <time.h>
#include <iostream>

class BaseGhost;

class InBoxState : public BaseState
{
	clock_t m_oldTime = NULL;
	InBoxState() {}
public:
	~InBoxState() {}
	static InBoxState* getInstance();
	void Enter(BaseGhost* curState);
	void Execute(BaseGhost* curState);
	void Exit(BaseGhost* curState);
};

class HunterState : public BaseState
{
	clock_t m_oldTime = NULL;
	POSITION destinationPos;
	POSITION nextPos;
	HunterState() {}
public:
	~HunterState() {}
	static HunterState* getInstance();
	void Enter(BaseGhost* curState);
	void Execute(BaseGhost* curState);
	void Exit(BaseGhost* curState);
};

class HuntedState : public BaseState
{
	clock_t m_oldTime = NULL;
	POSITION destinationPos;
	POSITION nextPos;
	HuntedState() {}
public:
	~HuntedState() {}
	static HuntedState* getInstance();
	void Enter(BaseGhost* curState);
	void Execute(BaseGhost* curState);
	void Exit(BaseGhost* curState);
};

class EatenState : public BaseState
{
	clock_t m_oldTime = NULL;
	POSITION destinationPos;
	POSITION nextPos;
	EatenState() {}
public:
	~EatenState() {}
	static EatenState* getInstance();
	void Enter(BaseGhost* curState);
	void Execute(BaseGhost* curState);
	void Exit(BaseGhost* curState);
};