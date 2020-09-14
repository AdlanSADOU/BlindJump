/*
** EPITECH PROJECT, 2020
** solver
** File description:
** breadth_first_search
*/

#include "rpg.h"

queue_t *check_direction(char **maze, queue_t *s_queue, int x, int y)
{
    if (maze[y][x + 1] == '0' || maze[y][x + 1] == 'T'
    || maze[y][x + 1] == 'P') {
        s_queue = push_back_queue(s_queue, s_queue->first, x + 1, y);
        if (maze[y][x + 1] != '1') maze[y][x + 1] = 'W';
    } if (maze[y + 1] != NULL && (maze[y + 1][x] == '0'
    || maze[y + 1][x] == 'T' || maze[y + 1][x] == 'P')) {
        s_queue = push_back_queue(s_queue, s_queue->first, x, y + 1);
        if (maze[y + 1][x] != '1') maze[y + 1][x] = 'W';
    } if (y - 1 != -1 && (maze[y - 1][x] == '0' || maze[y - 1][x] == 'T'
    || maze[y - 1][x] == 'P')) {
        s_queue = push_back_queue(s_queue, s_queue->first, x, y - 1);
        if (maze[y - 1][x] != '1') maze[y - 1][x] = 'W';
    } if (x - 1 != -1 && (maze[y][x - 1] == '0' || maze[y][x - 1] == 'T'
    || maze[y][x - 1] == 'P')) {
        s_queue = push_back_queue(s_queue, s_queue->first, x - 1, y);
        if (maze[y][x - 1] != '1') maze[y][x - 1] = 'W';
    } return (s_queue);
}

queue_t *push_new_generation(char **maze, queue_t *s_queue,
    queue_t **s_dequeue)
{
    int x = s_queue->first->x;
    int y = s_queue->first->y;

    s_queue = check_direction(maze, s_queue, x, y);

    s_queue = dequeue_front(s_queue, s_dequeue);

    return (s_queue);
}

sfVector2i find_pos(all_t *s_all, char entity)
{
    sfVector2i pos = {0, 0};

    for (; s_all->s_map.map[pos.y] != NULL; pos.y++, pos.x = 0)
        for (; s_all->s_map.map[pos.y][pos.x] != '\0'; pos.x++)
            if (s_all->s_map.map[pos.y][pos.x] == entity)
                return (pos);
    return (pos);
}

int check_if_found(queue_t *s_queue, sfVector2i pos_end)
{
    queue_node_t *tmp = s_queue->last;

    for (int i = 0; tmp != NULL && i != 4; i++, tmp = tmp->back)
        if (tmp->y == pos_end.y && tmp->x == pos_end.x)
            return (1);
    return (0);
}

int breadth_first_search(char **map, all_t *s_all, char start, char end)
{
    queue_t *s_queue = new_queue();
    queue_t *s_dequeue = new_queue();
    char **maze = copy_map(map);
    sfVector2i pos_start = find_pos(s_all, start);
    sfVector2i pos_end = find_pos(s_all, end);

    s_queue = push_back_queue(s_queue, NULL, pos_start.x, pos_start.y);
    maze[pos_start.y][pos_start.x] = 'W';
    while (s_queue != NULL && check_if_found(s_queue, pos_end) == 0)
        s_queue = push_new_generation(maze, s_queue, &s_dequeue);
    if (s_queue == NULL) {
        s_dequeue = clear_queue(s_dequeue);
        return (1);
    }
    for (int i = 0; maze[i] != NULL; i++)
        free(maze[i]);
    free(maze);
    s_queue = clear_queue(s_queue);
    s_dequeue = clear_queue(s_dequeue);
    return (0);
}