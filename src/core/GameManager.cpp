#include "GameManager.h"

GameManager::GameManager(RendererBase& renderer) : rendererProxy_(std::make_shared<RendererProxy>(renderer))
{
    init();
}

void GameManager::init()
{
    std::unique_ptr<GameStateBase> newState = std::make_unique<GameStateMenu>(rendererProxy_);
    changeState(std::move(newState));
    currState_->enter();
}

void GameManager::changeState(std::unique_ptr<GameStateBase> newState)
{
    if (!newState)
        throw std::invalid_argument("newState is nullptr. | GameManager::changeState()\n");

    if (currState_)
        currState_->exit();
    
    currState_ = std::move(newState);
    currState_->enter();
}

void GameManager::update(float delta)
{
    if (currState_)
        currState_->update(delta);
}

void GameManager::render()
{
    if (currState_)
        currState_->render();
}