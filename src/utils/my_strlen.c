/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_strlen
*/

#include "utils.h"

int my_strlen(const char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);

    for (; str[i] != '\0'; i++);

    return (i);
}

int my_ptrlen(char **str)
{
    int i = 0;
    for (; str[i] != NULL; i++);
    return (i);
}
