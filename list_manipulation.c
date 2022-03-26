/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:13:20 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/26 14:55:50 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_list *creat_node(char **str)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->str = *str;
	return (node);
}

void	free_list(t_list **list)
{
	t_list *to_free;

	while ((*list) != NULL)
	{
		to_free = *list;
		(*list) = (*list)->next;
		free(to_free->str);
		free(to_free);
	}
	*list = NULL;
}

t_list *add_at_end(t_list **list, char **str)
{
	t_list	*node;

	node = creat_node(str);
	if (node)
	{
		if (*list == NULL)
			*list = node;
		else
		{
			(*list)->next = node;
			node->prev = (*list);
		}
	}
	else
	{
		free_list(list);
		write(2, "Error\n", 6);
		write(2, "aji ... ash tadir ta tma / (couldn't allocat memory)\n", 54);
		exit(1);
	}
	return (node);
}

int	list_len(t_list *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}