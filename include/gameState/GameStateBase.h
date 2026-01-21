#pragma once

#include "RendererProxy.h"
#include "HandleInputSemantic.h"
#include <memory>

class GameStateManager;

struct GameStateContext
{
    GameStateContext(std::shared_ptr<RendererProxy> renderer, std::shared_ptr<HandleInputSemantic> handleInput, std::shared_ptr<GameStateManager> stateManager)
        : renderer(renderer)
        , handleInput(handleInput)
        , stateManager(stateManager)
    { }

    std::shared_ptr<RendererProxy> renderer;
    std::shared_ptr<HandleInputSemantic> handleInput;
    std::shared_ptr<GameStateManager> stateManager;
};

class GameStateBase
{
public:
    virtual void enter() = 0;
    virtual void exit() = 0;

    virtual void update(float delta) = 0;
    virtual void render() = 0;
public:
    GameStateBase(GameStateContext context)
        : context_(context)
    { }
    virtual ~GameStateBase() = default;
protected:
    GameStateContext context_;
};