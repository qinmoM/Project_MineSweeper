#pragma once

#include "ISerialization.h"

struct GlobalConfig
{
    short width_;
    short height_;
    short fps_;
    std::string title_;

    void serialize(ISerialization& serializer)
    {
        serializer.value("width", width_);
        serializer.value("height", height_);
        serializer.value("title", title_);
        serializer.value("fps", fps_);
    }
};