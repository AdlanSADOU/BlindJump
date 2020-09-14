/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_spawn
*/

#include "rpg.h"

void init_spawn3(all_t *s_all)
{
    s_all->s_spawn.background = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(s_all->s_spawn.background,
        (sfColor){12, 37, 41, 255});
    sfRectangleShape_setFillColor(s_all->s_spawn.background,
        (sfColor){0, 0, 0, 0});
    sfRectangleShape_setSize(s_all->s_spawn.background,
        (sfVector2f){210, 625});
    sfRectangleShape_setPosition(s_all->s_spawn.background,
        (sfVector2f){860, 200});
    sfRectangleShape_setOutlineThickness(s_all->s_spawn.background, 300.0);
    s_all->s_spawn.open = 0;
    s_all->s_chest = fill_chests(NULL, s_all, (sfVector2f){s_all->s_player.
    shadow_pos.x + 65, s_all->s_player.shadow_pos.y - 117});
}

void init_spawn2(all_t *s_all)
{
    s_all->s_spawn.door_pos = render_pos_center(s_all);
    create_sprite(&s_all->s_spawn.door, &s_all->s_spawn.door_tx,
        s_all->s_spawn.door_pos, "sprites/spawn_wall.png");
    sfSprite_setOrigin(s_all->s_spawn.door,
        (sfVector2f){sfSprite_getGlobalBounds(s_all->s_spawn.door).width / 2,
        sfSprite_getGlobalBounds(s_all->s_spawn.door).height / 2});
    sfSprite_setPosition(s_all->s_spawn.door,
        (sfVector2f){s_all->s_spawn.door_pos.x += 300,
        s_all->s_spawn.door_pos.y += 48});
    sfSprite_setTextureRect(s_all->s_spawn.door,
        (sfIntRect){0, 0, 200, 100});
    sfSprite_setColor(s_all->s_spawn.door, (sfColor){210, 210, 210, 255});
    s_all->s_spawn.ship_pos = render_pos_center(s_all);
    s_all->s_spawn.ship = sfSprite_create();
    sfSprite_setTexture(s_all->s_spawn.ship, s_all->s_player.hero_tx, sfTrue);
    sfSprite_setPosition(s_all->s_spawn.ship, (sfVector2f){s_all->s_spawn.
    ship_pos.x -= 6, s_all->s_spawn.ship_pos.y += 145});
    sfSprite_setTextureRect(s_all->s_spawn.ship,
        (sfIntRect){165, 145, 45, 50});
    s_all->s_spawn.door_clock = sfClock_create();
}

void init_spawn(all_t *s_all)
{
    s_all->s_spawn.ground_pos = render_pos_center(s_all);
    create_sprite(&s_all->s_spawn.ground, &s_all->s_spawn.ground_tx,
        s_all->s_spawn.ground_pos, "sprites/spawn_ground.png");
    sfSprite_setOrigin(s_all->s_spawn.ground,
        (sfVector2f){sfSprite_getGlobalBounds(s_all->s_spawn.ground).width / 2,
        sfSprite_getGlobalBounds(s_all->s_spawn.ground).height / 2});
    sfSprite_setColor(s_all->s_spawn.ground, (sfColor){210, 210, 210, 255});
    s_all->s_spawn.mask_pos = render_pos_center(s_all);
    create_sprite(&s_all->s_spawn.mask, &s_all->s_spawn.mask_tx,
        s_all->s_spawn.mask_pos, "sprites/spawn_mask.png");
    sfSprite_setOrigin(s_all->s_spawn.mask,
        (sfVector2f){sfSprite_getGlobalBounds(s_all->s_spawn.mask).width / 2,
        sfSprite_getGlobalBounds(s_all->s_spawn.mask).height / 2});
    sfSprite_setColor(s_all->s_spawn.mask, (sfColor){210, 210, 210, 255});
    init_spawn2(s_all);
    sfSprite_setColor(s_all->s_spawn.ship, (sfColor){190, 190, 190, 255});
    init_spawn3(s_all), init_computer(s_all);
}

void display_spawn_under(all_t *s_all)
{
    door_animation(s_all);
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_spawn.ground, NULL);
    if (s_all->s_player.hero_pos.y > 580) {
        sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_spawn.door, NULL);
        display_computer(s_all);
    }
    if (s_all->s_player.hero_pos.y > 655)
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_spawn.ship, NULL);
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_tp.tp_shadow, NULL);
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_tp.tp, NULL);
}

void display_spawn_over(all_t *s_all)
{
    if (s_all->s_player.hero_pos.y <= 580) {
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_spawn.door, NULL);
        display_computer(s_all);
    }
    if (s_all->s_player.hero_pos.y <= 655)
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_spawn.ship, NULL);
    display_light_spawn(s_all);
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_spawn.mask, NULL);
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        s_all->s_spawn.background, NULL);
}