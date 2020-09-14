/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_strcpy
*/

#include "utils.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';

    return (dest);
}
