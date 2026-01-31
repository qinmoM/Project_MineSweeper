#pragma once

#include "ISound.h"
#include "IMusic.h"
#include <unordered_map>
#include <vector>
#include <stdint.h>

class IAudioSystem
{
public:
    virtual void update() = 0;

    virtual void setBGMVolume(float volume) = 0;
    virtual void setAmbientVolume(float volume) const = 0;
    virtual void setSFXVolume(float volume) = 0;

    virtual void loadBGM(const std::string& filePath) = 0;
    virtual void playBGM() = 0;
    virtual void stopBGM() = 0;
    virtual void pauseBGM() = 0;
    virtual void resumeBGM() = 0;

    virtual void registerAmbient(const std::string& name, const std::string& filePath) = 0;
    virtual void unregisterAmbient(const std::string& name) = 0;
    virtual void playAmbient(const std::string& name) = 0;
    virtual void stopAmbient(const std::string& name) = 0;
    virtual void pauseAmbient(const std::string& name) = 0;
    virtual void resumeAmbient(const std::string& name) = 0;

    virtual void registerSFX(const std::string& name, const std::string& filePath, uint8_t poolSize = 1) = 0;
    virtual void unregisterSFX(const std::string& name) = 0;
    virtual void playSFX(const std::string& name) = 0;
    virtual void stopSFX(const std::string& name) = 0;
public:
    virtual ~IAudioSystem() = default;
protected:
    struct ISoundPool
    {
        std::vector<std::unique_ptr<ISound>> sounds_;
        int currentSoundIndex_ = 0;
    };
protected:
    std::unique_ptr<IMusic> mainMusic_;
    std::string mainMusicPath_;

    std::unordered_map<std::string, std::unique_ptr<IMusic>> musicMap_;
    std::unordered_map<std::string, ISoundPool> soundMap_;
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