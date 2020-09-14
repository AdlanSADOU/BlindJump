/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_inventory
*/

#include "rpg.h"

void trash_items(all_t *s_all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(s_all->s_game.window);
    sfFloatRect rect = sfSprite_getGlobalBounds(s_all->s_inventory.trash);
    if (sfFloatRect_contains(&rect, mouse.x, mouse.y) == 1
    && s_all->s_inventory.drag == 1
    && s_all->s_game.event.mouseButton.type == sfEvtMouseButtonReleased) {
        s_all->s_inventory.dragged->drag = 0;
        s_all->s_inventory.drag = 0;
        s_all->s_inventory.dragged->id = 0;
        s_all->s_inventory.dragged->is_item = 0;
        s_all->s_inventory.dragged->dmg = 0;
        s_all->s_inventory.dragged->health = 0;
        sfSprite_destroy(s_all->s_inventory.dragged->item);
        s_all->s_inventory.dragged->item = sfSprite_create();
        s_all->s_game.event.mouseButton.type = 0;
        s_all->s_inventory.dragged = NULL;
    }
}

int hover_item(all_t *s_all, sfVector2i mouse, slots_t *tmp)
{
    if (tmp->is_item == 0) return (0);
    sfVector2f pos = (sfVector2f){mouse.x - 275, mouse.y - 63};
    sfRectangleShape_setPosition(s_all->s_inventory.infos, pos);
    sfText_setPosition(s_all->s_inventory.infos_text,
        (sfVector2f){pos.x + 10, pos.y + 12});
    char *str = malloc(sizeof(char) * 20);
    str[0] = '\0';
    str = my_strcat(str, "Add +");
    if (tmp->id < 4) {
        str = my_strcat(str, strnbr(tmp->dmg));
        str = my_strcat(str, " damages");
    } else {
        str = my_strcat(str, strnbr(tmp->health));
        str = my_strcat(str, " health");
    } sfText_setString(s_all->s_inventory.infos_text, str);
    free(str);
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_inventory.selected, NULL);
    return (1);
}

void display_items_and_select(all_t *s_all, int *check)
{
    slots_t *tmp = s_all->s_inventory.head;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(s_all->s_game.window);
    for (; s_all->s_game.pause != 1 && tmp != NULL; tmp = tmp->next) {
        sfFloatRect rect = sfSprite_getGlobalBounds(tmp->slot);
        rect.width -= 2, rect.left += 1;
        rect.height -= 2, rect.top += 1;
        if (sfFloatRect_contains(&rect, mouse.x, mouse.y) == 1) {
            *check = hover_item(s_all, mouse, tmp);
            slot_click(s_all, tmp);
            sfSprite_setPosition(s_all->s_inventory.selected,
                sfSprite_getPosition(tmp->slot));
            sfRenderWindow_drawSprite(s_all->s_game.window,
                s_all->s_inventory.selected, NULL);
        } if (tmp->item != NULL && tmp->drag != 1)
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->item, NULL);
    } drag_item(s_all);
    trash_items(s_all);
}

void display_inventory(all_t *s_all)
{
    slots_t *tmp = s_all->s_inventory.head;
    int check = 0;
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        s_all->s_inventory.inv_back, NULL);
    for (; tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawSprite(s_all->s_game.window, tmp->slot, NULL);
        sfFloatRect rect = sfSprite_getGlobalBounds(tmp->slot);
        rect.width -= 2, rect.left += 1, rect.height -= 2, rect.top += 1;
        sfSprite_setColor(tmp->slot, (sfColor){255, 255, 255, 255});
        if (tmp->under != NULL)
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->under, NULL);
        if (tmp->item != NULL && tmp->drag != 1)
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->item, NULL);
    } sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_inventory.trash, NULL);
    display_items_and_select(s_all, &check);
    display_inventory_inf(s_all, check);
}

int drop_check(all_t *s_all, slots_t *tmp)
{
    if (tmp->slot_nb == 4 && (s_all->s_inventory.dragged->id != 7 && s_all->
    s_inventory.dragged->id != 11 && s_all->s_inventory.dragged->id != 15
    && s_all->s_inventory.dragged->id != 19)) return (1);
    if (tmp->slot_nb == 3 && (s_all->s_inventory.dragged->id != 6 && s_all->
    s_inventory.dragged->id != 10 && s_all->s_inventory.dragged->id != 14
    && s_all->s_inventory.dragged->id != 18)) return (1);
    if (tmp->slot_nb == 2 && (s_all->s_inventory.dragged->id != 5 && s_all->
    s_inventory.dragged->id != 9 && s_all->s_inventory.dragged->id != 13
    && s_all->s_inventory.dragged->id != 17)) return (1);
    if (tmp->slot_nb == 1 && (s_all->s_inventory.dragged->id != 4 && s_all->
    s_inventory.dragged->id != 8 && s_all->s_inventory.dragged->id != 12
    && s_all->s_inventory.dragged->id != 16)) return (1);
    if (tmp->slot_nb == 5 && (s_all->s_inventory.dragged->id > 3)) return (1);
    return (0);
}