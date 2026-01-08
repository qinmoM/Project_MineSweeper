#pragma once

#include "BaseKeyboard.h"

class KeyBoardBase
{
public:
    // sustained check
    virtual void keyDown(Base::Key key) = 0;
    // signal check
    virtual void keyPressed(Base::Key key) = 0;
    virtual void keyReleased(Base::Key key) = 0;

public:
    virtual ~KeyBoardBase() = default;
};