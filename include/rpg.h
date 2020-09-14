/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Network.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>

#include "utils.h"

#ifndef MY_PI
#define MY_PI (3.14159265358979323846)
#endif /* !MY_PI */

#ifndef MENU
#define MENU (0)
#endif

#ifndef SPAWN
#define SPAWN (1)
#endif

#ifndef MAP
#define MAP (2)
#endif

#ifndef GAME_OVER
#define GAME_OVER (3)
#endif

#ifndef CUSTOM
#define CUSTOM (4)
#endif

#ifndef OPT
#define OPT (5)
#endif

#ifndef LOAD
#define LOAD (6)
#endif

typedef struct statbox
{
    sfRectangleShape *bg;
    sfRectangleShape *bg1;
    sfSprite *player;
    sfFont *font;
    sfText *p_name;
    sfText *xp;
    sfText *dmg;
    sfText *hp;
    sfText *lvl;
    sfText *xp_tx;
    sfText *dmg_tx;
    sfText *hp_tx;
    sfText *lvl_tx;
    sfText *speed;
    sfText *speed_tx;
    sfText *sh_speed;
    sfText *sh_speed_tx;
    sfText *lvl_up;
    char *dmg_str;
    char *speed_str;
    char *sh_speed_str;
    char *hp_str;
    char *lvl_str;
} statbox_t;

typedef struct chatbox {
    sfRectangleShape *box;
    sfText *text;
    sfFont *font;
    sfClock *clock;
    sfTime time;
    sfSprite *eric;
    sfTexture *eric_tx;
    float sec, s;
    int fd, idx, car, op;
    char *buff;
} chatbox_t;

typedef struct check_box {
    sfRectangleShape *box;
    int checked;
    int id;
    sfFont *font;
    sfText *text;
    sfVector2f pos;
} check_box_t;

typedef struct volume {
    sfRectangleShape *bar1;
    sfRectangleShape *bar2;
    int vol;
    sfSprite *left;
    sfSprite *right;
    sfTexture *right_tx;
    sfTexture *left_tx;
} volume_t;

typedef struct options {
    sfSprite *bg;
    sfTexture *bg_tx;
    volume_t s_volume;
    check_box_t fps[3];
    struct menu_buttons *buttons;
} options_t;

typedef struct sounds {
    sfClock *clock;
    sfTime time;
    float seconds;
    int d;
    int fat_bool;
    sfMusic *music;
    sfSound *laser;
    sfSoundBuffer *laser_b;
    sfSound *tp;
    sfSoundBuffer *heart_b;
    sfSound *heart;
    sfSoundBuffer *tp_b;
    sfSound *item;
    sfSoundBuffer *item_b;
    sfSound *blast;
    sfSoundBuffer *blast_b;
    sfSound *creak;
    sfSoundBuffer *creak_b;
    sfSound *hit;
    sfSoundBuffer *hit_b;
    sfSound *dead;
    sfSoundBuffer *dead_b;
    sfSound *player;
    sfSoundBuffer *player_b;
    sfSound *lvl;
    sfSoundBuffer *lvl_b;
    sfSound *step1;
    sfSoundBuffer *step1_b;
    sfSound *step2;
    sfSoundBuffer *step2_b;
    sfSound *step3;
    sfSoundBuffer *step3_b;
    sfSound *step4;
    sfSoundBuffer *step4_b;
    sfSound *step5;
    sfSoundBuffer *step5_b;
} sound_t;

typedef struct game {
    sfRenderWindow *window;
    sfFont *font;
    sfFont *monospaced;
    sfEvent event;
    sfView *camera;
    sfClock *clock;
    sfTime time;
    sfShader *shader;
    sfRenderStates state;
    sfSprite *black;
    sfTexture *black_tx;
    float seconds;
    sfClock *clock_button;
    sfText *the_stage;
    sfText *mob_left;
    sfTime time_button;
    float seconds_button;
    int scene;
    int debug_mode;
    int nb;
    sfText *quest;
    int display_inv;
    int pause;
    int level_up;
    sfClock *lvl_clk;
    sfTime lvl_time;
    float lvl_seconds;
    char key_press;
    sfSprite *menu;
    sfTexture *arrow;
    sfTexture *menu_tx;
    int fps;
    int stage_script;
    float volume;
    int tp_chat;
    int chat;
    sfTexture *hearth_tx;
} game_t;

