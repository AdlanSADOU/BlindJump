/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_inventory
*/

#include "rpg.h"

void set_texture_items(slots_t *tmp, int id, all_t *s_all)
{
    if (id == 0) {
        sfSprite_setTexture(tmp->item, s_all->s_inventory.pistol, sfTrue);
        tmp->dmg = 10;
    } if (id == 1) {
        sfSprite_setTexture(tmp->item, s_all->s_inventory.scorpion, sfTrue);
        tmp->dmg = 20;
    } if (id == 2) {
        sfSprite_setTexture(tmp->item, s_all->s_inventory.scarh, sfTrue);
        tmp->dmg = 35;
    } if (id == 3) {
        sfSprite_setTexture(tmp->item, s_all->s_inventory.sniper, sfTrue);
        tmp->dmg = 50;
    } if (id >= 4)
        sfSprite_setTexture(tmp->item, s_all->s_inventory.armors_tx, sfTrue);
    set_texture_items2(tmp, id);
}

void init_slots(all_t *s_all, sfVector2f pos)
{
    slots_t *old = NULL;
    pos.x += 10, pos.y += 10;
    int x = pos.x;
    for (int i = 0, count = 0; i != 20; i++, count++) {
        slots_t *tmp = malloc(sizeof(slots_t));
        tmp->slot = sfSprite_create();
        sfSprite_setTexture(tmp->slot, s_all->s_inventory.slot_tx, sfTrue);
        sfSprite_setPosition(tmp->slot, pos);
        tmp->item = sfSprite_create();
        tmp->drag = 0, tmp->health = 0, tmp->dmg = 0;
        pos.x += 62;
        tmp->equip = 0;
        tmp->slot_nb = 0;
        tmp->is_item = 0;
        tmp->under = NULL;
        if (count == 3) count = -1, pos.x = x, pos.y += 62;
        tmp->next = old;
        old = tmp;
    } s_all->s_inventory.head = old;
    init_equip_slots(s_all);
}

void init_items_texture(all_t *s_all)
{
    s_all->s_inventory.pistol =
        sfTexture_createFromFile("sprites/weapons/pistol.png", NULL);
    s_all->s_inventory.scorpion =
        sfTexture_createFromFile("sprites/weapons/scorpion.png", NULL);
    s_all->s_inventory.trash_tx =
        sfTexture_createFromFile("sprites/inv/trash.png", NULL);
    s_all->s_inventory.scarh =
        sfTexture_createFromFile("sprites/weapons/scarh.png", NULL);
    s_all->s_inventory.sniper =
        sfTexture_createFromFile("sprites/weapons/sniper.png", NULL);
    s_all->s_inventory.armors_tx =
        sfTexture_createFromFile("sprites/weapons/armors.png", NULL);
}

void init_inventory2(all_t *s_all)
{
    sfSprite_setPosition(s_all->s_inventory.trash, (sfVector2f){1440, 640});
    s_all->s_inventory.infos = sfRectangleShape_create();
    sfRectangleShape_setSize(s_all->s_inventory.infos,
        (sfVector2f) {250, 50});
    sfRectangleShape_setFillColor(s_all->s_inventory.infos,
        (sfColor){70, 103, 113, 255});
    sfRectangleShape_setPosition(s_all->s_inventory.infos,
        (sfVector2f){-500, -500});
    s_all->s_inventory.infos_text = sfText_create();
    sfText_setFont(s_all->s_inventory.infos_text, s_all->s_game.monospaced);
    sfText_setCharacterSize(s_all->s_inventory.infos_text, 18);
    sfText_setPosition(s_all->s_inventory.infos_text,
        (sfVector2f){-500, -500});
}

void init_inventory(all_t *s_all)
{
    sfVector2f pos = {1500, 375};
    s_all->s_inventory.inv_back = sfRectangleShape_create();
    sfRectangleShape_setSize(s_all->s_inventory.inv_back,
        (sfVector2f) {269, 330});
    sfRectangleShape_setFillColor(s_all->s_inventory.inv_back,
        (sfColor){56, 79, 88, 160});
    sfRectangleShape_setPosition(s_all->s_inventory.inv_back, pos);
    s_all->s_inventory.slot_tx =
        sfTexture_createFromFile("sprites/inv/slot.png", NULL);
    s_all->s_inventory.selected_tx =
        sfTexture_createFromFile("sprites/inv/selector.png", NULL);
    s_all->s_inventory.selected = sfSprite_create();
    sfSprite_setPosition(s_all->s_inventory.selected,
        (sfVector2f){-100, -100});
    sfSprite_setTexture(s_all->s_inventory.selected,
    s_all->s_inventory.selected_tx, sfTrue), s_all->s_inventory.drag = 0;
    s_all->s_inventory.swap = 0, s_all->s_inventory.trash = sfSprite_create();
    init_items_texture(s_all), init_slots(s_all, pos);
    sfSprite_setTexture(s_all->s_inventory.trash,
    s_all->s_inventory.trash_tx, sfTrue), init_inventory2(s_all);
}