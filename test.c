#include <mlx.h>

typedef struct img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		img_data;

void	my_mlx_pixel_put(img_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	void		*mlx;
	void		*mlx_win;
	img_data	img;
	// int			color;
	int			i;
	char		*path = "./small.XPM";
	int			img_width;
	int			img_height;
	int			j = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 500, "so_long");
	
	i = 0;
	// img.img = mlx_new_image(mlx, 0, 0);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	while (j < 20)
	{
		mlx_put_image_to_window(mlx, mlx_win, img.img, i, 0);
		i += 50;
		j++;
	}
	
	mlx_loop(mlx);
}