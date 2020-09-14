/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_statbox
*/

#include "rpg.h"

void stat_create(all_t *s_all)
{
    s_all->s_statbox.bg = sfRectangleShape_create();
    s_all->s_statbox.bg1 = sfRectangleShape_create();
    s_all->s_statbox.font = sfFont_createFromFile("font/Cornerstone.ttf");
    s_all->s_statbox.hp = sfText_create(), s_all->s_statbox.xp =
    sfText_create(), s_all->s_statbox.dmg = sfText_create(), s_all->
    s_statbox.lvl = sfText_create(), s_all->s_statbox.hp_tx = sfText_create(),
    s_all->s_statbox.xp_tx = sfText_create(), s_all->s_statbox.dmg_tx =
    sfText_create(), s_all->s_statbox.sh_speed_tx = sfText_create(), s_all->
    s_statbox.speed_tx = sfText_create(), s_all->s_statbox.speed =
    sfText_create(), s_all->s_statbox.sh_speed = sfText_create();
    s_all->s_statbox.lvl_tx = sfText_create();
    s_all->s_statbox.p_name = sfText_create();
    s_all->s_statbox.dmg_str = strnbr(s_all->s_infos.dmg);
    s_all->s_statbox.lvl_str = strnbr(s_all->s_infos.level);
    s_all->s_statbox.hp_str = malloc(25), s_all->s_statbox.hp_str[0] = '\0';
    s_all->s_statbox.speed_str = malloc(25);
    s_all->s_statbox.speed_str[0] = '\0';
    s_all->s_statbox.sh_speed_str = malloc(25),
    s_all->s_statbox.sh_speed_str[0] = '\0';
    s_all->s_statbox.lvl_up = sfText_create();
}

void stat_text(all_t *s_all)
{
    sfText_setColor(s_all->s_statbox.dmg, sfWhite);
    sfText_setFont(s_all->s_statbox.dmg, s_all->s_statbox.font);
    sfText_setCharacterSize(s_all->s_statbox.dmg, 20);
    sfText_setColor(s_all->s_statbox.hp, sfWhite);
    sfText_setFont(s_all->s_statbox.hp, s_all->s_statbox.font);
    sfText_setCharacterSize(s_all->s_statbox.hp, 20);
    sfText_setColor(s_all->s_statbox.hp_tx, sfWhite);
    sfText_setFont(s_all->s_statbox.hp_tx, s_all->s_statbox.font);
    sfText_setCharacterSize(s_all->s_statbox.hp_tx, 20);
    sfText_setColor(s_all->s_statbox.xp, sfWhite);
    sfText_setFont(s_all->s_statbox.xp, s_all->s_statbox.font);
    sfText_setCharacterSize(s_all->s_statbox.xp, 20);
    sfText_setColor(s_all->s_statbox.xp_tx, sfWhite);
    sfText_setFont(s_all->s_statbox.xp_tx, s_all->s_statbox.font);
    sfText_setCharacterSize(s_all->s_statbox.xp_tx, 20);
    sfText_setColor(s_all->s_statbox.dmg_tx, sfWhite);
    sfText_setFont(s_all->s_statbox.dmg_tx, s_all->s_statbox.font);
    sfText_setCharacterSize(s_all->s_statbox.dmg_tx, 20);
    sfText_setColor(s_all->s_statbox.lvl, sfWhite);
    sfText_setFont(s_all->s_statbox.lvl, s_all->s_statbox.font);
}

