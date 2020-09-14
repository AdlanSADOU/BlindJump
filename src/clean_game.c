/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clean_game
*/

#include "rpg.h"

void free_chest(all_t *s_all)
{
    chest_t *tmp = s_all->s_chest;
    chest_t *old = NULL;
    while (tmp != NULL) {
        sfSprite_destroy(tmp->shadow);
        sfSprite_destroy(tmp->sprite);
        sfClock_destroy(tmp->clock);
        sfText_destroy(tmp->open_txt);
        old = tmp;
        tmp = tmp->next;
        free(old);
    }
    s_all->s_chest = NULL;
}

void free_inventory(all_t *s_all)
{
    slots_t *tmp = s_all->s_inventory.head;
    while (tmp != NULL) {
        sfSprite_destroy(tmp->item);
        tmp->item = sfSprite_create();
        tmp->dmg = 0;
        tmp->drag = 0;
        tmp->health = 0;
        tmp->is_item = 0;
        tmp = tmp->next;
    }
    s_all->s_inventory.dragged = NULL;
}

void clean_game3(all_t *s_all)
{
    rgb_t *tmp = s_all->s_rgb;
    for (int i = 0; tmp != NULL; tmp = tmp->next, i++) {
        if (i == 0) sfSprite_setPosition(tmp->cursor, (sfVector2f){1075, 600});
        if (i == 1) sfSprite_setPosition(tmp->cursor, (sfVector2f){1075, 650});
        if (i == 2) sfSprite_setPosition(tmp->cursor, (sfVector2f){1075, 700});
        tmp->value = 255;
    } s_all->s_custom.p_color = (sfColor){255, 255, 255, 255};
    sfSprite_setColor(s_all->s_custom.hero, s_all->s_custom.p_color);
    s_all->s_chatbox.buff[0] = '\0';
    s_all->s_chatbox.op = 0, s_all->s_chatbox.idx = 0;
    s_all->s_chatbox.car = 0;
    s_all->s_sounds.fat_bool = 0;
}

void clean_game2(all_t *s_all)
{
    s_all->s_infos.level = 1, s_all->s_game.key_press = 0;
    sfText_setString(s_all->s_infos.lvl_txt, "Level 1");
    sfText_setString(s_all->s_infos.xp_txt, "0/100");
    sfRectangleShape_setSize(s_all->s_infos.xp, (sfVector2f){3, 20});
    sfText_setString(s_all->s_infos.hp_txt, "100/100");
    sfRectangleShape_setSize(s_all->s_infos.hp, (sfVector2f){250, 20});
    s_all->s_map.stage = 0, sfText_setString(s_all->s_statbox.xp, "0/100");
    s_all->s_infos.str_xp = malloc(sizeof(char) * 20);
    s_all->s_infos.str_xp[0] = '\0', s_all->s_infos.current_hp = 100;
    my_strcat(s_all->s_infos.str_xp, "0/100"), s_all->s_spawn.open = 0;
    sfSprite_setTextureRect(s_all->s_spawn.door, (sfIntRect){0, 0, 200, 100});
    load3(s_all), s_all->s_game.display_inv = 0, color_hp(s_all);
    clean_game3(s_all);
}

void clean_game(all_t *s_all)
{
    s_all->s_game.pause = 0;
    free_chest(s_all);
    free_inventory(s_all);
    destroy_mobs(s_all);
    sfText_setPosition(s_all->s_infos.p_name_txt, (sfVector2f){775, 182});
    sfText_setString(s_all->s_infos.p_name_txt, "");
    free(s_all->s_infos.p_name);
    s_all->s_infos.p_name = malloc(sizeof(char) * 20);
    s_all->s_infos.p_name[0] = '\0';
    s_all->s_custom.pos = (sfVector2f){777, 184};
    sfSprite_setPosition(s_all->s_custom.sprite, s_all->s_custom.pos);
    sfText_setFont(s_all->s_infos.p_name_txt, s_all->s_game.monospaced);
    s_all->s_custom.p_color = (sfColor){255, 255, 255, 255};
    s_all->s_cine.door = 0, s_all->s_cine.script = 0, s_all->s_cine.count = 0;
    s_all->s_cine.cinematic = 0, s_all->s_cine.move = 0;
    s_all->s_cine.tuto = 1, s_all->s_npc.talk = 0, s_all->s_game.chat = 0;
    s_all->s_infos.dmg = 50, s_all->s_infos.max_hp = 100;
    s_all->s_infos.max_hp_save = 100, s_all->s_infos.save_dmg = 50;
    s_all->s_infos.current_xp = 0, s_all->s_infos.max_xp = 100;
    clean_game2(s_all), s_all->s_npc.talk = 0;
}