#pragma once

#include "HandleInputBase.h"
#include "ToolClock.h"
#include <memory>
#include <unordered_map>
#include <vector>

class HandleInputSemantic
{
public:

    //              semantic

    bool mouseClicked(Base::MouseButton button) const;
    bool mouseLongPressed(Base::MouseButton button) const;

    //              base

    void update(float delta);
    // keyboard
    bool keyDown(Base::Key key) const;
    bool keyPressed(Base::Key key) const;
    bool keyReleased(Base::Key key) const;
    // mouse
    bool mouseDown(Base::MouseButton button) const;
    bool mousePressed(Base::MouseButton button) const;
    bool mouseReleased(Base::MouseButton button) const;
    Base::Point mousePosition() const;
    bool mouseInWindow() const;
    void mouseSetPosition(Base::Point position);
    float mouseWheelMove() const;
    void mouseSetCursor(Base::MouseCursor cursor);
public:
    HandleInputSemantic(std::shared_ptr<HandleInputBase> handle);

protected:
    struct ClickState
    {
        Base::Point position_{0.0f, 0.0f};
        float time_ = 0.0f;
        bool thisFrame_ = false;
    };
protected:
    std::shared_ptr<HandleInputBase> handle_;
    std::unordered_map<Base::MouseButton, ClickState> mouseClickStates_;
    float maxClickTime_ = 0.5f;
    float maxMoveDistance_ = 5.0f;
    float minLongPressTime_ = 1.0f;
};