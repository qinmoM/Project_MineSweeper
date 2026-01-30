#pragma once

#include <string>
#include <stdexcept>

class IMusic
{
public:
    ~IMusic() = default;
public:
    virtual float getTimeLength() = 0;
    virtual float getTimePlayed() = 0;

    virtual void update() = 0;

    virtual void play() = 0;
    virtual void stop() = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual bool isPlaying() = 0;

    virtual void seek(float seconds) = 0;
    virtual void setVolume(float volume) = 0;
    virtual void setPitch(float pitch) = 0;
    virtual void setPan(float pan) = 0;
};