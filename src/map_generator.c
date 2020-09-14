/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** map_generator
*/

#include "rpg.h"

char **copy_map(char **old_map)
{
    int lines = 0;
    int cols = my_strlen(old_map[0]);

    for (; old_map[lines] != NULL; lines++);
    char **new_map = malloc(sizeof(char *) * (lines + 1));

    for (int i = 0, j = 0; old_map[i] != NULL; i++) {
        new_map[i] = malloc(sizeof(char) * (cols + 1));
        for (j = 0; old_map[i][j] != '\0'; j++) {
            new_map[i][j] = old_map[i][j];
        }
        new_map[i][j] = '\0';
    }
    new_map[lines] = NULL;

    return (new_map);
}

void fill_random_map(char **map)
{
    int random = 0;
    int chance = 38;

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            random = rand() % 100 + 1;
            if (random <= chance)
                map[i][j] = '1';
            else
                map[i][j] = '0';
        }
    }
}

int count_alive_neighbours(char **old_map, int x, int y)
{
    int count = 0;

    for (int i = y - 1; i != y + 2; i++) {
        for (int j = x - 1; j != x + 2; j++) {
            if (i == y && j == x)
                continue;
            else if (i < 0 || old_map[i] == NULL
            || j < 0 || old_map[i][j] == '\0')
                count++;
            else if (old_map[i][j] == '1')
                count++;
        }
    }

    return (count);
}

void simulation_print(char *new_map, char *old_map, int alive)
{
    if (*old_map == '1') {
        if (alive < 3)
            *new_map = '0';
        else
            *new_map = '1';
    }
    else {
        if (alive > 4)
            *new_map = '1';
        else
            *new_map = '0';
    }
}

void simulation_step(char **old_map, char **new_map)
{
    int alive = 0;

    for (int i = 0; old_map[i] != NULL; i++) {
        for (int j = 0; old_map[i][j] != '\0'; j++) {
            alive = count_alive_neighbours(old_map, j, i);
            simulation_print(&new_map[i][j], &old_map[i][j], alive);
        }
    }
}