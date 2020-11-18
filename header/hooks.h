#ifndef HOOKS_H
# define HOOKS_H

# ifdef APPLE
#  include "../lib/minilibx_mms/mlx.h"
#  define KEY_A 0 //walk_L
#  define KEY_D 2//walk_R
#  define KEY_S 1 //walk_Front
#  define KEY_W 13 //Walk_Back
#  define KEY_Q 12
#  define KEY_ESC 53 
#  define KEY_AR_L 123 //see_left
#  define KEY_AR_R 124 //see_right
#  define LINUX 0
# elif __linux
#  include "../lib/minilibx-linux/mlx.h"
#  include "../lib/minilibx-linux/mlx_int.h"
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_S 115
#  define KEY_W 119
#  define KEY_Q 113
#  define KEY_ESC 65307
#  define KEY_AR_L 65361
#  define KEY_AR_R 65363
#  define LINUX 1
# endif

#endif