/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** breadth_first_search_entity
*/

#include "rpg.h"

char **process_result(char **maze, queue_t *s_dequeue, queue_t *s_queue,
    sfVector2i pos_end)
{
    queue_node_t *tmp = s_queue->last;
    for (int i = 0; tmp != NULL && i != 4; i++, tmp = tmp->back)
        if (tmp->y == pos_end.y && tmp->x == pos_end.x)
            break;

    for (; tmp != NULL; tmp = tmp->parent)
        maze[tmp->y][tmp->x] = ' ';

    format_map(maze);

    s_dequeue = clear_queue(s_dequeue);
    s_queue = clear_queue(s_queue);

    return (maze);
}

char **breadth_first_search_entity(char **map, all_t *s_all, int x, int y)
{
    queue_t *s_queue = new_queue();
    queue_t *s_dequeue = new_queue();
    char **maze = copy_map(map);
    sfVector2i pos_start = (sfVector2i){x, y};
    sfVector2i pos_end = (sfVector2i){s_all->s_player.x, s_all->s_player.y};

    s_queue = push_back_queue(s_queue, NULL, pos_start.x, pos_start.y);
    maze[pos_start.y][pos_start.x] = 'W';
    while (s_queue != NULL && check_if_found(s_queue, pos_end) == 0)
        s_queue = push_new_generation(maze, s_queue, &s_dequeue);

    if (s_queue == NULL) {
        s_dequeue = clear_queue(s_dequeue);
        return (NULL);
    }
    maze = process_result(maze, s_dequeue, s_queue, pos_end);
    return (maze);
}