/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rect_hero2
*/

#include "rpg.h"

int rect_down_condition(all_t *s_all, int *check, int *i)
{
    if (rect_down(s_all, check, i) == 1) {

        if (s_all->s_movement.down == 0 && s_all->s_movement.right == 0
        && s_all->s_movement.up == 0 && s_all->s_movement.left == 0) {

            s_all->s_player.hero_rect.left = 406;
            s_all->s_player.hero_rect.top = 109;
            s_all->s_player.hero_rect.height = 31;
            sfSprite_setTextureRect(s_all->s_player.hero,
                s_all->s_player.hero_rect);
        }
        return (1);
    }
    return (0);
}

int rect_up_condition(all_t *s_all, int *check, int *i)
{
    if (rect_up(s_all, check, i) == 1) {

        if (s_all->s_movement.down == 0 && s_all->s_movement.right == 0
        && s_all->s_movement.up == 0 && s_all->s_movement.left == 0) {

            s_all->s_player.hero_rect.left = 214;
            s_all->s_player.hero_rect.top = 109;
            s_all->s_player.hero_rect.height = 31;
            sfSprite_setTextureRect(s_all->s_player.hero,
                s_all->s_player.hero_rect);
        }
        return (1);
    }
    return (0);
}

int rect_left_condition(all_t *s_all, int *check, int *i)
{
    if (rect_left(s_all, check, i) == 1) {

        if (s_all->s_movement.down == 0 && s_all->s_movement.right == 0
        && s_all->s_movement.up == 0 && s_all->s_movement.left == 0) {

            s_all->s_player.hero_rect.left = 214;
            s_all->s_player.hero_rect.top = 76;
            s_all->s_player.hero_rect.height = 32;
            sfSprite_setTextureRect(s_all->s_player.hero,
                s_all->s_player.hero_rect);
        }
        return (1);
    }
    return (0);
}

int rect_right_condition(all_t *s_all, int *check, int *i)
{
    if (rect_right(s_all, check, i) == 1) {

        if (s_all->s_movement.down == 0 && s_all->s_movement.right == 0
        && s_all->s_movement.up == 0 && s_all->s_movement.left == 0) {

            s_all->s_player.hero_rect.left = 438;
            s_all->s_player.hero_rect.top = 76;
            s_all->s_player.hero_rect.height = 32;
            sfSprite_setTextureRect(s_all->s_player.hero,
                s_all->s_player.hero_rect);
        }
        return (1);
    }
    return (0);
}