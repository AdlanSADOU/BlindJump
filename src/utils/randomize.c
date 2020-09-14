/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** randomize
*/

#include "utils.h"

int randomizer(FILE *file)
{
    unsigned int seed = 0;

    if (file == NULL)
        return (-1);

    if (fread(&seed, sizeof(seed), 1, file) == 1) {
        fclose(file);
        srand(seed);
        return (0);
    }
    fclose(file);

    return (-1);
}

int randomize(void)
{
    if (randomizer(fopen("/dev/urandom", "r")) == 0)
        return (0);

    if (randomizer(fopen("/dev/arandom", "r")) == 0)
        return (0);

    if (randomizer(fopen("/dev/random", "r")) == 0)
        return (0);

    return (-1);
}
