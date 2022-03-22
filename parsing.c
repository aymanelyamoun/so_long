/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:59:47 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/22 11:27:51 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "list.h"
#include "get_next_line_SL/get_next_line.h"

static char	*strdup_no_n(char **str)
{
	int 	i;
	char	*new_str;

	i = 0;
	if (*str == NULL)
		return (NULL);
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
		i++;
	new_str = malloc(sizeof(char)*i + 1);
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

t_list	*parsing(t_list **last)
{
	int		fd;
	char	*line;
	char	*str;
	t_list	*parsed;

	fd = open("map", O_RDONLY);
	str = get_next_line(fd);
	
	while (1337)
	{
		line = get_next_line(fd);
		str = strdup_no_n(&line);
		if (str == NULL)
			break;
		*last = add_at_end(&parsed, &str);
	}
	return (parsed);
}