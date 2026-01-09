#pragma once

#include "KeyboardBase.h"
#include "raylib.h"

class KeyboardRaylib final : public KeyboardBase
{
public:
    static KeyboardBase& getInstance();
public:
    // sustained check
    bool keyDown(Base::Key key) const override;

    // signal check
    bool keyPressed(Base::Key key) const override;
    bool keyReleased(Base::Key key) const override;

public:
    KeyboardRaylib(const KeyboardRaylib&) = delete;
    KeyboardRaylib& operator=(const KeyboardRaylib&) = delete;

private:
    KeyboardKey mapKey(Base::Key key) const;

private:
    KeyboardRaylib() = default;
    ~KeyboardRaylib() = default;
};