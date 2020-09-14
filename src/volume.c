/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** volume
*/

#include "rpg.h"

void init_volume2(all_t *s_all)
{
    s_all->s_options.s_volume.left_tx =
    sfTexture_createFromFile("sprites/buttons/arrow.png", NULL);
    s_all->s_options.s_volume.right_tx =
    sfTexture_createFromFile("sprites/buttons/arrow.png", NULL);
    s_all->s_options.s_volume.left = sfSprite_create();
    s_all->s_options.s_volume.right = sfSprite_create();
    sfSprite_setTexture(s_all->s_options.s_volume.left,
    s_all->s_options.s_volume.left_tx, sfTrue);
    sfSprite_setTexture(s_all->s_options.s_volume.right,
    s_all->s_options.s_volume.right_tx, sfTrue);
    sfSprite_setScale(s_all->s_options.s_volume.left, (sfVector2f){-1, 1});
    sfSprite_setPosition(s_all->s_options.s_volume.left,
    (sfVector2f){620, 640});
    sfSprite_setPosition(s_all->s_options.s_volume.right,
    (sfVector2f){1330, 640});
}

void init_volume1(all_t *s_all)
{
    s_all->s_options.s_volume.bar1 = sfRectangleShape_create();
    s_all->s_options.s_volume.bar2 = sfRectangleShape_create();
    sfRectangleShape_setFillColor(s_all->s_options.s_volume.bar1, sfWhite);
    sfRectangleShape_setFillColor(s_all->s_options.s_volume.bar2,
    (sfColor){172, 56, 36, 255});
    sfRectangleShape_setSize(s_all->s_options.s_volume.bar1,
    (sfVector2f){500, 50});
    sfRectangleShape_setSize(s_all->s_options.s_volume.bar2,
    (sfVector2f){400, 50});
    sfRectangleShape_setPosition(s_all->s_options.s_volume.bar1,
    (sfVector2f){720, 647});
    sfRectangleShape_setPosition(s_all->s_options.s_volume.bar2,
    (sfVector2f){720, 647});
    init_volume2(s_all);
    s_all->s_options.s_volume.vol = 80;
}

int check_right(all_t *s_all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(s_all->s_game.window);
    sfFloatRect r = sfSprite_getGlobalBounds(s_all->s_options.s_volume.right);
    if (sfFloatRect_contains(&r, mouse.x, mouse.y) == sfTrue
    && s_all->s_game.event.mouseButton.type == sfEvtMouseButtonPressed) {
        return 1;
    }
    return 0;
}

int check_left(all_t *s_all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(s_all->s_game.window);
    sfFloatRect r = sfSprite_getGlobalBounds(s_all->s_options.s_volume.left);
    if (sfFloatRect_contains(&r, mouse.x, mouse.y) == sfTrue
    && s_all->s_game.event.mouseButton.type == sfEvtMouseButtonPressed) {
        return 1;
    }
    return 0;
}

void adjust_volume(all_t *s_all)
{
    if (s_all->s_options.s_volume.vol < 100) {
        s_all->s_options.s_volume.vol += check_right(s_all);
    }
    if (s_all->s_options.s_volume.vol > 0) {
        s_all->s_options.s_volume.vol -= check_left(s_all);
    }
    sfRectangleShape_setSize(s_all->s_options.s_volume.bar2,
    (sfVector2f){s_all->s_options.s_volume.vol * 5, 50});
    s_all->s_game.volume = (float)s_all->s_options.s_volume.vol;
    set_volume(s_all);
}