/*
** EPITECH PROJECT, 2020
** generator
** File description:
** map
*/

#include "rpg.h"

void format_map(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++) {

        for (int j = 0; maze[i][j] != '\0'; j++) {
            if (maze[i][j] == 'W')
                maze[i][j] = '0';
        }

    }
}