typedef struct menu_buttons {
    sfSprite *sprite;
    sfTexture *button1;
    sfTexture *button2;
    sfVector2f position;
    int id;
    struct menu_buttons *next;
} m_buttons_t;

typedef struct rgb {
    sfRectangleShape *rect;
    int value;
    char id;
    sfSprite *right;
    sfSprite *left;
    sfSprite *cursor;
    sfTexture *right_tx;
    sfTexture *left_tx;
    sfTexture *cursor_tx;
    struct rgb *next;
} rgb_t;

typedef struct custom {
    sfText *select_name;
    sfText *title_hero;
    sfText *enter;
    sfRectangleShape *input;
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *hero;
    sfTexture *hero_tx;
    sfVector2f pos;
    sfClock *clock;
    sfTime time;
    sfColor p_color;
    int r, g, b;
    float seconds;
    int show;
} custom_t;

typedef struct direction {
    int up;
    int down;
    int left;
    int right;
} direction_t;

typedef struct movement {
    int up;
    int down;
    int left;
    int right;
    int wall_up;
    int wall_down;
    int wall_right;
    int wall_left;
} movement_t;

typedef struct bullet_mob {
    sfSprite *bullet;
    sfVector2f pos;
    int shoot;
    float bullet_speed;
    int check_shoot;
    float vx, vy;
    float normalize;
    int bullet_travel;
    int hit;
    sfClock *shoot_clock;
    sfTime shoot_time;
    float shoot_seconds;
    struct bullet_mob *next;
} b_mob_t;

typedef struct mob {
    sfSprite *mob;
    sfTexture *mob_txt;
    sfVector2f mob_pos;
    int speed;
    sfClock *clock, *refresh_clk;
    sfTime time, refresh_tm;
    float seconds, refresh_sec;
    sfClock *rect_clock;
    sfTime rect_time;
    float rect_seconds;
    sfIntRect rect;
    sfClock *shoot_clock;
    sfTime shoot_time;
    float shoot_seconds;
    sfText *text;
    char *name, *strlvl;
    sfSprite *shadow;
    sfTexture *shadow_tx;
    sfVector2f shadow_pos;
    int move, status;
    char type, prev;
    int x, y, hor, ver, xp;
    char **path;
    struct mob *next;
    int aggro, hp, lvl;
    sfSprite *bullet;
    int shoot;
    float bullet_speed;
    int check_shoot;
    float vx, vy;
    float normalize;
    int bullet_travel;
    int hit;
    b_mob_t *l_bullets;
} mob_t;

typedef struct p_infos {
    sfRectangleShape *xp;
    sfRectangleShape *xp_base;
    sfRectangleShape *hp;
    sfRectangleShape *hp_base;
    sfClock *clock;
    sfClock *hit_clk;
    sfTime time, hit_tm;
    int is_hit, is_color;
    float seconds, hit_sec;
    char *p_name;
    char *str_xp;
    char *str_current_xp;
    char *str_max_xp;
    char *str_hp;
    int current_xp, max_xp, level, dmg, max_hp, current_hp;
    int max_hp_save, save_dmg;
    char *str_level;
    float atk_speed;
    sfText *xp_txt;
    sfText *hp_txt;
    sfText *heath;
    sfText *lvl_txt;
    sfText *game_over;
    sfText *p_name_txt;
} p_infos_t;

