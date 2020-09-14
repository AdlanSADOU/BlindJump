/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_putstr
*/

#include "utils.h"

void my_putstr(char *str)
{
    if (str != NULL)
        write(1, str, my_strlen(str));
}