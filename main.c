/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:59:58 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/25 21:54:13 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	init_imgs(t_data *data)
{
	int			arr[2];

	data->images.wall.img = mlx_xpm_file_to_image(data->mlx, "./imgs/wall.xpm", &arr[0], &arr[1]);
	data->images.player.img = mlx_xpm_file_to_image(data->mlx, "./imgs/player.xpm", &arr[0], &arr[1]);
	data->images.collectable.img = mlx_xpm_file_to_image(data->mlx, "./imgs/collectable.xpm", &arr[0], &arr[1]);
	data->images.exit.img = mlx_xpm_file_to_image(data->mlx, "./imgs/exit.xpm", &arr[0], &arr[1]);
	data->images.space.img = mlx_xpm_file_to_image(data->mlx, "./imgs/space.xpm", &arr[0], &arr[1]);
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

void	set_data(t_data *data, t_list *map)
{
	data->mlx = mlx_init();
	data->win_x = (ft_strlen(map->str))*30;
	data->win_y = (list_len(map))*30;
	data->win = mlx_new_window(data->mlx, data->win_x, data->win_y, "so long");
	data->moves = 0;
}

void	put_img(char c, t_data *data, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->images.wall.img, x, y);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->images.space.img, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->images.player.img, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->images.collectable.img, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->images.exit.img, x, y);
}

void	draw(t_list *map, t_data *data)
{
	int	i;
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(data->mlx, data->win);
	while (map != NULL)
	{
		i = 0;
		x = 0;
		while (map->str[i] != '\0')
		{
			put_img(map->str[i], data, x, y);
			x += 30;
			i++;
		}
		y += 30;
		map = map->next;
	}
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	return (0);
}

void	destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->images.collectable.img);
	mlx_destroy_image(data->mlx, data->images.wall.img);
	mlx_destroy_image(data->mlx, data->images.player.img);
	mlx_destroy_image(data->mlx, data->images.space.img);
	mlx_destroy_image(data->mlx, data->images.exit.img);
}

void	end_game(t_data *data)
{
	free_list(&(data->map));
	mlx_clear_window(data->mlx, data->win);
	destroy(data);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int check_left_C(t_list *list)
{
	int	has_c;

	while (list != NULL)
	{
		has_c = haschar(list->str, 'C');
		if (has_c)
			return (1);
		list = list->next;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void     ft_putnbr(int new_nb)
{
        const int		len = 10;
        char const		*base = "0123456789";
        int				nb;

        nb = new_nb;
        if (new_nb < 0)
        {
                ft_putchar('-');
                new_nb *= -1;
        }
        if (new_nb < len)
                ft_putchar(base[new_nb]);
        else
        {
                ft_putnbr(new_nb / len);
                ft_putnbr(new_nb % len);
        }
}

static void move_up_asset(t_list **tmp, int	i, t_data *data)
{
	(*tmp)->str[i] = '0';
	(*tmp)->prev->str[i] = 'P';
	data->moves += 1;
	ft_putnbr(data->moves);
	write(1, "\n", 1);
}

void	move_up(t_data *data)
{
	int i;
	t_list *tmp;

	tmp = data->map->next;
	while (tmp != NULL)
	{
		i = 0;
		while ((tmp->str[i] != 'P') && (tmp->str[i] != '\0'))
			i++;
		if ((tmp->str[i] == 'P') && (tmp->prev->str[i] != '1') && (tmp->prev->str[i] != 'E'))
			move_up_asset(&tmp, i, data);
		if (tmp->prev->str[i] == 'E' && check_left_C(tmp) == 0)
		{
			move_up_asset(&tmp, i, data);
			draw(data->map, data);
			end_game(data);
		}
		tmp = tmp->next;
	}
}

static void move_down_asset(t_list **tmp, int	i, t_data *data)
{
	(*tmp)->str[i] = '0';
	(*tmp)->next->str[i] = 'P';
	data->moves += 1;
	draw(data->map, data);
	ft_putnbr(data->moves);
	write(1, "\n", 1);
}

void	move_down(t_data *data)
{
	int i;
	t_list *tmp;

	tmp = data->map->next;
	while (tmp != NULL)
	{
		i = 0;
		while ((tmp->str[i] != 'P') && (tmp->str[i] != '\0'))
			i++;
		if ((tmp->str[i] == 'P') && (tmp->next->str[i] != '1') && (tmp->next->str[i] != 'E'))
		{
			move_down_asset(&tmp, i, data);
			break;
		}
		else if (tmp->next != NULL && tmp->next->str[i] == 'E' && check_left_C(data->map) == 0)
		{
			move_down_asset(&tmp, i, data);
			end_game(data);
		}
		tmp = tmp->next;
	}
}

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

int	moves(int key, t_data *data)
{
	if (key == 13)
		move_up(data);
	if (key == 0)
		move_left(data);
	if (key == 1)
		move_down(data);
	if (key == 2)
		move_right(data);
	if (key == 53)
		end_game(data);
	if (key == 13 || key == 0 || key == 1 || key == 2)
		draw(data->map ,data);
	return (0);
}

int	main()
{
	int				fd;
	t_data			data;

	fd = open("./map", O_RDONLY);
	data.map = check(fd);
	set_data(&data, data.map);
	init_imgs(&data);
	draw(data.map, &data);
	mlx_hook(data.win, 2, (1L<<2), moves, &data);
	mlx_loop(data.mlx);
	return (0);
}