typedef struct player {
    sfVector2f save_pos;
    sfRectangleShape *debug;
    sfRectangleShape *debug_shadow;
    sfSprite *hero, *hit_sprite;
    int up, down, left, right, range, hit;
    sfSprite *ver_shoot;
    sfSprite *hor_shoot;
    sfTexture *hit_txt;
    sfTexture *ver_shoot_txt;
    sfTexture *hor_shoot_txt;
    char *heal;
    sfTexture *hero_tx;
    sfVector2f hero_pos, shoot_pos, hor_pos, ver_pos, hit_pos;
    sfClock *heal_clk;
    sfTime heal_tim;
    float heal_sec;
    int shoot_speed;
    int save_speed;
    int space;
    int fast_shoot;
    int hero_speed, ver, hor, shooting;
    sfClock *hero_clock, *hit_clk, *reload_clk;
    sfTime hero_time, hit_tm, reload_tm;
    float hero_seconds, refresh_sec, shoot_sec, hit_sec, reload_sec;
    sfClock *rect_clock, *refresh_clk, *shoot_clk;
    sfTime rect_time, refresh_tm, shoot_tm;
    float rect_seconds;
    sfIntRect hero_rect, hit_rect;
    sfSprite *shadow;
    sfTexture *shadow_tx;
    sfVector2f shadow_pos;
    sfSprite *gun;
    int tp, x, y;
} player_t;

typedef struct stars {
    sfRenderTexture *render1;
    sfRenderTexture *render2;
    sfSprite *front;
    sfSprite *back;
    sfTexture *front_tx;
    sfTexture *back_tx;
    sfVector2f pos;
    sfVector2f pos2;
} stars_t;

typedef struct load {
    sfSprite *hero;
    sfSprite *button;
    sfTexture *hero_tx;
    sfTexture *hover;
    sfTexture *click;
    sfTexture *normal;
    sfColor color;
    int id, fion;
    sfText *level_tx;
    sfText *p_name_tx;
    sfVector2f pos;
    struct load *next;
} load_t;

typedef struct save {
    sfSprite *button;
    sfTexture *normal;
    sfTexture *hover;
    sfTexture *clicked;
    sfText *description;
    int id, fion;
    char *filepath;
    struct save *next;
} save_t;

typedef struct npc {
    sfSprite *computer;
    sfVector2f pos_pc;
    sfSprite *screen;
    sfText *talk_text;
    int talk;
} npc_t;

typedef struct spawn {
    sfSprite *ground;
    sfTexture *ground_tx;
    sfVector2f ground_pos;
    sfSprite *mask;
    sfTexture *mask_tx;
    sfVector2f mask_pos;
    sfSprite *door;
    sfTexture *door_tx;
    sfVector2f door_pos;
    sfSprite *ship;
    sfVector2f ship_pos;
    sfRectangleShape *background;
    int open;
    sfClock *door_clock;
    sfTime door_time;
    float door_seconds;
} spawn_t;

typedef struct dead {
    sfSprite *dead;
    sfTexture *dead_tx;
    sfText *respawn;
    sfVector2f pos;
    sfClock *clock;
    sfTime time;
    float seconds;
    int fuck;
    sfIntRect rect;
} dead_t;

typedef struct explode {
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfTime time;
    sfIntRect rect;
    sfVector2f pos;
    int show;
    float seconds;
} explode_t;

typedef struct tileset {
    sfRectangleShape *debug;
    sfSprite *tile;
    sfSprite *top;
    sfSprite *bottom;
    sfSprite *grass;
} tileset_t;

typedef struct map {
    sfSprite *background;
    sfTexture *background_tx;
    sfVector2f background_pos;
    sfVector2f tileset_pos;
    sfTexture *tileset_tx;
    sfTexture *grass_tx;
    sfTexture *grass2_tx;
    tileset_t **tileset;
    sfRenderTexture *render;
    const sfTexture *map_texture;
    sfSprite *map_sprite;
    char **map;
    char **grass;
    int x;
    int y;
    int stage;
} map_t;

typedef struct chest {
    sfSprite *sprite;
    sfSprite *shadow;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    int status;
    sfText *open_txt;
    struct chest *next;
} chest_t;

