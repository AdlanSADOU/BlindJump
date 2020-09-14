/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** mob_generator
*/

#include "rpg.h"

void free_all_mobs(all_t *s_all)
{
    mob_t *temp;
    mob_t *head = s_all->s_mob;
    while (head != NULL) {
        temp = head->next;
        sfSprite_destroy(head->mob);
        sfSprite_destroy(head->shadow);
        sfClock_destroy(head->rect_clock);
        sfClock_destroy(head->clock);
        sfClock_destroy(head->refresh_clk);
        if (head->path != NULL)
            free_map(head->path);
        free(head);
        head = temp;
    }
    s_all->s_mob = NULL;
}

void generate_random_chests(all_t *s_all)
{
    int x = s_all->s_map.x, select = s_all->s_map.stage;
    int y = s_all->s_map.y - 1, randx = 0, randy = 0;
    int tab[10] = {0, 10, 15, 20, 25, 30};
    if (select > 5) select = 5;
    int i = tab[select];
    free_chest(s_all);
    int check = 0;
    while (i != 0) {
        randx = (rand() % x);
        randy = (rand() % y);
        if (s_all->s_map.map[randy][randx] == '0' &&
        breadth_first_search_entity(s_all->s_map.map, s_all, randx, randy)
        != NULL) {
            s_all->s_chest = fill_chests(s_all->s_chest, s_all,
            (sfVector2f){randx * 32 + 8, randy * 26 - 7});
            i--;
            check = check_chest_turret_overlap(s_all);
        } if (check == 1)
            pop_front_chest(s_all), check = 0, i++;
    }
}

void generate_random_mobs2(all_t *s_all)
{
    int x = s_all->s_map.x, select = s_all->s_map.stage;
    int y = s_all->s_map.y - 1, randx = 0, randy = 0;
    int tab[10] = {0, 0, 15, 10, 10, 15};
    if (select > 5) select = 5;
    int i = tab[select];
    while (i != 0) {
        randx = (rand() % x);
        randy = (rand() % y);
        s_all->s_mob_pos.x = randx, s_all->s_mob_pos.y = randy;
        if (s_all->s_map.map[randy][randx] == '0' &&
        breadth_first_search_entity(s_all->s_map.map, s_all, randx, randy)
        != NULL) {
            s_all->s_mob = fill_mob(s_all->s_mob, 'A',
            (sfVector2f){randx * 32 + 13, randy * 26}, s_all);
            i--;
        }
    } generate_random_mobs3(s_all);
    generate_random_chests(s_all);
}

void generate_random_mobs(all_t *s_all)
{
    free_all_mobs(s_all);
    int x = s_all->s_map.x, select = s_all->s_map.stage;
    int y = s_all->s_map.y - 1, randx = 0, randy = 0;
    int tab[10] = {0, 30, 15, 10, 15, 15};
    if (select > 5) select = 5;
    int i = tab[select];
    while (i != 0) {
        randx = (rand() % x);
        randy = (rand() % y);
        s_all->s_mob_pos.x = randx, s_all->s_mob_pos.y = randy;
        if (s_all->s_map.map[randy][randx] == '0' &&
        breadth_first_search_entity(s_all->s_map.map, s_all, randx, randy)
        != NULL) {
            s_all->s_mob = fill_mob(s_all->s_mob, 'B',
            (sfVector2f){randx * 32 + 8, randy * 26 - 4}, s_all);
            i--;
        }
    } generate_random_mobs2(s_all);
}