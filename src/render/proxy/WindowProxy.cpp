#include "WindowProxy.h"

void WindowProxy::windowInit(int width, int height, const std::string& str)
{
    renderer_.windowInit(width, height, str);
}

void WindowProxy::windowClose()
{
    renderer_.windowClose();
}

bool WindowProxy::windowExists()
{
    return renderer_.windowExists();
}




void WindowProxy::FPSset(int fps)
{
    renderer_.FPSset(fps);
}

void WindowProxy::FPSDelay()
{
    renderer_.FPSDelay();
}

int WindowProxy::FPSget()
{
    return renderer_.FPSget();
}

int WindowProxy::FPSsetValueGet()
{
    return renderer_.FPSsetValueGet();
}

float WindowProxy::FPSgetFrameTime()
{
    return renderer_.FPSgetFrameTime();
}




void WindowProxy::drawingBegin()
{
    renderer_.drawingBegin();
}

void WindowProxy::drawingEnd()
{
    renderer_.drawingEnd();
}




void WindowProxy::clearBackground(const Base::Color& color)
{
    renderer_.clearBackground(color);
}
