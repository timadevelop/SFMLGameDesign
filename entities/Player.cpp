//
// Created by vtimofeev on 13/08/16.
//

#include <commands/Category.h>
#include <iostream>
#include "Player.h"

void Player::handleRealtimeInput(CommandQueue &commands) {
    const float  playerSpeed = 4.f;

    sf::Vector2f vel;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        vel.y -= playerSpeed;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        vel.y += playerSpeed;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        vel.x -= playerSpeed;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        vel.x += playerSpeed;

    Command move;
    move.category = Category::PlayerAircraft;
    move.action = derivedAction<Aircraft>(AircraftMover(vel.x, vel.y));
    commands.push(move);
}

void Player::handleEvent(const sf::Event &event, CommandQueue &commands) {
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
    {
        Command output;
        output.category = Category::PlayerAircraft;
        output.action = [] (SceneNode& s, sf::Time)
        {
            std::cout << s.getPosition().x << " " << s.getPosition().y << std::endl;
        };
        commands.push(output);
    }
}