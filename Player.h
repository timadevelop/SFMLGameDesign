//
// Created by vtimofeev on 13/08/16.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include <SFML/Window/Event.hpp>
#include "CommandQueue.h"

class Player {
public:
    void handleEvent(const sf::Event& event, CommandQueue& commands);
    void handleRealtimeInput(CommandQueue& commands);
};


#endif //GAME_PLAYER_H
