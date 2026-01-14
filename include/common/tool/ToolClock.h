#pragma once

#include <chrono>

namespace Tool
{

class Clock
{
public:
    Clock();
public:
    /// @brief Reset the clock to the current time.
    void reset();
    /// @brief Get the elapsed time in milliseconds since the last reset() call.
    float getTimeNow() const;
    /// @brief Get the elapsed time in milliseconds since the last deltaTime() call.
    /// @note The function is the same as getTimeNow() if not called deltaTime() or called reset().
    float deltaTime();
private:
    std::chrono::steady_clock::time_point start_;
    std::chrono::steady_clock::time_point last_;
};

Clock::Clock()
{
    reset();
}

void Clock::reset()
{
    start_ = std::chrono::steady_clock::now();
    last_ = start_;
}

float Clock::getTimeNow() const
{
    return std::chrono::duration<float, std::milli>(std::chrono::steady_clock::now() - start_).count();
}

float Clock::deltaTime()
{
    std::chrono::steady_clock::time_point temp = last_;
    last_ = std::chrono::steady_clock::now();
    return std::chrono::duration<float, std::milli>(last_ - temp).count();
}

}