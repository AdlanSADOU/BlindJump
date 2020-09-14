/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_chests
*/

#include "rpg.h"

void chest_text(chest_t *new, all_t *s_all)
{
    new->open_txt = sfText_create();
    sfText_setFont(new->open_txt, s_all->s_game.font);
    sfText_setString(new->open_txt, "PRESS \"E\" TO OPEN");
    sfText_setPosition(new->open_txt,
        (sfVector2f){new->pos.x - 29, new->pos.y - 5});
    sfText_setCharacterSize(new->open_txt, 7);
    sfText_setColor(new->open_txt, (sfColor){255, 255, 255, 255});
}

chest_t *fill_chests(chest_t *old, all_t *s_all, sfVector2f pos)
{
    chest_t *new = malloc(sizeof(chest_t));
    new->sprite = sfSprite_create();
    new->shadow = sfSprite_create();
    new->texture = s_all->s_player.hero_tx;
    new->clock = sfClock_create();
    new->rect = (sfIntRect){656, 77, 16, 29};
    new->pos.x = pos.x, new->pos.y = pos.y - 10;
    new->seconds = 0, new->status = 0;
    chest_text(new, s_all);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setTexture(new->shadow, new->texture, sfTrue);
    sfSprite_setTextureRect(new->sprite, new->rect);
    sfSprite_setTextureRect(new->shadow, (sfIntRect){20, 109, 16, 7});
    sfSprite_setPosition(new->sprite, new->pos);
    sfSprite_setPosition(new->shadow,
        (sfVector2f){new->pos.x, new->pos.y + 28});
    sfSprite_setScale(new->shadow, (sfVector2f){1.14, 1.14});
    new->next = old;
    return (new);
}

void open_chest(chest_t *temp, all_t *s_all)
{
    if (temp->seconds > 0.1) {
        if (temp->rect.left < 736 && temp->status != -1) {
            temp->rect.left += 16;
            sfSprite_setTextureRect(temp->sprite, temp->rect);
            sfVector2f scale = sfSprite_getScale(temp->shadow);
            sfSprite_setScale(temp->shadow,
                (sfVector2f){scale.x, scale.y += 0.2});
        } else {
            temp->status = -1;
            if (s_all->s_sounds.fat_bool == 0)
                sfSound_play(s_all->s_sounds.item);
            if (s_all->s_game.scene == SPAWN) {
                s_all->s_chatbox.buff[0] = '\0', s_all->s_chatbox.op = 0;
                s_all->s_chatbox.idx = 0, s_all->s_chatbox.car = 0;
                if (s_all->s_cine.script < 2)
                    put_item_in_slot(s_all, 0);
            } else put_item_in_slot(s_all, rand() % 20);
            if (s_all->s_cine.script == 1) s_all->s_cine.script = 2;
        } sfClock_restart(temp->clock);
    }
}

void display_chests_over(all_t *s_all, int y)
{
    chest_t *temp = s_all->s_chest;
    while (temp != NULL) {
        if (temp->status == 1)
            open_chest(temp, s_all);
        if (temp->pos.y + 14 >= y) {
            sfRenderWindow_drawSprite(s_all->s_game.window,
                temp->sprite, NULL);
            sfRenderWindow_drawSprite(s_all->s_game.window,
                temp->shadow, NULL);
        }
        temp = temp->next;
    }
}

int display_chests_under(all_t *s_all)
{
    chest_t *temp = s_all->s_chest;
    int y = sfSprite_getPosition(s_all->s_player.shadow).y;
    while (temp != NULL) {
        if (temp->pos.y + 14 < y) {
            sfRenderWindow_drawSprite(s_all->s_game.window,
                temp->sprite, NULL);
            sfRenderWindow_drawSprite(s_all->s_game.window,
                temp->shadow, NULL);
        }
        temp = temp->next;
    }
    return (y);
}