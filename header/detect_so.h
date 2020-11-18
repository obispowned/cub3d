# if defined(__APPLE__)
#  include "key_macos.h"
#  include "../mlx/minilibx-macos/mlx.h"
# else
#  include "key_linux.h"
#  include "../mlx/minilibx-linux/mlx.h"
# endif