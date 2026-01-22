#pragma once

#include "ButtonBase.h"
#include "Sprite.h"

class ButtonImage : public ButtonBase
{
public:
    virtual bool contains(const Base::Point& pos) const override;
    virtual Sprite& getSprite() { return sprite_; }
    virtual const Sprite& getSprite() const { return sprite_; }

    virtual void update(HandleInputSemantic& handle, float delta) override;
    virtual void render(RendererProxy& renderer) override;
public:
    ButtonImage(const Sprite& sprite, const Base::Point& position, const TriggerFunc& callback, const ContainsFunc& contains, const UpdateFunc& update);
protected:
    Sprite sprite_;
};