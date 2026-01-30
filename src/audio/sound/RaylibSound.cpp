#include "RaylibSound.h"

RaylibSound::RaylibSound(IAudioSystem::SoundToken, RaylibAudio& audioSystem, const std::string& filePath)
{
    sound_ = LoadSound(filePath.c_str());
    if (!IsSoundValid(sound_))
        throw std::runtime_error("Failed to load sound: " + filePath + ". | RaylibSound::RaylibSound");
}

RaylibSound::~RaylibSound()
{
    UnloadSound(sound_);
}



void RaylibSound::play()
{
    PlaySound(sound_);
}

void RaylibSound::stop()
{
    StopSound(sound_);
}

void RaylibSound::pause()
{
    PauseSound(sound_);
}

void RaylibSound::resume()
{
    ResumeSound(sound_);
}

bool RaylibSound::isPlaying()
{
    return IsSoundPlaying(sound_);
}



void RaylibSound::setVolume(float volume)
{
    SetSoundVolume(sound_, volume);
}

void RaylibSound::setPitch(float pitch)
{
    SetSoundPitch(sound_, pitch);
}

void RaylibSound::setPan(float pan)
{
    SetSoundPan(sound_, pan);
}
