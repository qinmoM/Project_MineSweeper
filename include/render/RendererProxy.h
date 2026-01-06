#pragma once

#include "RendererBase.h"

class RendererProxy
{
public:
    int FPSget();
    int FPSsetValueGet();

    void clearBackground(const Base::ColorBase& color);

    void drawLine(int startX, int startY, int endX, int endY, int thick, const Base::ColorBase& color);
    void drawLineAngle(int startX, int startY, float angle, float length, int thick, const Base::ColorBase& color);
    void drawRectangle(int posX, int posY, int width, int height, int thick, const Base::ColorBase& color);
    void drawRectangleRound(int posX, int posY, int width, int height, float roundness, int thick, const Base::ColorBase& color);
    void drawCircle(int posX, int posY, float innerRadius, float outerRadius, const Base::ColorBase& color);

    void drawRectangleFill(int posX, int posY, int width, int height, const Base::ColorBase& color);
    void drawRectangleRoundFill(int posX, int posY, int width, int height, float roundness, const Base::ColorBase& color);
    void drawCircleFill(int posX, int posY, float radius, const Base::ColorBase& color);
public:
    RendererProxy(RendererBase& renderer) : renderer_(renderer) { }
    ~RendererProxy() = default;
private:
    RendererBase& renderer_;
};