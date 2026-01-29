#pragma once

#include "BasePoint.h"
#include "string"

class FontBase
{
public:
    virtual Base::Point getBoundaries(const std::string& text, float size, int spacing) const = 0;
public:
    virtual ~FontBase() = default;

    FontBase(const FontBase& other) = delete;
    FontBase& operator=(const FontBase& other) = delete;
protected:
    FontBase() = default;
};