//
// Created by vtimofeev on 13/08/16.
//

#include <commands/Category.h>
#include <iostream>
#include "Player.h"


// functor for changing velocity of aircraft
struct AircraftMover
{
    AircraftMover(float vx, float vy) : velocity(vx, vy) {}

    void operator() (Aircraft& aircraft, sf::Time) const {
        aircraft.accelerate(velocity);
    }
    sf::Vector2f velocity;
};

Player::Player() {
    // initializing keys
    mkeyBinding[sf::Keyboard::Left] = Action::MoveLeft;
    mkeyBinding[sf::Keyboard::Right] = Action::MoveRight;
    mkeyBinding[sf::Keyboard::Up] = Action::MoveUp;
    mkeyBinding[sf::Keyboard::Down] = Action::MoveDown;

    initializeActions();

    // categories
    for(auto& pair : mActionBinding)
        pair.second.category = Category::PlayerAircraft;
}

void Player::initializeActions() {
    const float playerSpeed = 200.f;


    mActionBinding[Action::MoveLeft].action	 = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f));
    mActionBinding[Action::MoveRight].action = derivedAction<Aircraft>(AircraftMover(+playerSpeed, 0.f));
    mActionBinding[Action::MoveUp].action    = derivedAction<Aircraft>(AircraftMover(0.f, -playerSpeed));
    mActionBinding[Action::MoveDown].action  = derivedAction<Aircraft>(AircraftMover(0.f, +playerSpeed));

}


bool Player::isRealtimeAction(Action action) {
    switch(action)
    {
        case Action::MoveUp:
        case Action::MoveDown:
        case Action::MoveLeft:
        case Action::MoveRight:
            return true;
        default:
            return false;
    }
}



// *****************
//      Key bingings
// *****************
void Player::assignKey(Action action, sf::Keyboard::Key key) {
    for (auto itr = mkeyBinding.begin(); itr != mkeyBinding.end();)
    {
        if(itr->second == action)
            mkeyBinding.erase(itr++);
        else
            itr++;
    }
    // insert
    mkeyBinding[key] = action;
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const {
    for(auto pair : mkeyBinding)
    {
        if(pair.second == action)
            return pair.first;
    }

    return sf::Keyboard::Unknown;
}

// *****************
//      Handle input
// *****************

void Player::handleRealtimeInput(CommandQueue &commands) {
    for(auto pair : mkeyBinding)
    {
        if(sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
            commands.push(mActionBinding[pair.second]);
    }
}

void Player::handleEvent(const sf::Event &event, CommandQueue &commands) {
    if(event.type == sf::Event::KeyPressed)
    {
        // check if pressed key appears to key binding
        auto found = mkeyBinding.find(event.key.code);
        if(found != mkeyBinding.end() && !isRealtimeAction(found->second))
            commands.push(mActionBinding[found->second]);
    }
}