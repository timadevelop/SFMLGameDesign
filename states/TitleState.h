//
// Created by vtimofeev on 25/08/16.
//

#ifndef GAME_TITLESTATE_H
#define GAME_TITLESTATE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include "State.h"

class TitleState : public State{
public:
    TitleState(StateStack& stack, Context context);

    virtual void		draw();
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);


private:
    sf::Sprite			mBackgroundSprite;
    sf::Text			mText;

    bool				mShowText;
    sf::Time			mTextEffectTime;
};


#endif //GAME_TITLESTATE_H
