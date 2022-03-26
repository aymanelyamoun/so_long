/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:47:19 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/26 17:17:10 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

static void	put_img(char c, t_data *data, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, \
		data->win, data->images.wall.img, x, y);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, \
		data->win, data->images.space.img, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx, \
		data->win, data->images.player.img, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, \
		data->win, data->images.collectable.img, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, \
		data->win, data->images.exit.img, x, y);
	else if (c == 'O')
		mlx_put_image_to_window(data->mlx, \
		data->win, data->images.enemy.img, x, y);
}

void	draw(t_list *map, t_data *data)
{
	int	i;
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(data->mlx, data->win);
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
}
