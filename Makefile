##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME	=	my_rpg

CC	=	gcc

SRC	=	src/main.c \
		src/clock.c \
		src/clocks2.c \
		src/display.c \
		src/game_loop.c \
		src/event_control.c \
		src/display_player.c \
		src/create_entities.c \
		src/player_movement.c \
		src/player_up_down_left_right.c \
		src/player_diagonal.c \
		src/hitbox_debug.c \
		src/hitbox_spawn.c \
		src/game_over.c \
		src/get_player_name.c \
		src/spawn_scene.c \
		src/display_effect.c \
		src/aim_direction.c \
		src/door_animation.c \
		src/camera.c \
		src/rect_hero.c \
		src/update_infos.c \
		src/rect_hero2.c \
		src/rect_hero3.c \
		src/map.c \
		src/player_hp.c \
		src/map2.c \
		src/mob_generator.c \
		src/mob_generator2.c \
		src/turret.c \
		src/buttons_menu.c \
		src/rgb_cursor.c \
		src/inventory_items.c \
		src/turret2.c \
		src/display_inventory.c \
		src/vectors.c \
		src/chest_hitbox.c \
		src/pause_save.c \
		src/shoot.c \
		src/shoot2.c \
		src/mob_hitbox.c \
		src/map_generator.c \
		src/map_generator2.c \
		src/cinematic.c \
		src/buttons_pause.c \
		src/map_design.c \
		src/destroy_sounds.c \
		src/clean_game.c \
		src/map_grass.c \
		src/tp_anim.c \
		src/chatbox2.c \
		src/destroy_mobs.c \
		src/init/init_health_drop.c \
		src/init/init_player.c \
		src/init/init_stars2.c \
		src/init/init_npc.c \
		src/init/init_infos.c \
		src/init/init_chests.c \
		src/init/init_statbox.c \
		src/init/init_movement.c \
		src/init/init_custom.c \
		src/init/init_custom2.c \
		src/init/init_all.c \
		src/init/init_effect.c \
		src/init/init_inventory.c \
		src/init/init_inventory2.c \
		src/init/init_inventory3.c \
		src/init/init_mobs3.c \
		src/init/init_load.c \
		src/init/init_save.c \
		src/init/init_mobs.c \
		src/init/init_mobs2.c \
		src/init/init_stars.c \
		src/init/init_minimap.c \
		src/init/init_explosions.c \
		src/init/init_dead.c \
		src/init/init_sounds.c \
		src/teleporter.c \
		src/pathfinding/breadth_first_search.c \
		src/pathfinding/breadth_first_search_entity.c \
		src/pathfinding/dequeue.c \
		src/pathfinding/format_map.c \
		src/pathfinding/queue.c \
		src/pathfinding/mob_path.c \
		src/pathfinding/mob_movements.c \
		src/utils/get_next_line.c \
		src/utils/my_atoi.c \
		src/utils/my_putstr.c \
		src/utils/my_revstr.c \
		src/utils/my_strcat.c \
		src/utils/my_strcpy.c \
		src/utils/my_strdup.c \
		src/utils/my_strlen.c \
		src/utils/save2.c \
		src/utils/my_strnbr.c \
		src/utils/randomize.c \
		src/utils/save.c \
		src/utils/my_strcmp.c \
		src/utils/save_inventory.c \
		src/utils/write_file.c \
		src/utils/render_pos_center.c \
		src/options_menu.c \
		src/fps.c \
		src/load.c \
		src/utils/my_itoa.c \
		src/volume.c \
		src/chatbox.c \
		src/dialog_utils.c \
		src/stat_box.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra
CFLAGS	+=	-I./include -g3
FFLAGS	+=	-l csfml-system
FFLAGS	+=	-l csfml-graphics
FFLAGS	+=	-l csfml-audio
FFLAGS	+=	-l csfml-window
FFLAGS  +=	-lm

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(FFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
