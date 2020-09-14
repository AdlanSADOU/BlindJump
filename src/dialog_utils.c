/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** dialog_utils
*/

#include "rpg.h"

void add_text(all_t *s_all, char *buf)
{
    sfText_setString(s_all->s_chatbox.text, buf);
    sfClock_restart(s_all->s_chatbox.clock);
}

void dialog_time(all_t *s_all)
{
    s_all->s_chatbox.time = sfClock_getElapsedTime(s_all->s_chatbox.clock);
    s_all->s_chatbox.sec = sfTime_asSeconds(s_all->s_chatbox.time);
}