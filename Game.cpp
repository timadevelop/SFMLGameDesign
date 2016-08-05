#include "Game.h"
#include "StringHelpers.hpp"

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "App")
	, mPlayer()
{
	mWindow.setVerticalSyncEnabled(true); // avoid graphical artifacts
	mWindow.setFramerateLimit(60);

	textureHolder.load(TexturesID::Airplane, "Media/Textures/Eagle.png");
	mPlayer.setTexture(textureHolder.get(TexturesID::Airplane));
	mPlayer.setPosition(100.f, 100.f);

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
			processEvents(); // but we`re still catch user input
			update(FRAMERATE_LIMIT_IN_SECONDS); // eventually @skipping@ some frames if there are 1+ loops
		}
		
		updateStatistics(elapsedTime);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
		movement.y -= 1.f;
	if (mIsMovingDown)
		movement.y += 1.f;
	if (mIsMovingLeft)
		movement.x -= 1.f;
	if (mIsMovingRight)
		movement.x += 1.f;
	mPlayer.move(movement * static_cast<float>(deltaTime.asMilliseconds()));
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

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.draw(mStatisticsText);
	mWindow.display();
}