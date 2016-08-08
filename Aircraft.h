//
// Created by vtimofeev on 08/08/16.
//

#ifndef GAME_AIRCRAFT_H
#define GAME_AIRCRAFT_H


class Aircraft {
public:
    enum Type
    {
        Eagle,
        Raptor,
    };
    explicit Aircraft(Type type);

private:
    Type mType;
};


#endif //GAME_AIRCRAFT_H
