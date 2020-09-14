/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** turret
*/

#include "rpg.h"

void turret_init(mob_t *new, char type, all_t *s_all)
{
    if (type == 'T') {
        new->speed = 0, new->rect = (sfIntRect){0, 0, 16, 32};
        new->xp = 20, new->hp = 400, new->path = NULL;
        sfSprite_setOrigin(new->mob, (sfVector2f){8, 15});
        new->shadow_pos = (sfVector2f){new->mob_pos.x + 2,
            new->mob_pos.y + 7};
        sfSprite_setTextureRect(new->shadow, (sfIntRect){0, 32, 16, 24});
        b_mob_t *old = NULL;
        for (int i = 0; i != 8; i++) {
            b_mob_t *tmp = malloc(sizeof(b_mob_t));
            tmp->bullet = sfSprite_create();
            sfSprite_setTexture(tmp->bullet, s_all->s_player.hero_tx, sfTrue);
            sfSprite_setTextureRect(tmp->bullet, (sfIntRect){13, 89, 10, 10});
            sfSprite_setPosition(tmp->bullet, (sfVector2f){new->mob_pos.x,
            new->mob_pos.y - 10});
            sfSprite_setOrigin(tmp->bullet, (sfVector2f){5, 5});
            tmp->hit = 0, tmp->bullet_speed = 3, tmp->check_shoot = 0;
            tmp->pos = new->mob_pos, tmp->next = old, old = tmp;
        } new->l_bullets = old;
    }
}

void turret_rect(mob_t *temp)
{
    if (temp->aggro == 1 && temp->rect_seconds > 0.05) {
        if (temp->rect.left < 64) {
            temp->rect.left += 16;
            sfSprite_setTextureRect(temp->mob, temp->rect);
            sfClock_restart(temp->rect_clock);
        }
    }
    else if (temp->aggro == 0 && temp->rect_seconds > 0.05) {
        if (temp->rect.left > 0) {
            temp->rect.left -= 16;
            sfSprite_setTextureRect(temp->mob, temp->rect);
            sfClock_restart(temp->rect_clock);
        }
    }
}

sfVector2f turret_if_forest(int i, sfVector2f aim_pos)
{
    if (i == 0) aim_pos.y -= 10;
    if (i == 1) aim_pos.y -= 5, aim_pos.x += 5;
    if (i == 2) aim_pos.x += 10;
    if (i == 3) aim_pos.x += 5, aim_pos.y += 5;
    if (i == 4) aim_pos.y += 10;
    if (i == 5) aim_pos.y += 5, aim_pos.x -= 5;
    if (i == 6) aim_pos.x -= 10;
    if (i == 7) aim_pos.x -= 5, aim_pos.y -= 5;
    return (aim_pos);
}

void turret_aim(int i, mob_t *temp, b_mob_t *bullet)
{
    if (temp->type == 'T' && temp->shoot_seconds < 0.01) return;
    if (temp->type != 'T') return;
    if (temp->shoot == 1) {
        temp->check_shoot = 1;
        sfVector2f bullet_pos = sfSprite_getPosition(bullet->bullet);
        if (bullet->check_shoot == 0) {
            sfVector2f aim_pos = bullet_pos;
            aim_pos = turret_if_forest(i, aim_pos);
            bullet->vx = aim_pos.x - bullet_pos.x;
            bullet->vy = aim_pos.y - bullet_pos.y;
            bullet->normalize = sqrt(pow(bullet->vx, 2) + pow(bullet->vy, 2));
            bullet->check_shoot = 1;
        } bullet_pos.x = bullet_pos.x
        + (bullet->bullet_speed * (bullet->vx / bullet->normalize));
        bullet_pos.y = bullet_pos.y
        + (bullet->bullet_speed * (bullet->vy / bullet->normalize));
        sfSprite_setPosition(bullet->bullet, bullet_pos);
        temp->bullet_travel++;
        sfClock_restart(temp->shoot_clock);
    }
}

void turret(all_t *s_all)
{
    mob_t *temp = s_all->s_mob;
    for (; temp != NULL; temp = temp->next) {
        if (temp->type != 'T') continue;
        if (s_all->s_game.pause == 0 && s_all->s_game.scene != GAME_OVER) {
            float magnitude = calcul_mob_magnitude(temp,
            s_all->s_player.shadow);
            if (magnitude > 150) {
                temp->aggro = 0;
                sfText_setColor(temp->text, (sfColor){255, 255, 255, 255});
            } turret_rect(temp);
            if (temp->aggro == 1 && temp->rect.left >= 64
            && temp->check_shoot == 0) temp->shoot = 1;
        }
        turret_loop(s_all, temp);
    }
}