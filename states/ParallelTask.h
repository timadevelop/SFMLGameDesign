//
// Created by vtimofeev on 25/08/16.
//

#ifndef GAME_PARALLELTASK_H
#define GAME_PARALLELTASK_H

#include <SFML/System/Thread.hpp>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Lock.hpp>
#include <SFML/System/Clock.hpp>


class ParallelTask
{
public:
    ParallelTask();
    void				execute();
    bool				isFinished();
    float				getCompletion();

private:
    void				runTask();

private:
    sf::Thread			mThread;
    bool				mFinished;
    sf::Clock			mElapsedTime;
    sf::Mutex			mMutex;
};


#endif //GAME_PARALLELTASK_H
