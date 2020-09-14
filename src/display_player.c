/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_player
*/

#include "rpg.h"

int check_if_full(all_t *s_all)
{
    slots_t *tmp = s_all->s_inventory.head;
    int count = 0;
    while (tmp != NULL) {
        if (tmp->slot_nb == 0 && tmp->is_item == 1)
            count++;
        tmp = tmp->next;
    }
    if (count == 20) return (1);
    return (0);
}

void display_weapon_down(all_t *s_all)
{
    if (s_all->s_inventory.head->is_item == 0) return;
    if (s_all->s_direction.down == 1 && s_all->s_player.tp != 1) {
        sfSprite_setPosition(s_all->s_player.gun,
            (sfVector2f){s_all->s_player.hero_pos.x + 6,
            s_all->s_player.hero_pos.y + 17});
        sfSprite_setScale(s_all->s_player.gun, (sfVector2f){0.79, 0.79});
        sfSprite_setTextureRect(s_all->s_player.gun,
            (sfIntRect){742, 107, 23, 10});
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_player.gun, &s_all->s_game.state);
    }
}

void display_weapon_left_right(all_t *s_all)
{
    if (s_all->s_inventory.head->is_item == 0) return;
    if (s_all->s_direction.right == 1 && s_all->s_player.tp != 1) {
        sfSprite_setPosition(s_all->s_player.gun,
            (sfVector2f){s_all->s_player.hero_pos.x + 4,
            s_all->s_player.hero_pos.y + 17});
        sfSprite_setScale(s_all->s_player.gun, (sfVector2f){0.79, 0.79});
        sfSprite_setTextureRect(s_all->s_player.gun,
            (sfIntRect){687, 107, 23, 10});
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_player.gun, &s_all->s_game.state);
    } if (s_all->s_direction.left == 1 && s_all->s_player.tp != 1) {
        sfSprite_setPosition(s_all->s_player.gun,
            (sfVector2f){s_all->s_player.hero_pos.x + 16,
            s_all->s_player.hero_pos.y + 17});
        sfSprite_setScale(s_all->s_player.gun, (sfVector2f){-0.79, 0.79});
        sfSprite_setTextureRect(s_all->s_player.gun,
            (sfIntRect){687, 107, 23, 10});
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_player.gun, &s_all->s_game.state);
    }
}

void display_shooting_elements(all_t *s_all)
{
    if (s_all->s_player.tp != 1) {
        if (s_all->s_player.hor == 1) {
            sfShader_setVec2Uniform(s_all->s_game.shader, "storm_position",
                s_all->s_player.hor_pos);
            sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_player.hor_shoot, NULL);
        }
        else if (s_all->s_player.ver == 1) {
            sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_player.ver_shoot, NULL);
            sfShader_setVec2Uniform(s_all->s_game.shader, "storm_position",
                s_all->s_player.ver_pos);
        }
        else
            sfShader_setVec2Uniform(s_all->s_game.shader, "storm_position",
            (sfVector2f){-1000, -1000});
        display_weapon_left_right(s_all);
        if (s_all->s_player.hit == 1) display_hit(s_all);
    }
}

void display_hero(all_t *s_all)
{
    rect_hero(s_all);
    if (s_all->s_player.refresh_sec > 0.1 && s_all->s_mob != NULL &&
    s_all->s_game.pause == 0)
        refresh_path(s_all);
    sfSprite_setPosition(s_all->s_player.shadow,
    (sfVector2f){s_all->s_player.hero_pos.x + 3,
    s_all->s_player.hero_pos.y + 26});
    display_shooting_elements(s_all);
    if (s_all->s_tp.anim != 2) {
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_player.shadow, &s_all->s_game.state);
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_player.hero, &s_all->s_game.state);
    } if (s_all->s_player.tp != 1) display_weapon_down(s_all);
    shooting_control(s_all), player_immunity(s_all);
}