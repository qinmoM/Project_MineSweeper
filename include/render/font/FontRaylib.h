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
    Base::Point getBoundaries(const std::string& text, float size, int spacing) const override;
public:
    FontRaylib(RendererBase::FontToken, RendererRaylib& renderer, const std::string& path, int size);
    ~FontRaylib();
    Font font_;
};