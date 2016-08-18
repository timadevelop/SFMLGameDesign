//
// Created by vtimofeev on 13/08/16.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include <SFML/Window/Event.hpp>
#include "../commands/CommandQueue.h"
#include "Aircraft.h"

class Player {
public: // Key bindings
    enum class Action
    {
        MoveLeft, MoveRight, MoveUp, MoveDown, someAction
    };
    void assignKey(Action action, sf::Keyboard::Key key);
    sf::Keyboard::Key getAssignedKey(Action action) const;

private:
    void initializeActions();
    static bool isRealtimeAction(Action action);
    std::map<sf::Keyboard::Key, Action> mkeyBinding;
    std::map<Action, Command> mActionBinding;


public:
    Player();
    void handleEvent(const sf::Event& event, CommandQueue& commands); // handles events from "pollEvent SFML loop"
    void handleRealtimeInput(CommandQueue& commands); // handles all user`s input outside App.pollEvent
};
#endif //GAME_PLAYER_H
