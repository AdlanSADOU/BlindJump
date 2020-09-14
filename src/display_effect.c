/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_effect
*/

#include "rpg.h"

void display_light_spawn(all_t *s_all)
{
    sfSprite_setPosition(s_all->s_effect.light, (sfVector2f){840, 470});
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_effect.light, s_all->s_effect.light_state);
    sfSprite_setPosition(s_all->s_effect.light, (sfVector2f){580, 360});
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_effect.light, s_all->s_effect.light_state);
    sfSprite_setPosition(s_all->s_effect.light, (sfVector2f){580, 170});
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_effect.light, s_all->s_effect.light_state);
    sfSprite_setPosition(s_all->s_effect.light, (sfVector2f){840, 20});
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_effect.light, s_all->s_effect.light_state);
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_effect.tp_glow, s_all->s_effect.light_state);
}