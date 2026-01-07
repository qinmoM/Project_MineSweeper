#pragma once

#include "raylib.h"
#include "FontBase.h"
#include "RendererBase.h"
#include <string>
#include <stdexcept>

class RendererRaylib;

class FontRaylib final : public FontBase
{
public:
    FontRaylib(RendererBase::FontToken, RendererRaylib& renderer, const std::string& path);
    ~FontRaylib();
    Font font_;
};