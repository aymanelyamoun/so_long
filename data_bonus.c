/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:47:11 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/26 17:14:16 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imgs(t_data *data)
{
	int			arr[2];

	data->images.wall.img = \
	mlx_xpm_file_to_image(data->mlx, "./imgs/wall.xpm", &arr[0], &arr[1]);
	data->images.player.img = \
	mlx_xpm_file_to_image(data->mlx, "./imgs/player.xpm", &arr[0], &arr[1]);
	data->images.collectable.img = \
	mlx_xpm_file_to_image(data->mlx, "./imgs/collec.xpm", &arr[0], &arr[1]);
	data->images.exit.img = \
	mlx_xpm_file_to_image(data->mlx, "./imgs/exit.xpm", &arr[0], &arr[1]);
	data->images.space.img = \
	mlx_xpm_file_to_image(data->mlx, "./imgs/space.xpm", &arr[0], &arr[1]);
	data->images.enemy.img = \
	mlx_xpm_file_to_image(data->mlx, "./imgs/enemy.xpm", &arr[0], &arr[1]);
}

void	set_data(t_data *data, t_list *map)
{
	data->mlx = mlx_init();
	data->win_x = (ft_strlen(map->str)) * 30;
	data->win_y = (list_len(map)) * 30;
	data->win = \
	mlx_new_window(data->mlx, data->win_x, data->win_y, "so long");
	data->moves = 0;
}
// int	ft_close(t_data *data)
// {
// 	mlx_destroy_window(data->mlx, data->win);
// 	return (0);
// }

void	destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->images.collectable.img);
	mlx_destroy_image(data->mlx, data->images.wall.img);
	mlx_destroy_image(data->mlx, data->images.player.img);
	mlx_destroy_image(data->mlx, data->images.space.img);
	mlx_destroy_image(data->mlx, data->images.exit.img);
}
