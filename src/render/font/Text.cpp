#include "Text.h"

Text::Text(const std::shared_ptr<FontBase>& font, int size) : font_(font), size_(size), color_(Base::Color{0, 0, 0, 255}) { }

void Text::setText(const std::string& text)
{
    text_ = text;
}

void Text::setPosition(const Base::Point& position)
{
    transform_.position_ = position;
}

void Text::setColor(const Base::Color& color)
{
    color_ = color;
}

void Text::setSize(int size)
{
    size_ = size;
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

Base::Color Text::getColor() const
{
    return color_;
}

int Text::getSize() const
{
    return size_;
}
