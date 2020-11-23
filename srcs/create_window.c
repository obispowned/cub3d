#include <mlx.h>
#include "../header/game.h"

void	game_loading(t_config config)
{
	create_window(config);
}

int		exit_game(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(-1);
	return(0);
}

int		close_win(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		exit_game(mlx);
	return (0); //me da warning si no pongo return pero podriamos evitarlo.
}

void	create_window(t_config config)
{
	t_mlx mlx; // estructura que contendrá todas las "cosas MLX"

//	reset_rc(&mlx.rc, config);
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window (mlx.ptr , config.height, config.width, "cub3D");
//	mlx.img = mlx_new_image (mlx.ptr , config.width, config.height);
//	mlx.addr = mlx_get_data_addr(mlx.img, mlx.bpp, &mlx.linesize, &mlx.endian);
//	my_pixel_put();

//	if (config.save == 1) //si hay --save
//		mlx_loop_hook(mlx.ptr, &screenshot, &mlx.rc);
//	else
//		mlx_loop_hook(rc.mlx_ptr, &raycasting, &rc);
	mlx_hook(mlx.win, 17, 1L << 17, exit_game, &mlx); //cerramos ventana al dar a la "equis"
	mlx_key_hook(mlx.win, close_win, &mlx);
	mlx_loop(mlx.ptr);


}
	/*
	 Ahora solo un pequeño ejemplo: aquí hay un bucle que dibujará cada píxel que
	 tienen un ancho impar en blanco y los que tienen un ancho par en negro.
	
	while (++ count_h <WIN_HEIGHT)
	{
		count_w = - 1 ;
		while (++ count_w <WIN_WIDTH)
		{
			si (count_w% 2 )
				/ *
				 Como puede ver aquí en lugar de usar la función mlx_put_pixel
				 Solo asigno un color a cada píxel uno por uno en la imagen,
				 y la imagen se imprimirá de una vez al final del ciclo.
				 Ahora bien, una cosa que hay que entender aquí es que estás trabajando en un modelo unidimensional.
				 matriz, mientras que su ventana es (obviamente) bidimensional.
				 Entonces, en lugar de tener datos [altura] [ancho] aquí, tendrá lo siguiente
				 fórmula: [altura actual * ancho máximo + ancho actual] (como puede ver a continuación)
				* /
				mlx. img . datos [count_h * WIN_WIDTH + count_w] = 0xFFFFFF ;
			más
				mlx. img . datos [count_h * WIN_WIDTH + count_w] = 0 ;
		}
	}
	// ¡ Ahora solo tienes que imprimir la imagen usando mlx_put_image_to_window!
	mlx_put_image_to_window (mlx. mlx_ptr , mlx. win , mlx. img . img_ptr , 0 , 0 );
	mlx_loop (mlx. mlx_ptr );*/