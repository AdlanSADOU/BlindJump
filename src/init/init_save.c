/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_save
*/

#include "rpg.h"

save_t *fill_save(save_t *old, int id, sfVector2f pos, all_t *s_all)
{
    save_t *new = malloc(sizeof(save_t));
    new->button = sfSprite_create();
    new->description = sfText_create();
    sfText_setFont(new->description, s_all->s_game.font);
    if (id == 1) {
        new->filepath = my_strdup("saves/save1");
        sfText_setString(new->description, "Save 1");
    } if (id == 2) {
        new->filepath = my_strdup("saves/save2");
        sfText_setString(new->description, "Save 2");
    } if (id == 3) {
        new->filepath = my_strdup("saves/save3");
        sfText_setString(new->description, "Save 3");
    }
    sfText_setPosition(new->description, (sfVector2f){pos.x + 15, pos.y});
    sfSprite_setPosition(new->button, (sfVector2f){pos.x, pos.y + 35});
    new->next = old, new->id = id, new->fion = 0;
    return (new);
}

void init_save_screen(all_t *s_all)
{
    int i = 1;
    sfVector2f pos = (sfVector2f){910, 230};
    sfTexture *normal, *hover, *clicked;
    s_all->s_save = NULL;
    normal = sfTexture_createFromFile("sprites/buttons/save.png", NULL);
    hover = sfTexture_createFromFile("sprites/buttons/save_hover.png", NULL);
    clicked =
    sfTexture_createFromFile("sprites/buttons/save_clicked.png", NULL);
    for (; i != 4; i++, pos.y += 150) {
        s_all->s_save = fill_save(s_all->s_save, i, pos, s_all);
        s_all->s_save->normal = normal;
        s_all->s_save->hover = hover;
        s_all->s_save->clicked = clicked;
    }
    init_buttons_pause(s_all);
}