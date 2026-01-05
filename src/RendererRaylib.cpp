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



void RendererRaylib::drawingBegin()
{
    BeginDrawing();
}

void RendererRaylib::drawingEnd()
{
    EndDrawing();
}



void RendererRaylib::clearBackground(const Base::ColorBase& color)
{
    ClearBackground({color.r, color.g, color.b, color.a});
}



void RendererRaylib::drawLine(int startX, int startY, int endX, int endY, int thick, const Base::ColorBase& color)
{
    DrawLineEx({static_cast<float>(startX), static_cast<float>(startY)}, {static_cast<float>(endX), static_cast<float>(endY)}, thick, {color.r, color.g, color.b, color.a});
}

void RendererRaylib::drawLineAngle(int startX, int startY, float angle, float length, int thick, const Base::ColorBase& color)
{
    float endX = startX + length * cos(angle * PI / 180.0f);
	float endY = startY + length * sin(angle * PI / 180.0f);
	DrawLineEx({static_cast<float>(startX), static_cast<float>(startY)}, {endX, endY}, thick, {color.r, color.g, color.b, color.a});
}

void RendererRaylib::drawRectangle(int posX, int posY, int width, int height, int thick, const Base::ColorBase& color)
{
    DrawRectangleLinesEx({static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(width), static_cast<float>(height)}, static_cast<float>(thick), {color.r, color.g, color.b, color.a});
}

void RendererRaylib::drawRectangleRound(int posX, int posY, int width, int height, float roundness, int segments, int thick, const Base::ColorBase& color)
{
    DrawRectangleRoundedLinesEx({static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(width), static_cast<float>(height)}, roundness, segments, thick, {color.r, color.g, color.b, color.a});
}

void RendererRaylib::drawCircle(int posX, int posY, float innerRadius, float outerRadius, const Base::ColorBase& color)
{
    DrawRing({static_cast<float>(posX), static_cast<float>(posY)}, innerRadius, outerRadius, 0.0f, 360.0f, static_cast<int>(outerRadius * 0.4f) + 4, {color.r, color.g, color.b, color.a});
}



void RendererRaylib::drawRectangleFill(int posX, int posY, int width, int height, const Base::ColorBase& color)
{
    DrawRectangle(posX, posY, width, height, {color.r, color.g, color.b, color.a});
}

void RendererRaylib::drawRectangleRoundFill(int posX, int posY, int width, int height, float roundness, int segments, const Base::ColorBase& color)
{
    DrawRectangleRounded({static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(width), static_cast<float>(height)}, roundness, segments, {color.r, color.g, color.b, color.a});
}

void RendererRaylib::drawCircleFill(int posX, int posY, float radius, const Base::ColorBase& color)
{
    DrawCircle(posX, posY, radius, {color.r, color.g, color.b, color.a});
}
