#include "FontRaylib.h"

FontRaylib::FontRaylib(RendererBase::FontToken, RendererRaylib& renderer, const std::string& path)
{
    font_ = LoadFont(path.c_str());
    if (0 == font_.baseSize)
        throw std::runtime_error("Failed to load font : " + path + " | FontRaylib::FontRaylib\n");
}