typedef struct mob_pos {
    sfClock *clock;
    sfTime time;
    float seconds;
    int x, y;
} mob_pos_t;

typedef struct effect {
    sfRenderStates *light_state;
    sfSprite *light;
    sfTexture *light_tx;
    sfVector2f light_pos;
    sfRenderStates *vignette_state;
    sfSprite *vignette1;
    sfTexture *vignette1_tx;
    sfSprite *vignette2;
    sfTexture *vignette2_tx;
    sfVector2f vignette_pos;
    sfSprite *tp_glow;
    sfTexture *tp_glow_tx;
    sfClock *clock;
    sfTime time;
    float seconds;
    int anim;
} effect_t;

typedef struct minimap {
    sfSprite *sprite;
    sfRectangleShape *black;
    sfCircleShape *player;
    sfCircleShape *tp;
    int dispay_tp;
} minimap_t;

typedef struct teleporter {
    sfSprite *tp;
    sfVector2f tp_pos;
    sfSprite *tp_shadow;
    sfRectangleShape *debug;
    sfRectangleShape *beam;
    sfClock *tp_clock;
    sfTime tp_time;
    sfRectangleShape *black;
    float tp_seconds;
    int alpha;
    int height;
    int anim;
    int width;
} tp_t;

typedef struct slots {
    sfSprite *slot;
    int drag;
    int is_item;
    int id;
    int health;
    int dmg;
    int equip;
    int slot_nb;
    sfSprite *item;
    sfSprite *under;
    struct slots *next;
} slots_t;

typedef struct inventory {
    sfRectangleShape *inv_back;
    sfTexture *selected_tx;
    sfSprite *selected;
    sfSprite *trash;
    sfTexture *pistol;
    sfTexture *scarh;
    sfTexture *sniper;
    sfTexture *scorpion;
    sfTexture *trash_tx;
    sfTexture *armors_tx;
    sfTexture *slot_tx;
    slots_t *dragged;
    slots_t *head;
    sfText *infos_text;
    sfRectangleShape *infos;
    int swap;
    int drag;
} inventory_t;

typedef struct hearth
{
    int life;
    int show;
    sfSprite *hearth;
    struct hearth *next;
} hearth_t;

typedef struct cinematic {
    int script;
    int cinematic;
    sfClock *clock;
    sfTime time;
    float seconds;
    int door;
    int tuto;
    int move;
    int count;
} cinematic_t;

typedef struct all {
    game_t s_game;
    npc_t s_npc;
    m_buttons_t *s_buttons;
    m_buttons_t *s_pause;
    tp_t s_tp;
    hearth_t *s_life;
    p_infos_t s_infos;
    explode_t s_explode;
    map_t s_map;
    effect_t s_effect;
    movement_t s_movement;
    player_t s_player;
    custom_t s_custom;
    cinematic_t s_cine;
    direction_t s_direction;
    spawn_t s_spawn;
    minimap_t s_minimap;
    mob_pos_t s_mob_pos;
    inventory_t s_inventory;
    dead_t s_dead;
    options_t s_options;
    chatbox_t s_chatbox;
    stars_t s_stars;
    sound_t s_sounds;
    struct save *s_save;
    struct rgb *s_rgb;
    struct mob *s_mob;
    struct chest *s_chest;
    struct load *s_load;
    statbox_t s_statbox;
} all_t;

