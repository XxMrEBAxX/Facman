#include "PacMan.h"

PacMan::PacMan() : m_dir(PacManDirection::DIR_LEFT), m_pos(0, 0)
{

}

PacMan::~PacMan()
{
}

void PacMan::KeyProcess()
{
    int key = 0;
    if (_kbhit())
        do { key = _getch(); } while (key == 224);
    switch (key)
    {
    case LEFT:
    case RIGHT:
    case UP:
    case DOWN:
        if (key == LEFT)
        {
            m_dir = PacManDirection::DIR_LEFT;
        }
        else if (key == RIGHT)
        {
            m_dir = PacManDirection::DIR_RIGHT;
        }
        else if (key == UP)
        {
            m_dir = PacManDirection::DIR_UP;
        }
        else if (key == DOWN)
        {
            m_dir = PacManDirection::DIR_DOWN;
        }

        key = 0;
        break;
    case ESC:
        //system("cls");
        //exit(0);
        break;
    }
}

POSITION PacMan::Move(int x, int y)
{
    m_pos.X += x;
    m_pos.Y += y;

    return m_pos;
}
