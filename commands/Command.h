//
// Created by vtimofeev on 13/08/16.
//

#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H


#include <functional>
#include <assert.h>
#include "SFML/System/Time.hpp"

// User commands

class SceneNode;

class Command {
public:
    Command(){};
    std::function<void(SceneNode&, sf::Time)> action;
    unsigned int category;
};


// converting commands to entity action
template <typename GameObject, typename Function>
std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn)
{
    return [=] (SceneNode& node, sf::Time dt)
    {
        // check safe cast
        assert(dynamic_cast<GameObject*>(&node) != nullptr);

        // downcast Node and invoking function on it
        fn(static_cast<GameObject&>(node), dt);
    };
};

#endif //GAME_COMMAND_H
