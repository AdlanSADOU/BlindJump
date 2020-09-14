/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** stat_box
*/

#include "rpg.h"

void set_stat_text(all_t *s_all)
{
    sfText_setString(s_all->s_statbox.speed, s_all->s_statbox.speed_str);
    sfText_setString(s_all->s_statbox.speed_tx, "MOVE SPEED: ");
    sfText_setString(s_all->s_statbox.sh_speed, s_all->s_statbox.sh_speed_str);
    sfText_setString(s_all->s_statbox.sh_speed_tx, "RELOAD SPEED: ");
}

void update_statbox(all_t *s_all)
{
    free(s_all->s_statbox.dmg_str), s_all->s_statbox.dmg_str =
    strnbr(s_all->s_infos.dmg);
    free(s_all->s_statbox.lvl_str), s_all->s_statbox.lvl_str =
    strnbr(s_all->s_infos.level);
    free(s_all->s_statbox.speed_str), s_all->s_statbox.speed_str =
    strnbr(s_all->s_player.hero_speed);
    free(s_all->s_statbox.sh_speed_str), s_all->s_statbox.sh_speed_str =
    strnbr_float(s_all->s_infos.atk_speed), free(s_all->s_statbox.hp_str);
    s_all->s_statbox.hp_str = malloc(25), s_all->s_statbox.hp_str[0] = '\0';
    my_strcat(s_all->s_statbox.hp_str, strnbr(s_all->s_infos.current_hp));
    my_strcat(s_all->s_statbox.hp_str, "/");
    my_strcat(s_all->s_statbox.hp_str, strnbr(s_all->s_infos.max_hp));
    sfText_setString(s_all->s_statbox.dmg, s_all->s_statbox.dmg_str);
    sfText_setString(s_all->s_statbox.hp, s_all->s_statbox.hp_str);
    sfText_setString(s_all->s_statbox.xp, s_all->s_infos.str_xp);
    sfText_setString(s_all->s_statbox.lvl, s_all->s_statbox.lvl_str);
    sfText_setString(s_all->s_statbox.p_name, s_all->s_infos.p_name);
    sfText_setString(s_all->s_statbox.speed, s_all->s_statbox.speed_str);
    sfText_setString(s_all->s_statbox.sh_speed, s_all->s_statbox.sh_speed_str);
}

void draw_stats1(all_t *s_all)
{
    sfRenderWindow_drawText(s_all->s_game.window, s_all->s_statbox.hp, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
    s_all->s_statbox.dmg_tx, NULL);
    sfRenderWindow_drawText(s_all->s_game.window, s_all->s_statbox.dmg, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
    s_all->s_statbox.xp_tx, NULL);
    sfRenderWindow_drawText(s_all->s_game.window, s_all->s_statbox.xp, NULL);
    sfRenderWindow_drawText(s_all->s_game.window, s_all->s_statbox.speed,
    NULL);
    sfRenderWindow_drawText(s_all->s_game.window, s_all->s_statbox.sh_speed,
    NULL);
    sfRenderWindow_drawText(s_all->s_game.window, s_all->s_statbox.speed_tx,
    NULL);
    sfRenderWindow_drawText(s_all->s_game.window, s_all->s_statbox.sh_speed_tx,
    NULL);
}

void draw_stats(all_t *s_all)
{
    update_statbox(s_all);
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
    s_all->s_statbox.bg, NULL);
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
    s_all->s_statbox.bg1, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
    s_all->s_statbox.p_name, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
    s_all->s_statbox.lvl_tx, NULL);
    sfRenderWindow_drawText(s_all->s_game.window, s_all->s_statbox.lvl, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
    s_all->s_statbox.hp_tx, NULL);
    draw_stats1(s_all);
}