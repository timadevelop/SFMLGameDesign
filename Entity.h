//
// Created by vtimofeev on 08/08/16.
//

#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H


#include <SFML/System.hpp>

class Entity {
public:
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float vx, float vy);
    sf::Vector2f getVelocity() const;

private:
    sf::Vector2f mVelocity;
};


#endif //GAME_ENTITY_H
