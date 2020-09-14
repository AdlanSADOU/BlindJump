/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_loop
*/

#include "rpg.h"

int game_loop(all_t *s_all)
{
    if (!s_all->s_game.window)
        return (EXIT_FAILURE);
    sfMusic_play(s_all->s_sounds.music);
    while (sfRenderWindow_isOpen(s_all->s_game.window)) {
        while (sfRenderWindow_pollEvent(s_all->s_game.window,
        &s_all->s_game.event))
            events_control(s_all);
        cinematic1(s_all);
        slow_heal_player(s_all);
        shoot(s_all);
        game_clocks(s_all);
        player_movement(s_all);
        display(s_all);
        game_over_check(s_all);
    }
    destroy_sounds(s_all);
    return (EXIT_SUCCESS);
}