/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_minimap
*/

#include "rpg.h"

float calcul_tp_magnitude(all_t *s_all)
{
    sfVector2f player = sfCircleShape_getPosition(s_all->s_minimap.player);
    sfVector2f tp = sfCircleShape_getPosition(s_all->s_minimap.tp);
    float vx = tp.x - player.x;
    float vy = tp.y - player.y;
    float magnitude = sqrt(pow(vx, 2) + pow(vy, 2));
    return (magnitude);
}

void display_minimap(all_t *s_all)
{
    if (s_all->s_game.scene == MAP) {
        sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        s_all->s_minimap.black, NULL);
        sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_minimap.sprite, NULL);
        sfCircleShape_setPosition(s_all->s_minimap.tp,
        (sfVector2f){(s_all->s_tp.tp_pos.x + 47) / 5,
        (s_all->s_tp.tp_pos.y + 50) / 5});
        if (calcul_tp_magnitude(s_all) < 45)
            s_all->s_minimap.dispay_tp = 1;
        if (s_all->s_player.tp == 0 && s_all->s_minimap.dispay_tp == 1)
            sfRenderWindow_drawCircleShape(s_all->s_game.window,
            s_all->s_minimap.tp, NULL);
        sfCircleShape_setPosition(s_all->s_minimap.player,
        (sfVector2f){(s_all->s_player.hero_pos.x + 47) / 5,
        (s_all->s_player.hero_pos.y + 60) / 5});
        sfRenderWindow_drawCircleShape(s_all->s_game.window,
        s_all->s_minimap.player, NULL);
    }
}

void init_minimap2(all_t *s_all)
{
    s_all->s_minimap.player = sfCircleShape_create();
    sfCircleShape_setFillColor(s_all->s_minimap.player,
        (sfColor){255, 0, 0, 255});
    sfCircleShape_setRadius(s_all->s_minimap.player, 3);
    s_all->s_minimap.tp = sfCircleShape_create();
    sfCircleShape_setFillColor(s_all->s_minimap.tp,
        (sfColor){0, 255, 255, 255});
    sfCircleShape_setRadius(s_all->s_minimap.tp, 3);
    s_all->s_minimap.dispay_tp = 0;
    char *str = malloc(sizeof(char) * 20);
    str[0] = '\0';
    str = my_strcat(str, "STAGE ");
    str = my_strcat(str, strnbr(s_all->s_map.stage));
    sfText_setString(s_all->s_game.the_stage, str);
    free(str);
}

void init_minimap(all_t *s_all)
{
    static int i = 0;
    if (i == 0) s_all->s_minimap.sprite = sfSprite_create();
    sfSprite_setTexture(s_all->s_minimap.sprite,
        s_all->s_map.map_texture, sfTrue);
    if (i == 0) {
        s_all->s_minimap.black = sfRectangleShape_create();
        sfRectangleShape_setSize(s_all->s_minimap.black,
            (sfVector2f){530, 224});
        sfRectangleShape_setFillColor(s_all->s_minimap.black,
            (sfColor){0, 0, 0, 150});
    } sfSprite_setScale(s_all->s_minimap.sprite, (sfVector2f){0.2, -0.2});
    sfSprite_setPosition(s_all->s_minimap.sprite, (sfVector2f){10, 215});
    sfRectangleShape_setPosition(s_all->s_minimap.black, (sfVector2f){0, 0});
    sfSprite_setColor(s_all->s_minimap.sprite, (sfColor){255, 255, 255, 150});
    init_minimap2(s_all);
    i = 1;
}