#pragma once

#include "MouseBase.h"
#include "KeyboardBase.h"

class HandleInputBase
{
public:
    virtual void update(float delta) = 0;

    // keyboard
    virtual bool keyDown(Base::Key key) const = 0;
    virtual bool keyPressed(Base::Key key) const = 0;
    virtual bool keyReleased(Base::Key key) const = 0;

    // mouse
    virtual bool mouseDown(Base::MouseButton button) const = 0;
    virtual bool mousePressed(Base::MouseButton button) const = 0;
    virtual bool mouseReleased(Base::MouseButton button) const = 0;
    virtual Base::Point mousePosition() const = 0;
    virtual bool mouseInWindow() const = 0;
    virtual void mouseSetPosition(Base::Point position) = 0;
    virtual float mouseWheelMove() const = 0;
    virtual void mouseSetCursor(Base::MouseCursor cursor) = 0;
public:
    HandleInputBase(MouseBase& mouse, KeyboardBase& keyboard) : mouse_(mouse), keyboard_(keyboard) { }
protected:
    MouseBase& mouse_;
    KeyboardBase& keyboard_;
};