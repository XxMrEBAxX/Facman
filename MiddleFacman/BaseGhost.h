#pragma once
#include "Position.h"

class BaseState;
class AStar;

enum class Ghost_Dir
{
	NONE = 0,
	DIR_LEFT,
	DIR_RIGHT,
	DIR_UP,
	DIR_DOWN
};

class BaseGhost
{
protected:
	Ghost_Dir m_dir;
	POSITION m_pos;
public:
	BaseGhost() : m_dir(Ghost_Dir::DIR_LEFT), m_pos(0,0) {}
	~BaseGhost() {}
	virtual void StateUpdate() = 0;
	virtual void changeState(BaseState*) = 0;

	// getter
	Ghost_Dir GetDir() { return m_dir; }
    POSITION GetPos()
    {
        return m_pos;
    }
	virtual AStar* getAstar() = 0;
	// setter
	void SetDir(Ghost_Dir dir) { m_dir = dir; }
	void SetPos(POSITION pos)
	{
		m_pos = pos;
	}
};