/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_movement
*/

#include "rpg.h"

void reset_wall(all_t *s_all)
{
    s_all->s_movement.wall_up = 0;
    s_all->s_movement.wall_down = 0;
    s_all->s_movement.wall_left = 0;
    s_all->s_movement.wall_right = 0;
}

void init_movement(all_t *s_all)
{
    s_all->s_movement.up = 0;
    s_all->s_movement.down = 0;
    s_all->s_movement.left = 0;
    s_all->s_movement.right = 0;
    reset_wall(s_all);
}

void init_direction(all_t *s_all)
{
    s_all->s_direction.up = 0;
    s_all->s_direction.down = 0;
    s_all->s_direction.left = 0;
    s_all->s_direction.right = 0;
}