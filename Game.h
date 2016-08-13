#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"
#include "World.h"
#include "Player.h"

class Game
{
public:
	Game();
	void run();

private:
	void processInput();
	void update(sf::Time deltaTime);
	void updateStatistics(sf::Time elapsedTime);
	void render();

private:
	const float FRAMERATE_LIMIT = 60.f;
	const sf::Time FRAMERATE_LIMIT_IN_SECONDS = sf::seconds(1.f / FRAMERATE_LIMIT);
	bool mIsPaused = false;
	ResourceHolder<sf::Font, std::string> fontHolder;

private:
	sf::RenderWindow mWindow;
	World mWorld;
//	Player mPlayer;
	sf::Text mStatisticsText;
	sf::Time mStatisticsUpdateTime;
	std::size_t mStatisticsNumFrames = 0;
};

#endif