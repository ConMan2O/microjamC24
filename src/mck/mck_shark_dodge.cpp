#include "mck_shark_dodge.h"

#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"

#include "mj/mj_game_list.h"

namespace
{
    constexpr bn::string_view code_credits[] = { "" };
    constexpr bn::string_view graphics_credits[] = { "" };
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
}

// Macros used to add game to game list
MJ_GAME_LIST_ADD(mck::mck_shark_dodge) // The class of the game is used here
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace mck {
    mck_shark_dodge::mck_shark_dodge(int completed_games, const mj::game_data& data):
        mj::game('mck')
    {}

    bn::string<16> mck_shark_dodge::title() const {
        return "Dodge the sharks!";
    }

    int mck_shark_dodge::total_frames() const {
    return 600; // 300 frames at 60fps = 5 seconds
}

/**
 * play is repeatedly called while the microgame is playing.
 * 
 * You can think of it as what previously was in the while event loop.
 * You do NOT need to write your own while event loop
 * You do NOT need to call bn::core::update()
 * 
 * @param data shared information, such as a rng and number of frames left in the microgame
 * @return the mj::game result indicating whether the game has finished and whether the title should be hidden
 */
mj::game_result mck_shark_dodge::play([[maybe_unused]] const mj::game_data& data)
{

    // Creates a game result indicating whether the game is finished and whether the title should be hidden early
    // For this game the game should end early if the player has won (if victory returns true)
    // The title is not hidden early (false is passed), so the title disappears at the default time
    mj::game_result result(victory(), false);
    return result;
}

/**
 * Returns whether the player has won the microgame.
 * 
 * In this particular microgame the player wins if they make the ball leave the screen.
 */
bool mck_shark_dodge::victory() const {
    return false;
}

/**
 * Called repeatedly as the game fades into view. Unused for this particular microgame.
 * 
 * @param data shared information, such as a rng and number of frames left in the microgame
 */
void mck_shark_dodge::fade_in([[maybe_unused]] const mj::game_data& data)
{
}

/**
 * Called repeatedly as the game fades into view. Unused for this particular microgame.
 * 
 * @param data shared information, such as a rng and number of frames left in the microgame
 */
void mck_shark_dodge::fade_out([[maybe_unused]] const mj::game_data& data)
{
}
}