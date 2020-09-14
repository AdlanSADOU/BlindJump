/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_load
*/

#include "rpg.h"
#include "utils.h"

void set_load(all_t *s_all, load_t *new, sfVector2f pos, char *level)
{
    int fd = 0;
    new->fion = 0;
    if (new->id == 1) fd = open("saves/save1", O_RDWR);
    if (new->id == 2) fd = open("saves/save2", O_RDWR);
    if (new->id == 3) fd = open("saves/save3", O_RDWR);
    sfText_setString(new->p_name_tx, read_field("name", fd));
    sfSprite_setColor(new->hero, (sfColor){my_atoi(read_field("r", fd)),
    my_atoi(read_field("g", fd)), my_atoi(read_field("b", fd)), 255});
    my_strcat(level, read_field("level", fd));
    sfText_setString(new->level_tx, level);
    sfText_setPosition(new->p_name_tx, pos);
    sfSprite_setPosition(new->hero, (sfVector2f){pos.x + 10, pos.y + 150});
    sfText_setPosition(new->level_tx, (sfVector2f){pos.x - 5, pos.y + 350});
    sfSprite_setPosition(new->button, (sfVector2f){pos.x - 15, pos.y + 450});
    sfText_setFont(new->level_tx, s_all->s_game.font);
    sfText_setFont(new->p_name_tx, s_all->s_game.font);
}

load_t *fill_load_slot(all_t *s_all, load_t *old, sfVector2f pos, int id)
{
    load_t *new = malloc(sizeof(load_t));
    char *level = malloc(20);
    level[0] = '\0';
    my_strcat(level, "Level ");
    new->hero = sfSprite_create(), new->button = sfSprite_create();
    new->level_tx = sfText_create(), new->p_name_tx = sfText_create();
    new->hero_tx = s_all->s_player.hero_tx;
    sfSprite_setTexture(new->hero, new->hero_tx, sfTrue);
    sfSprite_setTextureRect(new->hero, (sfIntRect){406, 109, 20, 31});
    sfSprite_setScale(new->hero, (sfVector2f){4, 4});
    new->id = id;
    set_load(s_all, new, pos, level);
    new->next = old;
    return (new);
}

void free_load_slots(all_t *s_all)
{
    load_t *tmp = s_all->s_load;
    load_t *old = NULL;
    while (tmp != NULL) {
        sfSprite_destroy(tmp->button);
        sfSprite_destroy(tmp->hero);
        sfText_destroy(tmp->level_tx);
        sfText_destroy(tmp->p_name_tx);
        old = tmp;
        tmp = tmp->next;
        free(old);
    } s_all->s_load = NULL;
}

void init_load_slots(all_t *s_all)
{
    int i = 1;
    sfTexture *load, *hover, *clicked;
    load = sfTexture_createFromFile("sprites/buttons/load.png", NULL);
    hover = sfTexture_createFromFile("sprites/buttons/load_hover.png", NULL);
    clicked =
    sfTexture_createFromFile("sprites/buttons/load_clicked.png", NULL);
    sfVector2f pos = (sfVector2f){450, 200};
    s_all->s_load = NULL;
    for (; i != 4; i++) {
        s_all->s_load = fill_load_slot(s_all, s_all->s_load, pos, i);
        s_all->s_load->normal = load;
        s_all->s_load->hover = hover;
        s_all->s_load->click = clicked;
        sfSprite_setTexture(s_all->s_load->button,
        s_all->s_load->normal, sfTrue);
        pos.x += 450;
    }
}