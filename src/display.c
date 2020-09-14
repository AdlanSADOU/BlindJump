/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** display
*/

#include "rpg.h"

void display_spawn(all_t *s_all)
{
    if (s_all->s_game.scene == SPAWN) {
        move_camera(s_all);
        sfRenderWindow_clear(s_all->s_game.window, (sfColor){12, 37, 41, 255});
        display_spawn_under(s_all);
        int y = display_chests_under(s_all);
        display_hero(s_all);
        display_spawn_over(s_all);
        display_chests_over(s_all, y);
        sfRenderWindow_setView(s_all->s_game.window,
        sfRenderWindow_getDefaultView(s_all->s_game.window));
    }
}

void display_map(all_t *s_all)
{
    if (s_all->s_game.scene == MAP) {
        sfRenderWindow_clear(s_all->s_game.window, sfBlack);
        sfSprite_setPosition(s_all->s_map.background,
            (sfVector2f){s_all->s_effect.vignette_pos.x - 10,
            s_all->s_effect.vignette_pos.y - 10});
        move_camera(s_all), sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_map.background, NULL);
        display_stars(s_all), display_tiles(s_all);
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_tp.tp, NULL);
        int y = display_chests_under(s_all);
        display_mobs4(s_all), display_hearth(s_all), display_hero(s_all);
        display_chests_over(s_all, y);
        display_mobs(s_all), destroy_mobs(s_all), display_hearth2(s_all);
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_effect.tp_glow, s_all->s_effect.light_state);
        display_explosions(s_all);
    }
}

void display_chatbox(all_t *s_all)
{
    if (s_all->s_npc.talk == 1 && s_all->s_cine.script == 0)
        chatbox(s_all, "pnj/tuto1");
    if (s_all->s_npc.talk == 1 && s_all->s_cine.script == 1)
        chatbox(s_all, "pnj/tuto2");
    if (s_all->s_npc.talk == 1 && s_all->s_cine.script == 2)
        chatbox(s_all, "pnj/tuto3");
    if (s_all->s_npc.talk == 1 && s_all->s_cine.script == 3)
        chatbox(s_all, "pnj/tuto4");
    if (s_all->s_npc.talk == 1 && s_all->s_cine.script == 4)
        chatbox(s_all, "pnj/tuto5");
    if (s_all->s_npc.talk == 1
    && (s_all->s_cine.script == 5 || s_all->s_cine.script == 6)) {
        chatbox(s_all, "pnj/computer1");
        s_all->s_cine.script = 6;
    } if (s_all->s_npc.talk == 1 && s_all->s_cine.script == 7)
        chatbox(s_all, "pnj/finish");
}

void display_hud_anim(all_t *s_all)
{
    display_debug(s_all), move_camera(s_all);
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        s_all->s_tp.beam, NULL);
    chest_message(s_all), sfRenderWindow_setView(s_all->s_game.window,
        sfRenderWindow_getDefaultView(s_all->s_game.window));
    display_minimap(s_all), quest_display(s_all);
    if (s_all->s_game.scene == MAP) {
        sfRenderWindow_drawText(s_all->s_game.window, s_all->s_game.the_stage,
        NULL), sfRenderWindow_drawText(s_all->s_game.window, s_all->s_game.
        mob_left, NULL), sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_game.quest, NULL);
    } if (s_all->s_game.scene != GAME_OVER && s_all->s_game.scene != CUSTOM
    && s_all->s_game.scene != OPT && s_all->s_game.scene != LOAD) {
        display_infos(s_all), display_chatbox(s_all);
        if (s_all->s_game.display_inv == 1)
            draw_stats(s_all), display_inventory(s_all);
    }
}

void display(all_t *s_all)
{
    sfRenderWindow_setFramerateLimit(s_all->s_game.window, s_all->s_game.fps);
    tp_animation(s_all);
    display_spawn(s_all), display_map(s_all);
    display_dead(s_all), display_hud_anim(s_all);
    if (s_all->s_game.scene == MENU) {
        sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_game.menu, NULL);
        dispay_buttons(s_all, s_all->s_buttons);
    } display_custom(s_all), display_rgb_selector(s_all);
    stage_cinematic(s_all);
    if (s_all->s_game.scene == OPT) draw_options(s_all);
    display_game_over(s_all);
    display_load_slots(s_all), display_save_slots(s_all);
    if ((s_all->s_game.scene == CUSTOM || s_all->s_game.scene == LOAD)
    && s_all->s_effect.anim > 45)
        dispay_buttons(s_all, s_all->s_options.buttons);
    if (s_all->s_game.level_up == 1 && s_all->s_game.lvl_seconds < 2.0)
        sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_statbox.lvl_up, NULL);
    sfRenderWindow_display(s_all->s_game.window);
}