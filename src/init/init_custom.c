/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_custom
*/

#include "rpg.h"
#include "utils.h"

void init_cursor(all_t *s_all)
{
    s_all->s_custom.sprite = sfSprite_create();
    s_all->s_custom.texture = s_all->s_player.hero_tx;
    sfSprite_setTexture(s_all->s_custom.sprite,
        s_all->s_custom.texture, sfTrue);
    sfSprite_setTextureRect(s_all->s_custom.sprite,
        (sfIntRect){67, 76, 5, 16});
    s_all->s_custom.pos = (sfVector2f){777, 184};
    sfSprite_setPosition(s_all->s_custom.sprite, s_all->s_custom.pos);
    sfSprite_setScale(s_all->s_custom.sprite, (sfVector2f){1, 2.5});
}

void init_custom_hero(all_t *s_all)
{
    s_all->s_custom.hero = sfSprite_create();
    s_all->s_custom.title_hero = sfText_create();
    s_all->s_custom.enter = sfText_create();
    sfText_setFont(s_all->s_custom.title_hero, s_all->s_game.monospaced);
    sfText_setString(s_all->s_custom.title_hero,
        "Select your skin");
    sfText_setFont(s_all->s_custom.enter, s_all->s_game.monospaced);
    sfText_setString(s_all->s_custom.enter,
        "Press enter to start");
    sfText_setPosition(s_all->s_custom.title_hero, (sfVector2f){745, 300});
    sfText_setPosition(s_all->s_custom.enter, (sfVector2f){705, 870});
    s_all->s_custom.hero_tx = s_all->s_player.hero_tx;
    sfSprite_setTexture(s_all->s_custom.hero,
        s_all->s_custom.hero_tx, sfTrue);
    sfSprite_setTextureRect(s_all->s_custom.hero, s_all->s_player.hero_rect);
    sfSprite_setPosition(s_all->s_custom.hero, (sfVector2f){900, 400});
    sfSprite_setScale(s_all->s_custom.hero, (sfVector2f){4, 4});
}

void init_custom(all_t *s_all)
{
    s_all->s_custom.select_name = sfText_create();
    s_all->s_custom.clock = sfClock_create();
    s_all->s_custom.input = sfRectangleShape_create();
    sfText_setFont(s_all->s_custom.select_name, s_all->s_game.monospaced);
    sfText_setString(s_all->s_custom.select_name,
        "Select your character's name");
    sfText_setPosition(s_all->s_custom.select_name, (sfVector2f){590, 120});
    sfRectangleShape_setFillColor(s_all->s_custom.input,
        (sfColor){19, 59, 65, 150});
    sfRectangleShape_setPosition(s_all->s_custom.input,
        (sfVector2f){770, 180});
    sfRectangleShape_setSize(s_all->s_custom.input, (sfVector2f){350, 40});
    sfText_setPosition(s_all->s_infos.p_name_txt, (sfVector2f){775, 182});
    sfText_setString(s_all->s_infos.p_name_txt, "");
    s_all->s_custom.seconds = 0;
    s_all->s_custom.show = 1;
    s_all->s_custom.p_color = (sfColor){255, 255, 255, 255};
    init_cursor(s_all);
    init_custom_hero(s_all);
    init_rgb_selector(s_all);
}

void display_cursor(all_t *s_all)
{
    if (s_all->s_custom.show == 1) {
        if (s_all->s_custom.seconds < 0.5) {
            sfRenderWindow_drawSprite(s_all->s_game.window,
                s_all->s_custom.sprite, NULL);
        } else {
            s_all->s_custom.show = 0;
        }
    }
    if (s_all->s_custom.seconds > 1) {
        sfClock_restart(s_all->s_custom.clock);
        s_all->s_custom.show = 1;
    }
}

void display_custom(all_t *s_all)
{
    if (s_all->s_game.scene == CUSTOM && s_all->s_effect.anim > 45) {
        sfRenderWindow_clear(s_all->s_game.window, sfBlack);
        sfRenderWindow_drawText(s_all->s_game.window,
            s_all->s_custom.select_name, NULL);
        sfRenderWindow_drawText(s_all->s_game.window,
            s_all->s_custom.title_hero, NULL);
        sfRenderWindow_drawText(s_all->s_game.window,
            s_all->s_custom.enter, NULL);
        sfRenderWindow_drawRectangleShape(s_all->s_game.window,
            s_all->s_custom.input, NULL);
        display_cursor(s_all);
        sfRenderWindow_drawText(s_all->s_game.window,
            s_all->s_infos.p_name_txt, NULL);
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_custom.hero, NULL);
    }
}