/*
** EPITECH PROJECT, 2020
** solver
** File description:
** queue
*/

#include "rpg.h"

int is_empty_queue(queue_t *li)
{
    if (li == NULL)
        return (1);

    return (0);
}

queue_node_t *new_queue_node(queue_node_t *parent, int x, int y)
{
    queue_node_t *element;

    element = malloc(sizeof(*element));
    element->x = x;
    element->y = y;
    element->next = NULL;
    element->back = NULL;
    element->parent = parent;

    return (element);
}

queue_t *push_back_queue(queue_t *li, queue_node_t *parent, int x, int y)
{
    queue_node_t *element = new_queue_node(parent, x, y);

    if (is_empty_queue(li)) {
        li = malloc(sizeof(*li));
        li->length = 0;
        li->first = element;
        li->last = element;
    }

    else {
        li->last->next = element;
        element->back = li->last;
        li->last = element;
    }

    li->length++;

    return (li);
}

queue_t *pop_front_queue(queue_t *li)
{
    if (is_empty_queue(li))
        return (new_queue());

    if (li->first == li->last) {
        free(li->first);
        free (li);
        return (new_queue());
    }

    queue_node_t *tmp = li->first;

    li->first = li->first->next;
    li->first->back = NULL;
    tmp->next = NULL;
    tmp->back = NULL;
    tmp->parent = NULL;
    li->length--;
    free (tmp);

    return (li);
}

queue_t *clear_queue(queue_t *li)
{
    while (!is_empty_queue(li))
        li = pop_front_queue(li);

    return (new_queue());
}