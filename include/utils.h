/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

char *get_next_line(int fd);

#ifndef READ_SIZE
#define READ_SIZE (100)
#endif /* !UTILS_H_ */

int randomizer(FILE *file);
int randomize(void);
void write_field(char *field, int fd, char *data);
char *read_field(char *field, int fd);

char *my_strdup(char *str);
int my_strcmp(const char *s1, char *s2);
int my_strlen(const char *str);
char *my_strcat(char *dest, char const *src);
char *strnbr(int n);
char *strnbr_float(float n);
int my_atoi(char const *str);
char *my_strcpy(char *dest, char *src);
char *my_revstr(char *str);
void my_putstr(char *str);
void write_file(char *filepath);
char *my_itoa(int n);

#endif /* !UTILS_H_ */
