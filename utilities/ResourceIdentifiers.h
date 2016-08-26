//
// Created by vtimofeev on 25/08/16.
//

#ifndef GAME_RESOURCEIDENTIFIERS_H
#define GAME_RESOURCEIDENTIFIERS_H

#include "ResourceHolder.hpp"
// Forward declaration of SFML classes
namespace sf
{
    class Texture;
    class Font;
}

namespace Textures
{
    enum ID
    {
        Eagle,
        Raptor,
        Desert,
        TitleScreen,
    };
}

namespace Fonts
{
    enum ID
    {
        Main,
    };
}

//// Forward declaration and a few type definitions
//template <typename Resource, typename Identifier>
//class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID>	TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>			FontHolder;

#endif //GAME_RESOURCEIDENTIFIERS_H
