NAME			= 	cub3D

SRCS			=	srcs/main.c\
					srcs/file_procesator.c\
					srcs/check_nd_save.c\
					srcs/get_map_reads.c\
					utils/ft_split.c\
					utils/ft_strdup.c\
					utils/ft_strjoin_char.c\
					get_next_line/get_next_line.c\
					utils/ft_strlen.c\
					utils/ft_calloc.c\
					utils/ft_is.c\
					utils/utilities.c\


OBJS			= $(SRCS:.c=.o)

FLAGS			= -Wall -Werror -Wextra -g

GCC 			= gcc

INCLUDE			= -I header

MLX_DIR			= minilibx_opengl

LEAKS			= DYLD_INSERT_LIBRARIES=/Applications/Xcode.app/Contents/Developer/usr/lib/libLeaksAtExit.dylib leaks -atExit -- ./cub3D maps/map3.cub

RED 			= \033[0;31m
PURPLE			= \033[0;35m
GREEN			= \033[1;32m

all:		$(NAME)

$(NAME):	$(OBJS)
				@echo "${RED}[...Haciendo CLEAN del a.out...]${RESET}"
				@rm -rf cub3D
				@echo "${PURPLE}[Compilando Minilibx...]${RESET}"
			$(MAKE) -C minilibx_opengl
			$(GCC) $(OBJS) -o $(NAME) -L $(MLX_DIR)
				@echo "${GREEN}[.oOo.oOo.oOo.oOo.]"
				@echo "[ C O M P I L A O ]"
				@echo "[.oOo.oOo.oOo.oOo.]"
#			$(LEAKS)

%.o: %.c
	$(GCC) $(FLAGS) $(INCLUDE) -c $<  -o $(<:.c=.o)

fclean: clean
	rm -f $(NAME)

clean :
		@echo "\033[0;31m[BORRANDO MIERDA...]"
	$(RM) $(OBJS)

re:				fclean $(NAME)
