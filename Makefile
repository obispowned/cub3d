#####################################
### CONFIG
#####################################
NAME		:= cub3D
CC 			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -pedantic -O3 #-Wall -Wextra -Werror # -O3 -Wall -Wextra -Werror
DFLAGS		:= -g
LIBFT 		:= ./libft/libft.a
LIBFTSRC	:= $(wildcard libft/*.c)
LIBFTOBJ	:= $(patsubst %.c, %.o, $(LIBFTSRC))
RM			:= rm -rf
MKDIR		:= mkdir -p


SRCS := $(shell find src/ -type f -iname *.c)
OBJ := $(patsubst %.c, %.o, $(SRCS))
MLX = ./mlx
INCLUDES 	:= -I includes -Imlx -Llibft -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

#####################################
### RULES
#####################################

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIRS) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT): $(LIBFTOBJ)
	ar rcs $(LIBFT) $(LIBFTOBJ)
$(MLX):
	@ make -C $(MLX)

all: $(NAME)

libft/%.o: libft/%.c
	$(CC) -I includes -c $< -o $@

obj/%.o: src/%.c
	$(MKDIR) obj/
	$(CC) -I includes -c $< -o $@

normi:
	norminette src/*

clean:
	$(RM) libft/*.o obj/* mlx/*.o

fclean: clean
	$(RM) $(NAME) *.dSYM $(LIBFT) a.out obj
	make -C $(MLX) clean

re: fclean all

debug: fclean
	$(CC) $(DFLAGS) $(SRCS) libft/*.c -I includes -o $(NAME)

debugmlx:	fclean
	$(CC) $(DFLAGS) $(INCLUDES) $(SRCS) libft/*.c -I includes -o $(NAME)

.PHONY:	all clean fclean re debug
