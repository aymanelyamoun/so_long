#include "so_long.h"

static void move_right_asset(t_list **tmp, int	i, t_data *data)
{
	(*tmp)->str[i] = '0';
	(*tmp)->str[i+1] = 'P';
	data->moves += 1;
	ft_putnbr(data->moves);
	write(1, "\n", 1);
}
void	move_right(t_data *data)
{
	int i;
	t_list *tmp;

	tmp = data->map->next;
	while (tmp != NULL)
	{
		i = 0;
		while ((tmp->str[i] != 'P') && (tmp->str[i] != '\0'))
			i++;
		if ((tmp->str[i] == 'P') && (tmp->str[i+1] != '1') && (tmp->str[i+1] != 'E'))
			move_right_asset(&tmp, i, data);
		if (tmp->str[i+1] == 'E' && check_left_C(tmp) == 0)
		{
			move_right_asset(&tmp, i, data);
			draw(data->map, data);
			end_game(data);
		}
		tmp = tmp->next;
	}
}
static void move_left_asset(t_list **tmp, int	i, t_data *data)
{
	(*tmp)->str[i] = '0';
	(*tmp)->str[i-1] = 'P';
	data->moves += 1;
	ft_putnbr(data->moves);
	write(1, "\n", 1);
}
void	move_left(t_data *data)
{
	int i;
	t_list *tmp;

	tmp = data->map->next;
	while (tmp != NULL)
	{
		i = 0;
		while ((tmp->str[i] != 'P') && (tmp->str[i] != '\0'))
			i++;
		if ((tmp->str[i] == 'P') && (tmp->str[i-1] != '1') && (tmp->str[i-1] != 'E'))
			move_left_asset(&tmp, i, data);
		if (tmp->str[i-1] == 'E' && check_left_C(tmp) == 0)
		{
			move_left_asset(&tmp, i, data);
			draw(data->map, data);
			end_game(data);
		}
		tmp = tmp->next;
	}
}