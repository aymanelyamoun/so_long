/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:59:47 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/28 21:17:31 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static char	*strdup_no_n(char **str)
{
	int		i;
	char	*new_str;

	i = 0;
	if (*str == NULL)
		return (NULL);
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
		i++;
	new_str = malloc(sizeof(char) * i + 1);
	i = 0;
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
	{
		new_str[i] = (*str)[i];
		i++;
	}
	new_str[i] = '\0';
	free(*str);
	return (new_str);
}

t_list	*parsing(t_list **last, int fd)
{
	char	*line;
	char	*str;
	t_list	*parsed;

	parsed = NULL;
	while (69)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		str = strdup_no_n(&line);
		*last = add_at_end(last, &str);
		if (parsed == NULL)
			parsed = *last;
	}
	return (parsed);
}
