/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_sounds
*/

#include "rpg.h"

void init_soundbuffers2(all_t *s_all)
{
    s_all->s_sounds.dead_b =
    sfSoundBuffer_createFromFile("sounds/dead.wav");
    s_all->s_sounds.lvl_b =
    sfSoundBuffer_createFromFile("sounds/level.ogg");
    s_all->s_sounds.player_b =
    sfSoundBuffer_createFromFile("sounds/player.wav");
    s_all->s_sounds.tp_b =
    sfSoundBuffer_createFromFile("sounds/tp.ogg");
    s_all->s_sounds.item_b =
    sfSoundBuffer_createFromFile("sounds/gotitem.ogg");
    s_all->s_sounds.heart_b =
    sfSoundBuffer_createFromFile("sounds/life.ogg");
}

void init_soundbuffers(all_t *s_all)
{
    s_all->s_sounds.blast_b =
    sfSoundBuffer_createFromFile("sounds/blast1.ogg");
    s_all->s_sounds.hit_b =
    sfSoundBuffer_createFromFile("sounds/bite-small.wav");
    s_all->s_sounds.creak_b =
    sfSoundBuffer_createFromFile("sounds/creak.ogg");
    s_all->s_sounds.laser_b =
    sfSoundBuffer_createFromFile("sounds/laser.ogg");
    s_all->s_sounds.step1_b =
    sfSoundBuffer_createFromFile("sounds/footstepDirt1.ogg");
    s_all->s_sounds.step2_b =
    sfSoundBuffer_createFromFile("sounds/footstepDirt2.ogg");
    s_all->s_sounds.step3_b =
    sfSoundBuffer_createFromFile("sounds/footstepDirt3.ogg");
    s_all->s_sounds.step4_b =
    sfSoundBuffer_createFromFile("sounds/footstepDirt4.ogg");
    s_all->s_sounds.step5_b =
    sfSoundBuffer_createFromFile("sounds/footstepDirt5.ogg");
    init_soundbuffers2(s_all);
}

void apply_sounds(all_t *s_all)
{
    s_all->s_sounds.fat_bool = 0;
    sfSound_setBuffer(s_all->s_sounds.blast, s_all->s_sounds.blast_b);
    sfSound_setBuffer(s_all->s_sounds.creak, s_all->s_sounds.creak_b);
    sfSound_setBuffer(s_all->s_sounds.hit, s_all->s_sounds.hit_b);
    sfSound_setBuffer(s_all->s_sounds.laser, s_all->s_sounds.laser_b);
    sfSound_setBuffer(s_all->s_sounds.step1, s_all->s_sounds.step1_b);
    sfSound_setBuffer(s_all->s_sounds.step2, s_all->s_sounds.step2_b);
    sfSound_setBuffer(s_all->s_sounds.step3, s_all->s_sounds.step3_b);
    sfSound_setBuffer(s_all->s_sounds.step4, s_all->s_sounds.step4_b);
    sfSound_setBuffer(s_all->s_sounds.step5, s_all->s_sounds.step5_b);
    sfSound_setBuffer(s_all->s_sounds.lvl, s_all->s_sounds.lvl_b);
    sfSound_setBuffer(s_all->s_sounds.dead, s_all->s_sounds.dead_b);
    sfSound_setBuffer(s_all->s_sounds.player, s_all->s_sounds.player_b);
    sfSound_setBuffer(s_all->s_sounds.tp, s_all->s_sounds.tp_b);
    sfSound_setBuffer(s_all->s_sounds.item, s_all->s_sounds.item_b);
    sfSound_setBuffer(s_all->s_sounds.heart, s_all->s_sounds.heart_b);
}

void play_random_sound(all_t *s_all)
{
    int i = rand() % 5;
    if (i == 0) {
        sfSound_play(s_all->s_sounds.step1);
    }
    if (i == 1) {
        sfSound_play(s_all->s_sounds.step2);
    }
    if (i == 2) {
        sfSound_play(s_all->s_sounds.step3);
    }
    if (i == 3) {
        sfSound_play(s_all->s_sounds.step4);
    }
    if (i == 4) {
        sfSound_play(s_all->s_sounds.step5);
    }
}

void init_sounds(all_t *s_all)
{
    s_all->s_sounds.blast = sfSound_create();
    s_all->s_sounds.creak = sfSound_create();
    s_all->s_sounds.hit = sfSound_create();
    s_all->s_sounds.laser = sfSound_create();
    s_all->s_sounds.lvl = sfSound_create();
    s_all->s_sounds.dead = sfSound_create();
    s_all->s_sounds.step1 = sfSound_create();
    s_all->s_sounds.step2 = sfSound_create();
    s_all->s_sounds.step3 = sfSound_create();
    s_all->s_sounds.step4 = sfSound_create();
    s_all->s_sounds.step5 = sfSound_create();
    s_all->s_sounds.player = sfSound_create();
    s_all->s_sounds.heart = sfSound_create();
    s_all->s_sounds.tp = sfSound_create();
    s_all->s_sounds.item = sfSound_create();
    s_all->s_sounds.music = sfMusic_createFromFile("music/Frostellar.ogg");
    sfMusic_setVolume(s_all->s_sounds.music, 60);
    sfMusic_setLoop(s_all->s_sounds.music, sfTrue);
    init_soundbuffers(s_all);
    apply_sounds(s_all);
}