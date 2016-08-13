//
// Created by vtimofeev on 13/08/16.
//

#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H


#include <functional>
#include "SFML/System/Time.hpp"

// User commands

class SceneNode;

class Command {
public:
    Command();
    std::function<void(SceneNode&, sf::Time)> action;
    unsigned int category;
};


#endif //GAME_COMMAND_H
