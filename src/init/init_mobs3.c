/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_mobs3
*/

#include "rpg.h"

void display_mobs3(mob_t *temp, all_t *s_all)
{
    if (temp->type == 'A' && s_all->s_game.pause == 0) {
        if (temp->bullet_travel >= 100) {
            sfSprite_setPosition(temp->bullet, (sfVector2f)
            {temp->mob_pos.x - 4, temp->mob_pos.y- 8}), temp->hit = 0;
            temp->check_shoot = 0, temp->bullet_travel = 0;
        } if (temp->aggro == 1
        && calcul_mob_magnitude(temp, s_all->s_player.shadow) <= 220) {
            temp->shoot = 1;
        } else temp->shoot = 0;
        if (calcul_mob_magnitude(temp, s_all->s_player.shadow) >= 220
        && temp->check_shoot == 0)
            sfSprite_setPosition(temp->bullet, (sfVector2f)
            {temp->mob_pos.x - 4, temp->mob_pos.y- 8});
        roballs_shoot(temp, s_all);
    } if (temp->check_shoot == 0 || temp->hit == 1 || temp->type != 'A') return;
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->bullet, NULL);
}

void display_turret_bullet(all_t *s_all, mob_t *temp)
{
    b_mob_t *bullet = temp->l_bullets;
    for (; bullet != NULL; bullet = bullet->next) {
        if (temp->check_shoot == 1 && bullet->hit == 0)
            sfRenderWindow_drawSprite(s_all->s_game.window,
            bullet->bullet, NULL);
    }
}

void display_mobs_death_under(all_t *s_all)
{
    mob_t *temp = s_all->s_mob;
    for (; temp != NULL; temp = temp->next) {
        if (s_all->s_player.hero_pos.y + 20 <= temp->mob_pos.y) continue;
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->shadow, NULL);
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->mob, NULL);
        if (temp->type == 'A' && temp->hit == 0 && temp->check_shoot == 1)
            sfRenderWindow_drawSprite(s_all->s_game.window,
            temp->bullet, NULL);
        if (temp->type == 'T')
            display_turret_bullet(s_all, temp);
    }
}

void display_mobs_death_over(all_t *s_all)
{
    mob_t *temp = s_all->s_mob;
    for (; temp != NULL; temp = temp->next) {
        if (s_all->s_player.hero_pos.y + 20 > temp->mob_pos.y) continue;
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->shadow, NULL);
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->mob, NULL);
        if (temp->type == 'A' && temp->hit == 0 && temp->check_shoot == 1)
            sfRenderWindow_drawSprite(s_all->s_game.window,
            temp->bullet, NULL);
        if (temp->type == 'T')
            display_turret_bullet(s_all, temp);
    }
}

void display_mobs4(all_t *s_all)
{
    mob_t *temp = s_all->s_mob;
    for (; temp != NULL; temp = temp->next) {
        if (s_all->s_player.hero_pos.y + 20 <= temp->mob_pos.y) continue;
        float magnitude = calcul_mob_magnitude(temp, s_all->s_player.shadow);
        if (magnitude <= 150 && s_all->s_player.tp == 0) {
            temp->aggro = 1;
            sfText_setColor(temp->text, (sfColor){255, 20, 20, 255});
        } if (temp->seconds > 0.01 && temp->aggro == 1
        && s_all->s_player.tp == 0) search_mob_path(temp, s_all);
        if (temp->rect_seconds > 0.1 && temp->type == 'B' && temp->aggro == 1
        && s_all->s_player.tp == 0 && s_all->s_game.pause != 1)
            move_mobs_rect(temp, 36, 18, 0);
        if (temp->rect_seconds > 0.1 && temp->type == 'A' && temp->aggro == 1
        && s_all->s_player.tp == 0 && s_all->s_game.pause != 1)
            move_mobs_rect(temp, 100, 12, 88);
        display_mobs2(temp, s_all);
    }
}