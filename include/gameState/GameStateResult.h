#pragma once

#include "GameStateManager.h"
#include "ButtonText.h"

class GameStateResult : public GameStateBase
{
public:
    virtual void enter() override;
    virtual void exit() override;

    virtual void update(float delta) override;
    virtual void render() override;
public:
    GameStateResult(GameStateContext& context);
    virtual ~GameStateResult() = default;
private:
    bool isGameWin_;
};