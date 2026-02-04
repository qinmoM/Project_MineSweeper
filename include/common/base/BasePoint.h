#pragma once

namespace Base
{

struct Point
{
    float x;
    float y;

    Point() : x(0.0f), y(0.0f) { }
    Point(float x, float y) : x(x), y(y) { }
};

inline Point operator+(const Point& a, const Point& b)
{
    return Point(a.x + b.x, a.y + b.y);
}

inline Point& operator+=(Point& a, const Point& b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

inline Point operator+(const Point& a, const float scalar)
{
    return Point(a.x + scalar, a.y + scalar);
}

inline Point& operator+=(Point& a, const float scalar)
{
    a.x += scalar;
    a.y += scalar;
    return a;
}

inline Point operator-(const Point& a, const Point& b)
{
    return Point(a.x - b.x, a.y - b.y);
}

inline Point& operator-=(Point& a, const Point& b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

inline Point operator-(const Point& a, const float scalar)
{
    return Point(a.x - scalar, a.y - scalar);
}

inline Point& operator-=(Point& a, const float scalar)
{
    a.x -= scalar;
    a.y -= scalar;
    return a;
}

inline Point operator-(const Point& a)
{
    return Point(-a.x, -a.y);
}

inline Point operator*(const Point& a, const float scalar)
{
    return Point(a.x * scalar, a.y * scalar);
}

inline Point& operator*=(Point& a, const float scalar)
{
    a.x *= scalar;
    a.y *= scalar;
    return a;
}

inline Point operator/(const Point& a, const float scalar)
{
    return Point(a.x / scalar, a.y / scalar);
}

inline Point& operator/=(Point& a, const float scalar)
{
    a.x /= scalar;
    a.y /= scalar;
    return a;
}

inline bool operator==(const Point& a, const Point& b)
{
    return (a.x == b.x) && (a.y == b.y);
}

inline bool operator!=(const Point& a, const Point& b)
{
    return (a.x != b.x) || (a.y != b.y);
}

inline bool operator<(const Point& a, const Point& b)
{
    return (a.x < b.x) && (a.y < b.y);
}

inline bool operator<=(const Point& a, const Point& b)
{
    return (a.x <= b.x) && (a.y <= b.y);
}

inline bool operator>(const Point& a, const Point& b)
{
    return (a.x > b.x) && (a.y > b.y);
}

inline bool operator>=(const Point& a, const Point& b)
{
    return (a.x >= b.x) && (a.y >= b.y);
}

}