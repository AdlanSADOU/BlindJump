/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rect_hero
*/

#include "rpg.h"

int rect_down(all_t *s_all, int *check, int *i)
{
    if ((s_all->s_direction.down == 1 || (s_all->s_movement.down == 1
    && s_all->s_movement.right == 0 && s_all->s_direction.right == 0
    && s_all->s_movement.left == 0 && s_all->s_direction.left == 0
    && s_all->s_direction.up == 0)) && s_all->s_player.rect_seconds >= 0.1) {
        if (*check != 0) {
            *check = 0;
            s_all->s_player.hero_rect.left = 406;
            s_all->s_player.hero_rect.height = 31;
        } if (*i == 5) {
            s_all->s_player.hero_rect.left = 406, *i = 0;
        } else
            s_all->s_player.hero_rect.left += 32;
        if (*i == 2 || *i == 4) s_all->s_player.hero_rect.top = 108;
        else s_all->s_player.hero_rect.top = 109;
        *i += 1;
        sfSprite_setTextureRect(s_all->s_player.hero,
            s_all->s_player.hero_rect);
        sfClock_restart(s_all->s_player.rect_clock);
        if (s_all->s_direction.down == 1) return (1);
    } return (0);
}

int rect_up(all_t *s_all, int *check, int *i)
{
    if ((s_all->s_direction.up == 1 || (s_all->s_movement.up == 1
    && s_all->s_movement.right == 0 && s_all->s_direction.right == 0
    && s_all->s_movement.left == 0 && s_all->s_direction.left == 0))
    && s_all->s_player.rect_seconds >= 0.1) {
        if (*check != 1) {
            *check = 1;
            s_all->s_player.hero_rect.left = 214;
            s_all->s_player.hero_rect.height = 31;
        } if (*i == 5) {
            s_all->s_player.hero_rect.left = 214, *i = 0;
        } else
            s_all->s_player.hero_rect.left += 32;
        if (*i == 2 || *i == 4) s_all->s_player.hero_rect.top = 108;
        else s_all->s_player.hero_rect.top = 109;
        *i += 1;
        sfSprite_setTextureRect(s_all->s_player.hero,
            s_all->s_player.hero_rect);
        sfClock_restart(s_all->s_player.rect_clock);
        if (s_all->s_direction.up == 1) return (1);
    } return (0);
}

int rect_left(all_t *s_all, int *check, int *i)
{
    if ((s_all->s_direction.left == 1 || (s_all->s_movement.left == 1
    && s_all->s_direction.right != 1))
    && s_all->s_player.rect_seconds >= 0.1) {
        if (*check != 2) {
            *check = 2;
            s_all->s_player.hero_rect.left = 214;
            s_all->s_player.hero_rect.top = 76;
            s_all->s_player.hero_rect.height = 32;
        }
        if (*i == 5) {
            s_all->s_player.hero_rect.left = 214;
            *i = 0;
        } else s_all->s_player.hero_rect.left += 32;
        *i += 1;
        sfSprite_setTextureRect(s_all->s_player.hero,
            s_all->s_player.hero_rect);
        sfClock_restart(s_all->s_player.rect_clock);
        if (s_all->s_direction.left == 1) return (1);
    }
    return (0);
}

int rect_right(all_t *s_all, int *check, int *i)
{
    if ((s_all->s_direction.right == 1 || (s_all->s_movement.right == 1
    && s_all->s_direction.left != 1)) && s_all->s_player.rect_seconds >= 0.1) {
        if (*check != 3) {
            *check = 3;
            s_all->s_player.hero_rect.left = 438;
            s_all->s_player.hero_rect.top = 76;
            s_all->s_player.hero_rect.height = 32;
        }
        if (*i == 5) {
            s_all->s_player.hero_rect.left = 438;
            *i = 0;
        } else
            s_all->s_player.hero_rect.left += 32;
        *i += 1;
        sfSprite_setTextureRect(s_all->s_player.hero,
            s_all->s_player.hero_rect);
        sfClock_restart(s_all->s_player.rect_clock);
        if (s_all->s_direction.right == 1) return (1);
    }
    return (0);
}

void rect_hero(all_t *s_all)
{
    static int i = 1;
    static int check = 0;
    if (s_all->s_game.pause == 1 || s_all->s_cine.move == 1) return;
    if ((s_all->s_movement.left == 1 && s_all->s_movement.right == 1
    && s_all->s_movement.up == 1 && s_all->s_movement.down == 1)
    || s_all->s_player.tp == 1)
        return;

    if (rect_down_condition(s_all, &check, &i) == 1)
        return;

    if (rect_up_condition(s_all, &check, &i) == 1)
        return;

    if (rect_left_condition(s_all, &check, &i) == 1)
        return;

    if (rect_right_condition(s_all, &check, &i) == 1)
        return;
}