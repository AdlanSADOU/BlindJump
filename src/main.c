/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main
*/

#include "rpg.h"
#include "utils.h"

int main(int ac, char **av)
{
    all_t s_all;

    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h'))
        write_file(".header");
    else if (ac == 1) {
        init_all(&s_all);
        if (game_loop(&s_all) == EXIT_FAILURE)
            return (84);
    }
    else {
        write(2, "USAGE\n    ./my_rpg [-h]\n", 24);
        return (84);
    }

    return (EXIT_SUCCESS);
}
