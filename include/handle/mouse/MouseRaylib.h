#pragma once

#include "MouseBase.h"
#include "raylib.h"
#include <stdexcept>

class MouseRaylib final : public MouseBase
{
public:
    static MouseBase& getInstance();
public:
    // sustained check
    bool buttonDown(Base::MouseButton button) override;
    // single check
    bool buttonPressed(Base::MouseButton button) override;
    bool buttonReleased(Base::MouseButton button) override;

    // position
    Base::Point getPosition() override;
    void setPosition(const Base::Point& position) override;

    // wheel
    float getWheelMove() override;

    // cursor
    void setCursor(Base::MouseCursor cursor) override;

public:
    MouseRaylib(const MouseRaylib&) = delete;
    MouseRaylib& operator=(const MouseRaylib&) = delete;

private:
    // button
    MouseButton mapButton(Base::MouseButton button);
    // cursor
    MouseCursor mapCursor(Base::MouseCursor cursor);

private:
    MouseRaylib() = default;
    ~MouseRaylib() = default;
};