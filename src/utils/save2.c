/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** save2
*/

#include "rpg.h"

void load4(all_t *s_all)
{
    sfSprite_setPosition(s_all->s_tp.tp_shadow,
        (sfVector2f){s_all->s_tp.tp_pos.x, s_all->s_tp.tp_pos.y + 7});
    sfRectangleShape_setPosition(s_all->s_tp.beam,
        (sfVector2f){s_all->s_tp.tp_pos.x + 16, s_all->s_tp.tp_pos.y + 19});
    sfSprite_setPosition(s_all->s_effect.tp_glow,
        (sfVector2f){s_all->s_tp.tp_pos.x - 190, s_all->s_tp.tp_pos.y - 195});
    color_hp(s_all);
    s_all->s_game.tp_chat = 0;
    s_all->s_game.stage_script = s_all->s_map.stage + 1;
    if (s_all->s_cine.script >= 2) s_all->s_sounds.fat_bool = 1;
    else s_all->s_sounds.fat_bool = 0;
    s_all->s_npc.talk = 0;
}

void load3(all_t *s_all)
{
    s_all->s_chest = fill_chests(NULL, s_all, (sfVector2f){s_all->s_player.
    shadow_pos.x + 65, s_all->s_player.shadow_pos.y - 117});
    s_all->s_player.hero_pos = s_all->s_player.save_pos;
    sfSprite_setPosition(s_all->s_player.hero, s_all->s_player.save_pos);
    s_all->s_player.shadow_pos = (sfVector2f){s_all->s_player.hero_pos.x + 4,
        s_all->s_player.hero_pos.y + 25};
    sfSprite_setPosition(s_all->s_player.shadow, s_all->s_player.shadow_pos);
    s_all->s_player.shoot_pos = (sfVector2f){s_all->s_player.hero_pos.x + 11,
    s_all->s_player.hero_pos.y + 20};
    sfSprite_setPosition(s_all->s_player.ver_shoot, s_all->s_player.shoot_pos);
    sfSprite_setPosition(s_all->s_player.hor_shoot, s_all->s_player.shoot_pos);
    s_all->s_game.pause = 0, s_all->s_cine.move = 0;
    s_all->s_player.hero_rect.left = 406, s_all->s_player.hero_rect.top = 109;
    s_all->s_player.hero_rect.height = 31;
    sfSprite_setTextureRect(s_all->s_player.hero, s_all->s_player.hero_rect);
    s_all->s_tp.tp_pos = (sfVector2f){935, 322};
    sfSprite_setPosition(s_all->s_tp.tp, s_all->s_tp.tp_pos);
    load4(s_all);
}