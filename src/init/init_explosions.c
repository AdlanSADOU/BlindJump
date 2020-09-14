/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_explosions
*/

#include "rpg.h"

void init_explosions(all_t *s_all)
{
    s_all->s_explode.sprite = sfSprite_create();
    s_all->s_explode.texture = s_all->s_player.hero_tx;
    s_all->s_explode.clock = sfClock_create();
    s_all->s_explode.rect = (sfIntRect){169, 225, 37, 37};
    sfSprite_setOrigin(s_all->s_explode.sprite, (sfVector2f){18.5, 18.5});
    sfSprite_setTexture(s_all->s_explode.sprite,
        s_all->s_explode.texture, sfTrue);
    s_all->s_explode.show = 0;
    s_all->s_explode.seconds = 0;
    sfSprite_setTextureRect(s_all->s_explode.sprite, s_all->s_explode.rect);
    sfSprite_setPosition(s_all->s_explode.sprite, s_all->s_player.hero_pos);
}

void rect_explosion(all_t *s_all)
{
    if (s_all->s_explode.rect.left < 354) {
        s_all->s_explode.rect.left += 37;
        sfSprite_setTextureRect(s_all->s_explode.sprite,
        s_all->s_explode.rect);
    } else {
        s_all->s_explode.rect.left = 169;
        sfSprite_setTextureRect(s_all->s_explode.sprite,
        s_all->s_explode.rect);
        s_all->s_explode.show = 0;
    }
}

void move_explosion(all_t *s_all)
{
    s_all->s_explode.show = 1;
    sfClock_restart(s_all->s_explode.clock);
}

void display_explosions(all_t *s_all)
{
    if (s_all->s_explode.show == 1) {
        if (s_all->s_explode.seconds > 0.04) {
            rect_explosion(s_all);
            sfClock_restart(s_all->s_explode.clock);
        }
        sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_explode.sprite, NULL);
    }
}