void set_volume(all_t *s_all);
void quest_display(all_t *s_all);
void free_all_mobs(all_t *s_all);
void stage_cinematic(all_t *s_all);
int check_if_full(all_t *s_all);
int check_chest_turret_overlap(all_t *s_all);
void pop_front_chest(all_t *s_all);
void free_load_slots(all_t *s_all);
void free_chest(all_t *s_all);
void free_inventory(all_t *s_all);
void clean_game2(all_t *s_all);
void clean_game(all_t *s_all);
void load3(all_t *s_all);
void init_buttons_pause(all_t *s_all);
void dispay_buttons_pause(all_t *s_all, m_buttons_t *buttons);
void cinematic1(all_t *s_all);
void color_hp(all_t *s_all);
void slow_heal_player(all_t *s_all);
int drop_check(all_t *s_all, slots_t *tmp);
void set_equip_stats(all_t *s_all);
int move_stars3(all_t *s_all, sfSprite *sprite, float speed, sfVector2f *pos);
int move_stars2(all_t *s_all, sfSprite *sprite, float speed, sfVector2f *pos);
void display_inventory_inf(all_t *s_all, int check);
void init_equip_slots(all_t *s_all);
void swap_items(all_t *s_all, slots_t *tmp);
void set_texture_items2(slots_t *tmp, int id);
void init_sounds(all_t *s_all);
void free_hearth(all_t *s_all);
void heal_hp(all_t *s_all);
void display_hearth2(all_t *s_all);
void destroy_sounds(all_t *s_all);
void display_hearth(all_t *s_all);
void push_front_hearth(all_t *s_all, mob_t *tmp);
void init_chatbox2(all_t *s_all);
void computer_event(all_t *s_all);
float calcul_sprite_magnitude(sfSprite *sprite1, sfSprite *sprite2);
void slide_hover(m_buttons_t *tmp, sfVector2i mouse);
void init_computer(all_t *s_all);
void display_computer(all_t *s_all);
void shoot3(all_t *s_all);
void display_stars(all_t *s_all);
void turret_aim(int i, mob_t *temp, b_mob_t *bullet);
void init_stars(all_t *s_all);
void turret_loop(all_t *s_all, mob_t *temp);
void turret_init(mob_t *new, char type, all_t *s_all);
void turret(all_t *s_all);
void generate_random_mobs3(all_t *s_all);
void display_mobs_death_under(all_t *s_all);
void display_mobs_death_over(all_t *s_all);
void display_mobs4(all_t *s_all);
void move_mobs_rect(mob_t *mob, int max, int offset, int reset);
void roballs_shoot(mob_t *tmp, all_t *s_all);
void display_mobs3(mob_t *temp, all_t *s_all);
void roballs(mob_t *new, char type, sfVector2f pos, all_t *s_all);
void display_minimap(all_t *s_all);
void dispay_buttons(all_t *s_all, m_buttons_t *buttons);
void init_buttons(all_t *s_all);
void init_inventory(all_t *s_all);
void display_inventory(all_t *s_all);
void init_all(all_t *s_all);
void init_clocks(all_t *s_all);
void game_clocks(all_t *s_all);
void display(all_t *s_all);
int game_loop(all_t *s_all);
void init_mobs(all_t *s_all);
void display_mobs(all_t *s_all);
int my_ptrlen(char **str);
void events_control(all_t *s_all);
void create_sprite(sfSprite **sprite, sfTexture **texture,
    sfVector2f pos, const char *path);
void display_hero(all_t *s_all);
void init_hero(all_t *s_all);
sfVector2f render_pos_center(all_t *s_all);
void init_explosions(all_t *s_all);
void player_movement(all_t *s_all);
void init_rgb_selector(all_t *s_all);
void display_rgb_selector(all_t *s_all);
void init_load_slots(all_t *s_all);
void display_load_slots(all_t *s_all);
void init_movement(all_t *s_all);
void display_infos(all_t *s_all);
void generate_random_mobs(all_t *s_all);
mob_t *fill_mob(mob_t *old, char type, sfVector2f pos, all_t *s_all);
void get_movement(all_t *s_all);
void info_clocks(all_t *s_all);
void display_explosions(all_t *s_all);
void init_mob_interface(mob_t *new, char type, all_t *s_all);
void move_explosion(all_t *s_all);
void movement_up_down(all_t *s_all);
void init_dead(all_t *s_all);
void display_dead(all_t *s_all);
void display_chests_over(all_t *s_all, int y);
void display_mobs2(mob_t *temp, all_t *s_all);
void loosing_hp(all_t *s_all);
int display_chests_under(all_t *s_all);
void movement_left_right(all_t *s_all);
void save_inventory(int fd, all_t *s_all);
void load_inventory(int fd, all_t *s_all);
void update_xp(all_t *s_all);
void movement_diagonal_left_up(all_t *s_all);
void movement_diagonal_left_down(all_t *s_all);
void movement_diagonal_right_down(all_t *s_all);
void play_random_sound(all_t *s_all);
void movement_diagonal_right_up(all_t *s_all);
void rect_hero(all_t *s_all);
void init_infos(all_t *s_all);
void player_immunity(all_t *s_all);
void display_hit(all_t *s_all);
sfRectangleShape *init_hitbox_debug(sfRectangleShape *rectangle, sfVector2f pos,
    sfSprite *sprite);
