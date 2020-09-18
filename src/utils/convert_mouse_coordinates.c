#include "rpg.h"

void convert_mouse_coordinates(sfRenderWindow *window, sfVector2i *mouse_pos)
{
    const sfView *view = sfRenderWindow_getView(window);
    sfVector2f tmp_mouse = sfRenderWindow_mapPixelToCoords(window, *mouse_pos, view);
    sfVector2i new_mouse = (sfVector2i){(int)tmp_mouse.x, (int)tmp_mouse.y};
    *mouse_pos = new_mouse;
}
