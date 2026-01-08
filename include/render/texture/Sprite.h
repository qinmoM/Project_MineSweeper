#pragma once

#include "BaseColor.h"
#include "BaseTransform.h"
#include "TextureBase.h"
#include <memory>

class Sprite
{
public:
    Sprite(const std::shared_ptr<TextureBase>& texture);

public:
    void setPosition(const Base::Point& position);
    void setScale(const Base::Point& scale);
    void setColor(const Base::Color& color);
    void setTexture(const std::shared_ptr<TextureBase>& texture);

    Base::Point getPosition() const;
    Base::Point getScale() const;
    Base::Color getColor() const;
    std::shared_ptr<TextureBase> getTexture() const;

private:
    std::shared_ptr<TextureBase> texture_;
    Base::Transform transform_;
    Base::Color color_;
};