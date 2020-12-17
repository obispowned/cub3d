
NAME			= 	cub3D

SRCS			=	get_next_line/get_next_line.c\
					srcs/main.c\
					srcs/file_procesator.c\
					srcs/file_procesator2.c\
					srcs/check_nd_save.c\
					srcs/get_map_reads.c\
					srcs/get_map_reads2.c\
					srcs/parse.c\
					srcs/create_and_clean.c\
					srcs/floor_sky_draw.c\
					srcs/init_raycast.c\
					srcs/raycasting.c\
					srcs/rc_wall.c\
					srcs/keyboard.c\
					srcs/handle_events.c\
					srcs/load_texture.c\
					srcs/init_params.c\
					srcs/utils.c\
					srcs/init_params2.c\
					srcs/sprites.c\
					srcs/sprites_casting.c\
					srcs/screenshoot.c\
					utils/ft_split.c\
					utils/ft_strdup.c\
					utils/ft_strjoin_char.c\
					utils/ft_strlen.c\
					utils/ft_calloc.c\
					utils/ft_is.c\
					utils/utilities.c\
					utils/utilities2.c\

#######BUFF QUINES###########

ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS),Darwin)
    MLXFLAGS = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(detected_OS),Linux)
    MLXFLAGS = -lm -lbsd -lmlx -lXext -lX11
endif

#############################

FLAGS			= -g

GCC 			= gcc

INCLUDE			= -I header

RED 			= \033[0;31m
PURPLE			= \033[0;35m
GREEN			= \033[1;32m
RESET			= \033[0m

all:
			@echo "${RED}[...Haciendo CLEAN del a.out...]${RESET}"
			@rm -rf cub3D
			@echo "${PURPLE}[Compilando Minilibx...]${RESET}"
			$(GCC) $(SRCS) $(FLAGS) $(MLXFLAGS) -o $(NAME)
			@echo "${GREEN}[.oOo.oOo.oOo.oOo.]"
			@echo "[ C O M P I L A O ]"
			@echo "[.oOo.oOo.oOo.oOo.]${RESET}"

run0: all
	clear && ./cub3D maps/map0.cub

run1: all
	clear && ./cub3D maps/valid_hip_hop.cub

fclean:	clean
	rm -f $(NAME)

clean :
	@echo "\033[0;31m[BORRANDO MIERDA...]"
	$(RM) $(OBJS)

re:				fclean all

.PHONY:	clean all