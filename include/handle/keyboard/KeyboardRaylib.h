#pragma once

#include "KeyboardBase.h"
#include "raylib.h"
#include <vector>

class KeyboardRaylib final : public KeyBoardBase
{
public:
    // sustained check
    bool keyDown(Base::Key key) const override;

    // signal check
    bool keyPressed(Base::Key key) const override;
    bool keyReleased(Base::Key key) const override;

private:
    KeyboardKey mapKey(Base::Key key) const;
};