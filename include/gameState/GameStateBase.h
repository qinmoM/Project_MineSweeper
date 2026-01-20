#pragma once

#include "RendererProxy.h"
#include "HandleInputSemantic.h"
#include <memory>

class GameStateManager;

class GameStateBase
{
public:
    virtual void enter() = 0;
    virtual void exit() = 0;

    virtual void update(float delta) = 0;
    virtual void render() = 0;
public:
    GameStateBase(std::shared_ptr<RendererProxy> renderer, std::shared_ptr<HandleInputSemantic> handleInput, std::shared_ptr<GameStateManager> gameStateManager)
        : renderer_(renderer)
        , handleInput_(handleInput)
        , stateManager_(gameStateManager)
    { }
    virtual ~GameStateBase() = default;
protected:
    std::shared_ptr<RendererProxy> renderer_;
    std::shared_ptr<HandleInputSemantic> handleInput_;
    std::shared_ptr<GameStateManager> stateManager_;
};