void stat_text1(all_t *s_all)
{
    sfText_setCharacterSize(s_all->s_statbox.lvl, 20);
    sfText_setColor(s_all->s_statbox.lvl_tx, sfWhite);
    sfText_setFont(s_all->s_statbox.lvl_tx, s_all->s_statbox.font);
    sfText_setCharacterSize(s_all->s_statbox.lvl_tx, 20);
    sfText_setColor(s_all->s_statbox.p_name, sfWhite);
    sfText_setFont(s_all->s_statbox.p_name, s_all->s_game.monospaced);
    sfText_setCharacterSize(s_all->s_statbox.p_name, 15);
    sfText_setString(s_all->s_statbox.dmg, s_all->s_statbox.dmg_str);
    sfText_setString(s_all->s_statbox.dmg_tx, "DMG: ");
    sfText_setString(s_all->s_statbox.hp, s_all->s_infos.str_hp);
    sfText_setString(s_all->s_statbox.hp_tx, "HP: ");
    sfText_setString(s_all->s_statbox.xp, s_all->s_infos.str_xp);
    sfText_setString(s_all->s_statbox.xp_tx, "XP: ");
    sfText_setString(s_all->s_statbox.lvl, s_all->s_infos.str_level);
    sfText_setString(s_all->s_statbox.lvl_tx, "LVL: ");
    sfText_setString(s_all->s_statbox.p_name, s_all->s_infos.p_name);
    sfText_setPosition(s_all->s_statbox.p_name, (sfVector2f){270, 370});
    sfText_setPosition(s_all->s_statbox.lvl_tx, (sfVector2f){270, 450});
    sfText_setPosition(s_all->s_statbox.lvl, (sfVector2f){350, 450});
    sfText_setPosition(s_all->s_statbox.hp_tx, (sfVector2f){270, 500});
}

void stat_text2(all_t *s_all)
{
    sfText_setCharacterSize(s_all->s_statbox.speed_tx, 20);
    sfText_setColor(s_all->s_statbox.speed_tx, sfWhite);
    sfText_setFont(s_all->s_statbox.speed_tx, s_all->s_statbox.font);
    sfText_setCharacterSize(s_all->s_statbox.speed, 20);
    sfText_setColor(s_all->s_statbox.speed, sfWhite);
    sfText_setFont(s_all->s_statbox.speed, s_all->s_statbox.font);
    sfText_setCharacterSize(s_all->s_statbox.sh_speed_tx, 20);
    sfText_setColor(s_all->s_statbox.sh_speed_tx, sfWhite);
    sfText_setFont(s_all->s_statbox.sh_speed_tx, s_all->s_statbox.font);
    sfText_setCharacterSize(s_all->s_statbox.sh_speed, 20);
    sfText_setColor(s_all->s_statbox.sh_speed, sfWhite);
    sfText_setFont(s_all->s_statbox.sh_speed, s_all->s_statbox.font);
    sfText_setPosition(s_all->s_statbox.speed_tx, (sfVector2f){270, 650});
    sfText_setPosition(s_all->s_statbox.speed, (sfVector2f){450, 650});
    sfText_setPosition(s_all->s_statbox.sh_speed_tx, (sfVector2f){270, 700});
    sfText_setPosition(s_all->s_statbox.sh_speed, (sfVector2f){450, 700});
    sfText_setCharacterSize(s_all->s_statbox.lvl_up, 40);
    sfText_setFont(s_all->s_statbox.lvl_up, s_all->s_statbox.font);
    sfText_setString(s_all->s_statbox.lvl_up, "  LEVEL UP\n+50 DAMAGE");
    sfText_setPosition(s_all->s_statbox.lvl_up, (sfVector2f){840, 200});
}

void init_stat_box(all_t *s_all)
{
    stat_create(s_all);
    sfRectangleShape_setFillColor(s_all->s_statbox.bg,
    (sfColor){56, 79, 88, 220});
    sfRectangleShape_setSize(s_all->s_statbox.bg, (sfVector2f) {269, 400});
    sfRectangleShape_setPosition(s_all->s_statbox.bg, (sfVector2f){250, 350});
    sfRectangleShape_setOutlineColor(s_all->s_statbox.bg1,
    (sfColor){35, 53, 63, 255});
    sfRectangleShape_setOutlineThickness(s_all->s_statbox.bg1, 1.0);
    sfRectangleShape_setFillColor(s_all->s_statbox.bg1, sfTransparent);
    sfRectangleShape_setSize(s_all->s_statbox.bg1, (sfVector2f) {249, 380});
    sfRectangleShape_setPosition(s_all->s_statbox.bg1, (sfVector2f){260, 360});
    stat_text(s_all), stat_text1(s_all), stat_text2(s_all);
    set_stat_text(s_all);
    sfText_setPosition(s_all->s_statbox.hp, (sfVector2f){340, 500});
    sfText_setPosition(s_all->s_statbox.dmg_tx, (sfVector2f){270, 550});
    sfText_setPosition(s_all->s_statbox.dmg, (sfVector2f){350, 550});
    sfText_setPosition(s_all->s_statbox.xp_tx, (sfVector2f){270, 600});
    sfText_setPosition(s_all->s_statbox.xp, (sfVector2f){340, 600});
}