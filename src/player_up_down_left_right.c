/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_up_down_left_right
*/

#include "rpg.h"

void movement_up_down2(all_t *s_all)
{
    s_all->s_player.hero_pos.y += s_all->s_player.hero_speed;
    s_all->s_player.shoot_pos.y += s_all->s_player.hero_speed;
    if (s_all->s_player.shooting == 0 ||
    (s_all->s_player.up == 0 && s_all->s_player.down == 0)) {
        sfSprite_setPosition(s_all->s_player.ver_shoot,
            s_all->s_player.shoot_pos);
    } if (s_all->s_player.shooting == 0 ||
    (s_all->s_player.left == 0 && s_all->s_player.right == 0)) {
        sfSprite_setPosition(s_all->s_player.hor_shoot,
            s_all->s_player.shoot_pos);
    }
    sfSprite_setPosition(s_all->s_player.hero, s_all->s_player.hero_pos);
}

void movement_up_down(all_t *s_all)
{
    if (s_all->s_player.hero_seconds >= 0.01 && s_all->s_movement.up == 1
    && s_all->s_movement.down != 1) {
        s_all->s_player.hero_pos.y -= s_all->s_player.hero_speed;
        s_all->s_player.shoot_pos.y -= s_all->s_player.hero_speed;
        sfSprite_setPosition(s_all->s_player.hero, s_all->s_player.hero_pos);
        if (s_all->s_player.shooting == 0 ||
        (s_all->s_player.up == 0 && s_all->s_player.down == 0)) {
            sfSprite_setPosition(s_all->s_player.ver_shoot,
                s_all->s_player.shoot_pos);
        } if (s_all->s_player.shooting == 0 ||
        (s_all->s_player.left == 0 && s_all->s_player.right == 0)) {
            sfSprite_setPosition(s_all->s_player.hor_shoot,
                s_all->s_player.shoot_pos);
        } sfClock_restart(s_all->s_player.hero_clock);
    } if (s_all->s_player.hero_seconds >= 0.01 && s_all->s_movement.down == 1
    && s_all->s_movement.up != 1) {
        movement_up_down2(s_all);
        sfClock_restart(s_all->s_player.hero_clock);
    }
}

void movement_left_right2(all_t *s_all)
{
    s_all->s_player.hero_pos.x += s_all->s_player.hero_speed;
    s_all->s_player.shoot_pos.x += s_all->s_player.hero_speed;
    sfSprite_setPosition(s_all->s_player.hero, s_all->s_player.hero_pos);
    if (s_all->s_player.shooting == 0 ||
    (s_all->s_player.up == 0 && s_all->s_player.down == 0)) {
        sfSprite_setPosition(s_all->s_player.ver_shoot,
            s_all->s_player.shoot_pos);
    } if (s_all->s_player.shooting == 0 ||
    (s_all->s_player.left == 0 && s_all->s_player.right == 0)) {
        sfSprite_setPosition(s_all->s_player.hor_shoot,
            s_all->s_player.shoot_pos);
    }
}

void movement_left_right(all_t *s_all)
{
    if (s_all->s_player.hero_seconds >= 0.01 && s_all->s_movement.left == 1
    && s_all->s_movement.right != 1) {
        s_all->s_player.hero_pos.x -= s_all->s_player.hero_speed;
        s_all->s_player.shoot_pos.x -= s_all->s_player.hero_speed;
        sfSprite_setPosition(s_all->s_player.hero, s_all->s_player.hero_pos);
        if (s_all->s_player.shooting == 0 ||
        (s_all->s_player.up == 0 && s_all->s_player.down == 0)) {
            sfSprite_setPosition(s_all->s_player.ver_shoot,
                s_all->s_player.shoot_pos);
        } if (s_all->s_player.shooting == 0 ||
        (s_all->s_player.left == 0 && s_all->s_player.right == 0)) {
            sfSprite_setPosition(s_all->s_player.hor_shoot,
                s_all->s_player.shoot_pos);
        } sfClock_restart(s_all->s_player.hero_clock);
    } if (s_all->s_player.hero_seconds >= 0.01
        && s_all->s_movement.right == 1 && s_all->s_movement.left != 1) {
        movement_left_right2(s_all);
        sfClock_restart(s_all->s_player.hero_clock);
    }
}