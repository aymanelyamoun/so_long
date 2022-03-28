/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:50:17 by ael-yamo          #+#    #+#             */
/*   Updated: 2021/11/26 11:54:06 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

void	ft_free(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

char	*ft_line(char **line, char **rem)
{
	char	*to_free;
	int		b_n;

	to_free = *rem;
	b_n = detect_n(*rem);
	if (b_n != -1)
	{
		*line = ft_substr(*rem, 0, b_n + 1);
		*rem = ft_strdup(*rem + b_n + 1);
	}
	else
	{
		*line = ft_strdup(*rem);
		*rem = NULL;
	}
	ft_free(to_free);
	return (*line);
}

void	ft_read_file(int fd, char *buffer, char **rem, char **line)
{
	int		n;
	char	*to_free;

	n = 1;
	while ((detect_n(*rem) == -1) && n != 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		buffer[n] = '\0';
		to_free = *rem;
		*rem = ft_strjoin(*rem, buffer);
		free(to_free);
	}
	ft_line(line, rem);
}

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || (read(fd, buffer, 0) < 0))
		return (NULL);
	if (!rem)
		rem = ft_strdup("");
	ft_read_file(fd, buffer, &rem, &line);
	if (*line == '\0')
	{
		ft_free(line);
		return (NULL);
	}
	return (line);
}
