#pragma once

#include "GameStateMenu.h"
#include "GameStateMatch.h"
#include <stdexcept>
#include <vector>

class GameManager
{
public:
    GameManager(RendererBase& renderer,
        std::unique_ptr<HandleInputBase> handleInput,
        std::unique_ptr<Archive> archive,
        float maxClickTime = 0.5f,
        float maxMoveDistance = 5.0f,
        float minLongPressTime = 1.0f
    );

    ~GameManager() = default;
public:
    void init(std::string state);
    GameStateContext& getContext() { return context_; }
    void registerState(std::string state, GameStateManager::Creator creator);

    void update(float delta);
    void render();
protected:
    GameStateContext context_;
    bool isQuit_ = false;
};