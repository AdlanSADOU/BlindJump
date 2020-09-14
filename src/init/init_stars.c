/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_stars
*/

#include "rpg.h"

void stars_create_texture(all_t *s_all, sfSprite *sprite,
    sfRenderTexture *render)
{
    render = sfRenderTexture_create(128 * 50, 128 * 50, 0);
    s_all->s_stars.pos = (sfVector2f){0, 0};
    for (int i = 0, j = 0; i != 50; i++, s_all->s_stars.pos.y += 128,
    s_all->s_stars.pos.x = 0) {
        for (j = 0; j != 50; j++, s_all->s_stars.pos.x += 128) {
        sfSprite_setPosition(sprite, s_all->s_stars.pos);
        sfRenderTexture_drawSprite(render, sprite, NULL);
        }
    }
    sfSprite_setTexture(sprite, sfRenderTexture_getTexture(render), sfTrue);
    s_all->s_stars.pos = (sfVector2f){-128 * 15, -128 * 15};
    sfSprite_setPosition(sprite, s_all->s_stars.pos);
}

void init_stars(all_t *s_all)
{
    s_all->s_stars.front = sfSprite_create();
    s_all->s_stars.back = sfSprite_create();
    s_all->s_stars.back_tx =
        sfTexture_createFromFile("sprites/stars_back.png", NULL);
    s_all->s_stars.front_tx =
        sfTexture_createFromFile("sprites/stars_front.png", NULL);
    sfSprite_setTexture(s_all->s_stars.back, s_all->s_stars.back_tx, sfTrue);
    sfSprite_setTexture(s_all->s_stars.front, s_all->s_stars.front_tx, sfTrue);
    stars_create_texture(s_all, s_all->s_stars.back, s_all->s_stars.render1);
    stars_create_texture(s_all, s_all->s_stars.front, s_all->s_stars.render2);
    s_all->s_stars.pos = (sfVector2f){-128 * 15, -128 * 15};
    s_all->s_stars.pos2 = (sfVector2f){-128 * 15, -128 * 15};
}

int check_hitbox_stars(all_t *s_all)
{
    if (s_all->s_movement.up == 1 && s_all->s_movement.down == 1
    && s_all->s_movement.left == 1 && s_all->s_movement.right == 0
    && s_all->s_movement.wall_down == 1 && s_all->s_movement.wall_left == 0
    && s_all->s_movement.wall_right == 0) return (1);
    if (s_all->s_movement.up == 1 && s_all->s_movement.down == 1
    && s_all->s_movement.left == 0 && s_all->s_movement.right == 1
    && s_all->s_movement.wall_down == 1 && s_all->s_movement.wall_left == 0
    && s_all->s_movement.wall_right == 0) return (1);
    if (s_all->s_movement.up == 0 && s_all->s_movement.down == 1
    && s_all->s_movement.left == 1 && s_all->s_movement.right == 1
    && s_all->s_movement.wall_down == 0 && s_all->s_movement.wall_left == 1
    && s_all->s_movement.wall_up == 0) return (1);
    if (s_all->s_movement.up == 1 && s_all->s_movement.down == 1
    && s_all->s_movement.left == 1 && s_all->s_movement.right == 0
    && s_all->s_movement.wall_right == 0 && s_all->s_movement.wall_left == 0
    && s_all->s_movement.wall_up == 1) return (1);
    return (0);
}

void move_stars(all_t *s_all, sfSprite *sprite, float speed, sfVector2f *pos)
{
    if (s_all->s_player.hero_seconds < 0.01 || s_all->s_player.tp == 1
    || s_all->s_game.pause == 1) return;
    if (s_all->s_movement.left == 1 && s_all->s_movement.wall_left == 0) {
        if (s_all->s_movement.right == 1) return;
        (*pos).x -= speed;
        sfSprite_setPosition(sprite, *pos);
    } if (s_all->s_movement.down == 1 && s_all->s_movement.wall_down == 0) {
        if (s_all->s_movement.up == 1) return;
        (*pos).y += speed;
        sfSprite_setPosition(sprite, *pos);
    } if (s_all->s_movement.right == 1 && s_all->s_movement.wall_right == 0) {
        if (s_all->s_movement.left == 1) return;
        (*pos).x += speed;
        sfSprite_setPosition(sprite, *pos);
    } if (s_all->s_movement.up == 1 && s_all->s_movement.wall_up == 0) {
        if (s_all->s_movement.down == 1) return;
        (*pos).y -= speed;
        sfSprite_setPosition(sprite, *pos);
    }
}

void display_stars(all_t *s_all)
{
    int check = 0;
    if (check_hitbox_stars(s_all) == 0) {
        check = move_stars2(s_all, s_all->s_stars.front,
            s_all->s_player.hero_speed - 1.5, &s_all->s_stars.pos);
        check = move_stars2(s_all, s_all->s_stars.back,
            s_all->s_player.hero_speed - 2, &s_all->s_stars.pos2);
        if (check == 0) {
            move_stars(s_all, s_all->s_stars.front,
                s_all->s_player.hero_speed - 1.5, &s_all->s_stars.pos);
            move_stars(s_all, s_all->s_stars.back,
                s_all->s_player.hero_speed - 2, &s_all->s_stars.pos2);
        }
    }
    sfRenderWindow_drawSprite(s_all->s_game.window, s_all->s_stars.back, NULL);
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_stars.front, NULL);
}