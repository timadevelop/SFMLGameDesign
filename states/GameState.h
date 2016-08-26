//
// Created by vtimofeev on 25/08/16.
//

#ifndef GAME_GAMESTATE_H
#define GAME_GAMESTATE_H

#include "State.h"
#include "logic/World.h"
#include <entities/Player.h>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class GameState : public State{
public:
    GameState(StateStack& stack, State::Context context);
    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);


private:
    World mWorld;
    Player& mPlayer;
};


#endif //GAME_GAMESTATE_H
