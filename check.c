#include <fcntl.h>
#include "list.h"
#include "get_next_line_SL/get_next_line.h"

char	*strdup_no_n(char **str)
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

int check_line(char *str)
{
	while (*str)
	{
			if (*str != '1')
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			str++;
	}
	return (1);
}

int check_hrsntl(char *first, char *last)
{
	check_line(first);
	check_line(last);
	return (1);
}

int	check_r_l(char *str)
{
	int	len;
	
	len = ft_strlen(str);
	if ((str[0] != '1') || (str[len] != '1'))
	{
		write(2, "Error\n", 6);
		exit(1);	
	}
	else
		return (1);
}

int	check_vrtcl(t_list *list)
{
	while (list != NULL)
	{
		check_r_l(list->str);
		list = list->next;
	}
	return (1);
}

int haschar(char *str, char c)
{
	int	has_c;

	while (*str)
	{
		if (*str == c)
			has_c++;
		str++;
	}
	return (has_c);
}

int check_P(t_list *list)
{
	int	player;
	int	has_c;
	while (list != NULL)
	{
		has_c = haschar(list->str, 'P');
		if (has_c == 1)
			player++;
		else if (has_c > 1)
		{
			write(2, "Error\nThere is no player to play\n", 35);
		}
		if (player > 1)
			write(2, "Error\nThere is too many players\n", 34);
		list = list->next;
	}
	return (1);	
}

int check_C(t_list *list)
{
	int	col;
	int	has_c;
	while (list != NULL)
	{
		has_c = haschar(list->str, 'C');
		if (has_c >= 1)
			return (1);
		list = list->next;
	}
	return (0);	
}

int check_E(t_list *list)
{
	int	has_c;
	while (list != NULL)
	{
		has_c = haschar(list->str, 'E');
		if (has_c >= 1)
			return (1);
		list = list->next;
	}
	return (0);	
}

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
			return (0);
		list = list->next;
	}
	return (1);
}

int	check_if_rctnglr(t_list *list)
{
	while (list->next != NULL)
	{
		if (ft_strlen(list->str) != ft_strlen(list->next->str))
			return (0);
		list = list->next;
	}
	
}
int	check()
{
	t_list *last;
	t_list *parsed;

	parsed = parsing(&last);
	if (check_hrsntl(parsed->str, last->str) && check_vrtcl(parsed))
	{

	}
}