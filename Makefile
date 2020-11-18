  
NAME			= 	cub3D

SRCS			=	srcs/main.c\
					srcs/file_procesator.c\
					srcs/check_nd_save.c\
					srcs/get_map_reads.c\
					srcs/create_window.c\
					utils/ft_split.c\
					utils/ft_strdup.c\
					utils/ft_strjoin_char.c\
					get_next_line/get_next_line.c\
					utils/ft_strlen.c\
					utils/ft_calloc.c\
					utils/ft_is.c\
					utils/utilities.c\

FLAGS			= -g

GCC 			= gcc

MLX				= ./mlx
INCLUDE			= -I includes -lmlx -framework OpenGL -framework AppKit

RED 			= \033[0;31m
PURPLE			= \033[0;35m
GREEN			= \033[1;32m
RESET			= \033[0m

all:		
				@echo "${RED}[...Haciendo CLEAN del a.out...]${RESET}"
				@rm -rf cub3D
				@echo "${PURPLE}[Compilando Minilibx...]${RESET}"
				$(GCC) $(SRCS) $(INCLUDE) -o $(NAME)
				@echo "${GREEN}[.oOo.oOo.oOo.oOo.]"
				@echo "[ C O M P I L A O ]"
				@echo "[.oOo.oOo.oOo.oOo.]${RESET}"
run: all
	clear && ./cub3D maps/Validos/map0.cub 

fclean: clean
	rm -f $(NAME)

clean :
	@echo "\033[0;31m[BORRANDO MIERDA...]"
	$(RM) $(OBJS)

re:				fclean all