void display_hitbox_debug(all_t *s_all, sfRectangleShape *rectangle,
    sfSprite *sprite);
void set_position_debug(sfRectangleShape *rectangle, sfVector2f pos);
void activate_debug_mode(all_t *s_all);
void init_direction(all_t *s_all);
void get_text_entered(all_t *s_all);
void get_aim_direction(all_t *s_all);
int rect_down(all_t *s_all, int *check, int *i);
void gaining_hp(all_t *s_all, int hp);
int rect_up(all_t *s_all, int *check, int *i);
int rect_left(all_t *s_all, int *check, int *i);
int rect_right(all_t *s_all, int *check, int *i);
int rect_down_condition(all_t *s_all, int *check, int *i);
int rect_up_condition(all_t *s_all, int *check, int *i);
int rect_left_condition(all_t *s_all, int *check, int *i);
int rect_right_condition(all_t *s_all, int *check, int *i);
void init_spawn(all_t *s_all);
void check_mob_hitboxes(all_t *s_all);
void move_hit(all_t *s_all);
void destroy_mobs(all_t *s_all);
void display_spawn_under(all_t *s_all);
void display_spawn_over(all_t *s_all);
void move_camera(all_t *s_all);
int check_borders(all_t *s_all);
int check_middle_wall(all_t *s_all);
void game_over_check(all_t *s_all);
void save(all_t *s_all, char *filepath);
void load(all_t *s_all, char *filepath);
void init_save_screen(all_t *s_all);
void display_save_slots(all_t *s_all);
void display_debug(all_t *s_all);
int check_ship(all_t *s_all);
void init_effect(all_t *s_all);
void display_light_spawn(all_t *s_all);
void init_view(all_t *s_all);
void init_tp(all_t *s_all);
void tp_animation(all_t *s_all);
void init_custom(all_t *s_all);
void respawn(all_t *s_all);
void display_custom(all_t *s_all);
void door_animation(all_t *s_all);
void set_iddle_rect(all_t *s_all);
int hitbox_tp(all_t *s_all);
void init_map(all_t *s_all);
void reset_wall(all_t *s_all);
void shoot(all_t *s_all);
void shoot2(all_t *s_all);
void shooting_control(all_t *s_all);
void display_map(all_t *s_all);
int loop_map_hitbox(all_t *s_all);
char **init_new_random_map(all_t *s_all);
void free_map(char **map);
char **create_map(int x, int y);
void moove_rgb_cursor_left(all_t *s_all, rgb_t *temp);
void moove_rgb_cursor_right(all_t *s_all, rgb_t *temp);
void enter_event(all_t *s_all);
void display_tiles(all_t *s_all);
void generate_random_map(all_t *s_all);
void display_game_over(all_t *s_all);
char **init_new_random_map(all_t *s_all);
void fill_random_map(char **map);
char **copy_map(char **old_map);
void simulation_step(char **old_map, char **new_map);
void set_rect_tile(tileset_t *tile, all_t *s_all, int i, int j);
void put_tp(char **map);
void set_tp_position(all_t *s_all);
chest_t *fill_chests(chest_t *old, all_t *s_all, sfVector2f pos);
sfVector2f find_tp_spawn(all_t *s_all);
char **init_new_gass_map(all_t *s_all);
void set_grass(tileset_t *tile, all_t *s_all, int i, int j);
sfVector2i find_pos(all_t *s_all, char entity);
void create_map_sprite(all_t *s_all);
float calcul_mob_magnitude(mob_t *temp, sfSprite *sprite);
float calcul_chest_magnitude(chest_t *temp, sfSprite *sprite);
int loop_chest_hitbox(all_t *s_all);
void chest_message(all_t *s_all);
void init_minimap(all_t *s_all);
sfBool is_key_released(sfEvent *e, sfKeyCode key);
void put_item_in_slot(all_t *s_all, int id);
void slot_click(all_t *s_all, slots_t *tmp);
void drag_item(all_t *s_all);
void set_texture_items(slots_t *tmp, int id, all_t *s_all);
void init_options(all_t *s_all);
void draw_options(all_t *s_all);
check_box_t create_check_box(int id, sfVector2f pos);
void init_fps(all_t *s_all);
void draw_fps(all_t *s_all);
int click_box(all_t *s_all, check_box_t box);
void change_check(all_t *s_all, check_box_t fps[], int i);
void init_volume1(all_t *s_all);
void init_volume2(all_t *s_all);
int check_right(all_t *s_all);
int check_left(all_t *s_all);
void adjust_volume(all_t *s_all);
void draw_volume(all_t *s_all);
void chatbox(all_t *s_all, char *filepath);
int start_dialog(all_t *s_all, char *filepath);
void init_chatbox(all_t *s_all);
int add_letter(int fd, int idx, char *buf, all_t *s_all);
void add_text(all_t *s_all, char *buf);
void dialog_time(all_t *s_all);
int quit_dialog(all_t *s_all);
void open_file(all_t *s_all, char *filepath);
int read_chat_file(all_t *s_all);
int wait_close(all_t *s_all);
void init_stat_box(all_t *s_all);
void draw_stats(all_t *s_all);
void update_statbox(all_t *s_all);
void stat_create(all_t *s_all);
void stat_text(all_t *s_all);
void stat_text1(all_t *s_all);
void stat_text2(all_t *s_all);
void set_stat_text(all_t *s_all);
void draw_stats1(all_t *s_all);

