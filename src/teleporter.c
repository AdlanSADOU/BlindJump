/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_tp
*/

#include "rpg.h"

void init_tp2(all_t *s_all)
{
    s_all->s_tp.beam = sfRectangleShape_create();
    sfRectangleShape_setFillColor(s_all->s_tp.beam,
        (sfColor){117, 253, 234, 0});
    sfRectangleShape_setSize(s_all->s_tp.beam, (sfVector2f){2, 50});
    sfRectangleShape_setOrigin(s_all->s_tp.beam, (sfVector2f){1, 50});
    sfRectangleShape_setPosition(s_all->s_tp.beam,
        (sfVector2f){s_all->s_tp.tp_pos.x + 16, s_all->s_tp.tp_pos.y + 19});
    s_all->s_tp.alpha = 0, s_all->s_tp.height = 0;
    s_all->s_tp.anim = 0, s_all->s_tp.width = 2;
    s_all->s_tp.black = sfRectangleShape_create();
    sfRectangleShape_setFillColor(s_all->s_tp.black,
        (sfColor){0, 0, 0, 0});
    sfRectangleShape_setSize(s_all->s_tp.black,
        (sfVector2f){sfSprite_getGlobalBounds(s_all->s_effect.vignette1).width,
        sfSprite_getGlobalBounds(s_all->s_effect.vignette1).height});
}

void init_tp(all_t *s_all)
{
    s_all->s_tp.tp_clock = sfClock_create();
    s_all->s_tp.tp = sfSprite_create();
    sfSprite_setTexture(s_all->s_tp.tp, s_all->s_player.hero_tx, sfTrue);
    s_all->s_tp.tp_pos = (sfVector2f){935, 322};
    sfSprite_setTextureRect(s_all->s_tp.tp, (sfIntRect){391, 224, 32, 30});
    sfSprite_setPosition(s_all->s_tp.tp, s_all->s_tp.tp_pos);
    s_all->s_tp.tp_shadow = sfSprite_create();
    sfSprite_setTexture(s_all->s_tp.tp_shadow,
        s_all->s_player.hero_tx, sfTrue);
    sfSprite_setTextureRect(s_all->s_tp.tp_shadow,
        (sfIntRect){175, 196, 32, 32});
    sfSprite_setPosition(s_all->s_tp.tp_shadow,
        (sfVector2f){s_all->s_tp.tp_pos.x, s_all->s_tp.tp_pos.y + 7});
    s_all->s_tp.debug = init_hitbox_debug(s_all->s_tp.debug,
        s_all->s_tp.tp_pos, s_all->s_tp.tp);
    init_tp2(s_all);
}

void set_tp_position(all_t *s_all)
{
    s_all->s_tp.tp_pos = (sfVector2f){s_all->s_map.tileset_pos.x,
        s_all->s_map.tileset_pos.y - 5};
    sfSprite_setPosition(s_all->s_tp.tp, s_all->s_tp.tp_pos);
    sfSprite_setPosition(s_all->s_tp.tp_shadow,
        (sfVector2f){s_all->s_tp.tp_pos.x, s_all->s_tp.tp_pos.y + 7});
    sfRectangleShape_setPosition(s_all->s_tp.beam,
        (sfVector2f){s_all->s_tp.tp_pos.x + 16, s_all->s_tp.tp_pos.y + 19});
    sfSprite_setPosition(s_all->s_effect.tp_glow,
        (sfVector2f){s_all->s_tp.tp_pos.x - 185, s_all->s_tp.tp_pos.y - 190});
}

int hitbox_tp(all_t *s_all)
{
    sfFloatRect shadow = sfSprite_getGlobalBounds(s_all->s_player.shadow);
    sfFloatRect tp = sfSprite_getGlobalBounds(s_all->s_tp.tp);
    if (sfFloatRect_intersects(&shadow, &tp, NULL))
        return (1);
    return (0);
}

void put_tp(char **map)
{
    int count = 0;

    for (int i = 0; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\0'; j++)
            if (map[i][j] == '0')
                count++;
    int random = rand() % count;
    count = 0;
    for (int i = 0; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (count == random && map[i][j] == '0') {
                map[i][j] = 'T';
                return;
            }
            if (map[i][j] == '0')
                count++;
        }
}