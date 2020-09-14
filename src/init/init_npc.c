/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_npc
*/

#include "rpg.h"

void init_computer2(all_t *s_all)
{
    sfText_setCharacterSize(s_all->s_npc.talk_text, 8);
    s_all->s_npc.talk = 0;
}

void init_computer(all_t *s_all)
{
    s_all->s_npc.computer = sfSprite_create();
    s_all->s_npc.screen = sfSprite_create();
    sfSprite_setTexture(s_all->s_npc.computer,
        s_all->s_player.hero_tx, sfTrue);
    sfSprite_setTexture(s_all->s_npc.screen,
        s_all->s_player.hero_tx, sfTrue);
    sfSprite_setTextureRect(s_all->s_npc.computer,
        (sfIntRect){0, 133, 21, 38});
    sfSprite_setTextureRect(s_all->s_npc.screen, (sfIntRect){21, 133, 19, 10});
    s_all->s_npc.pos_pc = (sfVector2f){s_all->s_spawn.ship_pos.x - 60,
        s_all->s_spawn.ship_pos.y - 79};
    sfSprite_setPosition(s_all->s_npc.computer, s_all->s_npc.pos_pc);
    sfSprite_setPosition(s_all->s_npc.screen,
        (sfVector2f){s_all->s_npc.pos_pc.x + 1, s_all->s_npc.pos_pc.y + 2});
    s_all->s_npc.talk_text = sfText_create();
    sfText_setFont(s_all->s_npc.talk_text, s_all->s_game.font);
    sfText_setPosition(s_all->s_npc.talk_text,
        (sfVector2f){s_all->s_npc.pos_pc.x - 20, s_all->s_npc.pos_pc.y - 33});
    sfText_setString(s_all->s_npc.talk_text, "Press \"E\" to talk");
    init_computer2(s_all);
}

void computer_event(all_t *s_all)
{
    if (s_all->s_game.scene == SPAWN && s_all->s_cine.script >= 5
    && sfKeyboard_isKeyPressed(sfKeyE) == 1
    && calcul_sprite_magnitude(s_all->s_npc.screen,
    s_all->s_player.shadow) <= 25
    && s_all->s_player.hero_pos.y + 10 >= s_all->s_npc.pos_pc.y) {
        s_all->s_npc.talk = 1;
        s_all->s_game.chat = 1;
        s_all->s_cine.move = 1;
    }
}

void display_computer(all_t *s_all)
{
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_npc.computer, NULL);
    if (s_all->s_npc.talk == 1 && s_all->s_cine.tuto == 0)
        sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_npc.screen, NULL);
    if (calcul_sprite_magnitude(s_all->s_npc.screen,
    s_all->s_player.shadow) <= 25 && s_all->s_game.chat == 0
    && s_all->s_player.hero_pos.y + 10 >= s_all->s_npc.pos_pc.y) {
        sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_npc.talk_text, NULL);
    }
}