/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** shoot
*/

#include "rpg.h"

void shoot(all_t *s_all)
{
    if (s_all->s_game.pause == 1 || s_all->s_player.tp == 1) return;
    if (s_all->s_inventory.head->is_item == 0) return;
    if (s_all->s_player.reload_sec >= s_all->s_infos.atk_speed
    && s_all->s_player.shooting == 0
    && s_all->s_player.range == 120 && s_all->s_player.space == 1) {
        s_all->s_game.event.type = 0;
        shoot3(s_all);
        shoot2(s_all);
        sfClock_restart(s_all->s_player.reload_clk);
    }
}

void shoot_direction(all_t *s_all)
{
    if (s_all->s_player.up == 1) {
        s_all->s_player.ver_pos.y -= s_all->s_player.shoot_speed;
        sfSprite_setPosition(s_all->s_player.ver_shoot,
        s_all->s_player.ver_pos);
    } if (s_all->s_player.down == 1) {
        s_all->s_player.ver_pos.y += s_all->s_player.shoot_speed;
        sfSprite_setPosition(s_all->s_player.ver_shoot,
        s_all->s_player.ver_pos);
    } if (s_all->s_player.left == 1) {
        s_all->s_player.hor_pos.x -= s_all->s_player.shoot_speed;
        sfSprite_setPosition(s_all->s_player.hor_shoot,
        s_all->s_player.hor_pos);
    } if (s_all->s_player.right == 1) {
        s_all->s_player.hor_pos.x += s_all->s_player.shoot_speed;
        sfSprite_setPosition(s_all->s_player.hor_shoot,
        s_all->s_player.hor_pos);
    }
}

void move_hit(all_t *s_all)
{
    if (s_all->s_player.left == 1 || s_all->s_player.right == 1)
        s_all->s_player.hit_pos = s_all->s_player.hor_pos;
    if (s_all->s_player.up == 1 || s_all->s_player.down == 1)
        s_all->s_player.hit_pos = s_all->s_player.ver_pos;
    sfSprite_setPosition(s_all->s_player.hit_sprite, s_all->s_player.hit_pos);
    sfSprite_setPosition(s_all->s_explode.sprite, s_all->s_player.hit_pos);
    s_all->s_player.hit = 1, s_all->s_player.ver = 0;
    s_all->s_player.shooting = 0, s_all->s_player.range = 120;
    s_all->s_player.left = 0, s_all->s_player.right = 0;
    s_all->s_player.up = 0, s_all->s_player.down = 0;
    s_all->s_player.ver_pos = s_all->s_player.shoot_pos;
    s_all->s_player.hor_pos = s_all->s_player.shoot_pos;
    sfSprite_setPosition(s_all->s_player.hor_shoot,
    s_all->s_player.hor_pos), s_all->s_player.hor = 0;
    sfSprite_setPosition(s_all->s_player.ver_shoot,
    s_all->s_player.ver_pos);
    sfClock_restart(s_all->s_player.hit_clk);
}

void display_hit(all_t *s_all)
{
    if (s_all->s_player.hit_sec > 0.05) {
        if (s_all->s_player.hit_rect.left < 136) {
            s_all->s_player.hit_rect.left += 16;
            sfSprite_setTextureRect(s_all->s_player.hit_sprite,
                s_all->s_player.hit_rect);
        }
        else {
            s_all->s_player.hit_rect.left = 88;
            sfSprite_setTextureRect(s_all->s_player.hit_sprite,
                s_all->s_player.hit_rect);
            s_all->s_player.hit = 0;
        } sfClock_restart(s_all->s_player.hit_clk);
    }
    sfRenderWindow_drawSprite(s_all->s_game.window,
    s_all->s_player.hit_sprite, NULL);
}

void shooting_control(all_t *s_all)
{
    if (s_all->s_player.shoot_sec > 0.01) {
        if (s_all->s_player.shooting == 1 && s_all->s_player.range != 0) {
            shoot_direction(s_all);
            s_all->s_player.range -= s_all->s_player.shoot_speed;
        }
        if (s_all->s_player.range <= 0) {
            move_hit(s_all);
        } sfClock_restart(s_all->s_player.shoot_clk);
    }
}