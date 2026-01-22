#pragma once

namespace Base
{

struct Color
{
    unsigned char r;        // Color red value
    unsigned char g;        // Color green value
    unsigned char b;        // Color blue value
    unsigned char a;        // Color alpha value

    bool operator==(const Color& other) const
    {
        return r == other.r && g == other.g && b == other.b && a == other.a;
    }

    bool operator!=(const Color& other) const
    {
        return r != other.r || g != other.g || b != other.b || a != other.a;
    }
};

}