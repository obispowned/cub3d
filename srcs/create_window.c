#include <mlx.h>
#include "../header/game.h"

void	game_loading(t_config config)
{
	create_window(config);
}
/*
int		close(int keycode, t_mlx mlx)
{
	mlx_destroy_window()
}
*/
void	create_window(t_config config)
{
	t_mlx mlx; // primero creo mi estructura que contendrá todas las "cosas MLX"

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window (mlx.ptr , config.height, config.width, "cub3D");
//	mlx.img = mlx_new_image (mlx.ptr , config.width, config.height);
//	mlx.addr = mlx_get_data_addr(mlx.img, mlx.bpp, &mlx.linesize, &mlx.endian);
	
	mlx_loop(mlx.ptr);



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

}