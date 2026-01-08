#pragma once

#include "BasePoint.h"

namespace Base
{

class Transform
{
public:
    Base::Point position_;
    Base::Point scale_;
    Base::Point origin_;
    float rotation_;
};

}