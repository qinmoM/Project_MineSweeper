#include "RendererProxy.h"

int RendererProxy::FPSget()
{
    return renderer_.FPSget();
}

int RendererProxy::FPSsetValueGet()
{
    return renderer_.FPSsetValueGet();
}

void RendererProxy::clearBackground(const Base::ColorBase& color)
{
    renderer_.clearBackground(color);
}

void RendererProxy::drawLine(int startX, int startY, int endX, int endY, int thick, const Base::ColorBase& color)
{
    renderer_.drawLine(startX, startY, endX, endY, thick, color);
}

void RendererProxy::drawLineAngle(int startX, int startY, float angle, float length, int thick, const Base::ColorBase& color)
{
    renderer_.drawLineAngle(startX, startY, angle, length, thick, color);
}

void RendererProxy::drawRectangle(int posX, int posY, int width, int height, int thick, const Base::ColorBase& color)
{
    renderer_.drawRectangle(posX, posY, width, height, thick, color);
}

void RendererProxy::drawRectangleRound(int posX, int posY, int width, int height, float roundness, int thick, const Base::ColorBase& color)
{
    renderer_.drawRectangleRound(posX, posY, width, height, roundness, thick, color);
}

void RendererProxy::drawCircle(int posX, int posY, float innerRadius, float outerRadius, const Base::ColorBase& color)
{
    renderer_.drawCircle(posX, posY, innerRadius, outerRadius, color);
}


void RendererProxy::drawRectangleFill(int posX, int posY, int width, int height, const Base::ColorBase& color)
{
    renderer_.drawRectangleFill(posX, posY, width, height, color);
}

void RendererProxy::drawRectangleRoundFill(int posX, int posY, int width, int height, float roundness, const Base::ColorBase& color)
{
    renderer_.drawRectangleRoundFill(posX, posY, width, height, roundness, color);
}

void RendererProxy::drawCircleFill(int posX, int posY, float radius, const Base::ColorBase& color)
{
    renderer_.drawCircleFill(posX, posY, radius, color);
}
