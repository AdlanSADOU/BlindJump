/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_stars2
*/

#include "rpg.h"

int move_stars3(all_t *s_all, sfSprite *sprite, float speed, sfVector2f *pos)
{
    int check = 0;
    if (s_all->s_movement.left == 1 && s_all->s_movement.right == 0
    && s_all->s_movement.down == 1 && s_all->s_movement.up == 1 && s_all->
    s_movement.wall_left == 0 && s_all->s_movement.wall_up == 0
    && s_all->s_movement.wall_down == 0) {
        (*pos).x -= speed, sfSprite_setPosition(sprite, *pos);
        check = 1;
    } if (s_all->s_movement.left == 0 && s_all->s_movement.right == 1
    && s_all->s_movement.down == 1 && s_all->s_movement.up == 1 && s_all->
    s_movement.wall_right == 0 && s_all->s_movement.wall_up == 0
    && s_all->s_movement.wall_down == 0) {
        (*pos).x += speed, sfSprite_setPosition(sprite, *pos);
        check = 1;
    } return (check);
}

int move_stars2(all_t *s_all, sfSprite *sprite, float speed, sfVector2f *pos)
{
    int check = move_stars3(s_all, sprite, speed, pos);
    if (s_all->s_player.hero_seconds < 0.01 || s_all->s_player.tp == 1
        || s_all->s_game.pause == 1) return (0);
    if (s_all->s_movement.left == 1 && s_all->s_movement.right == 1 && s_all->
    s_movement.down == 1 && s_all->s_movement.up == 0 && s_all->s_movement.
    wall_down == 0 && s_all->s_movement.wall_left == 0
    && s_all->s_movement.wall_right == 0) {
        (*pos).y += speed, sfSprite_setPosition(sprite, *pos);
        check = 1;
    } if (s_all->s_movement.left == 1 && s_all->s_movement.right == 1
    && s_all->s_movement.down == 0 && s_all->s_movement.up == 1 && s_all->
    s_movement.wall_up == 0 && s_all->s_movement.wall_left == 0
    && s_all->s_movement.wall_right == 0) {
        (*pos).y -= speed, sfSprite_setPosition(sprite, *pos);
        check = 1;
    } return (check);
}