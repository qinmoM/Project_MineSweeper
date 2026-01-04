#pragma once

#include "Base.h"
#include <string>

class RendererBase
{
public:
    virtual void windowInit(int width, int height, const std::string& str) = 0;
    virtual void windowClose() = 0;
    virtual bool windowExists() = 0;

    virtual void drawingBegin() = 0;
    virtual void drawingFlush() = 0;
    virtual void drawingEnd() = 0;

    virtual void clearBackground(const Base::ColorBase& color) = 0;

    virtual void drawLine(int startX, int startY, int endX, int endY, int thick, const Base::ColorBase& color) = 0;
    virtual void drawRectangle(int posX, int posY, int width, int height, int thick, const Base::ColorBase& color) = 0;
    virtual void drawRectangleRound(int posX, int posY, int roundness, int segments, int thick, const Base::ColorBase& color) = 0;
    virtual void drawCircle(int posX, int posY, float radius, int thick, const Base::ColorBase& color) = 0;

    virtual void drawLineFill(int startX, int startY, int endX, int endY, const Base::ColorBase& color) = 0;
    virtual void drawRectangleFill(int posX, int posY, int width, int height, const Base::ColorBase& color) = 0;
    virtual void drawRectangleRoundFill(int posX, int posY, int roundness, int segments, const Base::ColorBase& color) = 0;
    virtual void drawCircleFill(int posX, int posY, float radius, const Base::ColorBase& color) = 0;
};