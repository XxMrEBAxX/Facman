#pragma once
#include <conio.h>
#include "Position.h"

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define PAUSE 112
#define ESC 27

// �Ѹ��� �̵� ���� ENUM
enum class PacManDirection
{
    NONE = 0,
    DIR_LEFT,
    DIR_RIGHT,
    DIR_DOWN,
    DIR_UP = 4
};

class PacMan
{
    // �Ѹ��� �̵� ����
    PacManDirection m_dir;
    // �Ѹ��� ��ġ ����
    POSITION m_pos;
    
public:
    PacMan();
    ~PacMan();

    // �̵� �Է� Ű ó��
    void KeyProcess();
    // �̵� �Լ� x  y �� ���ϱ�
    POSITION Move(int x, int y);

    // Setter
    void SetPos(POSITION pos)
    {
        m_pos = pos;
    }
    void SetDir(PacManDirection dir)
    {
        m_dir = dir;
    }
    
    // Getter
    POSITION GetPos()
    {
        return m_pos;
    }
    PacManDirection GetDir()
    {
        return m_dir;
    }
};