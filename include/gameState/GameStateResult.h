#pragma once

#include "GameStateManager.h"
#include "ButtonImage.h"

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
    std::vector<std::shared_ptr<FontBase>> fonts_;
    bool isGameWin_;
    int width_;
    int height_;
};