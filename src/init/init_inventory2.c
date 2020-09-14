/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_inventory2
*/

#include "rpg.h"

void set_texture_items5(slots_t *tmp, int id)
{
    if (id == 4) {
        sfSprite_setTextureRect(tmp->item, (sfIntRect){0, 64, 64, 64});
        tmp->health = 5;
    } if (id == 5) {
        tmp->health = 5;
        sfSprite_setTextureRect(tmp->item, (sfIntRect){64, 64, 64, 64});
    } if (id == 6) {
        tmp->health = 5;
        sfSprite_setTextureRect(tmp->item, (sfIntRect){128, 64, 64, 64});
    } if (id == 7) {
        tmp->health = 5;
        sfSprite_setTextureRect(tmp->item, (sfIntRect){196, 64, 64, 64});
    }
}

void set_texture_items4(slots_t *tmp, int id)
{
    if (id == 16) {
        tmp->health = 25;
        sfSprite_setTextureRect(tmp->item, (sfIntRect){0, 320, 64, 64});
    } if (id == 17) {
        tmp->health = 25;
        sfSprite_setTextureRect(tmp->item, (sfIntRect){64, 320, 64, 64});
    } if (id == 18) {
        tmp->health = 25;
        sfSprite_setTextureRect(tmp->item, (sfIntRect){128, 320, 64, 64});
    } if (id == 19) {
        tmp->health = 25;
        sfSprite_setTextureRect(tmp->item, (sfIntRect){196, 320, 64, 64});
    } set_texture_items5(tmp, id);
}

void set_texture_items3(slots_t *tmp, int id)
{
    if (id == 12) {
        tmp->health = 15;
        sfSprite_setTextureRect(tmp->item, (sfIntRect){0, 196, 64, 64});
    } if (id == 13) {
        tmp->health = 15;
        sfSprite_setTextureRect(tmp->item, (sfIntRect){64, 196, 64, 64});
    } if (id == 14) {
        tmp->health = 15;
        sfSprite_setTextureRect(tmp->item, (sfIntRect){128, 196, 64, 64});
    } if (id == 15) {
        tmp->health = 15;
        sfSprite_setTextureRect(tmp->item, (sfIntRect){196, 196, 64, 64});
    } set_texture_items4(tmp, id);
}

void set_texture_items2(slots_t *tmp, int id)
{
    if (id == 8) {
        tmp->health = 10;
        sfSprite_setTextureRect(tmp->item, (sfIntRect){0, 128, 64, 64});
    } if (id == 9) {
        tmp->health = 10;
        sfSprite_setTextureRect(tmp->item, (sfIntRect){64, 128, 64, 64});
    } if (id == 10) {
        tmp->health = 10;
        sfSprite_setTextureRect(tmp->item, (sfIntRect){128, 128, 64, 64});
    } if (id == 11) {
        tmp->health = 10;
        sfSprite_setTextureRect(tmp->item, (sfIntRect){196, 128, 64, 64});
    } set_texture_items3(tmp, id);
}

void swap_items(all_t *s_all, slots_t *tmp)
{
    int id = tmp->id;
    tmp->id = s_all->s_inventory.dragged->id;
    s_all->s_inventory.dragged->id = id;
}