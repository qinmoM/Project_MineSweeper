#include "Game.h"

void Game::run()
{
    std::unique_ptr<Archive> archive = std::make_unique<Archive>();
    archive->registerSerializer("Json", std::make_unique<JsonSerialization>());

    GlobalConfig globalConfig;
    archive->deserialize("Json", "../data/global.json", globalConfig);

    WindowProxy window(RendererRaylib::getInstance());
    window.windowInit(globalConfig.width_, globalConfig.height_, globalConfig.title_);
    window.FPSset(globalConfig.fps_);

    GameManager gameManager(
        RendererRaylib::getInstance(),
        std::make_unique<HandleInputRaylib>(
            MouseRaylib::getInstance(),
            KeyboardRaylib::getInstance()
        ),
        std::move(archive),
        globalConfig.maxClickTime_,
        globalConfig.maxMoveDistance_,
        globalConfig.minLongPressTime_
    );
    gameManager.registerState("Menu", [&gameManager]() -> GameStateManager::stateType { return std::make_unique<GameStateMenu>(gameManager.getContext()); });
    gameManager.init("Menu");

    while (window.windowExists())
    {
        window.drawingBegin();
        window.clearBackground(Base::Color{230, 230, 230, 0});

        gameManager.update(window.FPSgetFrameTime());
        gameManager.render();

        window.drawingEnd();
        window.FPSDelay();
    }

    window.windowClose();
    gameManager.getContext().archive->serialize("Json", "../data/global.json", globalConfig);
    gameManager.getContext().archive->flushAll();
}