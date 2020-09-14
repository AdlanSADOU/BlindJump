/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** mob_generator2
*/

#include "rpg.h"

int check_chest_turret_overlap(all_t *s_all)
{
    mob_t *tmp = s_all->s_mob;
    sfFloatRect mob, chest = sfSprite_getGlobalBounds(s_all->s_chest->sprite);
    while (tmp != NULL) {
        mob = sfSprite_getGlobalBounds(tmp->mob);
        if (sfFloatRect_intersects(&mob, &chest, NULL) == 1)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

void pop_front_chest(all_t *s_all)
{
    if (s_all->s_chest == NULL) return;
    chest_t *tmp = s_all->s_chest;
    s_all->s_chest = s_all->s_chest->next;
    sfSprite_destroy(tmp->sprite);
    sfSprite_destroy(tmp->shadow);
    sfClock_destroy(tmp->clock);
    sfText_destroy(tmp->open_txt);
    free(tmp);
}

void generate_random_mobs3(all_t *s_all)
{
    int x = s_all->s_map.x, select = s_all->s_map.stage;
    int y = s_all->s_map.y - 1, randx = 0, randy = 0;
    int tab[10] = {0, 0, 0, 10, 10, 10};
    if (select > 5) select = 5;
    int i = tab[select];
    while (i != 0) {
        randx = (rand() % x);
        randy = (rand() % y);
        s_all->s_mob_pos.x = randx, s_all->s_mob_pos.y = randy;
        if (s_all->s_map.map[randy][randx] == '0' &&
        breadth_first_search_entity(s_all->s_map.map, s_all,
        randx, randy) != NULL) {
            s_all->s_mob = fill_mob(s_all->s_mob, 'T',
            (sfVector2f){randx * 32 + 17, randy * 26}, s_all);
            i--;
        }
    }
}