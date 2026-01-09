#pragma once

#include "BasePoint.h"
#include "BaseMouseButton.h"
#include "BaseMouseCursor.h"

class MouseBase
{
public:
    // sustained check
    virtual bool buttonDown(Base::MouseButton button) = 0;
    // single check
    virtual bool buttonPressed(Base::MouseButton button) = 0;
    virtual bool buttonReleased(Base::MouseButton button) = 0;

    // position
    virtual Base::Point getPosition() = 0;
    virtual bool inWindow() = 0;
    virtual void setPosition(const Base::Point& position) = 0;

    // wheel
    virtual float getWheelMove() = 0;

    // cursor
    virtual void setCursor(Base::MouseCursor cursor) = 0;

public:
    virtual ~MouseBase() = default;
};