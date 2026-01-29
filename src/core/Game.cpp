#include "Game.h"

void Game::run()
{
    std::unique_ptr<Archive> archive = std::make_unique<Archive>();
    archive->registerSerializer("Json", std::make_unique<JsonSerialization>());

    std::unique_ptr<ConfigSystem> configSystem = std::make_unique<ConfigSystem>();
    archive->deserialize("Json", "../data/global.json", configSystem->globalConfig());
    archive->deserialize("Json", "../data/setting.json", configSystem->gameSetting());

    WindowProxy window(RendererRaylib::getInstance());
    window.windowInit(configSystem->globalConfig().width_, configSystem->globalConfig().height_, configSystem->globalConfig().title_);
    window.FPSset(configSystem->globalConfig().fps_);

    GameManager gameManager(
        RendererRaylib::getInstance(),
        std::make_unique<HandleInputRaylib>(
            MouseRaylib::getInstance(),
            KeyboardRaylib::getInstance()
        ),
        std::move(archive),
        std::move(configSystem),
        configSystem->globalConfig().maxClickTime_,
        configSystem->globalConfig().maxMoveDistance_,
        configSystem->globalConfig().minLongPressTime_
    );
    gameManager.registerState("Menu", [&gameManager]() -> GameStateManager::stateType { return std::make_unique<GameStateMenu>(gameManager.getContext()); });
    gameManager.registerState("Match", [&gameManager]() -> GameStateManager::stateType { return std::make_unique<GameStateMatch>(gameManager.getContext()); });
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
    gameManager.getContext().archive->serialize("Json", "../data/global.json", gameManager.getContext().configSystem->globalConfig());
    gameManager.getContext().archive->serialize("Json", "../data/setting.json", gameManager.getContext().configSystem->gameSetting());
    gameManager.getContext().archive->flushAll();
}