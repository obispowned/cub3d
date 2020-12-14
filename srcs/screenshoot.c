#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

static t_bitmap	fill_header(t_mlx *mlx)
{
	t_bitmap header;

	ft_memset(&header, 0, sizeof(header));
	header.filesize = (mlx->win_width * mlx->win_height * (mlx->image.bpp / 8)) + 54;
	header.pixeldataoffset = 54;
	header.headersize = 40;
	header.imagewidth = mlx->win_width;
	header.imageheight = mlx->win_height;
	header.planes = 1;
	header.bitsperpixel = mlx->image.bpp;
	header.imagesize = mlx->win_width * mlx->win_height * (mlx->image.bpp / 8);
	return (header);
}

static void		file_write(int fd, const void *buf, ssize_t len)
{
	if (write(fd, buf, len) != len)
	{
		perror("Error\nfile_write");
		exit(-1);
	}
}

int				save_bmp(t_mlx *mlx)
{
	int				fd;
	t_bitmap		bmp;
	int				i;
	unsigned int	*line;

	mlx->image.addr = mlx_get_data_addr(mlx->image.img,
	&mlx->image.bpp, &mlx->image.linesize, &mlx->image.endian);
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	bmp = fill_header(mlx);
	if (fd < 0)
		return (1);
	file_write(fd, "BM", 2);
	file_write(fd, &bmp, sizeof(bmp));
	i = 0;
	while (i < mlx->win_height)
	{
		line = (unsigned int *)&mlx->image.addr[(mlx->win_height - i - 1) * mlx->image.linesize];
		file_write(fd, line, mlx->image.linesize);
		i++;
	}
	//close_success(mlx); //////*///////
	if (close(fd) == -1)
		return (1);
	return (0);
}
