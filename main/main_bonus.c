/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:47:31 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/28 21:17:31 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*st1;
	char	*st2;

	i = 0;
	st1 = (char *)s1;
	st2 = (char *)s2;
	while (i < n && st1[i] && st2[i] && st1[i] == st2[i])
		i++;
	if (i == n || st2[i] == st1[i])
		return (0);
	return ((unsigned char)(st1[i]) - (unsigned char)(st2[i]));
}

static int	is_ber_at_end(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	if (i > 4)
	{
		return (ft_strncmp((str + i - 4), ".ber", 4));
	}
	else
		return (1);
}

int	animat(t_data *data)
{
	int	random;

	random = (rand() % (2 - 0 + 1)) + 0;
	if (random == 0)
	{
		data->images.player.img = data->p.p.img;
		draw(data->map, data);
		usleep(15000);
	}
	else if (random == 1)
	{
		data->images.player.img = data->p.p1.img;
		draw(data->map, data);
		usleep(15000);
	}
	else if (random == 2)
	{
		data->images.player.img = data->p.p2.img;
		draw(data->map, data);
		usleep(15000);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	if (argc == 2)
	{
		if (is_ber_at_end(argv[1]))
			exit (1);
		fd = open(argv[argc - argc + 1], O_RDONLY);
		data.map = check(fd);
		set_data(&data, data.map);
		init_imgs(&data);
		init_imgs_p(&data);
		draw(data.map, &data);
		mlx_hook(data.win, 2, (1L << 2), moves, &data);
		mlx_loop_hook(data.mlx, animat, (void *)(&data));
		mlx_loop(data.mlx);
		return (0);
	}
	return (1);
}
