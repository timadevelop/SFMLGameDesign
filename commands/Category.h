//
// Created by vtimofeev on 13/08/16.
//

#ifndef GAME_CATEGORY_H
#define GAME_CATEGORY_H

// Category Types for input handling

namespace Category
{
    enum Type
    {
        None = 0,
        Scene = 1 << 0,
        PlayerAircraft = 1 << 1,
        AlliedAircraft = 1 << 2,
        EnemyAircraft = 1 << 3,
    };
}

/*
 * Example:
 * unsigned int anyAircraft = Category::PlayerAircraft | Category::AlliedAircraft | Category::EnemyAircraft;
 */


#endif //GAME_CATEGORY_H
