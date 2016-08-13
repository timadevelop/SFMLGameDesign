#include "Game.h"
#include "StringHelpers.hpp"
#include "Aircraft.h"

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "App")
, mWorld(mWindow)
{
	mWindow.setVerticalSyncEnabled(true); // avoid graphical artifacts
	mWindow.setFramerateLimit(60);
	fontHolder.load("statisctics font", "Media/Fonts/Sansation.ttf");


	mStatisticsText.setFont(fontHolder.get("statisctics font"));
	mStatisticsText.setColor(sf::Color::White);
	mStatisticsText.setPosition(10.f, 10.f);
	mStatisticsText.setCharacterSize(12);
}

void Game::run()
{
	// Time dependent update & render
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		updateStatistics(timeSinceLastUpdate);

		while (timeSinceLastUpdate > FRAMERATE_LIMIT_IN_SECONDS) // if it`s time for new frame
		{
			timeSinceLastUpdate -= FRAMERATE_LIMIT_IN_SECONDS;
			processInput(); // but we`re still catch user input
			if(!mIsPaused)
				update(FRAMERATE_LIMIT_IN_SECONDS); // eventually @skipping@ some frames if there are 1+ loops
		}
		
		updateStatistics(elapsedTime);
		render();
	}
}

void Game::processInput() {
	CommandQueue& commands = mWorld.getCommandQueue();

	sf::Event event;
	while(mWindow.pollEvent(event))
	{
		//mPlayer.handleEvent(event, commands);

		if(event.type == sf::Event::Closed)
			mWindow.close();
		else if(event.type == sf::Event::GainedFocus)
			mIsPaused = false;
		else if(event.type == sf::Event::LostFocus)
			mIsPaused = true;
	}

	//mPlayer.handleRealtimeInput(commands);

}

void Game::update(sf::Time deltaTime)
{
	mWorld.update(deltaTime);
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

void Game::render()
{
	mWindow.clear();
	mWorld.draw();

	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
	mWindow.display();
}