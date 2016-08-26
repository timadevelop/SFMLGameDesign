//
// Created by vtimofeev on 25/08/16.
//

#ifndef GAME_MENUSTATE_H
#define GAME_MENUSTATE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include "State.h"


class MenuState : public State
{
public:
    MenuState(StateStack& stack, Context context);

    virtual void			draw();
    virtual bool			update(sf::Time dt);
    virtual bool			handleEvent(const sf::Event& event);

    void					updateOptionText();


private:
    enum OptionNames
    {
        Play,
        Exit,
    };


private:
    sf::Sprite				mBackgroundSprite;

    std::vector<sf::Text>	mOptions;
    std::size_t				mOptionIndex;
};


#endif //GAME_MENUSTATE_H
