/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:16:02 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/28 21:17:31 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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
