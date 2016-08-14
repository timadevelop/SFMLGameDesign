//
// Created by vtimofeev on 13/08/16.
//

#include "CommandQueue.h"

void CommandQueue::push(const Command &command) {
    mQueue.push(command);
}

Command CommandQueue::pop() {
    Command tmp = mQueue.front();
    mQueue.pop();
    return tmp;
}

bool CommandQueue::isEmpty() const {
    return mQueue.empty();
}