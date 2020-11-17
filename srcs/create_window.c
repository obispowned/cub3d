#include <mlx.h>
#include "../header/game.h"

void	game_loading(t_config config)
{
	create_window(config);
}

int		create_window(t_config config)
{
	t_mlx mlx; // primero creo mi estructura que contendrá todas las "cosas MLX"
	int 		count_w;
	int 		count_h;

	count_h = - 1 ;
	// Primero almacenamos retorno de mlx_init y mlx_new_window y mls_new_img.
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window (mlx.ptr , config.height, config.width, "Un ejemplo de ventana" );
	mlx.img = mlx_new_image (mlx.ptr , config.width, config.height);
	/*
	 Ahora la parte importante:
	 mlx_get_data_addr devolverá un carácter * que es 4 veces el (ancho * alto) de su imagen.
	 Porque ? Déjame explicarte: este carácter * representará tu imagen, píxel a píxel,
	 y los valores de esta matriz son los colores. Es por eso que la matriz es 4 veces más grande:
	 necesita 4 caracteres para codificar el color de cada píxel (uno para rojo, verde y azul) y otro para el alfa.
	 Pero ... no es muy conveniente, ¿verdad? Así que aquí está mi pequeño truco: lanzas
	 mlx_get_data_addr como int * y almacenarlo en int *.
	 De esta manera, la matriz tendrá exactamente el mismo tamaño que su ventana, y cada índice
	 representará un color completo de un píxel!
	*/
	mlx. img . datos = ( int *) mlx_get_data_addr (mlx.img . img_ptr , & mlx.img . bpp , & mlx. img . size_l ,
		& mlx. img . endian );
	/*
	 Ahora solo un pequeño ejemplo: aquí hay un bucle que dibujará cada píxel que
	 tienen un ancho impar en blanco y los que tienen un ancho par en negro.
	*/
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
	mlx_loop (mlx. mlx_ptr );
	return ( 0 );
}