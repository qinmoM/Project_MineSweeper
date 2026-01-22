#include "GameManager.h"

GameManager::GameManager(RendererBase& renderer,
    std::shared_ptr<HandleInputBase> handleInput,
    float maxClickTime,
    float maxMoveDistance,
    float minLongPressTime)
    : context_(std::make_shared<RendererProxy>(renderer)
    , std::make_shared<HandleInputSemantic>(
        handleInput,
        maxClickTime,
        maxMoveDistance,
        minLongPressTime)
    , std::make_shared<GameStateManager>()
    )
{ }

void GameManager::init(std::string state)
{
    context_.stateManager->pushState(state);
}

void GameManager::registerState(std::string state, GameStateManager::Creator creator)
{
    context_.stateManager->registerState(state, creator);
}




void GameManager::update(float delta)
{
    // update input io
    context_.handleInput->update(delta);

    // update game state
    if (!context_.stateManager->stateStack_.empty())
        context_.stateManager->stateStack_.back()->update(delta);

    // tasks queue
    std::queue<std::function<void()>>& tasks = context_.stateManager->tasksQueue_;
    while (tasks.size())
    {
        tasks.front()();
        tasks.pop();
    }
}

void GameManager::render()
{
    for (GameStateManager::stateType& state : context_.stateManager->stateStack_)
        state->render();
}