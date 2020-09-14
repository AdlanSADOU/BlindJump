/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** my_atoi
*/

#include "utils.h"

int my_atoi(char const *str)
{
    int i = 0;
    int result = 0;
    int check = 0;

    if (str[0] == '\0' || (str[0] > '9' && str[0] < '0'))
        return (0);
    if (str[0] == '-' && (str[1] <= '9' && str[1] >= '0')) {
        check++;
        i++;
    }
    if (str[0] == '+' && (str[1] <= '9' && str[1] >= '0'))
        i++;
    for (; str[i] != '\0' && (str[i] <= '9' && str[i] >= '0'); i++) {
        result += str[i] - '0';
        if (str[i+1] <= '9' && str[i+1] >= '0')
            result *= 10;
    }
    if (check == 1)
        result *= -1;
    return (result);
}
