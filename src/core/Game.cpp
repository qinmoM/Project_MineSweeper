#include "Game.h"

void Game::run()
{
    WindowProxy window(RendererRaylib::getInstance());
    GameManager gameManager;
    window.windowInit(600, 700, "test");
    window.FPSset(60);

    while (window.windowExists())
    {
        window.drawingBegin();
        window.clearBackground(Base::ColorBase{255, 255, 255, 0});

        gameManager.update(window.FPSgetFrameTime());
        gameManager.render();

        window.drawingEnd();
        window.FPSDelay();
    }

    window.windowClose();
}