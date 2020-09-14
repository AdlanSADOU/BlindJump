/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** tp_anim
*/

#include "rpg.h"

sfVector2f find_tp_spawn(all_t *s_all)
{
    int count = 0;
    for (int i = 0; s_all->s_map.map[i] != NULL; i++)
        for (int j = 0; s_all->s_map.map[i][j] != '\0'; j++)
            if (s_all->s_map.map[i][j] == '0')
                count++;
    int random = 1 + rand() % (count - 1);
    count = 0;
    sfVector2f pos = {0, 0};
    for (int i = 0; s_all->s_map.map[i] != NULL; i++, pos.y += 26, pos.x = 0)
        for (int j = 0; s_all->s_map.map[i][j] != '\0'; j++, pos.x += 32) {
            if (s_all->s_map.map[i][j] == '0')
                count++;
            if (count == random) {
                s_all->s_map.map[i][j] = 'P';
                s_all->s_player.y = i;
                s_all->s_player.x = j;
                return ((sfVector2f) {pos.x + 6, pos.y - 15});
            }
        }
    return (pos);
}

void tp_animation4(all_t *s_all, int *alpha)
{
    if (s_all->s_tp.anim == 3 && s_all->s_player.tp == 1) {
        free_hearth(s_all), generate_random_map(s_all), s_all->s_tp.anim = 4;
        s_all->s_sounds.fat_bool = 0;
        sfSprite_setPosition(s_all->s_player.hero, s_all->s_player.hero_pos);
        s_all->s_player.shoot_pos = (sfVector2f)
        {s_all->s_player.hero_pos.x + 11, s_all->s_player.hero_pos.y + 20};
        sfSprite_setPosition(s_all->s_player.ver_shoot, s_all->s_player.
        shoot_pos), sfSprite_setPosition(s_all->s_player.hor_shoot,
        s_all->s_player.shoot_pos), s_all->s_game.scene = MAP;
        generate_random_mobs(s_all), init_minimap(s_all);
    } if (s_all->s_tp.anim == 4 && s_all->s_player.tp == 1) {
        *alpha -= 5;
        sfRectangleShape_setFillColor(s_all->s_tp.black,
            (sfColor){0, 0, 0, *alpha});
        if (*alpha <= 40) {
            s_all->s_tp.anim = 0, s_all->s_player.tp = 0;
            s_all->s_minimap.dispay_tp = 0, s_all->s_dead.rect.left = 209;
            s_all->s_dead.fuck = 0;
        }
    }
}

void tp_animation3(all_t *s_all)
{
    static int alpha = 0;
    if (s_all->s_tp.width >= 20 && s_all->s_tp.anim == 1) s_all->s_tp.anim = 2;
    if (s_all->s_tp.anim == 2 && s_all->s_tp.width > 0) {
        s_all->s_tp.width -= 1;
        sfRectangleShape_setOrigin(s_all->s_tp.beam,
            (sfVector2f){s_all->s_tp.width / 2, s_all->s_tp.height});
    } if (s_all->s_tp.width <= 0 && s_all->s_tp.anim == 2) {
        alpha += 5, sfRectangleShape_setFillColor(s_all->s_tp.black,
            (sfColor){0, 0, 0, alpha});
        if (alpha >= 255) {
            s_all->s_tp.anim = 3;
            if (s_all->s_cine.script < 7) s_all->s_game.tp_chat = 1;
            s_all->s_stars.pos = (sfVector2f){-128 * 15, -128 * 15};
            s_all->s_stars.pos2 = (sfVector2f){-128 * 15, -128 * 15};
            sfSprite_setPosition(s_all->s_stars.front, s_all->s_stars.pos);
            sfSprite_setPosition(s_all->s_stars.back, s_all->s_stars.pos2);
        }
    } tp_animation4(s_all, &alpha), sfRectangleShape_setSize(s_all->s_tp.beam,
        (sfVector2f){s_all->s_tp.width, s_all->s_tp.height});
}

void tp_animation2(all_t *s_all)
{
    if (s_all->s_player.tp == 1 && s_all->s_tp.tp_seconds >= 0.01) {
        if (s_all->s_tp.anim == 0 && s_all->s_tp.alpha < 240) {
            s_all->s_tp.alpha += 10;
            s_all->s_tp.height += 10;
            sfRectangleShape_setOrigin(s_all->s_tp.beam,
                (sfVector2f){1, s_all->s_tp.height});
            sfRectangleShape_setFillColor(s_all->s_tp.beam,
                (sfColor){120, 255, 242, s_all->s_tp.alpha});
        } if (s_all->s_tp.anim == 0 && s_all->s_tp.alpha >= 240) {
            s_all->s_tp.anim = 1;
            sfRectangleShape_setFillColor(s_all->s_tp.beam,
                (sfColor){120, 255, 242, 255});
        }
        if (s_all->s_tp.anim == 1 && s_all->s_tp.width < 20) {
            s_all->s_tp.width += 2;
            sfRectangleShape_setOrigin(s_all->s_tp.beam,
                (sfVector2f){s_all->s_tp.width / 2, s_all->s_tp.height});
        } tp_animation3(s_all);
        sfClock_restart(s_all->s_tp.tp_clock);
    }
}

void tp_animation(all_t *s_all)
{
    if (s_all->s_game.tp_chat == 0 &&
    hitbox_tp(s_all) == 1 && s_all->s_player.tp == 0
    && (s_all->s_game.scene == SPAWN || s_all->s_game.scene == MAP
    || s_all->s_game.scene == GAME_OVER)) {
        if (s_all->s_map.stage == 5 && s_all->s_cine.script == 6
        && s_all->s_game.nb != 0) return;
        sfSound_play(s_all->s_sounds.tp);
        s_all->s_player.tp = 1, s_all->s_map.stage += 1;
        if (s_all->s_game.scene != GAME_OVER) {
            s_all->s_player.hero_rect.left = 406;
            s_all->s_player.hero_rect.top = 109;
            s_all->s_player.hero_rect.height = 31;
        } sfSprite_setTextureRect(s_all->s_player.hero,
        s_all->s_player.hero_rect);
        s_all->s_player.hero_pos = (sfVector2f){s_all->s_tp.tp_pos.x + 6,
            s_all->s_tp.tp_pos.y - 17};
        sfSprite_setPosition(s_all->s_player.hero, s_all->s_player.hero_pos);
        sfRectangleShape_setPosition(s_all->s_player.debug,
            s_all->s_player.hero_pos);
    } tp_animation2(s_all);
}