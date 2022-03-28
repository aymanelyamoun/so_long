/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:49:42 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/28 21:17:31 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	move_right_asset(t_list **tmp, int i, t_data *data)
{
	(*tmp)->str[i] = '0';
	(*tmp)->str[i + 1] = 'P';
	draw(data->map, data);
	data->moves += 1;
	ft_putnbr(data->moves);
	write(1, "\n", 1);
}

void	move_right(t_data *data)
{
	int		i;
	t_list	*tmp;

	tmp = data->map->next;
	while (tmp != NULL)
	{
		i = 0;
		while ((tmp->str[i] != 'P') && (tmp->str[i] != '\0'))
			i++;
		if ((tmp->str[i] == 'P') && \
		(tmp->str[i + 1] != '1') && (tmp->str[i + 1] == 'O'))
			game_over(data);
		if ((tmp->str[i] == 'P') && \
		(tmp->str[i + 1] != '1') && (tmp->str[i + 1] != 'E'))
			move_right_asset(&tmp, i, data);
		if (tmp->str[i + 1] == 'E' && check_left_c(data->map) == 0)
		{
			move_right_asset(&tmp, i, data);
			end_game(data, 1);
		}
		tmp = tmp->next;
	}
}

static void	move_left_asset(t_list **tmp, int i, t_data *data)
{
	(*tmp)->str[i] = '0';
	(*tmp)->str[i - 1] = 'P';
	draw(data->map, data);
	data->moves += 1;
	ft_putnbr(data->moves);
	write(1, "\n", 1);
}

void	move_left(t_data *data)
{
	int		i;
	t_list	*tmp;

	tmp = data->map->next;
	while (tmp != NULL)
	{
		i = 0;
		while ((tmp->str[i] != 'P') && (tmp->str[i] != '\0'))
			i++;
		if ((tmp->str[i] == 'P') && \
		(tmp->str[i - 1] != '1') && (tmp->str[i - 1] == 'O'))
			game_over(data);
		if ((tmp->str[i] == 'P') && \
		(tmp->str[i - 1] != '1') && (tmp->str[i - 1] != 'E'))
			move_left_asset(&tmp, i, data);
		if (tmp->str[i - 1] == 'E' && check_left_c(data->map) == 0)
			(move_left_asset(&tmp, i, data), end_game(data, 1));
		tmp = tmp->next;
	}
}
