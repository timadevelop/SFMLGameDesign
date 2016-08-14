//
// Created by vtimofeev on 11/08/16.
//

#ifndef GAME_SPRITENODE_H
#define GAME_SPRITENODE_H


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "SceneNode.h"

class SpriteNode : public SceneNode {
public:
    explicit SpriteNode(const sf::Texture& texture);
    SpriteNode(const sf::Texture& texture, const sf::IntRect& rect);

private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::Sprite mSprite;
};


#endif //GAME_SPRITENODE_H
