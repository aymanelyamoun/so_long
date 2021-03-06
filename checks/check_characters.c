/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:13:55 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/29 14:42:25 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	haschar(char *str, char c)
{
	int	has_c;

	has_c = 0;
	while (*str)
	{
		if (*str == c)
			has_c++;
		str++;
	}
	return (has_c);
}

int	check_p(t_list *list)
{
	int	player;
	int	has_c;

	player = 0;
	while (list != NULL)
	{
		has_c = haschar(list->str, 'P');
		if (has_c == 1)
			player++;
		else if (has_c > 1)
		{
			write(2, "Error\nThere is too many players\n", 32);
			return (0);
		}
		if (player > 1)
		{
			write(2, "Error\nThere is too many players\n", 32);
			return (0);
		}
		list = list->next;
	}
	return (1);
}

int	check_c(t_list *list)
{
	int	has_c;

	while (list != NULL)
	{
		has_c = haschar(list->str, 'C');
		if (has_c)
			return (1);
		list = list->next;
	}
	write(2, "Error\nThere is no collectibles\n", 31);
	return (0);
}

int	check_e(t_list *list)
{
	int	has_c;

	while (list != NULL)
	{
		has_c = haschar(list->str, 'E');
		if (has_c >= 1)
			return (1);
		list = list->next;
	}
	write(2, "Error\nThere is no exit\n", 23);
	return (0);
}
