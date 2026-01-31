#include "RaylibAudio.h"

RaylibAudio::RaylibAudio()
{
    InitAudioDevice();
}

RaylibAudio::~RaylibAudio()
{
    CloseAudioDevice();
}

RaylibAudio& RaylibAudio::getInstance()
{
    static RaylibAudio instance;
    return instance;
}



void RaylibAudio::update()
{
    if (mainMusic_)
        mainMusic_->update();

    for (auto& [_, ambient] : musicMap_)
        ambient->update();
}



void RaylibAudio::setBGMVolume(float volume)
{
    if (volume < 0.0f || volume > 100.0f)
        throw std::invalid_argument("Volume must be between 0.0 and 100.0. | RaylibAudio::setAmbientVolume");

    if (mainMusic_)
        mainMusic_->setVolume(volume);
}

void RaylibAudio::setAmbientVolume(float volume) const
{
    if (volume < 0.0f || volume > 100.0f)
        throw std::invalid_argument("Volume must be between 0.0 and 100.0. | RaylibAudio::setAmbientVolume");

    for (auto& [_, ambient] : musicMap_)
        ambient->setVolume(volume);
}

void RaylibAudio::setSFXVolume(float volume)
{
    
    if (volume < 0.0f || volume > 100.0f)
        throw std::invalid_argument("Volume must be between 0.0 and 100.0. | RaylibAudio::setAmbientVolume");

    for (auto& [_, vec] : soundMap_)
    {
        for (std::unique_ptr<ISound>& sound : vec.sounds_)
            sound->setVolume(volume);
    }
}



void RaylibAudio::loadBGM(const std::string& filePath)
{
    if (mainMusicPath_ == filePath)
        return;

    if (mainMusic_)
        mainMusic_->stop();

    mainMusic_ = std::make_unique<RaylibMusic>(getMusicToken(), *this, filePath);
}

void RaylibAudio::playBGM()
{
    if (mainMusic_ && !mainMusic_->isPlaying())
        mainMusic_->play();
}

void RaylibAudio::stopBGM()
{
    if (mainMusic_ && mainMusic_->isPlaying())
        mainMusic_->stop();
}

void RaylibAudio::pauseBGM()
{
    if (mainMusic_ && mainMusic_->isPlaying())
        mainMusic_->pause();
}

void RaylibAudio::resumeBGM()
{
    if (mainMusic_ && !mainMusic_->isPlaying())
        mainMusic_->play();
}



void RaylibAudio::registerAmbient(const std::string& name, const std::string& filePath)
{
    if (name.empty() || musicMap_.find(name) != musicMap_.end())
        throw std::invalid_argument("name is illegal. | RaylibAudio::registerAmbient");

    std::unique_ptr<RaylibMusic> ambient = std::make_unique<RaylibMusic>(getMusicToken(), *this, filePath);
    musicMap_[name] = std::move(ambient);
}

void RaylibAudio::unregisterAmbient(const std::string& name)
{
    auto it = musicMap_.find(name);
    if (it != musicMap_.end())
    {
        if (it->second->isPlaying())
            it->second->stop();
        musicMap_.erase(name);
    }
}

void RaylibAudio::playAmbient(const std::string& name)
{
    auto it = musicMap_.find(name);
    if (it != musicMap_.end() && !it->second->isPlaying())
        it->second->play();
}

void RaylibAudio::stopAmbient(const std::string& name)
{
    auto it = musicMap_.find(name);
    if (it != musicMap_.end() && it->second->isPlaying())
        it->second->stop();
}

void RaylibAudio::pauseAmbient(const std::string& name)
{
    auto it = musicMap_.find(name);
    if (it != musicMap_.end() && it->second->isPlaying())
        it->second->pause();
}

void RaylibAudio::resumeAmbient(const std::string& name)
{
    auto it = musicMap_.find(name);
    if (it != musicMap_.end() && !it->second->isPlaying())
        it->second->play();
}



void RaylibAudio::registerSFX(const std::string& name, const std::string& filePath, uint8_t poolSize)
{
    if (poolSize < 1)
        return;

    if (name.empty() || soundMap_.find(name) != soundMap_.end())
        throw std::invalid_argument("name is illegal. | RaylibAudio::registerSFX");

    soundMap_[name] = ISoundPool{ std::vector<std::unique_ptr<ISound>>(poolSize), 0 };

    for (uint8_t i = 0; i < poolSize; ++i)
        soundMap_[name].sounds_[i] = std::make_unique<RaylibSound>(getSoundToken(), *this, filePath);

}

void RaylibAudio::unregisterSFX(const std::string& name)
{
    auto it = soundMap_.find(name);
    if (it != soundMap_.end())
    {
        for (auto& sound : it->second.sounds_)
        {
            if (sound->isPlaying())
                sound->stop();
        }

        soundMap_.erase(name);
    }
}

void RaylibAudio::playSFX(const std::string& name)
{
    auto it = soundMap_.find(name);
    if (it != soundMap_.end())
    {
        it->second.sounds_[it->second.currentSoundIndex_]->play();
        it->second.currentSoundIndex_ = (it->second.currentSoundIndex_ + 1) % it->second.sounds_.size();
    }
}

void RaylibAudio::stopSFX(const std::string& name)
{
    auto it = soundMap_.find(name);
    if (it != soundMap_.end())
    {
        for (auto& sound : it->second.sounds_)
        {
            if (sound->isPlaying())
                sound->stop();
        }
    }
}