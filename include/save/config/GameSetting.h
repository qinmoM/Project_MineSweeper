#pragma once

#include "ISerialization.h"

class GameSetting
{
public:
    static constexpr int VERSION = 0;

    int rows_;
    int cols_;
    std::string theme_;

    void serialize(ISerialization& serializer)
    {
        int version = VERSION;
        serializer.value("version", version);

        if (!serializer.isSavingMode())
        {
            if (version <= 0)
            {
                rows_ = 9;
                cols_ = 15;
                theme_ = "Bule";
            }
        }

        serializer.value("rows", rows_);
        serializer.value("cols", cols_);
        serializer.value("theme", theme_);
    }
};