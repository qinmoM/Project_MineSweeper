#include "FontRaylib.h"

Base::Point FontRaylib::getBoundaries(const std::string& text, float size, int spacing) const
{
    Vector2 vec = MeasureTextEx(font_, text.c_str(), size, static_cast<float>(spacing));
    return Base::Point(vec.x, vec.y);
}

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