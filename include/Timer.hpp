#pragma once

#include <chrono>



class Timer
{
private:
    typedef std::chrono::high_resolution_clock clock;
    typedef std::chrono::high_resolution_clock::time_point time_point;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::microseconds us;

public:
    void Start();
    float GetMs() const;
    float GetUs() const;

private:
    time_point start;
};

void Timer::Start()
{
    start = clock::now();
}

float Timer::GetMs() const
{
    time_point end = clock::now();
    std::chrono::duration<float> delta = end-start;
    ms d = std::chrono::duration_cast<ms>(delta);
    return d.count();
}

float Timer::GetUs() const
{
    time_point end = clock::now();
    std::chrono::duration<float> delta = end-start;
    us d = std::chrono::duration_cast<us>(delta);
    return d.count();
}