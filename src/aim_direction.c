/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** aim_direction
*/

#include "rpg.h"

void get_aim_direction_up_down(all_t *s_all)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) == 1) {
        s_all->s_direction.up = 1;
        s_all->s_direction.down = 0;
        s_all->s_direction.left = 0;
        s_all->s_direction.right = 0;
    }
    else
        s_all->s_direction.up = 0;

    if (sfKeyboard_isKeyPressed(sfKeyS) == 1) {
        s_all->s_direction.up = 0;
        s_all->s_direction.down = 1;
        s_all->s_direction.left = 0;
        s_all->s_direction.right = 0;
    }
    else
        s_all->s_direction.down = 0;
}

void get_aim_direction_left_right(all_t *s_all)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ) == 1) {
        s_all->s_direction.up = 0;
        s_all->s_direction.down = 0;
        s_all->s_direction.left = 1;
        s_all->s_direction.right = 0;
    }
    else
        s_all->s_direction.left = 0;

    if (sfKeyboard_isKeyPressed(sfKeyD) == 1) {
        s_all->s_direction.up = 0;
        s_all->s_direction.down = 0;
        s_all->s_direction.left = 0;
        s_all->s_direction.right = 1;
    }
    else
        s_all->s_direction.right = 0;
}

void get_aim_direction(all_t *s_all)
{
    if (s_all->s_game.pause == 1 || s_all->s_cine.move == 1) return;
    get_aim_direction_up_down(s_all);
    get_aim_direction_left_right(s_all);

    if (s_all->s_direction.up == 0 && s_all->s_direction.down == 0
    && s_all->s_direction.left == 0 && s_all->s_direction.right)
        s_all->s_player.space = 0;
}