/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** render_pos_center
*/

#include "rpg.h"

sfVector2f render_pos_center(all_t *s_all)
{
    sfVector2u center =
        (sfVector2u){sfRenderWindow_getSize(s_all->s_game.window).x / 2,
        sfRenderWindow_getSize(s_all->s_game.window).y / 2};

    return ((sfVector2f){center.x, center.y});
}