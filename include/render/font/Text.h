#pragma once

#include "BaseTransform.h"
#include "BaseColor.h"
#include "FontBase.h"
#include <string>
#include <memory>

class Text
{
public:
    Text(const std::shared_ptr<FontBase>& font, int size);

public:
    void setText(const std::string& text);
    void setPosition(const Base::Point& position);
    void setColor(const Base::Color& color);
    void setSize(int size);
    void setFont(const std::shared_ptr<FontBase>& font);

    std::string getText() const;
    std::shared_ptr<FontBase> getFont() const;
    Base::Point getPosition() const;
    Base::Color getColor() const;
    int getSize() const;

private:
    std::string text_;
    std::shared_ptr<FontBase> font_;
    Base::Transform transform_;
    Base::Color color_;
    int size_;
};