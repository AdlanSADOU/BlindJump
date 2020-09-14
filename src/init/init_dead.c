/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_dead
*/

#include "rpg.h"

void init_dead(all_t *s_all)
{
    s_all->s_dead.dead = sfSprite_create();
    s_all->s_dead.clock = sfClock_create();
    s_all->s_dead.respawn = sfText_create();
    s_all->s_dead.dead_tx = s_all->s_player.hero_tx;
    s_all->s_dead.rect = (sfIntRect){209, 39, 40, 37};
    sfText_setFont(s_all->s_dead.respawn, s_all->s_game.font);
    sfText_setString(s_all->s_dead.respawn, "Press R to respawn");
    sfText_setPosition(s_all->s_dead.respawn, (sfVector2f){835, 900});
    sfSprite_setTexture(s_all->s_dead.dead, s_all->s_dead.dead_tx, sfTrue);
    sfSprite_setTextureRect(s_all->s_dead.dead, s_all->s_dead.rect);
    sfSprite_setPosition(s_all->s_dead.dead, s_all->s_player.hero_pos);
    s_all->s_dead.seconds = 0;
    s_all->s_dead.fuck = 0;
}

void rect_dead(all_t *s_all)
{
    if (s_all->s_dead.seconds > 0.05 && s_all->s_dead.fuck == 0) {
        if (s_all->s_dead.rect.left < 609) {
            s_all->s_dead.rect.left += 40;
        }
        else s_all->s_dead.fuck = 1;
        sfSprite_setTextureRect(s_all->s_dead.dead, s_all->s_dead.rect);
        sfClock_restart(s_all->s_dead.clock);
    }
}

void display_dead(all_t *s_all)
{
    if (s_all->s_game.scene == GAME_OVER) {
        sfRenderWindow_clear(s_all->s_game.window, sfBlack);
        sfRenderWindow_setView(s_all->s_game.window, s_all->s_game.camera);
        sfSprite_setPosition(s_all->s_map.background,
            s_all->s_effect.vignette_pos);
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_map.background, NULL);
        display_stars(s_all), display_tiles(s_all);
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_tp.tp, NULL);
        int y = display_chests_under(s_all);
        display_mobs_death_under(s_all), display_hearth(s_all);
        rect_dead(s_all);
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_dead.dead, NULL);
        display_chests_over(s_all, y);
        display_mobs_death_over(s_all), display_hearth2(s_all);
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_effect.tp_glow, s_all->s_effect.light_state);
    }
}