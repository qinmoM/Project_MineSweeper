#pragma once

#include "BaseTransform.h"
#include "BaseColor.h"
#include "FontBase.h"
#include <string>
#include <memory>

class Text
{
public:
    Text(const std::shared_ptr<FontBase>& font);

public:
    void setText(const std::string& text);
    void setPosition(const Base::Point& position);
    void setOrigin(const Base::Point& origin);
    void setRotation(float rotation);
    void setColor(const Base::Color& color);
    void setSize(float size);
    void setSpacing(int spacing);
    void setFont(const std::shared_ptr<FontBase>& font);

    std::string getText() const;
    Base::Point getPosition() const;
    Base::Point getOrigin() const;
    float getRotation() const;
    Base::Color getColor() const;
    float getSize() const;
    int getSpacing() const;
    std::shared_ptr<FontBase> getFont() const;

    Base::Point getBounderies() const;
private:
    std::string text_;
    std::shared_ptr<FontBase> font_;
    Base::Transform transform_;
    Base::Color color_;
    float size_;
    int spacing_;
};