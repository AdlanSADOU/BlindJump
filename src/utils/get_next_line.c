/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** get_next_line
*/

#include "utils.h"

static char buff[READ_SIZE];

char *first_alloc(int *save, int *my_index)
{
    static int len_alloc = 0;
    int len = *my_index;

    for (; buff[len] != '\n' && buff[len] != '\0'; len++);
    len_alloc = len - *my_index;
    char *str = malloc(sizeof(char) * len_alloc + 1);
    *save = len_alloc;

    return (str);
}

char *my_realloc(char *str, int *save)
{
    int len = 0;
    int cpy = 0;

    for (; buff[len] != '\n' && buff[len] != '\0'; len++);
    *save += len;

    char *new_str = malloc(sizeof(char) * *save + 1);
    if (new_str == NULL)
        return (NULL);

    for (; cpy != *save - len; cpy++)
        new_str[cpy] = str[cpy];
    free(str);

    return (new_str);
}

char *get_next_line_loop(int fd, int *rd, int *save, int *my_index)
{
    char *str = first_alloc(save, my_index);
    if (str == NULL)
        return (NULL);
    int i = 0;
    for (; buff[*my_index] != '\n'
    && buff[*my_index] != '\0'; *my_index += 1, i++) {
        str[i] = buff[*my_index];
        if (*my_index == READ_SIZE - 1) {
            *my_index = -1;
            *rd = read(fd, buff, READ_SIZE);
            if (buff[0] == '\n' || *rd <= 0) {
                str[i + 1] = '\0', buff[*rd] = '\0';
                *my_index += 1;
                return (str);
            } buff[*rd] = '\0', str = my_realloc(str, save);
            if (str == NULL)
                return (NULL);
        }
    } str[i] = '\0';
    return (str);
}

char *get_next_line(int fd)
{
    static int save = 0, rd = 1, my_index = READ_SIZE;
    if (fd == -1)
        return (NULL);

    if (my_index >= rd) {
        rd = read(fd, buff, READ_SIZE);
        my_index = 0;
        buff[rd] = '\0';
    }
    if (rd <= 0)
        return (NULL);
    else if (buff[my_index] == '\0')
        my_index++;

    char *str = get_next_line_loop(fd, &rd, &save, &my_index);
    if (str == NULL)
        return (NULL);
    if (buff[my_index] == '\n')
        my_index += 1;
    return (str);
}
