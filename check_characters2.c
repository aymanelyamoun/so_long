/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:16:02 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/22 11:25:18 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	check_outsiders(t_list *list)
{
	int		has_outsdr;
	char	*str;
	
	while (list != NULL)
	{
		str = list->str;
		while (*str == '1' || *str == '0' || *str == 'E' ||\
		*str == 'P' || *str == 'C')
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

int	check_if_rctnglr(t_list *list)
{
	t_list	*next;

	while (list->next != NULL)
	{
		next = list->next;
		if (ft_strlen(list->str) != ft_strlen(next->str))
		{
			write(2, "Error\nThe map isn't rectangular\n", 32);
			return (0);
		}
		list = list->next;
	}
	return (1);
}
