#include "TextureRaylib.h"

TextureRaylib::TextureRaylib(RendererBase::TextureToken, RendererRaylib& renderer, const std::string& path)
{
    texture_ = LoadTexture(path.c_str());
    if (0 == texture_.id)
        throw std::runtime_error("Failed to load texture : " + path + " | TextureRaylib::TextureRaylib.\n");
}

TextureRaylib::~TextureRaylib()
{
    UnloadTexture(texture_);
}