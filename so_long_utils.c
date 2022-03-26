/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:30:55 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/26 19:10:45 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_list **list)
{
	free_list(list);
	*list = NULL;
	exit(1);
}

void	end_game(t_data *data)
{
	free_list(&(data->map));
	mlx_clear_window(data->mlx, data->win);
	destroy(data);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	game_over(t_data *data)
{
	write(1, "FIN AWA RADI\n", 13);
	end_game(data);
}

int	check_left_C(t_list *list)
{
	int has_c;

	while (list != NULL)
	{
		has_c = haschar(list->str, 'C');
		if (has_c)
			return (1);
		list = list->next;
	}
	return (0);
}
