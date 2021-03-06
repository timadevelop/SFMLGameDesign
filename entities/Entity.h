//
// Created by vtimofeev on 08/08/16.
//

#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H


#include <SFML/System.hpp>
#include "../nodes/SceneNode.h"

class Entity : public SceneNode {
public:
    virtual void updateCurrent(sf::Time dt);
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float vx, float vy);
    sf::Vector2f getVelocity() const;
    void accelerate(sf::Vector2f velocity);
    void accelerate(float vx, float vy);

private:
    sf::Vector2f mVelocity;
};


#endif //GAME_ENTITY_H
