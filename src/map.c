/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** map2
*/

#include "rpg.h"

void init_map(all_t *s_all)
{
    s_all->s_map.background_pos = (sfVector2f){200, 200};
    create_sprite(&s_all->s_map.background, &s_all->s_map.background_tx,
        s_all->s_map.background_pos, "sprites/background.png");
    sfSprite_setScale(s_all->s_map.background, (sfVector2f){2, 1.1});
    s_all->s_map.x = 80;
    s_all->s_map.y = 40, s_all->s_map.stage = 0;
    int size = s_all->s_map.x * s_all->s_map.y + 1;
    s_all->s_map.tileset = malloc(sizeof(tileset_t *) * size);
    s_all->s_map.tileset_tx =
        sfTexture_createFromFile("sprites/tile_set.png", NULL);
    s_all->s_map.grass_tx =
        sfTexture_createFromFile("sprites/grass_set.png", NULL);
    s_all->s_map.grass2_tx =
        sfTexture_createFromFile("sprites/grass_set_edge.png", NULL);
    s_all->s_map.tileset_pos = (sfVector2f){0, 0};
    s_all->s_map.map_sprite = NULL;
}

void map_hitbox2(all_t *s_all, int *direction, int *check)
{
    if (direction[0] == 0 && s_all->s_movement.up == 1) {
        s_all->s_movement.wall_up = 1;
        *check = 1;
    }
    if (direction[1] == 0 && s_all->s_movement.right == 1) {
        s_all->s_movement.wall_right = 1;
        *check = 1;
    }
    if (direction[2] == 0 && s_all->s_movement.down == 1) {
        s_all->s_movement.wall_down = 1;
        *check = 1;
    }
    if (direction[3] == 0 && s_all->s_movement.left == 1) {
        s_all->s_movement.wall_left = 1;
        *check = 1;
    }
}

int map_hitbox(all_t *s_all, sfFloatRect shadow_bounds)
{
    int i = 0;
    int direction[4] = {0, 0, 0, 0};
    int check = 0;
    sfFloatRect tile_bounds;
    for (; s_all->s_map.tileset[i] != NULL; i++) {
        tile_bounds = sfSprite_getGlobalBounds(s_all->s_map.tileset[i]->tile);
        direction[0] += sfFloatRect_contains(&tile_bounds, shadow_bounds.left +
        shadow_bounds.width / 2, shadow_bounds.top);
        direction[1] += sfFloatRect_contains(&tile_bounds, shadow_bounds.left +
        shadow_bounds.width, shadow_bounds.top + shadow_bounds.height / 2);
        direction[2] += sfFloatRect_contains(&tile_bounds, shadow_bounds.left +
        shadow_bounds.width / 2, shadow_bounds.top + shadow_bounds.height);
        direction[3] += sfFloatRect_contains(&tile_bounds, shadow_bounds.left,
        shadow_bounds.top + shadow_bounds.height / 2);
    }
    map_hitbox2(s_all, direction, &check);
    if (check != 0)
        return (1);
    return (0);
}

int loop_map_hitbox(all_t *s_all)
{
    if (s_all->s_game.scene != MAP)
        return (0);

    sfFloatRect shadow_bounds =
        sfSprite_getGlobalBounds(s_all->s_player.shadow);

    if (map_hitbox(s_all, shadow_bounds) == 1)
        return (1);
    return (0);
}

void display_tiles(all_t *s_all)
{
    if (s_all->s_map.map_sprite != NULL)
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_map.map_sprite, NULL);
}