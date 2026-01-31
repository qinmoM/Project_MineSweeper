#pragma once

#include "ISound.h"
#include "raylib.h"
#include "IAudioSystem.h"

class RaylibAudio;

class RaylibSound : public ISound
{
public:
    static constexpr float VOLUME_RATIO = 0.01f;

    RaylibSound(IAudioSystem::SoundToken, RaylibAudio& audioSystem, const std::string& filePath);
    ~RaylibSound();
public:
    void play() override;
    void stop() override;
    void pause() override;
    void resume() override;
    bool isPlaying() override;

    void setVolume(float volume) override;
    void setPitch(float pitch) override;
    void setPan(float pan) override;
private:
    Sound sound_;
};