/* ------------ !QUEUE ------------ */

typedef struct node_queue
{
    int x;
    int y;
    struct node_queue *parent;
    struct node_queue *next;
    struct node_queue *back;
} queue_node_t;

typedef struct queue
{
    int length;
    queue_node_t *last;
    queue_node_t *first;
} queue_t;

queue_t *new_queue(void);
int is_empty_queue(queue_t *li);
queue_node_t *new_queue_node(queue_node_t *parent, int x, int y);
queue_t *push_back_queue(queue_t *li, queue_node_t *parent, int x, int y);
queue_t *pop_front_queue(queue_t *li);
queue_t *clear_queue(queue_t *li);
queue_t *dequeue_front(queue_t *li, queue_t **dequeue);
queue_t *push_new_generation(char **maze, queue_t *s_queue,
    queue_t **s_dequeue);
int check_if_found(queue_t *s_queue, sfVector2i pos_end);

/* ------------ !BREADTH_FIRST_SEARCH ------------ */

int breadth_first_search(char **maze, all_t *s_all, char start, char end);
char **breadth_first_search_entity(char **maze, all_t *s_all, int x, int y);
void format_map(char **map);

/* ------------ !MOBS PATHFINDING ------------ */

void refresh_path(all_t *s_all);
void move_mob_up(mob_t *node, all_t *s_a_ll);
void move_mob_right(mob_t *node, all_t *s_all);
void move_mob_down(mob_t *node, all_t *s_all);
void move_mob_left(mob_t *node, all_t *s_all);
void search_mob_path(mob_t *node, all_t *s_all);
void refresh_path_to_player(all_t *s_all);


#endif /* !RPG_H_ */