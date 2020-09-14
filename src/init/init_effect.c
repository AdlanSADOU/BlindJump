/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_effect
*/

#include "rpg.h"

void init_effect2(all_t *s_all)
{
    s_all->s_effect.vignette_state = malloc(sizeof(sfRenderStates));
    s_all->s_effect.vignette_state->shader = NULL;
    s_all->s_effect.vignette_state->texture = NULL;
    s_all->s_effect.vignette_state->transform = sfTransform_Identity;
    s_all->s_effect.vignette_state->blendMode = sfBlendMultiply;
    s_all->s_effect.tp_glow = sfSprite_create();
    s_all->s_effect.tp_glow_tx =
        sfTexture_createFromFile("sprites/tp_glow.png", NULL);
    sfSprite_setTexture(s_all->s_effect.tp_glow,
        s_all->s_effect.tp_glow_tx, sfTrue);
    sfSprite_setPosition(s_all->s_effect.tp_glow,
        (sfVector2f){s_all->s_tp.tp_pos.x - 190, s_all->s_tp.tp_pos.y - 195});
    s_all->s_effect.anim = 0;
}

void init_effect(all_t *s_all)
{
    s_all->s_effect.light_state = malloc(sizeof(sfRenderStates));
    s_all->s_effect.light_state->shader = NULL;
    s_all->s_effect.light_state->texture = NULL;
    s_all->s_effect.light_state->transform = sfTransform_Identity;
    s_all->s_effect.light_state->blendMode = sfBlendAdd;
    s_all->s_effect.light_pos = render_pos_center(s_all);
    create_sprite(&s_all->s_effect.light, &s_all->s_effect.light_tx,
        s_all->s_effect.light_pos, "sprites/lamp_light.png");
    sfSprite_setPosition(s_all->s_effect.light, (sfVector2f){840, 470});
    sfSprite_setColor(s_all->s_effect.light, (sfColor){255, 255, 150, 255});
    s_all->s_effect.vignette_pos =
        (sfVector2f){s_all->s_player.hero_pos.x - 375,
        s_all->s_player.hero_pos.y - 194};
    sfSprite_setPosition(s_all->s_effect.vignette1,
        s_all->s_effect.vignette_pos);
    sfSprite_setPosition(s_all->s_effect.vignette2,
        s_all->s_effect.vignette_pos);
    init_effect2(s_all);
}