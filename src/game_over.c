/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_over
*/

#include "rpg.h"

void game_over_check(all_t *s_all)
{
    if (s_all->s_infos.current_hp <= 0) {
        sfSound_play(s_all->s_sounds.dead);
        sfSprite_setPosition(s_all->s_dead.dead, s_all->s_player.hero_pos);
        s_all->s_game.scene = GAME_OVER;
        sfSprite_setColor(s_all->s_dead.dead, s_all->s_custom.p_color);
        s_all->s_movement.left = 0;
        s_all->s_movement.right = 0;
        s_all->s_movement.down = 0;
        s_all->s_movement.up = 0;
        s_all->s_infos.current_hp = 1;
        sfRectangleShape_setFillColor(s_all->s_tp.black,
            (sfColor){150, 30, 30, 100});
    }
    respawn(s_all);
}

void lose_xp(all_t *s_all)
{
    if (s_all->s_infos.current_xp >= 60)
        s_all->s_infos.current_xp -= 60;
    else
        s_all->s_infos.current_xp = 0;
    update_xp(s_all);
}

void respawn(all_t *s_all)
{
    if (s_all->s_game.scene == GAME_OVER) {
        if (is_key_released(&s_all->s_game.event, sfKeyR)) {
            gaining_hp(s_all, 60), lose_xp(s_all);
            s_all->s_map.stage = 0, s_all->s_game.tp_chat = 0;
            s_all->s_game.stage_script = 1;
            s_all->s_tp.tp_pos = (sfVector2f){s_all->s_player.hero_pos.x,
            s_all->s_player.hero_pos.y + 17};
            sfSprite_setPosition(s_all->s_tp.tp, s_all->s_tp.tp_pos);
            sfSprite_setPosition(s_all->s_tp.tp_shadow,
            (sfVector2f){s_all->s_tp.tp_pos.x, s_all->s_tp.tp_pos.y + 7});
            sfRectangleShape_setPosition(s_all->s_tp.beam,
            (sfVector2f){s_all->s_tp.tp_pos.x + 16,
            s_all->s_tp.tp_pos.y + 19});
            sfSprite_setPosition(s_all->s_effect.tp_glow,
            (sfVector2f){s_all->s_tp.tp_pos.x - 185,
            s_all->s_tp.tp_pos.y - 190});
        }
    }
}

void display_game_over(all_t *s_all)
{
    if (s_all->s_game.scene == GAME_OVER) {
        sfRenderWindow_drawText(s_all->s_game.window,
            s_all->s_infos.game_over, NULL);
        sfRenderWindow_drawText(s_all->s_game.window,
            s_all->s_dead.respawn, NULL);
    }
}