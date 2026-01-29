#pragma once

#include "GameStateManager.h"
#include "ButtonImage.h"
#include "FontBase.h"
#include "GridView.h"

class GameStateMatch : public GameStateBase
{
public:
    virtual void enter() override;
    virtual void exit() override;

    virtual void update(float delta) override;
    virtual void render() override;
public:
    GameStateMatch(GameStateContext& context);
    virtual ~GameStateMatch() = default;
protected:
    std::unique_ptr<GridView> gridView_;
    std::vector<std::shared_ptr<FontBase>> font_;
    Base::Point pos_;
    Base::Point size_;
private:
    float fontSize() const;
    int mineCount() const;
    Base::Color fontColor(int num) const;
};