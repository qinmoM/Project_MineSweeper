#include "ButtonImage.h"

ButtonImage::ButtonImage(const Sprite& sprite, const Base::Point& position, const TriggerFunc& callback, const ContainsFunc& contains, const UpdateFunc& update)
    : ButtonBase(position, callback, contains, update), sprite_(sprite) { }

bool ButtonImage::contains(const Base::Point& pos) const
{
    return contains_(*this, pos);
}

void ButtonImage::update(HandleInputSemantic& handle, float delta)
{
    if (update_)
        update_(*this, handle, delta);
}

void ButtonImage::render(RendererProxy& renderer)
{
    renderer.drawSprite(sprite_);
}