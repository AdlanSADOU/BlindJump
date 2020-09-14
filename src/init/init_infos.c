/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_infos
*/

#include "rpg.h"
#include "utils.h"

void init_xp_bar(all_t *s_all)
{
    s_all->s_infos.p_name_txt = sfText_create();
    s_all->s_infos.xp = sfRectangleShape_create();
    s_all->s_infos.xp_base = sfRectangleShape_create();
    sfRectangleShape_setFillColor(s_all->s_infos.xp,
        (sfColor){255, 150, 50, 255});
    sfRectangleShape_setFillColor(s_all->s_infos.xp_base,
        (sfColor){35, 35, 35, 255});
    sfRectangleShape_setPosition(s_all->s_infos.xp,
        (sfVector2f){725, 930});
    sfRectangleShape_setPosition(s_all->s_infos.xp_base,
        (sfVector2f){725, 930});
    sfRectangleShape_setSize(s_all->s_infos.xp, (sfVector2f){3, 20});
    sfRectangleShape_setSize(s_all->s_infos.xp_base, (sfVector2f){450, 20});
}

void init_hp_texts(all_t *s_all)
{
    s_all->s_infos.hp_txt = sfText_create();
    s_all->s_infos.heath = sfText_create();
    s_all->s_infos.hit_clk = sfClock_create();
    s_all->s_infos.hit_sec = 0, s_all->s_infos.max_hp_save = 100;
    s_all->s_infos.save_dmg = 50, s_all->s_infos.atk_speed = 0.35;
    sfText_setFont(s_all->s_infos.heath, s_all->s_game.font);
    sfText_setPosition(s_all->s_infos.heath, (sfVector2f){1650, 35});
    sfText_setString(s_all->s_infos.heath, "Health");
    s_all->s_infos.game_over = sfText_create();
    sfText_setFont(s_all->s_infos.game_over, s_all->s_game.font);
    sfText_setPosition(s_all->s_infos.game_over, (sfVector2f){850, 300});
    sfText_setString(s_all->s_infos.game_over, " GAME OVER\nYOU ARE DEAD");
    sfText_setFont(s_all->s_infos.hp_txt, s_all->s_game.font);
    sfText_setPosition(s_all->s_infos.hp_txt, (sfVector2f){1662, 77});
    sfText_setString(s_all->s_infos.hp_txt, "100/100");
    s_all->s_infos.current_hp = 100, s_all->s_infos.max_hp = 100;
    s_all->s_infos.str_hp = malloc(20), s_all->s_infos.str_hp[0] = '\0';
    sfText_setCharacterSize(s_all->s_infos.game_over, 40);
    sfText_setCharacterSize(s_all->s_infos.hp_txt, 20);
}

void init_hp_bar(all_t *s_all)
{
    s_all->s_infos.clock = sfClock_create();
    s_all->s_infos.hp = sfRectangleShape_create();
    s_all->s_infos.hp_base = sfRectangleShape_create();
    sfRectangleShape_setFillColor(s_all->s_infos.hp,
        (sfColor){0, 190, 0, 255});
    sfRectangleShape_setFillColor(s_all->s_infos.hp_base,
        (sfColor){35, 35, 35, 255});
    sfRectangleShape_setPosition(s_all->s_infos.hp,
        (sfVector2f){1575, 80});
    sfRectangleShape_setPosition(s_all->s_infos.hp_base,
        (sfVector2f){1575, 80});
    sfRectangleShape_setSize(s_all->s_infos.hp, (sfVector2f){250, 20});
    sfRectangleShape_setSize(s_all->s_infos.hp_base, (sfVector2f){250, 20});
}

void init_infos(all_t *s_all)
{
    init_xp_bar(s_all), init_hp_bar(s_all), init_hp_texts(s_all);
    s_all->s_infos.lvl_txt = sfText_create(), s_all->s_infos.seconds = 0;
    s_all->s_infos.xp_txt = sfText_create(), s_all->s_infos.is_hit = 0;
    sfText_setFont(s_all->s_infos.p_name_txt, s_all->s_game.monospaced);
    sfText_setPosition(s_all->s_infos.p_name_txt, (sfVector2f){725, 885});
    sfText_setFont(s_all->s_infos.lvl_txt, s_all->s_game.font);
    sfText_setPosition(s_all->s_infos.lvl_txt, (sfVector2f){1060, 885});
    sfText_setString(s_all->s_infos.lvl_txt, "Level 1");
    sfText_setFont(s_all->s_infos.xp_txt, s_all->s_game.font);
    s_all->s_infos.current_xp = 0, s_all->s_infos.max_xp = 100;
    s_all->s_infos.str_xp = malloc(25), s_all->s_infos.str_xp[0] = '\0';
    s_all->s_infos.str_level = malloc(20), s_all->s_infos.str_level[0] = '\0';
    s_all->s_infos.str_xp[0] = '\0', s_all->s_infos.level = 1;
    my_strcat(s_all->s_infos.str_xp, strnbr(s_all->s_infos.current_xp));
    my_strcat(s_all->s_infos.str_xp, "/"), s_all->s_infos.p_name = malloc(15);
    s_all->s_infos.p_name[0] = '\0';
    my_strcat(s_all->s_infos.str_xp, strnbr(s_all->s_infos.max_xp));
    sfText_setString(s_all->s_infos.xp_txt, s_all->s_infos.str_xp);
    sfText_setPosition(s_all->s_infos.xp_txt, (sfVector2f){1200, 928});
    sfText_setCharacterSize(s_all->s_infos.xp_txt, 20);
}

void display_infos(all_t *s_all)
{
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        s_all->s_infos.xp_base, NULL);
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        s_all->s_infos.xp, NULL);
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        s_all->s_infos.hp_base, NULL);
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        s_all->s_infos.hp, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_infos.p_name_txt, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_infos.lvl_txt, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_infos.xp_txt, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_infos.heath, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_infos.hp_txt, NULL);
}