#include "GameManager.h"

GameManager::GameManager(RendererBase& renderer, std::shared_ptr<HandleInputBase> handleInput)
    : rendererProxy_(std::make_shared<RendererProxy>(renderer))
    , handleInput_(handleInput)
{
    init();
}

void GameManager::init()
{
    std::unique_ptr<GameStateBase> newState = std::make_unique<GameStateMenu>(rendererProxy_, handleInput_);
    pushState(std::move(newState));
    stateStack_.back()->enter();
}




void GameManager::pushState(std::unique_ptr<GameStateBase> newState)
{
    if (!newState)
        throw std::invalid_argument("newState is nullptr. | GameManager::changeState()\n");

    stateStack_.push_back(std::move(newState));
    stateStack_.back()->enter();
}

void GameManager::changeState(std::unique_ptr<GameStateBase> newState)
{
    if (!newState)
        throw std::invalid_argument("newState is nullptr. | GameManager::changeState()\n");

    if (!stateStack_.empty())
    {
        stateStack_.back()->exit();
        stateStack_.pop_back();
    }
    
    stateStack_.push_back(std::move(newState));
    stateStack_.back()->enter();
}




void GameManager::update(float delta)
{
    // update input io
    handleInput_->update();

    // update game state
    if (!stateStack_.empty())
        stateStack_.back()->update(delta);
}

void GameManager::render()
{
    for (std::unique_ptr<GameStateBase>& state : stateStack_)
        state->render();
}