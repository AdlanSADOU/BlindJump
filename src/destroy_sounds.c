/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_sounds
*/

#include "rpg.h"

void destroy_sounds2(all_t *s_all)
{
    sfSound_destroy(s_all->s_sounds.lvl);
    sfSound_destroy(s_all->s_sounds.dead);
    sfSound_destroy(s_all->s_sounds.player);
    sfSoundBuffer_destroy(s_all->s_sounds.dead_b);
    sfSound_destroy(s_all->s_sounds.item);
    sfSoundBuffer_destroy(s_all->s_sounds.item_b);
    sfSound_destroy(s_all->s_sounds.tp);
    sfSoundBuffer_destroy(s_all->s_sounds.heart_b);
    sfSound_destroy(s_all->s_sounds.heart);
    sfSoundBuffer_destroy(s_all->s_sounds.tp_b);
    sfSoundBuffer_destroy(s_all->s_sounds.lvl_b);
    sfSoundBuffer_destroy(s_all->s_sounds.player_b);
    sfMusic_destroy(s_all->s_sounds.music);
}

void destroy_sounds(all_t *s_all)
{
    sfSound_destroy(s_all->s_sounds.blast);
    sfSound_destroy(s_all->s_sounds.creak);
    sfSound_destroy(s_all->s_sounds.laser);
    sfSound_destroy(s_all->s_sounds.hit);
    sfSound_destroy(s_all->s_sounds.step1);
    sfSound_destroy(s_all->s_sounds.step2);
    sfSound_destroy(s_all->s_sounds.step3);
    sfSound_destroy(s_all->s_sounds.step4);
    sfSound_destroy(s_all->s_sounds.step5);
    sfSoundBuffer_destroy(s_all->s_sounds.blast_b);
    sfSoundBuffer_destroy(s_all->s_sounds.creak_b);
    sfSoundBuffer_destroy(s_all->s_sounds.laser_b);
    sfSoundBuffer_destroy(s_all->s_sounds.hit_b);
    sfSoundBuffer_destroy(s_all->s_sounds.step1_b);
    sfSoundBuffer_destroy(s_all->s_sounds.step2_b);
    sfSoundBuffer_destroy(s_all->s_sounds.step3_b);
    sfSoundBuffer_destroy(s_all->s_sounds.step4_b);
    sfSoundBuffer_destroy(s_all->s_sounds.step5_b);
    destroy_sounds2(s_all);
}