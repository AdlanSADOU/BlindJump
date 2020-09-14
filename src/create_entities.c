/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_sprite
*/

#include "rpg.h"

void create_sprite(sfSprite **sprite, sfTexture **texture,
    sfVector2f pos, const char *path)
{
    *sprite = sfSprite_create();
    *texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(*sprite, *texture, sfTrue);
    sfSprite_setPosition(*sprite, pos);
}

void quest_display(all_t *s_all)
{
    if (s_all->s_map.stage == 5 && s_all->s_cine.script < 7)
        sfText_setString(s_all->s_game.quest, "KILL EVERY THREATS");
    else if (s_all->s_map.stage < 5 && s_all->s_cine.script < 7)
        sfText_setString(s_all->s_game.quest, "REACH THE STAGE 5");
    else sfText_setString(s_all->s_game.quest, "INFINITE MODE");
}

void set_volume(all_t *s_all)
{
    sfMusic_setVolume(s_all->s_sounds.music, s_all->s_game.volume);
    sfSound_setVolume(s_all->s_sounds.blast, s_all->s_game.volume);
    sfSound_setVolume(s_all->s_sounds.creak, s_all->s_game.volume);
    sfSound_setVolume(s_all->s_sounds.dead, s_all->s_game.volume);
    sfSound_setVolume(s_all->s_sounds.heart, s_all->s_game.volume);
    sfSound_setVolume(s_all->s_sounds.hit, s_all->s_game.volume);
    sfSound_setVolume(s_all->s_sounds.item, s_all->s_game.volume);
    sfSound_setVolume(s_all->s_sounds.laser, s_all->s_game.volume);
    sfSound_setVolume(s_all->s_sounds.lvl, s_all->s_game.volume);
    sfSound_setVolume(s_all->s_sounds.player, s_all->s_game.volume);
    sfSound_setVolume(s_all->s_sounds.step1, s_all->s_game.volume);
    sfSound_setVolume(s_all->s_sounds.step2, s_all->s_game.volume);
    sfSound_setVolume(s_all->s_sounds.step3, s_all->s_game.volume);
    sfSound_setVolume(s_all->s_sounds.step4, s_all->s_game.volume);
    sfSound_setVolume(s_all->s_sounds.step5, s_all->s_game.volume);
    sfSound_setVolume(s_all->s_sounds.tp, s_all->s_game.volume);
}