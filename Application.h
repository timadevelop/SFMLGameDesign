//
// Created by vtimofeev on 25/08/16.
//

#ifndef GAME_APPLICATION_H
#define GAME_APPLICATION_H

#include "utilities/ResourceHolder.hpp"
#include "utilities/ResourceIdentifiers.h"
#include <entities/Player.h>
#include "states/StateStack.h"


#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Application {
public:
    Application();
    void run();


private:
    void processInput();
    void update(sf::Time dt);
    void render();

    void updateStatistics(sf::Time dt);
    void registerStates();


private:
    static const sf::Time	TimePerFrame;

    sf::RenderWindow mWindow;
    TextureHolder mTextures;
    FontHolder mFonts;
    Player mPlayer;

    StateStack mStateStack;

    sf::Text mStatisticsText;
    sf::Time mStatisticsUpdateTime;
    std::size_t mStatisticsNumFrames;
};


#endif //GAME_APPLICATION_H
