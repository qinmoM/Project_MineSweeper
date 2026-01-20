#pragma once

#include "GameStateBase.h"
#include <stdexcept>
#include <vector>

class GameStateManager
{
public:
    using stateType = std::unique_ptr<GameStateBase>;
    using Creator = std::function<stateType()>;
public:
    void registerState(std::string stateName, Creator creator);
    void unregisterState(std::string stateName);

    void pushState(std::string newState);
    void popState();
protected:
    std::vector<stateType> stateStack_;
    std::unordered_map<std::string, Creator> registerCreators_;
    friend class GameManager;
};