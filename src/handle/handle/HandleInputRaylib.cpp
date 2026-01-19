#include "HandleInputRaylib.h"

void HandleInputRaylib::update(float delta)
{
    // raylib will automatioally update
}



// keyboard
bool HandleInputRaylib::keyDown(Base::Key key) const
{
    return keyboard_.keyDown(key);
}

bool HandleInputRaylib::keyPressed(Base::Key key) const
{
    return keyboard_.keyPressed(key);
}

bool HandleInputRaylib::keyReleased(Base::Key key) const
{
    return keyboard_.keyReleased(key);
}



// mouse
bool HandleInputRaylib::mouseDown(Base::MouseButton button) const
{
    return mouse_.buttonDown(button);
}

bool HandleInputRaylib::mousePressed(Base::MouseButton button) const
{
    return mouse_.buttonPressed(button);
}

bool HandleInputRaylib::mouseReleased(Base::MouseButton button) const
{
    return mouse_.buttonReleased(button);
}

Base::Point HandleInputRaylib::mousePosition() const
{
    return mouse_.getPosition();
}

bool HandleInputRaylib::mouseInWindow() const
{
    return mouse_.inWindow();
}

void HandleInputRaylib::mouseSetPosition(Base::Point position)
{
    return mouse_.setPosition(position);
}

float HandleInputRaylib::mouseWheelMove() const
{
    return mouse_.getWheelMove();
}

void HandleInputRaylib::mouseSetCursor(Base::MouseCursor cursor)
{
    return mouse_.setCursor(cursor);
}
