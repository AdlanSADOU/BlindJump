/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clocks2
*/

#include "rpg.h"

void dead_clock(all_t *s_all)
{
    s_all->s_dead.time =
        sfClock_getElapsedTime(s_all->s_dead.clock);
    s_all->s_dead.seconds =
        s_all->s_dead.time.microseconds / 1000000.0;
    s_all->s_cine.time =
        sfClock_getElapsedTime(s_all->s_cine.clock);
    s_all->s_cine.seconds =
        s_all->s_cine.time.microseconds / 1000000.0;
    s_all->s_sounds.time =
        sfClock_getElapsedTime(s_all->s_sounds.clock);
    s_all->s_sounds.seconds =
        s_all->s_sounds.time.microseconds / 1000000.0;
}

void info_clocks(all_t *s_all)
{
    s_all->s_infos.time =
        sfClock_getElapsedTime(s_all->s_infos.clock);
    s_all->s_infos.seconds =
        s_all->s_infos.time.microseconds / 1000000.0;
    s_all->s_infos.hit_tm =
        sfClock_getElapsedTime(s_all->s_infos.hit_clk);
    s_all->s_infos.hit_sec =
        s_all->s_infos.hit_tm.microseconds / 1000000.0;
    s_all->s_custom.time =
        sfClock_getElapsedTime(s_all->s_custom.clock);
    s_all->s_custom.seconds =
        s_all->s_custom.time.microseconds / 1000000.0;
    s_all->s_game.time_button =
        sfClock_getElapsedTime(s_all->s_game.clock_button);
    s_all->s_game.seconds_button =
        s_all->s_game.time_button.microseconds / 1000000.0;
    dead_clock(s_all);
}