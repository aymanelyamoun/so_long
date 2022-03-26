/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:23:53 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/26 20:43:48 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	swich(t_data *data, int shap)
// {
// 	t_img_data	tmp;

// 	tmp.img = data->images.player.img;
// 	if (shap == 0)
// 		data->images.player.img = mlx_;
// }

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
		end_game(data, 53);
	if (key == 13 || key == 0 || key == 1 || key == 2)
		draw(data->map, data);
	return (0);
}
