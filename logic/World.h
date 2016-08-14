//
// Created by vtimofeev on 11/08/16.
//

#ifndef GAME_WORLD_H
#define GAME_WORLD_H


#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../utilities/ResourceHolder.hpp"
#include "../nodes/SceneNode.h"
#include "../nodes/SpriteNode.h"
#include "../entities/Aircraft.h"
#include "../commands/CommandQueue.h"

class World : sf::NonCopyable{
public:
    explicit World(sf::RenderWindow& window);
    void update(sf::Time dt);
    void draw();

public:
    CommandQueue& getCommandQueue();
private:
    void loadTextures();
    void buildScene();

private:
    enum Layer // not class because we need LayerCount integer
    {
        Background, Air, LayerCount
    };

private:
    sf::RenderWindow& mWindow;
    sf::View mWorldView;
    ResourceHolder<sf::Texture, Textures::ID> mTextures;
    SceneNode mSceneGraph;
    std::array<SceneNode*, Layer::LayerCount> mSceneLayers;

    CommandQueue mCommandQueue;

    sf::FloatRect mWorldBounds;
    sf::Vector2f mSpawnPosition;
    float mScrollSpeed;
    Aircraft* mPlayerAircraft;
};


#endif //GAME_WORLD_H
