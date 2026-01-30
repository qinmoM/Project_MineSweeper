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



std::shared_ptr<ISound> RaylibAudio::loadSound(const std::string& filePath)
{
    return std::make_shared<RaylibSound>(getSoundToken(), *this, filePath);
}

std::shared_ptr<IMusic> RaylibAudio::loadMusic(const std::string& filePath)
{
    return std::make_shared<RaylibMusic>(getMusicToken(), *this, filePath);
}