#pragma once

#include "IMusic.h"
#include "raylib.h"
#include "IAudioSystem.h"

class RaylibAudio;

class RaylibMusic final : public IMusic
{
public:
    RaylibMusic(IAudioSystem::MusicToken, RaylibAudio& audioSystem, const std::string& filename);
    ~RaylibMusic();
public:
    float getTimeLength() override;
    float getTimePlayed() override;

    void update() override;

    void play() override;
    void stop() override;
    void pause() override;
    void resume() override;
    bool isPlaying() override;

    void seek(float seconds) override;
    void setVolume(float volume) override;
    void setPitch(float pitch) override;
    void setPan(float pan) override;
private:
    Music music_;
};