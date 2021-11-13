#include "GhostStates.h"
#include "BaseGhost.h"
#include "AStar.h"

InBoxState* InBoxState::getInstance()
{
	static InBoxState* instance = NULL;
	if (instance == nullptr)
		instance = new InBoxState();
	return instance;
}

void InBoxState::Enter(BaseGhost* curState)
{
	m_oldTime = time(NULL);
}

void InBoxState::Execute(BaseGhost* curState)
{
	Ghost_Dir random = (Ghost_Dir)((rand() % 2) + 3);
	curState->SetDir(random);
	if (clock() - m_oldTime >= 5000)
	{
		curState->changeState(HunterState::getInstance());
	}
	
}

void InBoxState::Exit(BaseGhost* curState)
{
	curState->getAstar()->SetInBoxRelease();
}

HunterState* HunterState::getInstance()
{
	static HunterState* instance = NULL;
	if (instance == nullptr)
		instance = new HunterState();
	return instance;
}

void HunterState::Enter(BaseGhost* curState)
{
	destinationPos = curState->getAstar()->GetRandomPos();
	curState->getAstar()->findPath(curState->GetPos(), destinationPos);
	nextPos = curState->getAstar()->getNextNode();
}

void HunterState::Execute(BaseGhost* curState)
{
	if (curState->GetPos() != destinationPos)
	{
		POSITION chgAmount = nextPos - curState->GetPos();
		Ghost_Dir dir = Ghost_Dir::NONE;
		if (chgAmount.X > 0)
		{
			dir = Ghost_Dir::DIR_RIGHT;
		}
		else if (chgAmount.X < 0)
		{
			dir = Ghost_Dir::DIR_LEFT;
		}
		else if (chgAmount.Y > 0)
		{
			dir = Ghost_Dir::DIR_UP;
		}
		else if (chgAmount.Y < 0)
		{
			dir = Ghost_Dir::DIR_DOWN;
		}
		curState->SetDir(dir);

		nextPos = curState->getAstar()->getNextNode();
	}
	else
	{
		destinationPos = curState->getAstar()->GetRandomPos();
		curState->getAstar()->findPath(curState->GetPos(), destinationPos);
	}
}

void HunterState::Exit(BaseGhost* curState)
{

}

HuntedState* HuntedState::getInstance()
{
	static HuntedState* instance = NULL;
	if (instance == nullptr)
		instance = new HuntedState();
	return instance;
}

void HuntedState::Enter(BaseGhost* curState)
{

}

void HuntedState::Execute(BaseGhost* curState)
{


}

void HuntedState::Exit(BaseGhost* curState)
{

}

EatenState* EatenState::getInstance()
{
	static EatenState* instance = NULL;
	if (instance == nullptr)
		instance = new EatenState();
	return instance;
}

void EatenState::Enter(BaseGhost* curState)
{

}

void EatenState::Execute(BaseGhost* curState)
{


}

void EatenState::Exit(BaseGhost* curState)
{

}