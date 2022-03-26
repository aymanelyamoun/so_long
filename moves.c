/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:45:50 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/26 18:49:22 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up_asset(t_list **tmp, int i, t_data *data)
{
	(*tmp)->str[i] = '0';
	(*tmp)->prev->str[i] = 'P';
	draw(data->map, data);
	data->moves += 1;
	ft_putnbr(data->moves);
	write(1, "\n", 1);
}

void	move_up(t_data *data)
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
		(tmp->prev->str[i] != '1') && (tmp->prev->str[i] == 'O'))
			game_over(data);
		if ((tmp->str[i] == 'P') && \
		(tmp->prev->str[i] != '1') && (tmp->prev->str[i] != 'E'))
			move_up_asset(&tmp, i, data);
		if (tmp->prev->str[i] == 'E' && check_left_C(data->map) == 0)
			(move_up_asset(&tmp, i, data), end_game(data));
		tmp = tmp->next;
	}
}

static void	move_down_asset(t_list **tmp, int i, t_data *data)
{
	(*tmp)->str[i] = '0';
	(*tmp)->next->str[i] = 'P';
	draw(data->map, data);
	data->moves += 1;
	ft_putnbr(data->moves);
	write(1, "\n", 1);
}

void	move_down(t_data *data)
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
		(tmp->next->str[i] != '1') && (tmp->next->str[i] == 'O'))
			game_over(data);
		if ((tmp->str[i] == 'P') && \
		(tmp->next->str[i] != '1') && (tmp->next->str[i] != 'E'))
		{
			move_down_asset(&tmp, i, data);
			break ;
		}
		else if (tmp->next != NULL && \
		tmp->next->str[i] == 'E' && check_left_C(data->map) == 0)
			(move_down_asset(&tmp, i, data), end_game(data));
		tmp = tmp->next;
	}
}
