#include <mlx.h>

typedef struct img
{
	void	*img;
	char	*addr;
	int		img_width;
	int		img_height;
	int		x_positon;
	int		y_positon;
	}		img_data;

int main(void)
{
	void		*mlx;
	void		*mlx_win;
	img_data	img;
	int			i;
	char		*path = "./sun.xpm";
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
		i += 30;
		j++;
	}
	mlx_loop(mlx);
}