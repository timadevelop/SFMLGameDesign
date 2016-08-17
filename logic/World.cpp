//
// Created by vtimofeev on 11/08/16.
//

#include "World.h"

World::World(sf::RenderWindow &window)
: mWindow(window)
  ,mSceneGraph()
, mWorldView(window.getDefaultView())
, mWorldBounds(
                0.f,                    // top X position
                0.f,                    // top Y position
                mWorldView.getSize().x, // width
                2000.f)                 // height
, mSpawnPosition(
                mWorldView.getSize().x / 2.f,
                mWorldBounds.height - mWorldView.getSize().y / 2.f)
, mScrollSpeed(-50.f) // negative because mooving upwards
, mPlayerAircraft(nullptr)
{
    loadTextures();
    buildScene();

    // setting Default view center
    mWorldView.setCenter(mSpawnPosition);
}

void World::loadTextures() {
    mTextures.load(Textures::ID::Eagle, "Media/Textures/Eagle.png");
    mTextures.load(Textures::ID::Raptor, "Media/Textures/Raptor.png");
    mTextures.load(Textures::ID::Desert, "Media/Textures/Desert.png");
}

void World::buildScene() {
    for (std::size_t i = 0; i < LayerCount; ++i)
    {
        SceneNode::sceneUptr layer(new SceneNode());
        mSceneLayers[i] = layer.get(); // .get() returns standart pointer without ownership

        mSceneGraph.attachChild(std::move(layer));
    }

    // tiled background
    sf::Texture& texture = mTextures.get(Textures::ID::Desert);
    sf::IntRect textureRect(mWorldBounds);
    texture.setRepeated(true);

    // add the background sprite to the scene
    std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
    backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
    mSceneLayers[Background]->attachChild(std::move(backgroundSprite)); // .get() base class

    // player initializing
    std::unique_ptr<Aircraft> leader(new Aircraft(Aircraft::Type::Eagle, mTextures));
    mPlayerAircraft = leader.get(); // no ownership
    mPlayerAircraft->setPosition(mSpawnPosition);
    mPlayerAircraft->setVelocity(0.f, 0.f);
    mSceneLayers[Air]->attachChild(std::move(leader));

    // escort
    std::unique_ptr<Aircraft> leftEscort(new Aircraft(Aircraft::Type::Raptor, mTextures));
    leftEscort->setPosition(-80.f, 50.f); // relative to leader
    mPlayerAircraft->attachChild(std::move(leftEscort));

    std::unique_ptr<Aircraft> rightEscort(new Aircraft(Aircraft::Type::Raptor, mTextures));
    rightEscort->setPosition(80.f, 50.f); // relative to leader
    mPlayerAircraft->attachChild(std::move(rightEscort));
}


void World::draw() {
    mWindow.setView(mWorldView);
    mWindow.draw(mSceneGraph);
}

void World::update(sf::Time dt) {
    mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());

    // Forward commands to scene graph
    while(!mCommandQueue.isEmpty())
        mSceneGraph.onCommand(mCommandQueue.pop(), dt);


    sf::Vector2f position = mPlayerAircraft->getPosition();
    sf::Vector2f velocity = mPlayerAircraft->getVelocity();

    if(position.x <= mWorldBounds.left + 150 || position.x >= mWorldBounds.left + mWorldBounds.width - 150)
    {
        // bad collision realisation

        velocity.x = -velocity.x;
        mPlayerAircraft->move(velocity * dt.asSeconds());
    }

    mSceneGraph.update(dt);
}

CommandQueue& World::getCommandQueue() {
    return mCommandQueue;
}