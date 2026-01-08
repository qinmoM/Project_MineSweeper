#include "Sprite.h"

Sprite::Sprite(const std::shared_ptr<TextureBase>& texture) : texture_(texture) { }

void Sprite::setPosition(const Base::Point& position)
{
    transform_.position_ = position;
}

void Sprite::setScale(const Base::Point& scale)
{
    transform_.scale_ = scale;
}

void Sprite::setColor(const Base::Color& color)
{
    color_ = color;
}

void Sprite::setTexture(const std::shared_ptr<TextureBase>& texture)
{
    texture_ = texture;
}


Base::Point Sprite::getPosition() const
{
    return transform_.position_;
}

Base::Point Sprite::getScale() const
{
    return transform_.scale_;
}

Base::Color Sprite::getColor() const
{
    return color_;
}

std::shared_ptr<TextureBase> Sprite::getTexture() const
{
    return texture_;
}
