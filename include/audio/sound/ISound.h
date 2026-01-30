#pragma once

#include <memory>
#include <string>
#include <stdexcept>

class ISound
{
public:
    ~ISound() = default;
public:
    virtual void play() = 0;
    virtual void stop() = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual bool isPlaying() = 0;

    virtual void setVolume(float volume) = 0;
    virtual void setPitch(float pitch) = 0;
    virtual void setPan(float pan) = 0;
};