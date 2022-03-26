/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_outsider_enemy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:57:30 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/26 17:10:46 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_outsiders(t_list *list)
{
	char	*str;

	while (list != NULL)
	{
		str = list->str;
		while (*str == '1' || *str == '0' || *str == 'E' || \
		*str == 'P' || *str == 'C' || *str == 'O')
		{
			str++;
		}
		if (*str != '\0')
		{
			write(2, "Error\nThere is an outsider\n", 27);
			return (0);
		}
		list = list->next;
	}
	return (1);
}
