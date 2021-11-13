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

// 팩맨의 이동 방향 ENUM
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
    // 팩맨의 이동 방향
    PacManDirection m_dir;
    // 팩맨의 위치 정보
    POSITION m_pos;
    
public:
    PacMan();
    ~PacMan();

    // 이동 입력 키 처리
    void KeyProcess();
    // 이동 함수 x  y 값 더하기
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