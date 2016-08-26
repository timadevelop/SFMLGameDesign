//
// Created by vtimofeev on 25/08/16.
//

#ifndef GAME_UTILITY_H
#define GAME_UTILITY_H

#include <sstream>

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"


#include <cmath>

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.

template <typename T>
std::string toString(const T& value);

inline void centerOrigin(sf::Sprite& sprite);
inline void centerOrigin(sf::Text& text);

#include "Utility.inl"

#endif //GAME_UTILITY_H
