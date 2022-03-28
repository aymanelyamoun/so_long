/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:15:31 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/28 21:17:31 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	init_imgs(t_data *data)
{
	int			arr[2];

	data->images.wall.img = \
	mlx_xpm_file_to_image(data->mlx, "./imgs/wall.xpm", &arr[0], &arr[1]);
	if (data->images.wall.img == NULL)
		end_game(data, -1);
	data->images.player.img = \
	mlx_xpm_file_to_image(data->mlx, "./imgs/player.xpm", &arr[0], &arr[1]);
	if (data->images.player.img == NULL)
		end_game(data, -1);
	data->images.collectable.img = \
	mlx_xpm_file_to_image(data->mlx, "./imgs/collec.xpm", &arr[0], &arr[1]);
	if (data->images.collectable.img == NULL)
		end_game(data, -1);
	data->images.exit.img = \
	mlx_xpm_file_to_image(data->mlx, "./imgs/exit.xpm", &arr[0], &arr[1]);
	if (data->images.exit.img == NULL)
		end_game(data, -1);
	data->images.space.img = \
	mlx_xpm_file_to_image(data->mlx, "./imgs/space.xpm", &arr[0], &arr[1]);
	if (data->images.space.img == NULL)
		end_game(data, -1);
}

void	set_data(t_data *data, t_list *map)
{
	data->mlx = mlx_init();
	data->win_x = (ft_strlen(map->str)) * 30;
	data->win_y = (list_len(map)) * 30;
	data->win = mlx_new_window(data->mlx, data->win_x, data->win_y, "so long");
	data->moves = 0;
}

void	destroy(t_data *data)
{
	if (data->images.collectable.img != NULL)
		mlx_destroy_image(data->mlx, data->images.collectable.img);
	if (data->images.wall.img != NULL)
		mlx_destroy_image(data->mlx, data->images.wall.img);
	if (data->images.player.img != NULL)
		mlx_destroy_image(data->mlx, data->images.player.img);
	if (data->images.space.img != NULL)
		mlx_destroy_image(data->mlx, data->images.space.img);
	if (data->images.exit.img != NULL)
		mlx_destroy_image(data->mlx, data->images.exit.img);
}
