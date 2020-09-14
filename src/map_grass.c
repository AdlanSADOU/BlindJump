/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** map_grass
*/

#include "rpg.h"

char **init_new_gass_map(all_t *s_all)
{
    static int i = 0;
    if (i == 0)
        s_all->s_map.grass = create_map(s_all->s_map.x, s_all->s_map.y);
    else {
        free(s_all->s_map.grass);
        s_all->s_map.grass = create_map(s_all->s_map.x, s_all->s_map.y);
    }
    char **new_map = copy_map(s_all->s_map.grass);
    i = 1;
    fill_random_map(s_all->s_map.grass);
    for (int i = 0; i != 10; i++)
        simulation_step(s_all->s_map.grass, new_map);
    free_map(s_all->s_map.grass);
    for (int i = 0, j = 0; s_all->s_map.map[i] != NULL; i++, j = 0)
        for (; s_all->s_map.map[i][j] != '\0'; j++)
            if (s_all->s_map.map[i][j] == '1')
                new_map[i][j] = '1';
    return (new_map);
}

int check_grass(char **map, int i, int j)
{
    int check = 0;

    if (i - 1 == -1 || map[i - 1][j] == '1')
        check += 1000;
    if (map[i][j + 1] != '0')
        check += 100;
    if (map[i + 1] == NULL || map[i + 1][j] == '1')
        check += 10;
    if (j - 1 == -1 || map[i][j - 1] == '1')
        check += 1;

    return (check);
}

void rect_grass2(tileset_t *tile, int check)
{
    if (check == 1111)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){0, 0, 32, 26});
    if (check == 111)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 1, 0, 32, 26});
    if (check == 1011)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 2, 0, 32, 26});
    if (check == 11)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 3, 0, 32, 26});
    if (check == 1101)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 4, 0, 32, 26});
    if (check == 101)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 5, 0, 32, 26});
    if (check == 1001)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 6, 0, 32, 26});
    if (check == 1)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 7, 0, 32, 26});
    if (check == 1110)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 8, 0, 32, 26});
    if (check == 110)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 9, 0, 32, 26});
}

void rect_grass(tileset_t *tile, char **map, int i, int j)
{
    int check = check_grass(map, i, j);

    rect_grass2(tile, check);
    if (check == 1010)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 10, 0, 32, 26});
    if (check == 10)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 11, 0, 32, 26});
    if (check == 1100)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 12, 0, 32, 26});
    if (check == 100)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 13, 0, 32, 26});
    if (check == 1000)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 14, 0, 32, 26});
    if (check == 0)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 15, 0, 32, 26});
}

void set_grass(tileset_t *tile, all_t *s_all, int i, int j)
{
    char **map = s_all->s_map.map;
    char **grass = s_all->s_map.grass;
    int random = rand() % 100;

    if (map[i][j] != '1' && grass[i][j] == '0') {
        tile->grass = sfSprite_create();
        if (random <= 35)
            sfSprite_setTexture(tile->grass, s_all->s_map.grass_tx, sfTrue);
        else
            sfSprite_setTexture(tile->grass, s_all->s_map.grass2_tx, sfTrue);
        sfSprite_setPosition(tile->grass, (sfVector2f){s_all->s_map.
        tileset_pos.x, s_all->s_map.tileset_pos.y});
        rect_grass(tile, grass, i, j);
    }
    else
        tile->grass = NULL;
}