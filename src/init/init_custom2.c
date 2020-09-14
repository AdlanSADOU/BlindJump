/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_custom2
*/

#include "rpg.h"

void fill_rgb2(rgb_t *new, char type)
{
    sfSprite_setScale(new->left, (sfVector2f){-1, 0.40});
    sfSprite_setScale(new->right, (sfVector2f){1, 0.40});
    if (type == 'R') {
        sfRectangleShape_setSize(new->rect, (sfVector2f){255, 22});
        sfRectangleShape_setFillColor(new->rect, (sfColor){255, 0, 0, 255});
        sfRectangleShape_setPosition(new->rect, (sfVector2f){820, 600});
        sfSprite_setPosition(new->cursor, (sfVector2f){1075, 600});
        sfSprite_setPosition(new->left, (sfVector2f){810, 598});
        sfSprite_setPosition(new->right, (sfVector2f){1085, 598});
    }
    if (type == 'G') {
        sfRectangleShape_setSize(new->rect, (sfVector2f){255, 22});
        sfRectangleShape_setFillColor(new->rect, (sfColor){0, 255, 0, 255});
        sfRectangleShape_setPosition(new->rect, (sfVector2f){820, 650});
        sfSprite_setPosition(new->cursor, (sfVector2f){1075, 650});
        sfSprite_setPosition(new->left, (sfVector2f){810, 648});
        sfSprite_setPosition(new->right, (sfVector2f){1085, 648});
    }
}

rgb_t *fill_rbg(all_t *s_all, char type, rgb_t *old, sfTexture *arrow_tx)
{
    rgb_t *new = malloc(sizeof(rgb_t));
    new->rect = sfRectangleShape_create(), new->right = sfSprite_create();
    new->left = sfSprite_create(), new->cursor = sfSprite_create();
    new->cursor_tx = s_all->s_player.hero_tx;
    sfSprite_setTexture(new->left, arrow_tx, sfTrue);
    sfSprite_setTexture(new->right, arrow_tx, sfTrue);
    sfSprite_setTexture(new->cursor, new->cursor_tx, sfTrue);
    sfSprite_setTextureRect(new->cursor, (sfIntRect){67, 76, 5, 16});
    sfSprite_setScale(new->cursor, (sfVector2f){1, 1.70});
    fill_rgb2(new, type);
    if (type == 'B') {
        sfRectangleShape_setSize(new->rect, (sfVector2f){255, 22});
        sfRectangleShape_setFillColor(new->rect, (sfColor){0, 0, 255, 255});
        sfRectangleShape_setPosition(new->rect, (sfVector2f){820, 700});
        sfSprite_setPosition(new->cursor, (sfVector2f){1075, 700});
        sfSprite_setPosition(new->left, (sfVector2f){810, 698});
        sfSprite_setPosition(new->right, (sfVector2f){1085, 698});
    } new->value = 255, new->id = type;
    new->next = old;
    return (new);
}

void init_rgb_selector(all_t *s_all)
{
    s_all->s_game.arrow =
        sfTexture_createFromFile("sprites/buttons/arrow.png", NULL);
    s_all->s_rgb = NULL;
    s_all->s_rgb = fill_rbg(s_all, 'B', s_all->s_rgb, s_all->s_game.arrow);
    s_all->s_rgb = fill_rbg(s_all, 'G', s_all->s_rgb, s_all->s_game.arrow);
    s_all->s_rgb = fill_rbg(s_all, 'R', s_all->s_rgb, s_all->s_game.arrow);
}

void check_arrow_hitbox(rgb_t *temp, all_t *s_all)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    sfFloatRect left = sfSprite_getGlobalBounds(temp->left);
    sfFloatRect right = sfSprite_getGlobalBounds(temp->right);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&left, mouse_pos.x, mouse_pos.y))
            moove_rgb_cursor_left(s_all, temp);
        if (sfFloatRect_contains(&right, mouse_pos.x, mouse_pos.y))
            moove_rgb_cursor_right(s_all, temp);
    }
}

void display_rgb_selector(all_t *s_all)
{
    rgb_t *temp = s_all->s_rgb;
    if (s_all->s_game.scene != CUSTOM || s_all->s_effect.anim < 45) return;
    while (temp != NULL) {
        sfRenderWindow_drawRectangleShape(s_all->s_game.window,
            temp->rect, NULL);
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->cursor, NULL);
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->right, NULL);
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->left, NULL);
        check_arrow_hitbox(temp, s_all);
        temp = temp->next;
    }
}