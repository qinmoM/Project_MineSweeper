#include "HandleInputSemantic.h"


HandleInputSemantic::HandleInputSemantic(std::unique_ptr<HandleInputBase> handle, float maxClickTime, float maxMoveDistance, float minLongPressTime)
    : handle_(std::move(handle))
    , maxClickTime_(maxClickTime)
    , maxMoveDistance_(maxMoveDistance)
    , minLongPressTime_(minLongPressTime)
{
    mouseClickStates_[Base::MouseButton::Left] = ClickState();
    mouseClickStates_[Base::MouseButton::Right] = ClickState();
    mouseClickStates_[Base::MouseButton::Middle] = ClickState();
    mouseClickStates_[Base::MouseButton::forward] = ClickState();
    mouseClickStates_[Base::MouseButton::back] = ClickState();
}


bool HandleInputSemantic::mouseClicked(Base::MouseButton button) const
{
    return mouseClickStates_.at(button).thisFrame_;
}

bool HandleInputSemantic::mouseLongPressed(Base::MouseButton button) const
{
    return (mouseClickStates_.at(button).time_ >= minLongPressTime_) && (mouseDown(button));
}

//              base
void HandleInputSemantic::update(float delta)
{
    handle_->update(delta);

    for (auto& [button, state] : mouseClickStates_)
    {
        state.thisFrame_ = false;

        if (mouseDown(button))
            state.time_ += delta;

        if (mousePressed(button))
        {
            state.time_ = 0.0f;
            state.position_ = mousePosition();
        }

        if (mouseReleased(button))
        {
            Base::Point dPosition = mousePosition() - state.position_;
            if ((state.time_ <= maxClickTime_) && (dPosition.x * dPosition.x + dPosition.y * dPosition.y <= maxMoveDistance_ * maxMoveDistance_))
            {
                state.thisFrame_ = true;
                state.time_ = 0.0f;
            }
        }
    }
}

// keyboard
bool HandleInputSemantic::keyDown(Base::Key key) const
{
    return handle_->keyDown(key);
}

bool HandleInputSemantic::keyPressed(Base::Key key) const
{
    return handle_->keyPressed(key);
}

bool HandleInputSemantic::keyReleased(Base::Key key) const
{
    return handle_->keyReleased(key);
}

// mouse
bool HandleInputSemantic::mouseDown(Base::MouseButton button) const
{
    return handle_->mouseDown(button);
}

bool HandleInputSemantic::mousePressed(Base::MouseButton button) const
{
    return handle_->mousePressed(button);
}

bool HandleInputSemantic::mouseReleased(Base::MouseButton button) const
{
    return handle_->mouseReleased(button);
}

Base::Point HandleInputSemantic::mousePosition() const
{
    return handle_->mousePosition();
}

bool HandleInputSemantic::mouseInWindow() const
{
    return handle_->mouseInWindow();
}

void HandleInputSemantic::mouseSetPosition(Base::Point position)
{
    return handle_->mouseSetPosition(position);
}

float HandleInputSemantic::mouseWheelMove() const
{
    return handle_->mouseWheelMove();
}

void HandleInputSemantic::mouseSetCursor(Base::MouseCursor cursor)
{
    return handle_->mouseSetCursor(cursor);
}
