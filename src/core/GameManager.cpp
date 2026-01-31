#include "GameManager.h"

GameManager::GameManager(GameStateContext&& context) noexcept
    : context_(std::move(context))
{ }

void GameManager::init(std::string state)
{
    context_.stateManager.pushState(state);
}

void GameManager::registerState(std::string state, GameStateManager::Creator creator)
{
    context_.stateManager.registerState(state, creator);
}




void GameManager::update(float delta)
{
    // update input io
    context_.handleInput.update(delta);

    // update game state
    if (!context_.stateManager.stateStack_.empty())
        context_.stateManager.stateStack_.back()->update(delta);

    // update audio
    context_.audio.update();

    // tasks queue
    std::queue<std::function<void()>>& tasks = context_.stateManager.tasksQueue_;
    while (tasks.size())
    {
        tasks.front()();
        tasks.pop();
    }
}

void GameManager::render()
{
    for (GameStateManager::stateType& state : context_.stateManager.stateStack_)
        state->render();
}