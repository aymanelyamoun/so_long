#include "list.h"


static t_list *creat_node(char **str)
{
	t_list *node;

	node = malloc(sizeof(t_list *));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->str = *str;
	return (node);
}

static void	free_list(t_list **list)
{
	t_list *to_free;

	while ((*list) != NULL)
	{
		to_free = *list;
		(*list) = (*list)->next;
		free(to_free->str);
		free(to_free);
	}
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
}