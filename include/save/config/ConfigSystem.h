#pragma once

#include "GlobalConfig.h"
#include "GameSetting.h"
#include <memory>

class ConfigSystem
{
public:
    inline ConfigSystem() : globalConfig_(), gameSetting_() { }
public:
    inline GlobalConfig& globalConfig() { return globalConfig_; }
    inline GameSetting& gameSetting() { return gameSetting_; }
private:
    GlobalConfig globalConfig_;
    GameSetting gameSetting_;
};