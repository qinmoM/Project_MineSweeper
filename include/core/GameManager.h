#pragma once

#include "GameStateMenu.h"
#include <stdexcept>
#include <vector>

class GameManager
{
public:
    GameManager(RendererBase& renderer,
        std::shared_ptr<HandleInputBase> handleInput,
        float maxClickTime = 0.5f,
        float maxMoveDistance = 5.0f,
        float minLongPressTime = 1.0f);

    ~GameManager() = default;
public:
    void init(std::string state);
    GameStateContext& getContext() { return context_; }
    void registerState(std::string state, GameStateManager::Creator creator);

    void update(float delta);
    void render();
protected:
    GameStateContext context_;
};