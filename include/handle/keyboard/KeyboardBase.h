#pragma once

#include "BaseKeyboard.h"

class KeyboardBase
{
public:
    // sustained check
    virtual bool keyDown(Base::Key key) const = 0;

    // signal check
    virtual bool keyPressed(Base::Key key) const = 0;
    virtual bool keyReleased(Base::Key key) const = 0;

public:
    virtual ~KeyboardBase() = default;
};