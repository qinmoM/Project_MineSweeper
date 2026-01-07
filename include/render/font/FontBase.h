#pragma once

class FontBase
{
public:
    virtual ~FontBase() = default;

    FontBase(const FontBase& other) = delete;
    FontBase& operator=(const FontBase& other) = delete;
protected:
    FontBase() = default;
};