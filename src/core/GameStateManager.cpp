#include "GameStateManager.h"

void GameStateManager::registerState(std::string stateName, Creator creator)
{
    if (creator && registerCreators_.find(stateName) == registerCreators_.end())
        registerCreators_[stateName] = creator;
}

void GameStateManager::unregisterState(std::string stateName)
{
    registerCreators_.erase(stateName);
}



void GameStateManager::pushState(std::string newState)
{
    if (registerCreators_.find(newState) == registerCreators_.end())
        throw std::invalid_argument("newState is not registered | GameStateManager::pushState");

    stateStack_.push_back(registerCreators_.at(newState)());
    stateStack_.back()->enter();
}

void GameStateManager::popState()
{
    if (!stateStack_.empty())
    {
        stateStack_.back()->exit();
        stateStack_.pop_back();
    }
}
