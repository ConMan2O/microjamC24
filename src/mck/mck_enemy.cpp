#include "mck/mck_enemy.h"

#include <bn_keypad.h>

#include "bn_sprite_items_mck_shark.h"

#include "bn_sound_items.h"

// All game functions/classes/variables/constants scoped to the namespace
namespace mck {

/**
 * enemy constructor
 * 
 * @param speed the pixels/frame the enemy moves at in each dimension
 * @param data the current game data, used for random number generation
 */
enemy::enemy(bn::fixed speed, const mj::game_data& data) :
    _sprite(bn::sprite_items::mck_shark.create_sprite(bn::fixed_point(0, 0))),
    _xspeed(0),
    _yspeed(0)
    {
        // determine a random side for the shark to spawn on
        int side = data.random.get_unbiased_int(4);
        switch (side)
        {
        case 0 : // top
            _sprite = (bn::sprite_items::mck_shark.create_sprite
                (bn::fixed_point(data.random.get_unbiased_int(-120, 121), -80)));
            _xspeed = 0;
            _yspeed = speed;
            break;
        case 1 : // right
            _sprite = (bn::sprite_items::mck_shark.create_sprite
                (bn::fixed_point(120, data.random.get_unbiased_int(-80, 81))));
            _xspeed = speed.multiplication(-1);
            _yspeed = 0;
            break;
        case 2 : // bottom
            _sprite = (bn::sprite_items::mck_shark.create_sprite
                (bn::fixed_point(data.random.get_unbiased_int(-120, 121), 80)));
            _xspeed = 0;
            _yspeed = speed.multiplication(-1);
            break;
        case 3 : // left
            _sprite = (bn::sprite_items::mck_shark.create_sprite
                (bn::fixed_point(-120, data.random.get_unbiased_int(-80, 81))));
            _xspeed = speed;
            _yspeed = 0;
            break;
        default :
            _xspeed = 0;
            _yspeed = 0;
        }
    }


void enemy::update() {
    _update_position();
}

/**
 * Moves the enemy based on its current x and y speeds
 */
void mck::enemy::_update_position() {
    _sprite.set_x(_sprite.x() + _xspeed);
    _sprite.set_y(_sprite.y() + _yspeed);
}

bn::rect enemy::hitbox() const {
    return bn::rect(_sprite.x().integer(), _sprite.y().integer(), 16, 16);
}
}