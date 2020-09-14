/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_strcat
*/

#include "utils.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(dest);

    for (; src[i] != '\0'; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';

    return (dest);
}
