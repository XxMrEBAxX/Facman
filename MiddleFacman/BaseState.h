#pragma once
class BaseGhost;

class BaseState
{
public:
	BaseState() {}
	~BaseState() {}
	virtual void Enter(BaseGhost*) = 0;
	virtual void Execute(BaseGhost*) = 0;
	virtual void Exit(BaseGhost*) = 0;
};