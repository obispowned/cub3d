NAME			= 	cub3D

SRCS			=	srcs/get_next_line.c\
					srcs/get_next_line_utils.c\
					srcs/main.c\
					srcs/file_procesator.c\
					srcs/check_nd_save.c

OBJS			= $(SRCS:.c=.o)

LIBFT       	:= ./libft/libft.a

FLAGS			= -Wall -Werror -Wextra -g

GCC 			= gcc

INCLUDE			= -I minilibx -I header

MLX_DIR			= minilibx_opengl

all:		$(NAME)

$(NAME):	$(OBJS)
				@echo "\033[0;31m[Remove last version...]"
				@rm -rf cub3D
				@echo "\033[0;35m[minilib compilation...]"
			$(MAKE) -C minilibx_opengl
				@echo "\033[0;36m[Libft compilation...]"
			$(MAKE) -C libft
				@echo "\033[0;33m[cub3D compilation...]"
			$(GCC) $(LIBFT) $(OBJS) -o $(NAME) -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
				@echo "\033[1;32m[* * * * * * * * * * * * * * * * * * * * * * *]"
				@echo "\033[1;32m[ C O M P I L E D  	  S U C C E S F U L L Y]"
				@echo "\033[1;32m[* * * * * * * * * * * * * * * * * * * * * * *]"

%.o: %.c
	$(GCC) $(FLAGS) $(INCLUDE) -c $<  -o $(<:.c=.o)

fclean: clean
	rm -f $(NAME)

clean :
		@echo "\033[0;31m[Deleting Objects...]"
	$(RM) $(OBJS)

re:				fclean $(NAME)
