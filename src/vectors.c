/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** vectors
*/

#include "rpg.h"

float calcul_mob_magnitude(mob_t *temp, sfSprite *sprite)
{
    sfVector2f pos_sprite = sfSprite_getPosition(sprite);
    float vx = temp->mob_pos.x - pos_sprite.x + 7;
    float vy = temp->mob_pos.y - pos_sprite.y + 4;
    float magnitude = sqrt(pow(vx, 2) + pow(vy, 2));
    return (magnitude);
}

float calcul_chest_magnitude(chest_t *temp, sfSprite *sprite)
{
    sfVector2f pos_sprite = sfSprite_getPosition(sprite);
    float vx = temp->pos.x - 6 - pos_sprite.x + 7;
    float vy = temp->pos.y + 15 - pos_sprite.y + 4;
    float magnitude = sqrt(pow(vx, 2) + pow(vy, 2));
    return (magnitude);
}

float calcul_sprite_magnitude(sfSprite *sprite1, sfSprite *sprite2)
{
    sfVector2f pos1 = sfSprite_getPosition(sprite1);
    sfVector2f pos2 = sfSprite_getPosition(sprite2);
    float vx = pos1.x - 6 - pos2.x + 7;
    float vy = pos1.y + 15 - pos2.y + 4;
    float magnitude = sqrt(pow(vx, 2) + pow(vy, 2));
    return (magnitude);
}