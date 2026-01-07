#include "Game.h"

void Game::run()
{
    WindowProxy window(RendererRaylib::getInstance());
    window.windowInit(1200, 1000, "test");
    window.FPSset(120);

    GameManager gameManager(RendererRaylib::getInstance());
    while (window.windowExists())
    {
        window.drawingBegin();
        window.clearBackground(Base::ColorBase{200, 200, 200, 0});

        gameManager.update(window.FPSgetFrameTime());
        gameManager.render();

        window.drawingEnd();
        window.FPSDelay();
    }

    window.windowClose();
}