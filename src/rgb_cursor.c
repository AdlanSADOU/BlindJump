/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rgb_cursor
*/

#include "rpg.h"

void moove_rgb_cursor_left(all_t *s_all, rgb_t *temp)
{
    sfVector2f pos;
    if (temp->value == 0) return;
    pos = sfSprite_getPosition(temp->cursor);
    temp->value -= 3;
    pos.x -= 3;
    sfSprite_setPosition(temp->cursor, pos);
    if (temp->id == 'R')
        s_all->s_custom.p_color.r -= 3;
    if (temp->id == 'G')
        s_all->s_custom.p_color.g -= 3;
    if (temp->id == 'B')
        s_all->s_custom.p_color.b -= 3;
    sfSprite_setColor(s_all->s_custom.hero, s_all->s_custom.p_color);
}

void moove_rgb_cursor_right(all_t *s_all, rgb_t *temp)
{
    sfVector2f pos;
    if (temp->value == 255) return;
    pos = sfSprite_getPosition(temp->cursor);
    temp->value += 3;
    pos.x += 3;
    sfSprite_setPosition(temp->cursor, pos);
    if (temp->id == 'R')
        s_all->s_custom.p_color.r += 3;
    if (temp->id == 'G')
        s_all->s_custom.p_color.g += 3;
    if (temp->id == 'B')
        s_all->s_custom.p_color.b += 3;
    sfSprite_setColor(s_all->s_custom.hero, s_all->s_custom.p_color);
}

void enter_event(all_t *s_all)
{
    sfText_setPosition(s_all->s_infos.p_name_txt,
        (sfVector2f){725, 885});
    sfText_setFont(s_all->s_infos.p_name_txt,
        s_all->s_game.font);
    s_all->s_game.scene = SPAWN;
    sfRectangleShape_setFillColor(s_all->s_tp.black,
        (sfColor){0, 0, 0, 0});
    sfSprite_setColor(s_all->s_player.hero, s_all->s_custom.p_color);
}