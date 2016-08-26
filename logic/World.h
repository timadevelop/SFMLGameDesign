//
// Created by vtimofeev on 11/08/16.
//

#ifndef GAME_WORLD_H
#define GAME_WORLD_H


#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>
#include <queue>

#include "../utilities/ResourceHolder.hpp"
#include "../utilities/ResourceIdentifiers.h"
#include "../nodes/SceneNode.h"
#include "../nodes/SpriteNode.h"
#include "../entities/Aircraft.h"
#include "../commands/CommandQueue.h"
#include "../commands/Command.h"



// Forward declaration
namespace sf
{
    class RenderWindow;
}

class World : private sf::NonCopyable
{
public:
    explicit							World(sf::RenderWindow& window);
    void								update(sf::Time dt);
    void								draw();

    CommandQueue&						getCommandQueue();


private:
    void								loadTextures();
    void								buildScene();
    void								adaptPlayerPosition();
    void								adaptPlayerVelocity();


private:
    enum Layer
    {
        Background,
        Air,
        LayerCount
    };


private:
    sf::RenderWindow&					mWindow;
    sf::View							mWorldView;
    TextureHolder						mTextures;

    SceneNode							mSceneGraph;
    std::array<SceneNode*, LayerCount>	mSceneLayers;
    CommandQueue						mCommandQueue;

    sf::FloatRect						mWorldBounds;
    sf::Vector2f						mSpawnPosition;
    float								mScrollSpeed;
    Aircraft*							mPlayerAircraft;
};

#endif //GAME_WORLD_H
