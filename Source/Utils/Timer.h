#pragma once

#include <Windows.h>

class Timer
{
private:
    LARGE_INTEGER l__Start;
    double l__Freq;
public:
    Timer()
    {
        LARGE_INTEGER freq;
        QueryPerformanceFrequency(&freq);
        l__freq = 1 / freq.QuadPart;
        QueryPerformanceCounter(&l__Start);
    }

    void reset()
    {
        QueryPerformanceCounter(&l__Start);
    }

    double timeElapsed()
    {
        LARGE_INTEGER cur;
        QueryPerformanceCounter(&cur);
        unsigned __int64 cycles = cur.QuadPart - l__Start.QuadPart;
        return (double)(cycles * l__Freq);
    }
};