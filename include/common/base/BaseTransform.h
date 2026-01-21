#pragma once

#include "BasePoint.h"

namespace Base
{

struct Transform
{
    Transform() : position_(0.0f, 0.0f), scale_(1.0f, 1.0f), origin_(0.0f, 0.0f), rotation_(0) {}

    Base::Point position_;
    Base::Point scale_;
    Base::Point origin_;
    float rotation_;
};

}