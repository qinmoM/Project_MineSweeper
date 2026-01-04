#include "RendererRaylib.h"

int main()
{
    RendererBase& renderer = RendererRaylib::getInstance();
    renderer.windowInit(600, 700, "test");
    while (renderer.windowExists())
    {
        renderer.drawingBegin();

        renderer.clearBackground(Base::ColorBase{255, 255, 255, 0});

        renderer.drawCircle(200, 200, 10, 20, Base::ColorBase{255, 0, 0, 255});
        renderer.drawCircleFill(300, 300, 10, Base::ColorBase{0, 255, 0, 255});
        renderer.drawLine(0, 0, 600, 700, 2, Base::ColorBase{0, 0, 255, 255});
        renderer.drawLineAngle(300, 300, 10, 100, 2, Base::ColorBase{0, 0, 0, 255});
        renderer.drawRectangle(100, 100, 200, 200, 4, Base::ColorBase{0, 255, 255, 255});
        renderer.drawRectangleFill(400, 300, 100, 100, Base::ColorBase{255, 0, 255, 255});
        renderer.drawRectangleRound(400, 0, 200, 200, 0.6f, 10, 4, Base::ColorBase{111, 111, 200, 255});
        renderer.drawRectangleRoundFill(0, 400, 100, 200, 0.3f, 2, Base::ColorBase{0, 0, 0, 255});

        renderer.drawingEnd();
    }
    renderer.windowClose();
    return 0;
}