/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory_items
*/

#include "rpg.h"

int drop_item2(all_t *s_all, slots_t *tmp)
{
    if (tmp->is_item == 0) {
        tmp->is_item = 1;
        tmp->id = s_all->s_inventory.dragged->id;
        set_texture_items(tmp, tmp->id, s_all);
        sfSprite_setPosition(tmp->item, sfSprite_getPosition(tmp->slot));
        s_all->s_inventory.dragged->id = 0;
        s_all->s_inventory.dragged->drag = 0;
        sfSprite_destroy(s_all->s_inventory.dragged->item);
        s_all->s_inventory.dragged->item = sfSprite_create();
        s_all->s_inventory.dragged->is_item = 0;
        s_all->s_inventory.drag = 0;
        tmp->health = s_all->s_inventory.dragged->health;
        tmp->dmg = s_all->s_inventory.dragged->dmg;
        s_all->s_inventory.dragged->health = 0;
        s_all->s_inventory.dragged->dmg = 0;
        s_all->s_inventory.dragged = NULL;
        set_equip_stats(s_all);
        return (1);
    }
    return (0);
}

void drop_item(all_t *s_all, slots_t *tmp)
{
    s_all->s_game.event.mouseButton.type = 0;
    if (drop_check(s_all, tmp) == 1) return;
    if (tmp == s_all->s_inventory.dragged) {
        sfSprite_setPosition(tmp->item, sfSprite_getPosition(tmp->slot));
        s_all->s_inventory.drag = 0;
        tmp->drag = 0;
        s_all->s_inventory.dragged = NULL;
        set_equip_stats(s_all);
        return;
    }
    if (drop_item2(s_all, tmp) == 1)
        return;
    if (tmp->is_item == 1) {
        set_texture_items(tmp, s_all->s_inventory.dragged->id, s_all);
        set_texture_items(s_all->s_inventory.dragged, tmp->id, s_all);
        swap_items(s_all, tmp);
        set_equip_stats(s_all);
    }
}

void slot_click(all_t *s_all, slots_t *tmp)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1)
        sfSprite_setColor(tmp->slot, (sfColor){100, 100, 100, 150});
    if (s_all->s_game.event.mouseButton.type == sfEvtMouseButtonReleased) {
        if (tmp->is_item == 1 && tmp->drag == 0
        && s_all->s_inventory.drag == 0) {
            s_all->s_inventory.drag = 1;
            tmp->drag = 1;
            s_all->s_inventory.dragged = tmp;
            s_all->s_game.event.mouseButton.type = 0;
        }
        else if (s_all->s_inventory.drag == 1)
            drop_item(s_all, tmp);
    }
}

void drag_item(all_t *s_all)
{
    if (s_all->s_inventory.drag == 1) {
        sfVector2i mouse =
            sfMouse_getPositionRenderWindow(s_all->s_game.window);
        slots_t *tmp = s_all->s_inventory.head;
        for (; tmp != NULL; tmp = tmp->next)
            if (tmp->drag == 1) break;
        if (s_all->s_game.pause != 1)
            sfSprite_setPosition(tmp->item,
            (sfVector2f){mouse.x - 36, mouse.y - 32});
        sfRenderWindow_drawSprite(s_all->s_game.window, tmp->item, NULL);
    }
}

void put_item_in_slot(all_t *s_all, int id)
{
    slots_t *tmp = s_all->s_inventory.head;
    for (; tmp != NULL; tmp = tmp->next)
        if (tmp->is_item == 0 && tmp->equip == 0) {
            tmp->is_item = 1;
            break;
        }
    if (tmp == NULL) return;
    tmp->id = id;
    set_texture_items(tmp, tmp->id, s_all);
    sfSprite_setPosition(tmp->item, sfSprite_getPosition(tmp->slot));
}