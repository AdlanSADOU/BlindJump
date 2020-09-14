/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_health_drop
*/

#include "rpg.h"

void check_hearth_hitbox(all_t *s_all, hearth_t *tmp)
{
    sfFloatRect player = sfSprite_getGlobalBounds(s_all->s_player.shadow);
    sfFloatRect life = sfSprite_getGlobalBounds(tmp->hearth);
    if (sfFloatRect_intersects(&player, &life, NULL) == 1) {
        tmp->show = 1;
        s_all->s_infos.current_hp += 10;
        if (s_all->s_infos.current_hp > s_all->s_infos.max_hp)
            s_all->s_infos.current_hp = s_all->s_infos.max_hp;
        heal_hp(s_all);
    }
}

void display_hearth(all_t *s_all)
{
    hearth_t *tmp = s_all->s_life;
    sfVector2f pos;
    for (; tmp != NULL; tmp = tmp->next) {
        pos = sfSprite_getPosition(tmp->hearth);
        if (s_all->s_player.hero_pos.y + 10 <= pos.y || tmp->show == 1)
            continue;
        check_hearth_hitbox(s_all, tmp);
        sfRenderWindow_drawSprite(s_all->s_game.window, tmp->hearth, NULL);
    }
}

void display_hearth2(all_t *s_all)
{
    hearth_t *tmp = s_all->s_life;
    sfVector2f pos;
    for (; tmp != NULL; tmp = tmp->next) {
        pos = sfSprite_getPosition(tmp->hearth);
        if (s_all->s_player.hero_pos.y + 10 > pos.y || tmp->show == 1)
            continue;
        check_hearth_hitbox(s_all, tmp);
        sfRenderWindow_drawSprite(s_all->s_game.window, tmp->hearth, NULL);
    }
}

void free_hearth(all_t *s_all)
{
    hearth_t *tmp;
    while (s_all->s_life != NULL) {
        tmp = s_all->s_life->next;
        sfSprite_destroy(s_all->s_life->hearth);
        free(s_all->s_life);
        s_all->s_life = tmp;
    }
    s_all->s_life = NULL;
}

void push_front_hearth(all_t *s_all, mob_t *tmp)
{
    if (rand() % 2 == 0) return;
    hearth_t *life = malloc(sizeof(hearth_t));
    life->hearth = sfSprite_create();
    life->show = 0;
    life->life = 10;
    sfSprite_setTexture(life->hearth, s_all->s_game.hearth_tx, sfTrue);
    if (tmp->type == 'A')
        sfSprite_setPosition(life->hearth, (sfVector2f){tmp->mob_pos.x - 7,
            tmp->mob_pos.y - 9});
    else
        sfSprite_setPosition(life->hearth, (sfVector2f){tmp->mob_pos.x - 10,
            tmp->mob_pos.y - 5});
    sfSprite_setTextureRect(life->hearth, (sfIntRect){0, 0, 46, 46});
    sfSprite_setScale(life->hearth, (sfVector2f){0.4, 0.4});
    life->next = s_all->s_life;
    s_all->s_life = life;
}