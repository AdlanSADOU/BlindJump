/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_diagonal
*/

#include "rpg.h"

void movement_diagonal_left_up(all_t *s_all)
{
    if (s_all->s_movement.up == 1 && s_all->s_movement.left == 1
    && s_all->s_movement.right == 0 && s_all->s_movement.down == 0
    && s_all->s_player.hero_seconds >= 0.01) {
        if (s_all->s_movement.wall_left == 0) {
            s_all->s_player.shoot_pos.x -= s_all->s_player.hero_speed / 1.5;
            s_all->s_player.hero_pos.x -= s_all->s_player.hero_speed / 1.5;
        } if (s_all->s_movement.wall_up == 0) {
            s_all->s_player.shoot_pos.y -= s_all->s_player.hero_speed / 1.5;
            s_all->s_player.hero_pos.y -= s_all->s_player.hero_speed / 1.5;
        } sfSprite_setPosition(s_all->s_player.hero, s_all->s_player.hero_pos);
        if (s_all->s_player.shooting == 0 ||
        (s_all->s_player.up == 0 && s_all->s_player.down == 0)) {
            sfSprite_setPosition(s_all->s_player.ver_shoot,
                s_all->s_player.shoot_pos);
        } if (s_all->s_player.shooting == 0 ||
        (s_all->s_player.left == 0 && s_all->s_player.right == 0)) {
            sfSprite_setPosition(s_all->s_player.hor_shoot,
                s_all->s_player.shoot_pos);
        } sfClock_restart(s_all->s_player.hero_clock);
    }
}

void movement_diagonal_left_down(all_t *s_all)
{
    if (s_all->s_movement.up == 0 && s_all->s_movement.left == 1
    && s_all->s_movement.right == 0 && s_all->s_movement.down == 1
    && s_all->s_player.hero_seconds >= 0.01) {
        if (s_all->s_movement.wall_left == 0) {
            s_all->s_player.shoot_pos.x -= s_all->s_player.hero_speed / 1.5;
            s_all->s_player.hero_pos.x -= s_all->s_player.hero_speed / 1.5;
        } if (s_all->s_movement.wall_down == 0) {
            s_all->s_player.shoot_pos.y += s_all->s_player.hero_speed / 1.5;
            s_all->s_player.hero_pos.y += s_all->s_player.hero_speed / 1.5;
        } sfSprite_setPosition(s_all->s_player.hero, s_all->s_player.hero_pos);
        if (s_all->s_player.shooting == 0 ||
        (s_all->s_player.up == 0 && s_all->s_player.down == 0)) {
            sfSprite_setPosition(s_all->s_player.ver_shoot,
                s_all->s_player.shoot_pos);
        } if (s_all->s_player.shooting == 0 ||
        (s_all->s_player.left == 0 && s_all->s_player.right == 0)) {
            sfSprite_setPosition(s_all->s_player.hor_shoot,
                s_all->s_player.shoot_pos);
        } sfClock_restart(s_all->s_player.hero_clock);
    }
}

void movement_diagonal_right_down(all_t *s_all)
{
    if (s_all->s_movement.up == 0 && s_all->s_movement.right == 1
    && s_all->s_movement.left == 0 && s_all->s_movement.down == 1
    && s_all->s_player.hero_seconds >= 0.01) {
        if (s_all->s_movement.wall_right == 0) {
            s_all->s_player.shoot_pos.x += s_all->s_player.hero_speed / 1.5;
            s_all->s_player.hero_pos.x += s_all->s_player.hero_speed / 1.5;
        } if (s_all->s_movement.wall_down == 0) {
            s_all->s_player.shoot_pos.y += s_all->s_player.hero_speed / 1.5;
            s_all->s_player.hero_pos.y += s_all->s_player.hero_speed / 1.5;
        } sfSprite_setPosition(s_all->s_player.hero, s_all->s_player.hero_pos);
        if (s_all->s_player.shooting == 0 ||
        (s_all->s_player.up == 0 && s_all->s_player.down == 0)) {
            sfSprite_setPosition(s_all->s_player.ver_shoot,
                s_all->s_player.shoot_pos);
        } if (s_all->s_player.shooting == 0 ||
        (s_all->s_player.left == 0 && s_all->s_player.right == 0)) {
            sfSprite_setPosition(s_all->s_player.hor_shoot,
                s_all->s_player.shoot_pos);
        } sfClock_restart(s_all->s_player.hero_clock);
    }
}

void movement_diagonal_right_up(all_t *s_all)
{
    if (s_all->s_movement.up == 1 && s_all->s_movement.right == 1
    && s_all->s_movement.left == 0 && s_all->s_movement.down == 0
    && s_all->s_player.hero_seconds >= 0.01) {
        if (s_all->s_movement.wall_right == 0) {
            s_all->s_player.shoot_pos.x += s_all->s_player.hero_speed / 1.5;
            s_all->s_player.hero_pos.x += s_all->s_player.hero_speed / 1.5;
        } if (s_all->s_movement.wall_up == 0) {
            s_all->s_player.shoot_pos.y -= s_all->s_player.hero_speed / 1.5;
            s_all->s_player.hero_pos.y -= s_all->s_player.hero_speed / 1.5;
        } sfSprite_setPosition(s_all->s_player.hero, s_all->s_player.hero_pos);
        if (s_all->s_player.shooting == 0 ||
        (s_all->s_player.up == 0 && s_all->s_player.down == 0)) {
            sfSprite_setPosition(s_all->s_player.ver_shoot,
                s_all->s_player.shoot_pos);
        } if (s_all->s_player.shooting == 0 ||
        (s_all->s_player.left == 0 && s_all->s_player.right == 0)) {
            sfSprite_setPosition(s_all->s_player.hor_shoot,
                s_all->s_player.shoot_pos);
        } sfClock_restart(s_all->s_player.hero_clock);
    }
}