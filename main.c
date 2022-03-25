/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:59:58 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/24 20:44:44 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	init_imgs(t_data *data)
{
	int			arr[2];

	data->images.wall.img = mlx_xpm_file_to_image(data->mlx, "./imgs/wall.xpm", &arr[0], &arr[1]);
	data->images.player.img = mlx_xpm_file_to_image(data->mlx, "./imgs/player.xpm", &arr[0], &arr[1]);
	data->images.collectable.img = mlx_xpm_file_to_image(data->mlx, "./imgs/collectable.xpm", &arr[0], &arr[1]);
	data->images.exit.img = mlx_xpm_file_to_image(data->mlx, "./imgs/exit.xpm", &arr[0], &arr[1]);
	data->images.space.img = mlx_xpm_file_to_image(data->mlx, "./imgs/space.xpm", &arr[0], &arr[1]);
}

int	list_len(t_list *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	set_data(t_data *data, t_list *map)
{
	data->mlx = mlx_init();
	data->win_x = (ft_strlen(map->str))*30;
	data->win_y = (list_len(map))*30;
	data->win = mlx_new_window(data->mlx, data->win_x, data->win_y, "so long");
}

void	put_img(char c, t_data *data, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->images.wall.img, x, y);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->images.space.img, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->images.player.img, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->images.collectable.img, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->images.exit.img, x, y);
}

void	draw(t_list *map, t_data *data)
{
	int	i;
	int	x;
	int	y;

	y = 0;
	while (map != NULL)
	{
		i = 0;
		x = 0;
		while (map->str[i] != '\0')
		{
			put_img(map->str[i], data, x, y);
			x += 30;
			i++;
		}
		y += 30;
		map = map->next;
	}
	
	// mlx_put_image_to_window(data.mlx, data.win, data.images.player.img, 0, 150);
}
int	main()
{
	int				fd;
	t_list			*map;
	t_data			data;

	fd = open("./map", O_RDONLY);
	map = check(fd);
	set_data(&data, map);
	
	init_imgs(&data);
	draw(map, &data);
	mlx_loop(data.mlx);
	return (0);
}