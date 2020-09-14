/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_itoa
*/

#include "utils.h"

char *my_itoa(int n)
{
    int nb = n, i = 0;
    char *str;
    while (nb != 0) {
        nb /= 10;
        i++;
    }
    nb = i - 1;
    str = malloc(sizeof(char) * i + 1);
    while (nb > -1) {
        str[nb] = (n % 10) + 48;
        n /= 10;
        nb--;
    }
    str[i] = '\0';
    return str;
}