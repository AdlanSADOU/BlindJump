/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rect_hero3
*/

#include "rpg.h"

sfBool is_key_released(sfEvent *e, sfKeyCode key)
{
    if (e->key.code == key && e->key.type == sfEvtKeyReleased) {
        e->mouseButton.type = -1;
        return sfTrue;
        }
    return sfFalse;
}

void set_iddle_rect2(all_t *s_all)
{
    if (is_key_released(&s_all->s_game.event, sfKeyLeft)
    && s_all->s_movement.up == 0 && s_all->s_movement.down == 0
    && s_all->s_movement.right == 0 && s_all->s_direction.right == 0
    && s_all->s_direction.left == 0 && s_all->s_direction.up == 0
    && s_all->s_direction.down == 0) {
        s_all->s_player.hero_rect.left = 214;
        s_all->s_player.hero_rect.top = 76;
        s_all->s_player.hero_rect.height = 32;
    }
    if (is_key_released(&s_all->s_game.event, sfKeyRight)
    && s_all->s_movement.up == 0 && s_all->s_movement.down == 0
    && s_all->s_movement.left == 0 && s_all->s_direction.right == 0
    && s_all->s_direction.left == 0 && s_all->s_direction.up == 0
    && s_all->s_direction.down == 0) {
        s_all->s_player.hero_rect.left = 438;
        s_all->s_player.hero_rect.top = 76;
        s_all->s_player.hero_rect.height = 32;
    }
    sfSprite_setTextureRect(s_all->s_player.hero,
        s_all->s_player.hero_rect);
}

void set_iddle_rect(all_t *s_all)
{
    if (s_all->s_player.tp == 1 || s_all->s_game.pause == 1
    || s_all->s_cine.move == 1) return;
    if (is_key_released(&s_all->s_game.event, sfKeyUp)
    && s_all->s_movement.down == 0 && s_all->s_movement.left == 0
    && s_all->s_movement.right == 0 && s_all->s_direction.right == 0
    && s_all->s_direction.left == 0 && s_all->s_direction.up == 0
    && s_all->s_direction.down == 0) {
        s_all->s_player.hero_rect.left = 214;
        s_all->s_player.hero_rect.top = 109;
        s_all->s_player.hero_rect.height = 31;
    } if (is_key_released(&s_all->s_game.event, sfKeyDown)
    && s_all->s_movement.up == 0 && s_all->s_movement.left == 0
    && s_all->s_movement.right == 0 && s_all->s_direction.right == 0
    && s_all->s_direction.left == 0 && s_all->s_direction.up == 0
    && s_all->s_direction.down == 0) {
        s_all->s_player.hero_rect.left = 406;
        s_all->s_player.hero_rect.top = 109;
        s_all->s_player.hero_rect.height = 31;
    } set_iddle_rect2(s_all);
}