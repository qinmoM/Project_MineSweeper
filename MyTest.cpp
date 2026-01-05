#include "RendererRaylib.h"

int main()
{
    RendererBase& renderer = RendererRaylib::getInstance();
    renderer.windowInit(600, 700, "test");

    while (renderer.windowExists())
    {
        renderer.drawingBegin();
        renderer.clearBackground(Base::ColorBase{255, 255, 255, 0});

        ;

        renderer.drawingEnd();
        renderer.FPSDelay();
    }

    renderer.windowClose();
    return 0;
}