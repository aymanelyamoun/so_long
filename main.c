/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:59:58 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/26 14:45:30 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>


int	moves(int key, t_data *data)
{
	if (key == 13)
		move_up(data);
	if (key == 0)
		move_left(data);
	if (key == 1)
		move_down(data);
	if (key == 2)
		move_right(data);
	if (key == 53)
		end_game(data);
	if (key == 13 || key == 0 || key == 1 || key == 2)
		draw(data->map ,data);
	return (0);
}

int	main()
{
	int				fd;
	t_data			data;

	fd = open("./map", O_RDONLY);
	data.map = check(fd);
	set_data(&data, data.map);
	init_imgs(&data);
	draw(data.map, &data);
	mlx_hook(data.win, 2, (1L<<2), moves, &data);
	mlx_loop(data.mlx);
	return (0);
}