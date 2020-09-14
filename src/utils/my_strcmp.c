/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compare char and return int
*/

#include "utils.h"

int my_strcmp(const char *s1, char *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] < s2[i])
            return (-1);
        else if (s1[i] > s2[i])
            return (1);
    }
    if (my_strlen(s1) < my_strlen(s2))
        return (-1);
    return (0);
}
