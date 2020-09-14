/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_mobs
*/

#include "rpg.h"

mob_t *get_prev(all_t *s_all, mob_t *node)
{
    mob_t *temp = s_all->s_mob;
    while (temp != NULL) {
        if (temp->next == node)
            return (temp);
        temp = temp->next;
    }
    return (temp);
}

mob_t *destroy_mob_node(mob_t *prev, mob_t *temp)
{
    prev->next = temp->next;
    sfSprite_destroy(temp->mob);
    sfSprite_destroy(temp->shadow);
    sfClock_destroy(temp->rect_clock);
    sfClock_destroy(temp->clock);
    sfClock_destroy(temp->refresh_clk);
    if (temp->path != NULL)
        free_map(temp->path);
    free(temp);
    return (prev->next);
}

mob_t *destroy_mob_head(mob_t *s_tuto, all_t *s_all)
{
    mob_t *temp = s_tuto->next;
    sfSprite_destroy(s_tuto->mob), sfSprite_destroy(s_tuto->shadow);
    sfClock_destroy(s_tuto->rect_clock);
    sfClock_destroy(s_tuto->clock);
    sfClock_destroy(s_tuto->refresh_clk);
    if (s_tuto->path != NULL) free_map(s_tuto->path);
    free(s_tuto);
    s_all->s_mob = temp;
    return (temp);
}

void destroy_mobs(all_t *s_all)
{
    mob_t *temp = s_all->s_mob;
    mob_t *prev = NULL;
    while (temp != NULL) {
        prev = get_prev(s_all, temp);
        if (prev != NULL && temp->status == -1) {
            s_all->s_game.nb -= 1;
            push_front_hearth(s_all, temp);
            temp = destroy_mob_node(prev, temp);
            continue;
        }
        else if (temp->status == -1 && prev == NULL){
            s_all->s_game.nb -= 1;
            push_front_hearth(s_all, temp);
            temp = destroy_mob_head(temp, s_all);
            continue;
        } temp = temp->next;
    }
}