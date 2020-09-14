/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** mob_path
*/

#include "rpg.h"

void refresh_player_position(all_t *s_all)
{
    int i = 0, j = 0;
    for (; s_all->s_map.map[i] != NULL; i++) {
        for (j = 0; s_all->s_map.map[i][j] != '\0'; j++) {
            if (s_all->s_map.map[i][j] == 'P') {
                s_all->s_map.map[i][j] = '0';
                return;
            }
        }
    }
}

void refresh_path(all_t *s_all)
{
    sfVector2f pos = sfSprite_getPosition(s_all->s_player.shadow);
    int y = (pos.y + 4) / 26;
    int x = (pos.x + 7) / 32;
    refresh_player_position(s_all);
    s_all->s_map.map[y][x] = 'P';
    s_all->s_player.x = x;
    s_all->s_player.y = y;
    sfClock_restart(s_all->s_player.refresh_clk);
}

void search_mob_path(mob_t *node, all_t *s_all)
{
    int x = node->x, y = node->y;
    if (node->path == NULL) return;
    if (s_all->s_game.pause == 1) return;
    if (node->y != 0 && node->path[y - 1][x] == ' ' && node->prev != 'D') {
        move_mob_up(node, s_all);
        return;
    } if (node->path[y][x + 1] == ' ' && node->prev != 'L') {
        move_mob_right(node, s_all);
        return;
    } if (node->y != s_all->s_map.y - 1 && node->path[y + 1][x] == ' ' &&
    node->prev != 'U') {
        move_mob_down(node, s_all);
        return;
    } if (node->x != 0 && node->path[y][x - 1] == ' ' && node->prev != 'R') {
        move_mob_left(node, s_all);
        return;
    }
    free_map(node->path);
    node->path = breadth_first_search_entity(s_all->s_map.map,
    s_all, node->x, node->y);
}