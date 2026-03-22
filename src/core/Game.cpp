#include "Game.h"

void Game::run()
{
    renderer_ = std::make_unique<RendererProxy>(RendererRaylib::getInstance());
    window_ = std::make_unique<WindowProxy>(RendererRaylib::getInstance());
    stateManager_ = std::make_unique<GameStateManager>();
    archive_ = std::make_unique<Archive>();
    configSystem_ = std::make_unique<ConfigSystem>("../");
    blackboard_ = std::make_unique<Blackboard>();

    archive_->registerSerializer("Json", std::make_unique<JsonSerialization>());

    archive_->deserialize("Json", configSystem_->execPath() + "data/global.json", configSystem_->globalConfig());
    archive_->deserialize("Json", configSystem_->execPath() + "data/setting.json", configSystem_->gameSetting());

    handleInput_ = std::make_unique<HandleInputSemantic>(
        std::make_unique<HandleInputRaylib>(
            MouseRaylib::getInstance(),
            KeyboardRaylib::getInstance()
        ),
        configSystem_->globalConfig().maxClickTime_,
        configSystem_->globalConfig().maxMoveDistance_,
        configSystem_->globalConfig().minLongPressTime_
    );

    window_->windowInit(configSystem_->globalConfig().width_, configSystem_->globalConfig().height_, configSystem_->globalConfig().title_);
    window_->FPSset(configSystem_->globalConfig().fps_);

    GameManager gameManager(GameStateContext{
        *renderer_,
        *handleInput_,
        RaylibAudio::getInstance(),
        *stateManager_,
        *archive_,
        *configSystem_,
        *blackboard_
    });
    gameManager.registerState("Menu", [&gameManager]() -> GameStateManager::stateType { return std::make_unique<GameStateMenu>(gameManager.getContext(), "Menu"); });
    gameManager.registerState("Match", [&gameManager]() -> GameStateManager::stateType { return std::make_unique<GameStateMatch>(gameManager.getContext(), "Match"); });
    gameManager.registerState("Result", [&gameManager]() -> GameStateManager::stateType { return std::make_unique<GameStateResult>(gameManager.getContext(), "Result"); });
    gameManager.registerState("Setting", [&gameManager]() -> GameStateManager::stateType { return std::make_unique<GameStateSetting>(gameManager.getContext(), "Setting"); });
    gameManager.registerState("Help", [&gameManager]() -> GameStateManager::stateType { return std::make_unique<GameStateHelp>(gameManager.getContext(), "Help"); });
    gameManager.init("Menu");

    gameManager.getContext().audio.loadBGM(configSystem_->execPath() + "res/audio/music/840648__visidy__joyful-game-loop-kitty-yarn-play.wav");
    gameManager.getContext().audio.playBGM();
    gameManager.getContext().audio.registerSFX("Cell", configSystem_->execPath() + "res/audio/sound/844619__dioram__switch-3.wav", 1);
    gameManager.getContext().audio.registerSFX("Button", configSystem_->execPath() + "res/audio/sound/833601__subquire__aggressive-button-tap-ui-tap-hit.wav", 1);
    gameManager.getContext().audio.registerSFX("TextButton", configSystem_->execPath() + "res/audio/sound/844617__dioram__switch-1.wav", 1);

    while (window_->windowExists() && !gameManager.getContext().stateManager.shouldQuit())
    {
        window_->drawingBegin();
        window_->clearBackground(Base::Color{230, 230, 230, 0});

        gameManager.update(window_->FPSgetFrameTime());
        gameManager.render();

        window_->drawingEnd();
        window_->FPSDelay();
    }

    // clear blackboard
    gameManager.getContext().blackboard.clear();
    // close window
    window_->windowClose();
    gameManager.getContext().archive.serialize("Json", configSystem_->execPath() + "data/global.json", gameManager.getContext().configSystem.globalConfig());
    gameManager.getContext().archive.serialize("Json", configSystem_->execPath() + "data/setting.json", gameManager.getContext().configSystem.gameSetting());
    gameManager.getContext().archive.flushAll();
}