/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** event_controll
*/

#include "rpg.h"

void events_keyboard(all_t *s_all)
{
    if (s_all->s_game.pause == 1 || s_all->s_cine.move == 1) return;
    if (s_all->s_cine.script >= 2
    && is_key_released(&s_all->s_game.event, sfKeyI))
        s_all->s_game.display_inv = !s_all->s_game.display_inv;
    s_all->s_game.key_press = 0;
    if (sfKeyboard_isKeyPressed(sfKeyE) == 1) s_all->s_game.key_press = 'E';
    if (sfKeyboard_isKeyPressed(sfKeySpace) == 1) {
        if (s_all->s_cine.script == 3 && (s_all->s_direction.down == 1
        || s_all->s_direction.left == 1 || s_all->s_direction.right == 1
        || s_all->s_direction.up == 1)) {
            s_all->s_chatbox.buff[0] = '\0', s_all->s_chatbox.op = 0;
            s_all->s_chatbox.idx = 0, s_all->s_chatbox.car = 0;
            s_all->s_cine.script = 4;
        } s_all->s_player.space = 1, s_all->s_game.event.type = 0;
    } else if (is_key_released(&s_all->s_game.event, sfKeySpace) == 1) {
        s_all->s_player.space = 0, s_all->s_game.event.type = 0;
    } computer_event(s_all);
}

void pause_game(all_t *s_all)
{
    if (s_all->s_game.pause == 0 &&
    (s_all->s_game.scene == SPAWN || s_all->s_game.scene == MAP
    || s_all->s_game.scene == GAME_OVER)) {
        if (is_key_released(&s_all->s_game.event, sfKeyEscape)) {
            s_all->s_game.pause = 1;
        }
    }
    else if (s_all->s_game.pause == 1 &&
    (s_all->s_game.scene == SPAWN || s_all->s_game.scene == MAP
    || s_all->s_game.scene == GAME_OVER)) {
        if (is_key_released(&s_all->s_game.event, sfKeyEscape)) {
            s_all->s_game.pause = 0;
        }
    }
}

void events_control(all_t *s_all)
{
    pause_game(s_all);
    if (s_all->s_game.event.type == sfEvtClosed) {
        sfRenderWindow_close(s_all->s_game.window);
    }
    if (s_all->s_game.scene == MENU || s_all->s_game.scene == GAME_OVER
    || s_all->s_game.scene == CUSTOM || s_all->s_game.scene == OPT) {
        if (is_key_released(&s_all->s_game.event, sfKeyZ)
        && s_all->s_game.scene == MENU)
            s_all->s_game.scene = CUSTOM;
        if (s_all->s_game.scene == CUSTOM)
            get_text_entered(s_all);
        return;
    }
    get_movement(s_all), get_aim_direction(s_all),
    events_keyboard(s_all), set_iddle_rect(s_all);
}