#pragma once

#include "RendererProxy.h"
#include "HandleInputSemantic.h"
#include "ButtonBase.h"
#include "Archive.h"
#include <memory>
#include <vector>

class GameStateManager;

struct GameStateContext
{
    GameStateContext(std::unique_ptr<RendererProxy> renderer, std::unique_ptr<HandleInputSemantic> handleInput, std::unique_ptr<GameStateManager> stateManager, std::unique_ptr<Archive> archive)
        : renderer(std::move(renderer))
        , handleInput(std::move(handleInput))
        , stateManager(std::move(stateManager))
        , archive(std::move(archive))
    { }

    std::unique_ptr<RendererProxy> renderer;
    std::unique_ptr<HandleInputSemantic> handleInput;
    std::unique_ptr<GameStateManager> stateManager;
    std::unique_ptr<Archive> archive;
};

class GameStateBase
{
public:
    virtual void enter() = 0;
    virtual void exit() = 0;

    virtual void update(float delta) = 0;
    virtual void render() = 0;
public:
    GameStateBase(GameStateContext& context)
        : context_(context)
    { }
    virtual ~GameStateBase() = default;
protected:
    GameStateContext& context_;
    std::vector<std::shared_ptr<ButtonBase>> button_;
};