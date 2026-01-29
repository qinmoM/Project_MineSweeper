#include "Text.h"

Text::Text(const std::shared_ptr<FontBase>& font) : font_(font), color_(Base::Color{0, 0, 0, 255}) { }

void Text::setText(const std::string& text)
{
    text_ = text;
}

void Text::setPosition(const Base::Point& position)
{
    transform_.position_ = position;
}

void Text::setOrigin(const Base::Point& origin)
{
    transform_.origin_ = origin;
}

void Text::setRotation(float rotation)
{
    transform_.rotation_ = rotation;
}

void Text::setColor(const Base::Color& color)
{
    color_ = color;
}

void Text::setSize(float size)
{
    size_ = size;
}

void Text::setSpacing(int spacing)
{
    spacing_ = spacing;
}

void Text::setFont(const std::shared_ptr<FontBase>& font)
{
    font_ = font;
}



std::string Text::getText() const
{
    return text_;
}

std::shared_ptr<FontBase> Text::getFont() const
{
    return font_;
}

Base::Point Text::getPosition() const
{
    return transform_.position_;
}

Base::Point Text::getOrigin() const
{
    return transform_.origin_;
}

float Text::getRotation() const
{
    return transform_.rotation_;
}

Base::Color Text::getColor() const
{
    return color_;
}

float Text::getSize() const
{
    return size_;
}

int Text::getSpacing() const
{
    return spacing_;
}

Base::Point Text::getBounderies() const
{
    return font_->getBoundaries(text_, size_, spacing_);
}
