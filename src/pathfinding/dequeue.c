/*
** EPITECH PROJECT, 2020
** solver
** File description:
** dequeue
*/

#include "rpg.h"

void push_dequeue(queue_t **dequeue, queue_node_t *tmp)
{
    if (is_empty_queue(*dequeue)) {
        (*dequeue) = malloc(sizeof(queue_t));
        (*dequeue)->length = 0;
        (*dequeue)->first = tmp;
        (*dequeue)->last = tmp;
    }

    else {
        (*dequeue)->last->next = tmp;
        tmp->back = (*dequeue)->last;
        (*dequeue)->last = tmp;
        tmp->next = NULL;
    }

    (*dequeue)->length++;
}

queue_t *dequeue_front(queue_t *li, queue_t **dequeue)
{
    if (is_empty_queue(li))
        return (new_queue());

    queue_node_t *tmp = li->first;

    if (li->first != li->last) {
        li->first = li->first->next;
        li->first->back = NULL;
    }
    else {
        li->first = NULL;
        li->last = NULL;
        li->length--;
        free(li);
        li = new_queue();
    }

    push_dequeue(dequeue, tmp);

    return (li);
}

queue_t *new_queue(void)
{
    return (NULL);
}