/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** write_file
*/

#include "utils.h"

void write_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return;

    char *str = get_next_line(fd);

    while (str != NULL) {
        my_putstr(str);
        my_putstr("\n");
        free(str);
        str = get_next_line(fd);
    }
}