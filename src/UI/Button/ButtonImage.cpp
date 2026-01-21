#include "ButtonImage.h"

ButtonImage::ButtonImage(const Sprite& sprite, const Base::Point& position, const TriggerFunc& callback, const ContainsFunc& contains)
    : ButtonBase(position, callback, contains), sprite_(sprite) { }

bool ButtonImage::contains(const Base::Point& pos) const
{
    return contains_(*this, pos);
}

void ButtonImage::update(float delta)
{
    ;
}

void ButtonImage::render(RendererProxy& renderer)
{
    renderer.drawSprite(sprite_);
}