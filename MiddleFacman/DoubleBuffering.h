#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <time.h>

extern int g_nScreenIndex;
extern HANDLE g_hScreen[2];

class DoubleBuffering
{
public:
    clock_t CurTime, OldTime;
    DoubleBuffering() : CurTime(0), OldTime(0)
    {

    }
    ~DoubleBuffering() {}
    void ScreenInit()
    {
        CONSOLE_CURSOR_INFO cci;

        // ȭ�� ���� 2���� �����.
        g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
        g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

        // Ŀ���� �����.
        cci.dwSize = 1;
        cci.bVisible = FALSE;
        SetConsoleCursorInfo(g_hScreen[0], &cci);
        SetConsoleCursorInfo(g_hScreen[1], &cci);
    }

    void ScreenFlipping()
    {
        SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
        g_nScreenIndex = !g_nScreenIndex;
    }

    void ScreenClear()
    {
        COORD Coor = { 0, 0 };
        DWORD dw;
        FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 25, Coor, &dw);
    }

    void ScreenRelease()
    {
        CloseHandle(g_hScreen[0]);
        CloseHandle(g_hScreen[1]);
    }

    void ScreenPrint(int x, int y, char* string)
    {
        DWORD dw;
        COORD CursorPosition = { (SHORT)x, (SHORT)y };
        SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
        WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
    }

    void Render()
    {
        ScreenClear();

        ScreenFlipping();
    }
};