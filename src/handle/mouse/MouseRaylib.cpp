#include "MouseRaylib.h"

MouseBase& MouseRaylib::getInstance()
{
    static MouseRaylib instance;
    return instance;
}

bool MouseRaylib::buttonDown(Base::MouseButton button) const
{
    return IsMouseButtonDown(mapButton(button));
}

bool MouseRaylib::buttonPressed(Base::MouseButton button) const
{
    return IsMouseButtonPressed(mapButton(button));
}

bool MouseRaylib::buttonReleased(Base::MouseButton button) const
{
    return IsMouseButtonReleased(mapButton(button));
}

Base::Point MouseRaylib::getPosition() const
{
    Vector2 position = GetMousePosition();
    return {position.x, position.y};
}

bool MouseRaylib::inWindow() const
{
    return GetMouseX() >= 0 && GetMouseX() < GetScreenWidth()
        && GetMouseY() >= 0 && GetMouseY() < GetScreenHeight();
}

void MouseRaylib::setPosition(const Base::Point& position)
{
    SetMousePosition(position.x, position.y);
}

float MouseRaylib::getWheelMove() const
{
    return GetMouseWheelMove();
}

void MouseRaylib::setCursor(Base::MouseCursor cursor)
{
    SetMouseCursor(mapCursor(cursor));
}

MouseButton MouseRaylib::mapButton(Base::MouseButton button) const
{
    switch (button)
    {
    case Base::MouseButton::Left:       return MOUSE_BUTTON_LEFT;
    case Base::MouseButton::Right:      return MOUSE_BUTTON_RIGHT;
    case Base::MouseButton::Middle:     return MOUSE_BUTTON_MIDDLE;
    case Base::MouseButton::forward:    return MOUSE_BUTTON_FORWARD;
    case Base::MouseButton::back:       return MOUSE_BUTTON_BACK;
    }
    throw std::invalid_argument("Invalid mouse button. | MouseRaylib::mapButton()\n");
}

MouseCursor MouseRaylib::mapCursor(Base::MouseCursor cursor) const
{
    switch (cursor)
    {
    case Base::MouseCursor::Arrow:              return MOUSE_CURSOR_ARROW;
    case Base::MouseCursor::Text:               return MOUSE_CURSOR_DEFAULT;
    case Base::MouseCursor::Hand:               return MOUSE_CURSOR_POINTING_HAND;
    case Base::MouseCursor::Cross:              return MOUSE_CURSOR_CROSSHAIR;
    case Base::MouseCursor::ResizeVertical:     return MOUSE_CURSOR_RESIZE_NS;
    case Base::MouseCursor::ResizeHorizontal:   return MOUSE_CURSOR_RESIZE_EW;
    case Base::MouseCursor::ResizeAll:          return MOUSE_CURSOR_RESIZE_ALL;
    case Base::MouseCursor::RsizeTopLeft:       return MOUSE_CURSOR_RESIZE_NWSE;
    case Base::MouseCursor::RsizeTopRight:      return MOUSE_CURSOR_RESIZE_NESW;
    case Base::MouseCursor::NotAllowed:         return MOUSE_CURSOR_NOT_ALLOWED;
    }
    throw std::invalid_argument("Invalid mouse cursor. | MouseRaylib::mapCursor()\n");
}
