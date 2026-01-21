#pragma once

#include "BasePoint.h"
#include "EventSubject.h"
#include "RendererProxy.h"

class ButtonBase
{
public:
    using TriggerFunc = std::function<void()>;
    using ContainsFunc = std::function<bool(const ButtonBase& button, const Base::Point& pos)>;
public:
    virtual Base::Point getPosition() const { return position_; }
    virtual TriggerFunc getCallback() const { return callback_; }
    virtual bool contains(const Base::Point& pos) const = 0;

    virtual void update(float delta) = 0;
    virtual void render(RendererProxy& renderer) = 0;
public:
    ButtonBase(const Base::Point& position, const TriggerFunc& callback, const ContainsFunc& contains)
        : position_(position), callback_(callback), contains_(contains) { }
    virtual ~ButtonBase() = default;
protected:
    Base::Point position_;
    TriggerFunc callback_;
    ContainsFunc contains_;
};