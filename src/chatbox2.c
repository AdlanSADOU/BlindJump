/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** chatbox2
*/

#include "rpg.h"

void init_chatbox2(all_t *s_all)
{
    s_all->s_chatbox.eric = sfSprite_create();
    s_all->s_chatbox.eric_tx =
        sfTexture_createFromFile("sprites/eric.png", NULL);
    sfSprite_setTexture(s_all->s_chatbox.eric,
        s_all->s_chatbox.eric_tx, sfTrue);
    sfSprite_setPosition(s_all->s_chatbox.eric, (sfVector2f){1620, 790});
    s_all->s_chatbox.buff = malloc(sizeof(char) * 2000);
    s_all->s_chatbox.car = 0, s_all->s_chatbox.fd = 0,
    s_all->s_chatbox.idx = 0, s_all->s_chatbox.op = 0;
    s_all->s_chatbox.buff[0] = '\0';
    s_all->s_chatbox.s = 0.00;
}

void open_file(all_t *s_all, char *filepath)
{
    if (s_all->s_chatbox.op == 0 && s_all->s_chatbox.idx == 0) {
        s_all->s_chatbox.op = 1, s_all->s_chatbox.car = 0;
        s_all->s_chatbox.fd = open(filepath, O_RDONLY);
        s_all->s_chatbox.buff[0] = '\0';
    }
}

int read_chat_file(all_t *s_all)
{
    dialog_time(s_all);
    if (s_all->s_game.scene == CUSTOM || s_all->s_game.scene == MENU
    || s_all->s_game.scene == OPT || s_all->s_game.pause == 1) return 0;
    if (s_all->s_chatbox.car == 140 && s_all->s_chatbox.idx > 10) {
        s_all->s_chatbox.buff[s_all->s_chatbox.idx + 1] = '\n';
        s_all->s_chatbox.idx++, s_all->s_chatbox.car = 0;
    }
    if (s_all->s_chatbox.sec > s_all->s_chatbox.s) {
        s_all->s_chatbox.idx = add_letter(s_all->s_chatbox.fd,
        s_all->s_chatbox.idx, s_all->s_chatbox.buff, s_all);
        s_all->s_chatbox.car++;
        add_text(s_all, s_all->s_chatbox.buff);
    }
    return 0;
}

int wait_close(all_t *s_all)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue ||
    (s_all->s_game.scene == GAME_OVER && s_all->s_player.tp == 0)) {
        s_all->s_chatbox.idx = 0;
        s_all->s_chatbox.op = 0;
        s_all->s_game.tp_chat = 0;
        close(s_all->s_chatbox.fd);
        return 1;
    }
    return 0;
}