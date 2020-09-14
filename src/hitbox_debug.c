/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** hitbox_debug
*/

#include "rpg.h"

sfRectangleShape *init_hitbox_debug(sfRectangleShape *rectangle, sfVector2f pos,
    sfSprite *sprite)
{
    rectangle = sfRectangleShape_create();

    sfRectangleShape_setPosition(rectangle, pos);
    sfRectangleShape_setSize(rectangle,
        (sfVector2f){sfSprite_getGlobalBounds(sprite).width,
        sfSprite_getGlobalBounds(sprite).height});
    sfRectangleShape_setOutlineThickness(rectangle, 0.4);
    sfRectangleShape_setOutlineColor(rectangle,
        (sfColor){255, 0, 0, 255});
    sfRectangleShape_setFillColor(rectangle,
        (sfColor){0, 0, 0, 0});

    return (rectangle);
}

void display_hitbox_debug(all_t *s_all, sfRectangleShape *rectangle,
    sfSprite *sprite)
{
    sfRectangleShape_setSize(rectangle,
        (sfVector2f){sfSprite_getGlobalBounds(sprite).width,
        sfSprite_getGlobalBounds(sprite).height});
    sfRenderWindow_drawRectangleShape(s_all->s_game.window, rectangle, NULL);
}

void set_position_debug(sfRectangleShape *rectangle, sfVector2f pos)
{
    sfRectangleShape_setPosition(rectangle, pos);
}

void activate_debug_mode(all_t *s_all)
{
    if (s_all->s_game.event.type == sfEvtKeyPressed
    && sfKeyboard_isKeyPressed(sfKeyNum0) == 1)
        s_all->s_game.debug_mode = !s_all->s_game.debug_mode;
}

void display_debug(all_t *s_all)
{
    if (s_all->s_game.debug_mode == 1) {
        set_position_debug(s_all->s_player.debug_shadow,
            sfSprite_getPosition(s_all->s_player.shadow));
        for (int i = 0; s_all->s_game.scene == MAP
        && s_all->s_map.tileset[i] != NULL; i++)
            sfRenderWindow_drawRectangleShape(s_all->s_game.window,
            s_all->s_map.tileset[i]->debug, NULL);
        display_hitbox_debug(s_all, s_all->s_player.debug,
            s_all->s_player.hero);
        display_hitbox_debug(s_all, s_all->s_player.debug_shadow,
            s_all->s_player.shadow);
        set_position_debug(s_all->s_tp.debug,
            sfSprite_getPosition(s_all->s_tp.tp));
        display_hitbox_debug(s_all, s_all->s_tp.debug, s_all->s_tp.tp);
    }
}