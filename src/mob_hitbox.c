/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** mob_hitbox
*/

#include "rpg.h"

int mob_is_hit(all_t *s_all, mob_t *temp)
{
    sfFloatRect mob_rect, ver_rect, hor_rect;
    mob_rect = sfSprite_getGlobalBounds(temp->mob);
    ver_rect = sfSprite_getGlobalBounds(s_all->s_player.ver_shoot);
    hor_rect = sfSprite_getGlobalBounds(s_all->s_player.hor_shoot);
    if ((sfFloatRect_intersects(&mob_rect, &ver_rect, NULL)
        && s_all->s_player.ver == 1) ||
        (sfFloatRect_intersects(&mob_rect, &hor_rect, NULL)
        && s_all->s_player.hor == 1))
        return (1);
    return (0);
}

int player_is_hit(all_t *s_all, mob_t *temp)
{
    sfFloatRect mob_rect, shadow_rect, b_rect;
    if (temp->type == 'A') b_rect = sfSprite_getGlobalBounds(temp->bullet);
    mob_rect = sfSprite_getGlobalBounds(temp->mob);
    shadow_rect = sfSprite_getGlobalBounds(s_all->s_player.shadow);
    shadow_rect.top -= 12, shadow_rect.height += 12;
    b_mob_t *turret = temp->l_bullets;
    for (; temp->type == 'T' && turret != NULL; turret = turret->next) {
        b_rect = sfSprite_getGlobalBounds(turret->bullet);
        if (turret->hit != 1 &&
        sfFloatRect_intersects(&b_rect, &shadow_rect, NULL)) {
            turret->hit = 1;
            return (1);
        }
    } if (sfFloatRect_intersects(&mob_rect, &shadow_rect, NULL)) return (1);
    if (temp->type == 'A'
    && sfFloatRect_intersects(&b_rect, &shadow_rect, NULL)) {
        temp->hit = 1, sfSprite_setPosition(temp->bullet, (sfVector2f){
            temp->mob_pos.x - 4, temp->mob_pos.y - 8});
        return (1);
    } return (0);
}

void check_mob_hitboxes(all_t *s_all)
{
    if (s_all->s_game.pause == 1 || s_all->s_player.tp == 1) return;
    mob_t *temp = s_all->s_mob;
    while (temp != NULL) {
        if (mob_is_hit(s_all, temp)) {
            move_hit(s_all);
            move_explosion(s_all);
            temp->hp -= s_all->s_infos.dmg;
        }
        if (player_is_hit(s_all, temp) && s_all->s_infos.is_hit == 0)
            loosing_hp(s_all);
        if (temp->hp <= 0) {
            s_all->s_infos.current_xp += temp->xp;
            temp->status = -1, update_xp(s_all);
            if (temp->type != 'B') sfSound_play(s_all->s_sounds.blast);
            else sfSound_play(s_all->s_sounds.hit);
        }
        temp = temp->next;
    }
}