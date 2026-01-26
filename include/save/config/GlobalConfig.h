#pragma once

#include "ISerialization.h"

struct GlobalConfig
{
    static constexpr int VERSION = 2;

    short width_;
    short height_;
    short fps_;
    float maxClickTime_;
    float maxMoveDistance_;
    float minLongPressTime_;
    std::string title_;

    void serialize(ISerialization& serializer)
    {
        int version = VERSION;
        serializer.value("version", version);
        
        if (!serializer.isSavingMode())
        {
            if (version < 1)
                fps_ = 120;
            if (version < 2)
            {
                maxClickTime_ = 0.5f;
                maxMoveDistance_ = 10.0f;
                minLongPressTime_ = 0.5f;
            }
        }

        serializer.value("width", width_);
        serializer.value("height", height_);
        serializer.value("title", title_);

        if (1 <= version)
            serializer.value("fps", fps_);
        if (2 <= version)
        {
            serializer.value("maxClickTime", maxClickTime_);
            serializer.value("maxMoveDistance", maxMoveDistance_);
            serializer.value("minLongPressTime", minLongPressTime_);
        }
    }
};