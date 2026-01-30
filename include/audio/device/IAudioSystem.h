#pragma once

#include "ISound.h"
#include "IMusic.h"

class IAudioSystem
{
public:
    virtual std::shared_ptr<ISound> loadSound(const std::string& filePath) = 0;
    virtual std::shared_ptr<IMusic> loadMusic(const std::string& filePath) = 0;
public:
    virtual ~IAudioSystem() = default;
public:
    struct SoundToken
    {
    private:
        explicit SoundToken() = default;
        friend class IAudioSystem;
    };

    struct MusicToken
    {
    private:
        explicit MusicToken() = default;
        friend class IAudioSystem;
    };
protected:
    inline SoundToken getSoundToken() { return SoundToken(); }
    inline MusicToken getMusicToken() { return MusicToken(); }
};