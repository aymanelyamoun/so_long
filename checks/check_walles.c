/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:59:35 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/28 21:17:31 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	check_line(char *str)
{
	while (*str)
	{
		if (*str != '1')
			return (0);
		str++;
	}
	return (1);
}

int	check_hrsntl(char *first, char *last)
{
	if (check_line(first) && check_line(last))
	{
		return (1);
	}
	write(2, "Error\nSome thing wrong with the horizontal walles\n", 50);
	return (0);
}

static int	check_r_l(char *str)
{
	int	len;

	len = ft_strlen(str);
	if ((str[0] != '1') || (str[len - 1] != '1'))
	{
		write(2, "Error\nSome thing wrong with the vertical walles\n", 48);
		return (0);
	}
	else
		return (1);
}

int	check_vrtcl(t_list *list)
{
	while (list != NULL)
	{
		if (check_r_l(list->str) == 0)
			return (0);
		list = list->next;
	}
	return (1);
}
