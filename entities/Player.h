//
// Created by vtimofeev on 13/08/16.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include <SFML/Window/Event.hpp>
#include "../commands/CommandQueue.h"
#include "Aircraft.h"

class Player {
public:
    void handleEvent(const sf::Event& event, CommandQueue& commands);
    void handleRealtimeInput(CommandQueue& commands);
};


struct AircraftMover
{
    AircraftMover(float vx, float vy) : velocity(vx, vy) {}

    void operator() (Aircraft& aircraft, sf::Time) const {
        aircraft.setVelocity(velocity);
    }
    sf::Vector2f velocity;
};

#endif //GAME_PLAYER_H
