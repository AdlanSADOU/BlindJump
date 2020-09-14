/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_all
*/

#include "rpg.h"

void init_menu(all_t *s_all)
{
    create_sprite(&s_all->s_game.menu, &s_all->s_game.menu_tx,
        (sfVector2f){0, 0}, "sprites/menu.png");
    init_buttons(s_all);
    init_options(s_all);
    init_chatbox(s_all);
    s_all->s_game.black = sfSprite_create();
    s_all->s_game.black_tx =
        sfTexture_createFromFile("sprites/black.png", NULL);
    sfSprite_setTexture(s_all->s_game.black, s_all->s_game.black_tx, sfTrue);
    sfSprite_setColor(s_all->s_game.black, (sfColor){0, 0, 0, 150});
}

void init_shader(all_t *s_all)
{
    s_all->s_game.shader =
        sfShader_createFromFile("shaders/storm.vert", NULL, NULL);
    s_all->s_game.state.shader = s_all->s_game.shader;
    s_all->s_game.state.blendMode = sfBlendAlpha;
    s_all->s_game.state.transform = sfTransform_Identity;
    s_all->s_game.state.texture = NULL, s_all->s_game.nb = -1;
    sfShader_setVec2Uniform(s_all->s_game.shader, "storm_position",
        (sfVector2f){0, 0});
    sfShader_setFloatUniform(s_all->s_game.shader, "storm_total_radius", 28);
    sfShader_setFloatUniform(s_all->s_game.shader, "storm_inner_radius", 10);
    s_all->s_game.mob_left = sfText_create();
    sfText_setCharacterSize(s_all->s_game.mob_left, 25);
    sfText_setFont(s_all->s_game.mob_left, s_all->s_game.font);
    sfText_setPosition(s_all->s_game.mob_left, (sfVector2f){540, 50});
    s_all->s_map.map_sprite = sfSprite_create();
    s_all->s_map.render = sfRenderTexture_create(32 * s_all->s_map.x,
        26 * s_all->s_map.y, 0);
}

void setup(all_t *s_all)
{
    sfVideoMode mode = {1920, 1080, 32};
    s_all->s_game.window = sfRenderWindow_create(mode, "Blind Jump",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(s_all->s_game.window, 60);
    sfRenderWindow_setPosition(s_all->s_game.window, (sfVector2i){0, 0});
    s_all->s_game.scene = MENU;
    s_all->s_game.debug_mode = 0;
    s_all->s_game.display_inv = 0, s_all->s_game.pause = 0;
    s_all->s_game.fps = 60, s_all->s_game.volume = 1.0;
    s_all->s_mob = NULL;
    s_all->s_chest = NULL;
    s_all->s_game.font = sfFont_createFromFile("font/Cornerstone.ttf");
    s_all->s_game.monospaced = sfFont_createFromFile("font/joystix.ttf");
    s_all->s_game.hearth_tx =
        sfTexture_createFromFile("sprites/powerup.png", NULL);
    s_all->s_life = NULL, s_all->s_game.tp_chat = 0;
    s_all->s_game.stage_script = 1;
    init_view(s_all);
    randomize();
}

void init_cinematic(all_t *s_all)
{
    s_all->s_cine.script = 0, s_all->s_cine.cinematic = 0;
    s_all->s_cine.clock = sfClock_create();
    s_all->s_cine.door = 0, s_all->s_cine.move = 0;
    s_all->s_cine.count = 0, s_all->s_cine.tuto = 1;
    s_all->s_sounds.seconds = 0;
    s_all->s_sounds.clock = sfClock_create();
    s_all->s_cine.seconds = 0.0, s_all->s_player.heal_sec = 0.0;
    s_all->s_game.level_up = 0;
    s_all->s_game.the_stage = sfText_create();
    sfText_setCharacterSize(s_all->s_game.the_stage, 40);
    sfText_setFont(s_all->s_game.the_stage, s_all->s_game.font);
    sfText_setPosition(s_all->s_game.the_stage, (sfVector2f){10, 225});
    s_all->s_game.quest = sfText_create();
    sfText_setCharacterSize(s_all->s_game.quest, 30);
    sfText_setFont(s_all->s_game.quest, s_all->s_game.font);
    sfText_setPosition(s_all->s_game.quest, (sfVector2f){540, 5});
}

void init_all(all_t *s_all)
{
    setup(s_all);
    init_cinematic(s_all);
    init_menu(s_all);
    init_clocks(s_all);
    init_hero(s_all);
    init_spawn(s_all);
    init_tp(s_all);
    init_effect(s_all);
    init_map(s_all);
    init_explosions(s_all);
    init_infos(s_all);
    init_inventory(s_all);
    init_custom(s_all);
    init_dead(s_all);
    init_stars(s_all);
    init_load_slots(s_all);
    init_save_screen(s_all);
    init_stat_box(s_all), init_sounds(s_all), init_shader(s_all);
}