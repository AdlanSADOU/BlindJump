/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** save_inventory
*/

#include "utils.h"
#include "rpg.h"

void save_inventory(int fd, all_t *s_all)
{
    slots_t *temp = s_all->s_inventory.head;
    while (temp != NULL) {
        if (temp->is_item == 1) {
            write_field("slot", fd, strnbr(temp->id));
        }
        else {
            write_field("slot", fd, "-1");
        }
        temp = temp->next;
    }
}

void load_inventory(int fd, all_t *s_all)
{
    slots_t *temp = s_all->s_inventory.head;
    char *field;
    int id = -1;
    while (temp != NULL) {
        field = read_field("slot", fd);
        id = my_atoi(field);
        if (id != -1) {
            temp->id = id;
            temp->is_item = 1;
            set_texture_items(temp, temp->id, s_all);
            sfSprite_setPosition(temp->item, sfSprite_getPosition(temp->slot));
        }
        free(field);
        temp = temp->next;
    }
}