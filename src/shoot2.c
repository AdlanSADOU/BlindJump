/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** shoot2
*/

#include "rpg.h"

void shoot3(all_t *s_all)
{
    if (s_all->s_direction.left == 1) {
        s_all->s_player.shooting = 1, s_all->s_player.left = 1;
        s_all->s_player.hor_pos = s_all->s_player.shoot_pos;
        s_all->s_player.hor = 1;
        sfSound_play(s_all->s_sounds.laser);
        if (s_all->s_movement.left == 1)
            s_all->s_player.shoot_speed = s_all->s_player.fast_shoot;
        else s_all->s_player.shoot_speed = s_all->s_player.save_speed;
    }
    if (s_all->s_direction.right == 1) {
        s_all->s_player.shooting = 1, s_all->s_player.right = 1;
        s_all->s_player.hor_pos = s_all->s_player.shoot_pos;
        s_all->s_player.hor = 1;
        sfSound_play(s_all->s_sounds.laser);
        if (s_all->s_movement.right == 1)
            s_all->s_player.shoot_speed = s_all->s_player.fast_shoot;
        else s_all->s_player.shoot_speed = s_all->s_player.save_speed;
    }
}

void shoot2(all_t *s_all)
{
    if (s_all->s_direction.up == 1) {
        s_all->s_player.shooting = 1, s_all->s_player.up = 1;
        s_all->s_player.ver_pos = s_all->s_player.shoot_pos;
        sfSound_play(s_all->s_sounds.laser);
        s_all->s_player.ver = 1;
        if (s_all->s_movement.up == 1)
            s_all->s_player.shoot_speed = s_all->s_player.fast_shoot;
        else s_all->s_player.shoot_speed = s_all->s_player.save_speed;
    } if (s_all->s_direction.down == 1) {
        s_all->s_player.shooting = 1, s_all->s_player.down = 1;
        s_all->s_player.ver_pos = s_all->s_player.shoot_pos;
        sfSound_play(s_all->s_sounds.laser);
        s_all->s_player.ver = 1;
        if (s_all->s_movement.down == 1)
            s_all->s_player.shoot_speed = s_all->s_player.fast_shoot;
        else s_all->s_player.shoot_speed = s_all->s_player.save_speed;
    }
}