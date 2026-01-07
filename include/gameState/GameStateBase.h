#pragma once

#include "RendererProxy.h"
#include <memory>

class GameStateBase
{
public:
    virtual void enter() = 0;
    virtual void exit() = 0;

    virtual void update(float delta) = 0;
    virtual void render() = 0;
public:
    GameStateBase(std::shared_ptr<RendererProxy> renderer) : renderer_(renderer) { }
    virtual ~GameStateBase() = default;
protected:
    std::shared_ptr<RendererProxy> renderer_;
};