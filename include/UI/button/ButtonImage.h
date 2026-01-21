#pragma once

#include "ButtonBase.h"
#include "Sprite.h"

class ButtonImage : public ButtonBase
{
public:
    virtual bool contains(const Base::Point& pos) const override;

    virtual void update(float delta) override;
    virtual void render(RendererProxy& renderer) override;
public:
    ButtonImage(const Sprite& sprite, const Base::Point& position, const TriggerFunc& callback, const ContainsFunc& contains);
protected:
    Sprite sprite_;
};