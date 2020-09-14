/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** cinematic
*/

#include "rpg.h"

void nb_text(all_t *s_all)
{
    if (s_all->s_player.tp == 1) {
        if (s_all->s_map.stage == 1) s_all->s_game.nb = 30;
        if (s_all->s_map.stage == 2) s_all->s_game.nb = 30;
        if (s_all->s_map.stage == 3) s_all->s_game.nb = 30;
        if (s_all->s_map.stage == 4) s_all->s_game.nb = 35;
        if (s_all->s_map.stage >= 5) s_all->s_game.nb = 40;
    } char *str = malloc(sizeof(char) * 20);
    str[0] = '\0';
    str = my_strcat(str, strnbr(s_all->s_game.nb));
    str = my_strcat(str, " MONSTERS LEFT");
    sfText_setString(s_all->s_game.mob_left, str);
    free(str);
}

void stage_cinematic(all_t *s_all)
{
    if (s_all->s_game.tp_chat == 1 && s_all->s_game.stage_script == 1) {
        s_all->s_game.chat = 1;
        chatbox(s_all, "pnj/stage1");
    } if (s_all->s_game.tp_chat == 1 && s_all->s_game.stage_script == 2) {
        s_all->s_game.chat = 1;
        chatbox(s_all, "pnj/stage2");
    } if (s_all->s_game.tp_chat == 1 && s_all->s_game.stage_script == 3) {
        s_all->s_game.chat = 1;
        chatbox(s_all, "pnj/stage3");
    } if (s_all->s_game.tp_chat == 1 && s_all->s_game.stage_script == 4) {
        s_all->s_game.chat = 1;
        chatbox(s_all, "pnj/stage4");
    } if (s_all->s_game.tp_chat == 1 && s_all->s_game.stage_script == 5) {
        s_all->s_game.chat = 1;
        chatbox(s_all, "pnj/stage5");
    } if (s_all->s_game.tp_chat == 1 && s_all->s_game.stage_script == 6
    && s_all->s_game.nb == 0 && s_all->s_game.scene == MAP) {
        s_all->s_game.chat = 1, chatbox(s_all, "pnj/finish");
    } nb_text(s_all);
}

void cinematic2(all_t *s_all)
{
    static int i = 0;
    if (s_all->s_cine.script == 2 && s_all->s_inventory.head->is_item == 1) {
        s_all->s_cine.script = 3, s_all->s_chatbox.buff[0] = '\0';
        s_all->s_chatbox.op = 0, s_all->s_chatbox.idx = 0;
        s_all->s_chatbox.car = 0;
    } if (s_all->s_cine.script == 5 && i == 0) {
        i++;
        s_all->s_chatbox.buff[0] = '\0';
        s_all->s_chatbox.op = 0;
        s_all->s_chatbox.idx = 0;
        s_all->s_chatbox.car = 0;
    } if (s_all->s_cine.script > 1 && s_all->s_game.scene == SPAWN
    && s_all->s_chest != NULL && s_all->s_chest->status == 0)
        s_all->s_chest->status = 1;
    if (s_all->s_game.chat == 0) s_all->s_npc.talk = 0;
    if (s_all->s_game.nb == 0 && s_all->s_map.stage == 5
    && s_all->s_game.scene == MAP && s_all->s_cine.script != 7)
        s_all->s_cine.script = 7, s_all->s_game.tp_chat = 1;
}

void cinematic1(all_t *s_all)
{
    static int check1 = 0, check2 = 0, check3 = 0, check4 = 0;
    if (s_all->s_cine.seconds < 0.01) return;
    if (s_all->s_cine.script == 0 && s_all->s_cine.tuto == 1) {
        s_all->s_cine.move = 2, s_all->s_npc.talk = 1, s_all->s_game.chat = 1;
        if (s_all->s_movement.down == 1 && check1 == 0)
            check1 = 1, s_all->s_cine.count += 1;
        if (s_all->s_movement.up == 1 && check2 == 0)
            check2 = 1, s_all->s_cine.count += 1;
        if (s_all->s_movement.left == 1 && check3 == 0)
            check3 = 1, s_all->s_cine.count += 1;
        if (s_all->s_movement.right == 1 && check4 == 0)
            check4 = 1, s_all->s_cine.count += 1;
        if (s_all->s_cine.count == 4) {
            s_all->s_cine.script = 1, s_all->s_chatbox.buff[0] = '\0';
            s_all->s_chatbox.op = 0, s_all->s_chatbox.idx = 0;
            s_all->s_chatbox.car = 0;
        }
    } cinematic2(s_all);
    if (s_all->s_game.scene == MENU || s_all->s_game.scene == LOAD)
        check1 = 0, check2 = 0, check3 = 0, check4 = 0;
    sfClock_restart(s_all->s_cine.clock);
}