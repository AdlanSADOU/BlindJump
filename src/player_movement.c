/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_movement
*/

#include "rpg.h"

void get_movement(all_t *s_all)
{
    if (s_all->s_game.pause == 1) return;
    if (sfKeyboard_isKeyPressed(sfKeyUp) == 1)
        s_all->s_movement.up = 1;
    else
        s_all->s_movement.up = 0;

    if (sfKeyboard_isKeyPressed(sfKeyDown) == 1)
        s_all->s_movement.down = 1;
    else
        s_all->s_movement.down = 0;

    if (sfKeyboard_isKeyPressed(sfKeyLeft) == 1)
        s_all->s_movement.left = 1;
    else
        s_all->s_movement.left = 0;

    if (sfKeyboard_isKeyPressed(sfKeyRight) == 1)
        s_all->s_movement.right = 1;
    else
        s_all->s_movement.right = 0;
}

void up_down_left_right(all_t *s_all)
{
    if (s_all->s_game.pause == 1) return;
    reset_wall(s_all);
    int check = 0;
    check += loop_map_hitbox(s_all);
    check += check_borders(s_all);
    check += check_middle_wall(s_all);
    check += check_ship(s_all);
    check += loop_chest_hitbox(s_all);
    if (check != 0) return;
    if ((s_all->s_movement.left == 0 && s_all->s_movement.right == 0)
    || (s_all->s_movement.left == 1 && s_all->s_movement.right == 1))
        movement_up_down(s_all);
    if ((s_all->s_movement.up == 0 && s_all->s_movement.down == 0)
    || (s_all->s_movement.up == 1 && s_all->s_movement.down == 1))
        movement_left_right(s_all);
}

void player_movement(all_t *s_all)
{
    if (s_all->s_game.scene == 0 || s_all->s_player.tp == 1
    || s_all->s_game.pause == 1 || s_all->s_cine.move == 1)
        return;
    up_down_left_right(s_all);
    movement_diagonal_left_up(s_all);
    movement_diagonal_left_down(s_all);
    movement_diagonal_right_up(s_all);
    movement_diagonal_right_down(s_all);
    if (s_all->s_movement.up || s_all->s_movement.down ||
    s_all->s_movement.left || s_all->s_movement.right) {
        if (s_all->s_sounds.seconds > 0.4) {
            play_random_sound(s_all);
            sfClock_restart(s_all->s_sounds.clock);
        }
    }
    set_position_debug(s_all->s_player.debug, s_all->s_player.hero_pos);
}