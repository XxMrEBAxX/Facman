#include <iostream>
#include <windows.h>
//#include "DoubleBuffering.h"
#include "PacMap.h"


int main()
{
    /*
    DoubleBuffering m_db;
    m_db.ScreenInit();
    m_db.OldTime = clock();
    */
    PacMap m_map;
    m_map.InitMap();
    
    while (true) // Exit 상태 조건
    {
        //m_db.CurTime = clock();
        //m_db.Render();

        m_map.DrawMap(); //Draw

        m_map.GetPlayer().KeyProcess(); //KeyProcess

        Sleep(33); //frame

        m_map.MoveObject(); // Process
        system("cls");
        
    }
    //m_db.ScreenRelease();

    return 0;
}