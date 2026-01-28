#include "FontRaylib.h"

FontRaylib::FontRaylib(RendererBase::FontToken, RendererRaylib& renderer, const std::string& path, int size)
{
    font_ = LoadFontEx(path.c_str(), size, NULL, 0);
    if (0 == font_.baseSize)
        throw std::runtime_error("Failed to load font : " + path + " | FontRaylib::FontRaylib\n");
}

FontRaylib::~FontRaylib()
{
    UnloadFont(font_);
}