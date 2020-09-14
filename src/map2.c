/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** map2
*/

#include "rpg.h"

void create_map_sprite2(all_t *s_all)
{
    for (int i = 0; s_all->s_map.tileset[i] != NULL; i++) {
        sfRenderTexture_drawSprite(s_all->s_map.render,
            s_all->s_map.tileset[i]->tile, NULL);
        if (s_all->s_map.tileset[i]->top != NULL)
            sfRenderTexture_drawSprite(s_all->s_map.render,
                s_all->s_map.tileset[i]->top, NULL);
        if (s_all->s_map.tileset[i]->bottom != NULL)
            sfRenderTexture_drawSprite(s_all->s_map.render,
                s_all->s_map.tileset[i]->bottom, NULL);
        if (s_all->s_map.tileset[i]->grass != NULL)
            sfRenderTexture_drawSprite(s_all->s_map.render,
                s_all->s_map.tileset[i]->grass, NULL);
    }
}

void create_map_sprite(all_t *s_all)
{
    for (int j = 0; j != 2; j++) {
    sfRenderTexture_destroy(s_all->s_map.render);
    s_all->s_map.render = sfRenderTexture_create(32 * s_all->s_map.x,
        26 * s_all->s_map.y, 0);
    sfSprite_destroy(s_all->s_map.map_sprite);
    s_all->s_map.map_sprite = sfSprite_create();
    create_map_sprite2(s_all);
    s_all->s_map.map_texture = NULL;
    s_all->s_map.map_texture = sfRenderTexture_getTexture(s_all->s_map.render);
    sfSprite_setTexture(s_all->s_map.map_sprite,
        s_all->s_map.map_texture, sfTrue);
    sfSprite_setPosition(s_all->s_map.map_sprite,
    (sfVector2f){0, (26 * s_all->s_map.y)});
    sfSprite_setScale(s_all->s_map.map_sprite,
    (sfVector2f){1, -1});
    }
}