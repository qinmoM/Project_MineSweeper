#include "TextureRaylib.h"

TextureRaylib::TextureRaylib(RendererBase::TextureToken, RendererRaylib& renderer, const std::string& path)
{
    texture_ = LoadTexture(path.c_str());
}