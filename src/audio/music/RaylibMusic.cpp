#include "RaylibMusic.h"

RaylibMusic::RaylibMusic(IAudioSystem::MusicToken, RaylibAudio& audioSystem, const std::string& filename)
{
    music_ = LoadMusicStream(filename.c_str());
    if (!IsMusicValid(music_))
        throw std::runtime_error("Failed to load music stream:" + filename + ". | RaylibMusic::RaylibMusic");

    music_.looping = true;
}

RaylibMusic::~RaylibMusic()
{
    UnloadMusicStream(music_);
}



float RaylibMusic::getTimeLength()
{
    return GetMusicTimeLength(music_);
}

float RaylibMusic::getTimePlayed()
{
    return GetMusicTimePlayed(music_);
}



void RaylibMusic::update()
{
    UpdateMusicStream(music_);
}



void RaylibMusic::play()
{
    PlayMusicStream(music_);
}

void RaylibMusic::stop()
{
    StopMusicStream(music_);
}

void RaylibMusic::pause()
{
    PauseMusicStream(music_);
}

void RaylibMusic::resume()
{
    ResumeMusicStream(music_);
}

bool RaylibMusic::isPlaying()
{
    return IsMusicStreamPlaying(music_);
}



void RaylibMusic::setLoop(bool loop)
{
    music_.looping = loop;
}

void RaylibMusic::seek(float seconds)
{
    SeekMusicStream(music_, seconds);
}

void RaylibMusic::setVolume(float volume)
{
    if (volume < 0.0f || volume > 100.0f)
        throw std::invalid_argument("Volume must be between 0.0 and 100.0. | RaylibMusic::setVolume");

    SetMusicVolume(music_, volume * VOLUME_RATIO);
}

void RaylibMusic::setPitch(float pitch)
{
    SetMusicPitch(music_, pitch);
}

void RaylibMusic::setPan(float pan)
{
    SetMusicPan(music_, pan);
}
