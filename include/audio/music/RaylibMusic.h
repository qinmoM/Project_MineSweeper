#pragma once

#include "IMusic.h"
#include "raylib.h"
#include "IAudioSystem.h"

class RaylibAudio;

class RaylibMusic final : public IMusic
{
public:
    static constexpr float VOLUME_RATIO = 0.01f;

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

    void setLoop(bool loop) override;
    void seek(float seconds) override;
    void setVolume(float volume) override;
    void setPitch(float pitch) override;
    void setPan(float pan) override;
private:
    Music music_;
};