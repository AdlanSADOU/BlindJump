/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fps
*/

#include "rpg.h"

check_box_t create_check_box(int id, sfVector2f pos)
{
    check_box_t box;
    int f = (id * 30) + 60;
    char *str = my_itoa(f), *s = malloc(sizeof(char) * 8);
    my_strcpy(s, str), my_strcat(s, " FPS");
    free(str);
    if (id == 0)
        box.checked = 1;
    else if (id != 0)
        box.checked = 0;
    box.id = id, box.pos = pos, box.box = sfRectangleShape_create();
    sfRectangleShape_setPosition(box.box, box.pos);
    sfRectangleShape_setSize(box.box, (sfVector2f){20, 20});
    sfRectangleShape_setOutlineThickness(box.box, 2);
    sfRectangleShape_setOutlineColor(box.box, sfWhite);
    box.font = sfFont_createFromFile("font/Cornerstone.ttf");
    box.text = sfText_create();
    sfText_setString(box.text, s), sfText_setFont(box.text, box.font);
    sfText_setPosition(box.text, (sfVector2f){pos.x -40, pos.y - 50});
    sfText_setColor(box.text, sfWhite);
    return box;
}

void init_fps(all_t *s_all)
{
    sfVector2f pos = (sfVector2f){750, 400};
    for (int i = 0; i < 3; i++) {
        s_all->s_options.fps[i] = create_check_box(i, pos);
        pos.x += 200;
    }
}

int click_box(all_t *s_all, check_box_t box)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(s_all->s_game.window);
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(box.box);
    if (sfFloatRect_contains(&rect, mouse.x, mouse.y) == sfTrue
    && s_all->s_game.event.mouseButton.type == sfEvtMouseButtonPressed) {
        return 1;
    }
    else if (box.checked == 1)
        return 1;
    return 0;
}

void change_check(all_t *s_all, check_box_t fps[], int i)
{
    if (i == 0) {
        fps[1].checked = 0;
        fps[2].checked = 0;
    }
    else if (i == 1) {
        fps[0].checked = 0;
        fps[2].checked = 0;
    }
    else {
        fps[0].checked = 0;
        fps[1].checked = 0;
    }
    s_all->s_game.fps = (i * 30) + 60;
}

void draw_fps(all_t *s_all)
{
    for (int i = 0; i < 3; i++) {
        if ((s_all->s_options.fps[i].checked =
        click_box(s_all, s_all->s_options.fps[i])) == 1)
            change_check(s_all, s_all->s_options.fps, i);
        if (s_all->s_options.fps[i].checked == 1)
            sfRectangleShape_setFillColor(s_all->s_options.fps[i].box,
            (sfColor){172, 56, 36, 255});
        else if (s_all->s_options.fps[i].checked == 0)
            sfRectangleShape_setFillColor(s_all->s_options.fps[i].box,
            sfTransparent);
    }
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_options.fps[i].text, NULL);
        sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        s_all->s_options.fps[i].box, NULL);
    }
}