//
// Created by vtimofeev on 25/08/16.
//

#ifndef GAME_PAUSESTATE_H
#define GAME_PAUSESTATE_H

#include "State.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>


class PauseState : public State
{
public:
    PauseState(StateStack& stack, Context context);

    virtual void		draw();
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);


private:
    sf::Sprite			mBackgroundSprite;
    sf::Text			mPausedText;
    sf::Text			mInstructionText;
};


#endif //GAME_PAUSESTATE_H
