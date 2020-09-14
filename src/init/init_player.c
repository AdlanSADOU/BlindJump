/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_hero
*/

#include "rpg.h"

void init_hero3(all_t *s_all)
{
    sfSprite_setColor(s_all->s_player.gun, (sfColor){170, 170, 170, 255});
    sfSprite_setScale(s_all->s_player.gun, (sfVector2f){0.79, 0.79});
    s_all->s_player.hit_sprite = sfSprite_create();
    sfSprite_setTexture(s_all->s_player.hit_sprite,
        s_all->s_player.hero_tx, sfTrue);
    s_all->s_player.hit_rect = (sfIntRect){88, 145, 16, 16};
    sfSprite_setTextureRect(s_all->s_player.hit_sprite,
    s_all->s_player.hit_rect), s_all->s_infos.is_color = 0;
    sfSprite_setOrigin(s_all->s_player.hit_sprite, (sfVector2f){8, 8});
    s_all->s_player.hit_clk = sfClock_create();
    s_all->s_player.refresh_clk = sfClock_create();
    s_all->s_player.shoot_pos = (sfVector2f){s_all->s_player.hero_pos.x + 11,
    s_all->s_player.hero_pos.y + 20}, s_all->s_infos.dmg = 50;
    s_all->s_player.ver_pos = s_all->s_player.shoot_pos;
    s_all->s_player.hor_pos = s_all->s_player.shoot_pos;
    s_all->s_player.hit = 0, s_all->s_player.right = 0;
    s_all->s_player.down = 0, s_all->s_player.up = 0, s_all->s_player.left = 0;
    s_all->s_player.range = 120, s_all->s_player.shooting = 0;
    s_all->s_player.heal = malloc(sizeof(char) * 20);
    s_all->s_player.heal[0] = '\0';
}

void init_hero2(all_t *s_all)
{
    s_all->s_player.shadow = sfSprite_create();
    sfSprite_setTexture(s_all->s_player.shadow,
        s_all->s_player.hero_tx, sfTrue);
    s_all->s_player.shadow_pos = (sfVector2f){s_all->s_player.hero_pos.x + 4,
        s_all->s_player.hero_pos.y + 25};
    sfSprite_setPosition(s_all->s_player.shadow, s_all->s_player.shadow_pos);
    sfSprite_setTextureRect(s_all->s_player.shadow,
        (sfIntRect){2, 104, 15, 8});
    s_all->s_player.debug_shadow =
        init_hitbox_debug(s_all->s_player.debug_shadow,
        s_all->s_player.shadow_pos, s_all->s_player.shadow);
    s_all->s_player.tp = 0;
    s_all->s_player.gun = sfSprite_create();
    sfSprite_setTexture(s_all->s_player.gun,
        s_all->s_player.hero_tx, sfTrue);
    sfSprite_setPosition(s_all->s_player.gun,
        (sfVector2f){s_all->s_player.hero_pos.x + 4,
        s_all->s_player.hero_pos.y + 17});
    sfSprite_setTextureRect(s_all->s_player.gun,
        (sfIntRect){687, 107, 23, 10});
}

void init_shooting(all_t *s_all)
{
    s_all->s_player.hor_shoot = sfSprite_create();
    s_all->s_player.ver_shoot = sfSprite_create();
    s_all->s_player.shoot_clk = sfClock_create();
    s_all->s_player.ver = 0, s_all->s_player.hor = 0;
    s_all->s_player.ver_shoot_txt = s_all->s_player.hero_tx;
    s_all->s_player.hor_shoot_txt = s_all->s_player.hero_tx;
    sfSprite_setTexture(s_all->s_player.hor_shoot,
    s_all->s_player.hor_shoot_txt, sfTrue);
    sfSprite_setTexture(s_all->s_player.ver_shoot,
    s_all->s_player.ver_shoot_txt, sfTrue);
    sfSprite_setTextureRect(s_all->s_player.hor_shoot,
    (sfIntRect){45, 82, 16, 5}), s_all->s_player.reload_sec = 0;
    sfSprite_setOrigin(s_all->s_player.hor_shoot, (sfVector2f){8, 2.5});
    sfSprite_setScale(s_all->s_player.hor_shoot, (sfVector2f){0.70, 0.70});
    sfSprite_setPosition(s_all->s_player.hor_shoot, s_all->s_player.shoot_pos);
    sfSprite_setTextureRect(s_all->s_player.ver_shoot,
    (sfIntRect){67, 76, 5, 16});
    sfSprite_setOrigin(s_all->s_player.ver_shoot, (sfVector2f){2.5, 8});
    sfSprite_setScale(s_all->s_player.ver_shoot, (sfVector2f){0.70, 0.70});
    sfSprite_setPosition(s_all->s_player.ver_shoot, s_all->s_player.shoot_pos);
}

void init_hero(all_t *s_all)
{
    s_all->s_player.hero_pos = (sfVector2f){render_pos_center(s_all).x - 24,
        render_pos_center(s_all).y + 180};
    s_all->s_player.save_pos = s_all->s_player.hero_pos;
    create_sprite(&s_all->s_player.hero, &s_all->s_player.hero_tx,
        s_all->s_player.hero_pos, "sprites/game_objects.png");
    s_all->s_player.hero_speed = 3;
    s_all->s_player.hero_clock = sfClock_create();
    s_all->s_player.rect_clock = sfClock_create();
    s_all->s_player.hero_rect = (sfIntRect){406, 109, 20, 31};
    sfSprite_setTextureRect(s_all->s_player.hero, s_all->s_player.hero_rect);
    s_all->s_player.debug = init_hitbox_debug(s_all->s_player.debug,
        s_all->s_player.hero_pos, s_all->s_player.hero);
    sfSprite_setColor(s_all->s_player.hero, (sfColor){170, 170, 170, 255});
    init_movement(s_all), init_direction(s_all);
    init_hero2(s_all), init_hero3(s_all);
    init_shooting(s_all), s_all->s_player.space = 0;
    s_all->s_player.shoot_speed = 6;
    s_all->s_player.save_speed = s_all->s_player.shoot_speed;
    s_all->s_player.fast_shoot =
        s_all->s_player.shoot_speed + s_all->s_player.hero_speed;
}