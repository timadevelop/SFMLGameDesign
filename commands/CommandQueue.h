//
// Created by vtimofeev on 13/08/16.
//

#ifndef GAME_COMMANDQUEUE_H
#define GAME_COMMANDQUEUE_H


#include <queue>
#include "./Command.h"

class CommandQueue {
public:
    void push(const Command& command);
    Command pop();
    bool isEmpty() const;

private:
    std::queue<Command> mQueue;
};


#endif //GAME_COMMANDQUEUE_H
