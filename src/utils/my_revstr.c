/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_revstr
*/

#include "utils.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str) - 1;
    char temp;

    for (int i = 0; i < len; i++) {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        len--;
    }

    return (str);
}