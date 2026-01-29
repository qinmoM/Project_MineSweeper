#pragma once

#include "GameStateMenu.h"
#include "GameStateMatch.h"
#include "GameStateResult.h"
#include <stdexcept>
#include <vector>

class GameManager
{
public:
    GameManager(GameStateContext&& context) noexcept;

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