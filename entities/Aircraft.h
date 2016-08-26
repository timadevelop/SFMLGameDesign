//
// Created by vtimofeev on 08/08/16.
//

#ifndef GAME_AIRCRAFT_H
#define GAME_AIRCRAFT_H


#include <SFML/Graphics.hpp>
#include <utilities/ResourceIdentifiers.h>
#include "Entity.h"
#include "../utilities/ResourceHolder.hpp"
class Aircraft : public Entity
{
public:
    typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
    enum class Type
    {
        Eagle,
        Raptor,
    };
    explicit Aircraft(Type type, const TextureHolder& textures);
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    unsigned int getCategory() const;

private:
    Type mType;
    sf::Sprite mSprite;
};

#endif //GAME_AIRCRAFT_H
