//

// triggers (when)
// conditions (if, optional)
// actions (what to do)

#include <functional>

namespace play {

    struct trigger {
        bool onoff;
    };

    struct action {
        std::function<void()> code;
    };

    struct event {
        std::vector<bool> triggers;
        std::vector<action> actions;
        std::vector<condition> conditions;
    };
}

// [ref] http://crashworks.org/gdc12/GDC2012_Ruskin_Elan_DynamicDialog.pdf
// L4D2 rule = trigger + status + memory + environment -> code

int main() {
    // event = when( trigger ) do { action }  unless( exception[s] )

    event( door, player )
        .when( distance( player, door ) < 10 )
        .exec( door.open() )
        .unless( !player.has(key) );

    event( batman, enemy )
        .when( enemy.see( batman ) ).then( enemy.say("look! it's batman!" )
        .unless( player.in_shadow ).then( enemy.say( "i think i see batman!"))
        .unless( level == PENGUIN ).then( enemy.say("kwak! kwak! i think i see batman!"))
        .unless( enemy.gang <= 1 ).then( enemy.say("oh no batman! please don't hurt me"))
        .unless( player == CATWOMAN ).then( enemy.say("it's the kitty kat!"))
        .unless( player == CATWOMAN && poison_ivy.is_alive ).then( enemy.say("hey cat, the boss wants a word with you..."))

    // or
    on( hit, player, enemy ) = []() {
        /**/ if( player.in_shadow ) { enemy.say( "i think i see batman!")); }
        else if( level == PENGUIN ) { enemy.say("kwak! kwak! i think i see batman!")); }
        else if( enemy.gang <= 1 ) { enemy.say("oh no batman! please don't hurt me")); }
        else if( player == CATWOMAN ) { enemy.say("it's the kitty kat!")); }
        else if( player == CATWOMAN && poison_ivy.is_alive ) { enemy.say("hey cat, the boss wants a word with you...")); }
        else {
            enemy.say("look! it's batman!");
        }
    };
}
