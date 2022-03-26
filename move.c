/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:23:53 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/26 18:24:36 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		draw(data->map, data);
	return (0);
}
