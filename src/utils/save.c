/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** save
*/

#include "rpg.h"
#include "utils.h"

void write_field(char *field, int fd, char *data)
{
    int i = 0;
    char c;
    for (; field[i] != '\0'; i++)
        read(fd, &c, 1);
    read(fd, &c, 1);
    write(fd, data, my_strlen(data));
    write(fd, "/", 1);
    for (; read(fd, &c, 1);)
        if (c == '\n') break;
}

char *read_field(char *field, int fd)
{
    int i = 0;
    char c, *str = malloc(20);
    for (; field[i] != '\0'; i++)
        read(fd, &c, 1);
    read(fd, &c, 1);
    for (i = 0; read(fd, &c, 1) == 1 && c != '/'; i++) {
        str[i] = c;
    }
    str[i] = '\0';
    for (; read(fd, &c, 1);)
        if (c == '\n') break;
    return (str);
}

void save(all_t *s_all, char *filepath)
{
    int fd = open(filepath, O_RDWR);
    write_field("name", fd, s_all->s_infos.p_name);
    write_field("r", fd, strnbr(s_all->s_custom.p_color.r));
    write_field("g", fd, strnbr(s_all->s_custom.p_color.g));
    write_field("b", fd, strnbr(s_all->s_custom.p_color.b));
    write_field("level", fd, strnbr(s_all->s_infos.level));
    write_field("xp", fd, strnbr(s_all->s_infos.current_xp));
    write_field("maxxp", fd, strnbr(s_all->s_infos.max_xp));
    write_field("hp", fd, strnbr(s_all->s_infos.current_hp));
    if (s_all->s_infos.current_hp == 0)
        write_field("hp", fd, strnbr(60));
    write_field("maxhp", fd, strnbr(s_all->s_infos.max_hp));
    write_field("stage", fd, strnbr(s_all->s_map.stage - 1));
    write_field("tuto", fd, strnbr(s_all->s_cine.tuto));
    write_field("script", fd, strnbr(s_all->s_cine.script));
    if (s_all->s_game.scene != MAP)
        write_field("chat", fd, strnbr(s_all->s_game.chat));
    else write_field("chat", fd, strnbr(0));
    save_inventory(fd, s_all);
    close(fd);
}

void load_next(all_t *s_all, int fd)
{
    s_all->s_infos.current_xp = my_atoi(read_field("xp", fd));
    s_all->s_infos.max_xp = my_atoi(read_field("maxxp", fd));
    s_all->s_infos.str_xp[0] = '\0';
    update_xp(s_all);
    s_all->s_infos.current_hp = my_atoi(read_field("hp", fd));
    s_all->s_infos.max_hp = my_atoi(read_field("maxhp", fd));
    s_all->s_infos.str_hp[0] = '\0';
    my_strcat(s_all->s_infos.str_hp, strnbr(s_all->s_infos.current_hp));
    my_strcat(s_all->s_infos.str_hp, "/");
    my_strcat(s_all->s_infos.str_hp, strnbr(s_all->s_infos.max_hp));
    sfText_setString(s_all->s_infos.hp_txt, s_all->s_infos.str_hp);
    float size = 250.0 / s_all->s_infos.max_hp * s_all->s_infos.current_hp;
    sfRectangleShape_setSize(s_all->s_infos.hp, (sfVector2f){size, 20});
    s_all->s_map.stage = my_atoi(read_field("stage", fd));
    s_all->s_cine.tuto = my_atoi(read_field("tuto", fd));
    s_all->s_cine.script = my_atoi(read_field("script", fd));
    if (s_all->s_cine.script > 5) s_all->s_cine.door = 1;
    s_all->s_chatbox.car = 0, s_all->s_chatbox.fd = 0,
    s_all->s_chatbox.idx = 0, s_all->s_chatbox.op = 0;
    s_all->s_chatbox.buff[0] = '\0', s_all->s_game.chat = 0;
}

void load(all_t *s_all, char *filepath)
{
    free_inventory(s_all);
    int fd = open(filepath, O_RDWR);
    s_all->s_infos.p_name = read_field("name", fd);
    sfText_setString(s_all->s_infos.p_name_txt, s_all->s_infos.p_name);
    s_all->s_custom.p_color.r = my_atoi(read_field("r", fd));
    s_all->s_custom.p_color.g = my_atoi(read_field("g", fd));
    s_all->s_custom.p_color.b = my_atoi(read_field("b", fd));
    sfSprite_setColor(s_all->s_dead.dead, s_all->s_custom.p_color);
    s_all->s_infos.level = my_atoi(read_field("level", fd));
    s_all->s_infos.str_level[0] = '\0';
    my_strcat(s_all->s_infos.str_level, "Level ");
    my_strcat(s_all->s_infos.str_level, strnbr(s_all->s_infos.level));
    sfText_setString(s_all->s_infos.lvl_txt, s_all->s_infos.str_level);
    load_next(s_all, fd), s_all->s_game.chat = my_atoi(read_field("chat", fd));
    enter_event(s_all), load_inventory(fd, s_all);
    s_all->s_infos.dmg = (s_all->s_infos.level * 50);
    if (s_all->s_inventory.head->is_item == 1)
        s_all->s_infos.dmg += s_all->s_inventory.head->dmg;
    load3(s_all), close(fd);
}