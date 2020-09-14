/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_hp
*/

#include "rpg.h"

void color_hp(all_t *s_all)
{
    sfRectangleShape_setFillColor(s_all->s_infos.hp,
        (sfColor){255, 20, 0, 255});
    if (s_all->s_infos.current_hp >= s_all->s_infos.max_hp / 5 * 1)
        sfRectangleShape_setFillColor(s_all->s_infos.hp,
        (sfColor){255, 100, 0, 255});
    if (s_all->s_infos.current_hp >= s_all->s_infos.max_hp / 5 * 2)
        sfRectangleShape_setFillColor(s_all->s_infos.hp,
        (sfColor){230, 190, 0, 255});
    if (s_all->s_infos.current_hp >= s_all->s_infos.max_hp / 5 * 3)
        sfRectangleShape_setFillColor(s_all->s_infos.hp,
        (sfColor){120, 190, 0, 255});
    if (s_all->s_infos.current_hp >= s_all->s_infos.max_hp / 5 * 4)
        sfRectangleShape_setFillColor(s_all->s_infos.hp,
        (sfColor){0, 190, 0, 255});
}

void heal_hp(all_t *s_all)
{
    color_hp(s_all);
    sfSound_play(s_all->s_sounds.heart);
    if (s_all->s_infos.str_hp != NULL) free(s_all->s_infos.str_hp);
    s_all->s_infos.str_hp = malloc(sizeof(char) * 20);
    s_all->s_infos.str_hp[0] = '\0';
    my_strcat(s_all->s_infos.str_hp, strnbr(s_all->s_infos.current_hp));
    my_strcat(s_all->s_infos.str_hp, "/");
    my_strcat(s_all->s_infos.str_hp, strnbr(s_all->s_infos.max_hp));
    sfText_setString(s_all->s_infos.hp_txt, s_all->s_infos.str_hp);
    float size = 250.0 / s_all->s_infos.max_hp * s_all->s_infos.current_hp;
    sfRectangleShape_setSize(s_all->s_infos.hp, (sfVector2f){size, 20});
}

void loosing_hp(all_t *s_all)
{
    sfSound_play(s_all->s_sounds.player);
    s_all->s_infos.is_hit = 1;
    sfClock_restart(s_all->s_infos.clock);
    s_all->s_infos.current_hp -= 20;
    if (s_all->s_infos.current_hp < 0) s_all->s_infos.current_hp = 0;
    color_hp(s_all);
    if (s_all->s_infos.str_hp != NULL) free(s_all->s_infos.str_hp);
    s_all->s_infos.str_hp = malloc(sizeof(char) * 20);
    s_all->s_infos.str_hp[0] = '\0';
    my_strcat(s_all->s_infos.str_hp, strnbr(s_all->s_infos.current_hp));
    my_strcat(s_all->s_infos.str_hp, "/");
    my_strcat(s_all->s_infos.str_hp, strnbr(s_all->s_infos.max_hp));
    sfText_setString(s_all->s_infos.hp_txt, s_all->s_infos.str_hp);
    float size = 250.0 / s_all->s_infos.max_hp * s_all->s_infos.current_hp;
    sfRectangleShape_setSize(s_all->s_infos.hp, (sfVector2f){size, 20});
}

void gaining_hp(all_t *s_all, int hp)
{
    s_all->s_infos.current_hp += hp;
    color_hp(s_all);
    if (s_all->s_infos.str_hp != NULL) free(s_all->s_infos.str_hp);
    s_all->s_infos.str_hp = malloc(sizeof(char) * 20);
    s_all->s_infos.str_hp[0] = '\0';
    my_strcat(s_all->s_infos.str_hp, strnbr(s_all->s_infos.current_hp));
    my_strcat(s_all->s_infos.str_hp, "/");
    my_strcat(s_all->s_infos.str_hp, strnbr(s_all->s_infos.max_hp));
    sfText_setString(s_all->s_infos.hp_txt, s_all->s_infos.str_hp);
    float size = 250.0 / s_all->s_infos.max_hp * s_all->s_infos.current_hp;
    sfRectangleShape_setSize(s_all->s_infos.hp, (sfVector2f){size, 20});
}

void player_immunity(all_t *s_all)
{
    sfColor color = sfSprite_getColor(s_all->s_player.hero);
    if (s_all->s_infos.seconds >= 1 && s_all->s_infos.is_hit == 1) {
        s_all->s_infos.is_hit = 0;
        color.a = 255;
        sfSprite_setColor(s_all->s_player.hero, color);
        sfSprite_setColor(s_all->s_player.gun,
            (sfColor){255, 255, 255, color.a});
    } else if (s_all->s_infos.is_hit == 1 && s_all->s_infos.hit_sec > 0.01) {
        if (s_all->s_infos.is_color == 0) color.a -= 20;
        else if (s_all->s_infos.is_color == 1) color.a += 20;
        sfSprite_setColor(s_all->s_player.hero, color);
        sfSprite_setColor(s_all->s_player.gun,
            (sfColor){255, 255, 255, color.a});
        if (color.a < 100) s_all->s_infos.is_color = 1;
        if (color.a >= 255) s_all->s_infos.is_color = 0;
        sfClock_restart(s_all->s_infos.hit_clk);
    }
}