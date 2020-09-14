/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** mob_movements
*/

#include "rpg.h"

void move_mob_up(mob_t *node, all_t *s_all)
{
    if (node->ver > 0) {
        node->mob_pos.y -= node->speed;
        node->shadow_pos.y -= node->speed;
        node->ver -= node->speed;
    } else if (node->ver <= 0 || node->path == NULL) {
        node->path[node->y][node->x] = '1';
        node->y -= 1;
        node->ver = 26;
        free_map(node->path);
        node->path = breadth_first_search_entity(s_all->s_map.map,
        s_all, node->x, node->y);
    } sfClock_restart(node->clock);
}

void move_mob_right(mob_t *node, all_t *s_all)
{
    if (node->hor > 0) {
        node->mob_pos.x += node->speed;
        node->shadow_pos.x += node->speed;
        node->hor -= node->speed;
        sfSprite_setScale(node->mob, (sfVector2f){-1, 1});
    } else if (node->hor <= 0 || node->path == NULL) {
        node->path[node->y][node->x] = '1';
        node->x += 1;
        node->hor = 32;
        free_map(node->path);
        node->path = breadth_first_search_entity(s_all->s_map.map,
        s_all, node->x, node->y);
    } sfClock_restart(node->clock);
}

void move_mob_down(mob_t *node, all_t *s_all)
{
    if (node->ver > 0) {
        node->mob_pos.y += node->speed;
        node->shadow_pos.y += node->speed;
        node->ver -= node->speed;
    } else if (node->ver <= 0 || node->path == NULL) {
        node->path[node->y][node->x] = '1';
        node->y += 1;
        node->ver = 26;
        free_map(node->path);
        node->path = breadth_first_search_entity(s_all->s_map.map,
        s_all, node->x, node->y);
    } sfClock_restart(node->clock);
}

void move_mob_left(mob_t *node, all_t *s_all)
{
    if (node->hor > 0) {
        node->mob_pos.x -= node->speed;
        node->shadow_pos.x -= node->speed;
        node->hor -= node->speed;
        sfSprite_setScale(node->mob, (sfVector2f){1, 1});
    } else if (node->hor <= 0 || node->path == NULL) {
        node->path[node->y][node->x] = '1';
        node->x -= 1;
        node->hor = 32;
        free_map(node->path);
        node->path = breadth_first_search_entity(s_all->s_map.map,
        s_all, node->x, node->y);
    } sfClock_restart(node->clock);
}