#pragma once

#include "TextureBase.h"
#include "raylib.h"
#include "RendererBase.h"
#include <string>
#include <stdexcept>

class RendererRaylib;

class TextureRaylib final : public TextureBase
{
public:
    TextureRaylib(RendererBase::TextureToken, RendererRaylib& renderer, const std::string& path);
    ~TextureRaylib();
    Texture2D texture_;
};