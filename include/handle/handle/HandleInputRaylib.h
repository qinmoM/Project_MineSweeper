#pragma once

#include "raylib.h"
#include "HandleInputBase.h"
#include "MouseRaylib.h"
#include "KeyboardRaylib.h"

class HandleInputRaylib : public HandleInputBase
{
public:
    void update() override;

    // keyboard
    bool keyDown(Base::Key key) const override;
    bool keyPressed(Base::Key key) const override;
    bool keyReleased(Base::Key key) const override;

    // mouse
    bool mouseDown(Base::MouseButton button) const override;
    bool mousePressed(Base::MouseButton button) const override;
    bool mouseReleased(Base::MouseButton button) const override;
    Base::Point mousePosition() const override;
    bool mouseInWindow() const override;
    void mouseSetPosition(Base::Point position) override;
    float mouseWheelMove() const override;
    void mouseSetCursor(Base::MouseCursor cursor) override;
public:
    HandleInputRaylib(MouseBase& mouse, KeyboardBase& keyboard) : HandleInputBase(mouse, keyboard) { }
};