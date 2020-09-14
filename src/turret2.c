/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** turret2
*/

#include "rpg.h"

void turret_inside_loop(mob_t *temp, b_mob_t *bullet, int i)
{
    turret_aim(i, temp, bullet);
    if (temp->bullet_travel >= 650) {
        b_mob_t *reset = temp->l_bullets;
        for (; reset != NULL; reset = reset->next) {
            reset->check_shoot = 0, reset->hit = 0;
            sfSprite_setPosition(reset->bullet,
            (sfVector2f){temp->mob_pos.x, temp->mob_pos.y - 10});
        }
    }
}

void turret_loop(all_t *s_all, mob_t *temp)
{
    b_mob_t *bullet = temp->l_bullets;
    for (int i = 0; bullet != NULL; bullet = bullet->next, i++) {
        if (s_all->s_game.pause == 0 && s_all->s_game.scene != GAME_OVER) {
        turret_inside_loop(temp, bullet, i);
        if (temp->bullet_travel >= 650)
            temp->bullet_travel = 0, temp->shoot = 0, temp->check_shoot = 0;
        }
        if (temp->shoot == 1 && bullet->hit != 1)
            sfRenderWindow_drawSprite(s_all->s_game.window,
                bullet->bullet, NULL);
    }
}