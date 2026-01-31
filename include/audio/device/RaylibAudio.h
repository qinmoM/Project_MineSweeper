#pragma once

#include "IAudioSystem.h"
#include "RaylibSound.h"
#include "RaylibMusic.h"

class RaylibAudio final : public IAudioSystem
{
public:
    static RaylibAudio& getInstance();
public:
    void update() override;

    void setBGMVolume(float volume) override;
    void setAmbientVolume(float volume) const override;
    void setSFXVolume(float volume) override;

    void loadBGM(const std::string& filePath) override;
    void playBGM() override;
    void stopBGM() override;
    void pauseBGM() override;
    void resumeBGM() override;

    void registerAmbient(const std::string& name, const std::string& filePath) override;
    void unregisterAmbient(const std::string& name) override;
    void playAmbient(const std::string& name) override;
    void stopAmbient(const std::string& name) override;
    void pauseAmbient(const std::string& name) override;
    void resumeAmbient(const std::string& name) override;

    void registerSFX(const std::string& name, const std::string& filePath, uint8_t poolSize = 1) override;
    void unregisterSFX(const std::string& name) override;
    void playSFX(const std::string& name) override;
    void stopSFX(const std::string& name) override;
public:
    RaylibAudio(const RaylibAudio&) = delete;
    RaylibAudio& operator=(const RaylibAudio&) = delete;
private:
    RaylibAudio();
    ~RaylibAudio();
};