#include <map>
#include <functional>
#include <iostream>
#include <string>

struct player {
    int type = 0;
    enum { BATMAN = 0, CATWOMAN = 1 };
    bool in_shadow = 1;
};

struct enemy {
    int type = 0;
    int gang = 0;
    enum { HUMAN = 0, FLY = 1 };
    void say( std::string text ) {
        std::cout << text << std::endl;
    }
};

bool in_fov( player &p, enemy &e ) {
    return e.type == enemy::HUMAN ? true : false;
}
bool is_hit( player &p, enemy &e ) {
    return false;
}

template<typename K1, typename V>
using map = std::map<K1,V>;
template<typename K1, typename K2, typename V>
using map2 = map<K1,map<K2,V>>;
template<typename K1, typename K2, typename K3, typename V>
using map3 = map<K1,map2<K2,K3,V>>;

#include "multi.hpp"
template<typename VALUE>
using multi = moon9::multinmap<VALUE>;

#include <string>

#include "linq/linq.h"

int main() {
    multi< std::string > on;

    player pl;
    enemy en;
    int level = 6;

#if 0
    on( hit, player, enemy ) = []() {
    /**/ if( player.in_shadow ) { enemy.say( "i think i see batman!")); }
    else if( level == 6 ) { enemy.say("kwak! kwak! i think i see batman!")); }
    else if( !enemy.gang ) { enemy.say("oh no batman! please don't hurt me")); }
    else if( pl.type == player::CATWOMAN ) { enemy.say("it's the kitty kat!")); }
    else if( pl.type == player::CATWOMAN && poison_ivy.is_alive ) { enemy.say("hey cat, the boss wants a word with you...")); }
    else {
        enemy.say("look! it's batman!");
    }
#endif

    // in fov, in shadow, level no
    on[ true ].get() = "look! it's batman";
    on[ true ][ true ].get() = "i think i see batman!";
    on[ true ][ true ][ 6 ].get() = "kwak! kwak! i think i see batman!";

    en.type = enemy::FLY;
    std::cout << on[ in_fov(pl,en) ][ pl.in_shadow ][ level ].get() << std::endl;
    en.type = enemy::HUMAN;
    std::cout << on[ in_fov(pl,en) ][ pl.in_shadow ][ level ].get() << std::endl;

    //auto linq = LINQ( from);
}
