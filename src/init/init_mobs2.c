/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_mobs2
*/

#include "rpg.h"
#include "utils.h"

void init_mob_interface(mob_t *new, char type, all_t *s_all)
{
    int lvl = rand() % (s_all->s_map.stage + 1) + s_all->s_map.stage;
    new->text = sfText_create();
    sfText_setFont(new->text, s_all->s_game.font);
    sfText_setPosition(new->text, (sfVector2f)
        {new->mob_pos.x - 10, new->mob_pos.y - 10});
    new->name = malloc(25), new->name[0] = '\0', new->lvl = lvl;
    if (type == 'B') {
        my_strcat(new->name, "Blob lvl "), new->hp = (150 * lvl) / 2;
    } if (type == 'A') {
        my_strcat(new->name, "Roball lvl "), new->hp = (100 * lvl) / 2;
    } if (type == 'T') {
        my_strcat(new->name, "Sentry lvl "), new->hp = (400 * lvl) / 2;
    } my_strcat(new->name, strnbr(lvl)), sfText_setCharacterSize(new->text, 7);
    sfText_setString(new->text, new->name);
    sfText_setColor(new->text, (sfColor){255, 255, 255, 255});
}

void roballs(mob_t *new, char type, sfVector2f pos, all_t *s_all)
{
    if (type == 'A') {
        sfSprite_setScale(new->shadow, (sfVector2f){0.80, 0.80});
        new->mob_pos.x += 5, new->mob_pos.y += 5, new->speed = 1;
        new->shadow_pos = (sfVector2f){pos.x + 6, pos.y + 14};
        new->rect = (sfIntRect){88, 161, 12, 12};
        sfSprite_setOrigin(new->mob, (sfVector2f){6, 6});
        new->xp = 15, new->hp = 100;
        new->bullet = sfSprite_create();
        sfSprite_setTexture(new->bullet, s_all->s_player.hero_tx, sfTrue);
        sfSprite_setTextureRect(new->bullet, (sfIntRect){27, 76, 8, 15});
        sfSprite_setPosition(new->bullet, (sfVector2f){new->mob_pos.x - 4,
        new->mob_pos.y - 8});
        sfSprite_setOrigin(new->bullet, (sfVector2f){4, 7});
    }
}

void roballs_angle(mob_t *tmp, sfVector2f player_pos)
{
    float angle_mob = atan2(player_pos.y - (tmp->mob_pos.y),
        player_pos.x - (tmp->mob_pos.x));
    angle_mob = angle_mob * 180 / MY_PI;
    angle_mob -= 90;
    if (angle_mob < 0) angle_mob = 360 + angle_mob;
    sfSprite_setRotation(tmp->bullet, angle_mob);
}

void roballs_shoot(mob_t *tmp, all_t *s_all)
{
    if ((tmp->shoot == 0 && tmp->check_shoot == 0)
    || tmp->shoot_seconds < 0.01 || s_all->s_player.tp == 1) return;
    if (tmp->hit == 0) {
        sfVector2f bullet_pos = sfSprite_getPosition(tmp->bullet);
        if (tmp->check_shoot == 0) {
            sfVector2f player_pos =
                sfSprite_getPosition(s_all->s_player.shadow);
            player_pos.x += 8, player_pos.y -= 10;
            roballs_angle(tmp, player_pos);
            tmp->vx = player_pos.x - bullet_pos.x;
            tmp->vy = player_pos.y - bullet_pos.y;
            tmp->normalize = sqrt(pow(tmp->vx, 2) + pow(tmp->vy, 2));
            tmp->check_shoot = 1;
        } bullet_pos.x = bullet_pos.x
            + (tmp->bullet_speed * (tmp->vx / tmp->normalize));
        bullet_pos.y = bullet_pos.y
            + (tmp->bullet_speed * (tmp->vy / tmp->normalize));
        sfSprite_setPosition(tmp->bullet, bullet_pos);
        } tmp->bullet_travel++;
    sfClock_restart(tmp->shoot_clock);
}

void display_mobs2(mob_t *temp, all_t *s_all)
{
    sfRenderWindow_drawSprite(s_all->s_game.window, temp->shadow, NULL);
    sfRenderWindow_drawSprite(s_all->s_game.window, temp->mob, NULL);
    sfRenderWindow_drawText(s_all->s_game.window, temp->text, NULL);
    sfText_setPosition(temp->text, (sfVector2f)
        {temp->mob_pos.x - 20, temp->mob_pos.y - 15});
    if (temp->type == 'T')
        sfText_setPosition(temp->text, (sfVector2f)
        {temp->mob_pos.x - 24, temp->mob_pos.y - 25});
    if (temp->type == 'B')
        sfText_setPosition(temp->text, (sfVector2f)
        {temp->mob_pos.x - 20, temp->mob_pos.y - 18});
    sfSprite_setPosition(temp->mob, temp->mob_pos);
    sfSprite_setPosition(temp->shadow, temp->shadow_pos);
    display_mobs3(temp, s_all);
}