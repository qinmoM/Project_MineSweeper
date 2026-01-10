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
    bool buttonDown(Base::MouseButton button) const override;
    // single check
    bool buttonPressed(Base::MouseButton button) const override;
    bool buttonReleased(Base::MouseButton button) const override;

    // position
    Base::Point getPosition() const override;
    bool inWindow() const override;
    void setPosition(const Base::Point& position) override;

    // wheel
    float getWheelMove() const override;

    // cursor
    void setCursor(Base::MouseCursor cursor) override;

public:
    MouseRaylib(const MouseRaylib&) = delete;
    MouseRaylib& operator=(const MouseRaylib&) = delete;

private:
    // button
    MouseButton mapButton(Base::MouseButton button) const;
    // cursor
    MouseCursor mapCursor(Base::MouseCursor cursor) const;

private:
    MouseRaylib() = default;
    ~MouseRaylib() = default;
};