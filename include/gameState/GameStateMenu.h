#pragma once

#include "GameStateManager.h"
#include "ButtonImage.h"
#include "ButtonText.h"

class GameStateMenu : public GameStateBase
{
public:
    virtual void enter() override;
    virtual void exit() override;

    virtual void update(float delta) override;
    virtual void render() override;
public:
    GameStateMenu(GameStateContext& context);
    virtual ~GameStateMenu() = default;
};