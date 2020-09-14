/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_mobs
*/

#include "rpg.h"

void fill_mob2(mob_t *new)
{
    new->refresh_clk = sfClock_create();
    sfSprite_setTextureRect(new->mob, new->rect);
    sfSprite_setPosition(new->mob, new->mob_pos);
    sfSprite_setPosition(new->shadow, new->shadow_pos);
}

void mob_selector(mob_t *new, char type, sfVector2f pos, all_t *s_all)
{
    sfSprite_setTextureRect(new->shadow, (sfIntRect){55, 69, 20, 6});
    sfSprite_setOrigin(new->shadow, (sfVector2f){10, 3});
    if (type == 'B') {
        new->mob_pos.x += 9, new->mob_pos.y += 9, new->speed = 2;
        new->shadow_pos = (sfVector2f){pos.x + 10, pos.y + 17};
        new->rect = (sfIntRect){0, 57, 18, 17};
        sfSprite_setOrigin(new->mob, (sfVector2f){9, 9});
        new->xp = 10, new->hp = 150;
    }
    turret_init(new, type, s_all);
    roballs(new, type, pos, s_all);
}

mob_t *fill_mob(mob_t *old, char type, sfVector2f pos, all_t *s_all)
{
    mob_t *new = malloc(sizeof(mob_t));
    new->mob_pos = pos, new->check_shoot = 0, new->hit = 0;
    new->aggro = 0, new->shoot = 0, new->bullet_speed = 4;
    new->x = s_all->s_mob_pos.x, new->y = s_all->s_mob_pos.y;
    new->clock = sfClock_create(), new->rect_clock = sfClock_create();
    new->shoot_clock = sfClock_create(), new->bullet_travel = 0;
    new->mob = sfSprite_create(), new->shadow = sfSprite_create();
    new->mob_txt = s_all->s_player.hero_tx, new->seconds = 0;
    new->shadow_tx = s_all->s_player.hero_tx, new->prev = '@';
    new->path = breadth_first_search_entity(s_all->s_map.map,
    s_all, new->x, new->y), new->hor = 32, new->ver = 26;
    new->status = 0, new->rect_seconds = 0;
    sfSprite_setTexture(new->mob, new->mob_txt, sfTrue);
    sfSprite_setTexture(new->shadow, new->shadow_tx, sfTrue);
    mob_selector(new, type, pos, s_all);
    new->type = type, new->next = old;
    fill_mob2(new), init_mob_interface(new, type, s_all);
    new->shoot_seconds = 0.0;
    return (new);
}

void move_mobs_rect(mob_t *mob, int max, int offset, int reset)
{
    if (mob->rect.left != max)
        mob->rect.left += offset;
    else mob->rect.left = reset;
    sfSprite_setTextureRect(mob->mob, mob->rect);
    sfClock_restart(mob->rect_clock);
}

void display_mobs(all_t *s_all)
{
    mob_t *temp = s_all->s_mob;
    for (; temp != NULL; temp = temp->next) {
        if (s_all->s_player.hero_pos.y + 20 > temp->mob_pos.y) continue;
        float magnitude = calcul_mob_magnitude(temp, s_all->s_player.shadow);
        if (magnitude <= 150 && s_all->s_player.tp == 0) {
            temp->aggro = 1;
            sfText_setColor(temp->text, (sfColor){255, 20, 20, 255});
        } if (temp->seconds > 0.01 && temp->aggro == 1
        && s_all->s_player.tp == 0)
            search_mob_path(temp, s_all);
        if (temp->rect_seconds > 0.1 && temp->type == 'B' && temp->aggro == 1
        && s_all->s_player.tp == 0 && s_all->s_game.pause != 1)
            move_mobs_rect(temp, 36, 18, 0);
        if (temp->rect_seconds > 0.1 && temp->type == 'A' && temp->aggro == 1
        && s_all->s_player.tp == 0 && s_all->s_game.pause != 1)
            move_mobs_rect(temp, 100, 12, 88);
        display_mobs2(temp, s_all);
    } check_mob_hitboxes(s_all);
    turret(s_all);
}