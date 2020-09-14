/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** door_animation
*/

#include "rpg.h"

void door_animation(all_t *s_all)
{
    if (s_all->s_cine.door == 0) return;
    static int rect = 0;
    if (s_all->s_spawn.open == 0 && s_all->s_spawn.door_seconds >= 0.01 &&
    s_all->s_player.hero_pos.y <= 610 && s_all->s_player.hero_pos.x >= 900 &&
    s_all->s_player.hero_pos.x <= 980 && s_all->s_player.hero_pos.y >= 550) {
        rect += 200;
        sfSprite_setTextureRect(s_all->s_spawn.door,
            (sfIntRect){rect, 0, 200, 100});
        sfClock_restart(s_all->s_spawn.door_clock);
        if (rect >= 600) s_all->s_spawn.open = 1;
    } else if (s_all->s_spawn.door_seconds >= 0.01
    && (s_all->s_player.hero_pos.y > 610 || s_all->s_player.hero_pos.x < 900
    || s_all->s_player.hero_pos.x > 980 || s_all->s_player.hero_pos.y < 550)) {
        if (rect <= 0) {
            s_all->s_spawn.open = 0;
            return;
        } rect -= 200;
        sfSprite_setTextureRect(s_all->s_spawn.door,
            (sfIntRect){rect, 0, 200, 100});
        sfClock_restart(s_all->s_spawn.door_clock);
    }
}