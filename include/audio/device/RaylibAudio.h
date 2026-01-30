#pragma once

#include "IAudioSystem.h"
#include "RaylibSound.h"
#include "RaylibMusic.h"

class RaylibAudio final : public IAudioSystem
{
public:
    static RaylibAudio& getInstance();
public:
    std::shared_ptr<ISound> loadSound(const std::string& filePath) override;
    std::shared_ptr<IMusic> loadMusic(const std::string& filePath) override;
public:
    RaylibAudio(const RaylibAudio&) = delete;
    RaylibAudio& operator=(const RaylibAudio&) = delete;
private:
    RaylibAudio();
    ~RaylibAudio();
};