#pragma once

#include "GlobalConfig.h"
#include "GameSetting.h"
#include <memory>

class ConfigSystem
{
public:
    inline ConfigSystem(const std::string& executablePath) : globalConfig_(), gameSetting_(), executablePath_(executablePath) { }
public:
    inline GlobalConfig& globalConfig() { return globalConfig_; }
    inline GameSetting& gameSetting() { return gameSetting_; }
    inline const std::string& execPath() { return executablePath_; }
private:
    GlobalConfig globalConfig_;
    GameSetting gameSetting_;
    std::string executablePath_;
};