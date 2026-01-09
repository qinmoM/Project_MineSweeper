#pragma once

#include "RendererBase.h"

class WindowProxy final
{
public:
    void windowInit(int width, int height, const std::string& str);
    void windowClose();
    bool windowExists();
    bool windowFocused();

    void FPSset(int fps);
    void FPSDelay();
    int FPSget();
    int FPSsetValueGet();
    float FPSgetFrameTime();

    void drawingBegin();
    void drawingEnd();

    void clearBackground(const Base::Color& color);
public:
    WindowProxy(RendererBase& renderer) : renderer_(renderer) { }
    ~WindowProxy() = default;
private:
    RendererBase& renderer_;
};