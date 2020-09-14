/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_save
*/

#include "rpg.h"

void check_id2(save_t *temp, all_t *s_all)
{
    if (temp->id == 1) {
        save(s_all, "saves/save1");
    }
    if (temp->id == 2) {
        save(s_all, "saves/save2");
    }
    if (temp->id == 3) {
        save(s_all, "saves/save3");
    }
    s_all->s_game.pause = 0;
    free_load_slots(s_all);
    init_load_slots(s_all);
}

void check_button2(save_t *temp, all_t *s_all)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(s_all->s_game.window);
    sfFloatRect button = sfSprite_getGlobalBounds(temp->button);
    if (sfFloatRect_contains(&button, mouse_pos.x, mouse_pos.y) &&
    temp->fion == 0) {
        sfSprite_setTexture(temp->button, temp->hover, sfTrue);
    }
    else if (temp->fion == 0) {
        sfSprite_setTexture(temp->button, temp->normal, sfTrue);
    }
}

void click_button2(save_t *temp, all_t *s_all)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(s_all->s_game.window);
    sfFloatRect button = sfSprite_getGlobalBounds(temp->button);
    if (sfFloatRect_contains(&button, mouse_pos.x, mouse_pos.y)) {
        if (s_all->s_game.event.mouseButton.type == sfEvtMouseButtonPressed) {
            s_all->s_game.event.mouseButton.type = 0;
            temp->fion = 1;
            sfSprite_setTexture(temp->button, temp->clicked, sfTrue);
        }
        if (s_all->s_game.event.mouseButton.type == sfEvtMouseButtonReleased) {
            temp->fion = 0;
            s_all->s_game.event.mouseButton.type = 0;
            check_id2(temp, s_all);
            sfSprite_setTexture(temp->button, temp->normal, sfTrue);
        }
    }
}

void refresh_button2(all_t *s_all)
{
    if (s_all->s_game.event.mouseButton.type == sfEvtMouseButtonReleased) {
        save_t *temp = s_all->s_save;
        while (temp != NULL) {
            sfSprite_setTexture(temp->button, temp->normal, sfTrue);
            temp = temp->next;
        }
    }
}

void display_save_slots(all_t *s_all)
{
    save_t *temp = s_all->s_save;
    refresh_button2(s_all);
    if ((s_all->s_game.scene == MAP || s_all->s_game.scene == SPAWN)
    && s_all->s_game.pause == 1) {
        sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_game.black, NULL);
        while (temp != NULL) {
            click_button2(temp, s_all);
            check_button2(temp, s_all);
            sfRenderWindow_drawText(s_all->s_game.window,
                temp->description, NULL);
            sfRenderWindow_drawSprite(s_all->s_game.window,
                temp->button, NULL);
            temp = temp->next;
        }
    }
    dispay_buttons_pause(s_all, s_all->s_pause);
}