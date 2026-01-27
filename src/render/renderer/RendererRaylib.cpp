#include "RendererRaylib.h"

RendererBase& RendererRaylib::getInstance()
{
    static RendererRaylib instance;
    return instance;
}



void RendererRaylib::windowInit(int width, int height, const std::string& str)
{
    InitWindow(width, height, str.c_str());
}

void RendererRaylib::windowClose()
{
    CloseWindow();
}

bool RendererRaylib::windowExists()
{
    return !WindowShouldClose();
}

bool RendererRaylib::windowFocused()
{
    return IsWindowFocused();
}



int RendererRaylib::getWidth() const
{
    return GetScreenWidth();
}

int RendererRaylib::getHeight() const
{
    return GetScreenHeight();
}



void RendererRaylib::FPSset(int fps)
{
    SetTargetFPS(FPSmax_ = fps);
}

void RendererRaylib::FPSDelay()
{
    // drawingEnd() function will wait automatically.
}

int RendererRaylib::FPSget()
{
    return GetFPS();
}

int RendererRaylib::FPSsetValueGet()
{
    return FPSmax_;
}

float RendererRaylib::FPSgetFrameTime()
{
    return GetFrameTime();
}



void RendererRaylib::drawingBegin()
{
    BeginDrawing();
}

void RendererRaylib::drawingEnd()
{
    EndDrawing();
}



void RendererRaylib::clearBackground(const Base::Color& color)
{
    ClearBackground({color.r, color.g, color.b, color.a});
}



void RendererRaylib::drawLine(int startX, int startY, int endX, int endY, int thick, const Base::Color& color)
{
    DrawLineEx({static_cast<float>(startX), static_cast<float>(startY)}, {static_cast<float>(endX), static_cast<float>(endY)}, thick, {color.r, color.g, color.b, color.a});
}

void RendererRaylib::drawLineAngle(int startX, int startY, float angle, float length, int thick, const Base::Color& color)
{
    float endX = startX + length * cos(angle * PI / 180.0f);
	float endY = startY + length * sin(angle * PI / 180.0f);
	DrawLineEx({static_cast<float>(startX), static_cast<float>(startY)}, {endX, endY}, thick, {color.r, color.g, color.b, color.a});
}

void RendererRaylib::drawRectangle(int posX, int posY, int width, int height, int thick, const Base::Color& color)
{
    DrawRectangleLinesEx({static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(width), static_cast<float>(height)}, static_cast<float>(thick), {color.r, color.g, color.b, color.a});
}

void RendererRaylib::drawRectangleRound(int posX, int posY, int width, int height, float roundness, int thick, const Base::Color& color)
{
    DrawRectangleRoundedLinesEx({static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(width), static_cast<float>(height)}, roundness, static_cast<int>(0.4f * roundness * std::min(posX, posY)), thick, {color.r, color.g, color.b, color.a});
}

void RendererRaylib::drawCircle(int posX, int posY, float innerRadius, float outerRadius, const Base::Color& color)
{
    DrawRing({static_cast<float>(posX), static_cast<float>(posY)}, innerRadius, outerRadius, 0.0f, 360.0f, static_cast<int>(outerRadius * 0.4f) + 4, {color.r, color.g, color.b, color.a});
}



void RendererRaylib::drawRectangleFill(int posX, int posY, int width, int height, const Base::Color& color)
{
    DrawRectangle(posX, posY, width, height, {color.r, color.g, color.b, color.a});
}

void RendererRaylib::drawRectangleRoundFill(int posX, int posY, int width, int height, float roundness, const Base::Color& color)
{
    DrawRectangleRounded({static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(width), static_cast<float>(height)}, roundness, static_cast<int>(0.4f * roundness * std::min(posX, posY)), {color.r, color.g, color.b, color.a});
}

void RendererRaylib::drawCircleFill(int posX, int posY, float radius, const Base::Color& color)
{
    DrawCircle(posX, posY, radius, {color.r, color.g, color.b, color.a});
}




std::shared_ptr<TextureBase> RendererRaylib::loadTexture(const std::string& path)
{
    return std::make_shared<TextureRaylib>(getTextureToken(), *this, path);
}

void RendererRaylib::drawTexture(int posX, int posY, float scaleX, float scaleY, const std::shared_ptr<TextureBase>& texture, const Base::Color& color)
{
    Texture2D tex = static_cast<TextureRaylib*>(texture.get())->texture_;
    Rectangle origin = {0.0f, 0.0f, static_cast<float>(tex.width), static_cast<float>(tex.height)};
    Rectangle next = {0.0f, 0.0f, origin.width * scaleX, origin.height * scaleY};
    DrawTexturePro(
        tex,
        origin,
        next,
        {0.0f, 0.0f},
        0.0f,
        {color.r, color.g, color.b, color.a}
    );
}

void RendererRaylib::drawSprite(const Sprite& sprite)
{
    Texture2D tex = static_cast<TextureRaylib*>(sprite.getTexture().get())->texture_;
    Rectangle origin = { 0.0f, 0.0f, static_cast<float>(tex.width), static_cast<float>(tex.height) };
    Base::Point scale = sprite.getScale();
    Base::Point pos = sprite.getPosition();
    Base::Point originPoint = sprite.getOrigin();
    originPoint.x *= scale.x;
    originPoint.y *= scale.y;
    Rectangle next = { pos.x, pos.y, origin.width * scale.x, origin.height * scale.y };
    Base::Color color = sprite.getColor();
    DrawTexturePro(
        tex,
        origin,
        next,
        { originPoint.x, originPoint.y },
        sprite.getRotation(),
        { color.r, color.g, color.b, color.a }
    );
}





std::shared_ptr<FontBase> RendererRaylib::loadFont(const std::string& path)
{
    return std::make_shared<FontRaylib>(getFontToken(), *this, path);
}

void RendererRaylib::drawFont(int posX, int posY, int size, const std::string& text, const std::shared_ptr<FontBase>& font, const Base::Color& color)
{
    DrawText(text.c_str(), posX, posY, size, {color.r, color.g, color.b, color.a});
}

void RendererRaylib::drawText(const Text& text)
{
    ;
}
