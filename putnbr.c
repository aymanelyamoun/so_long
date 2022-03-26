/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:54:36 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/26 18:57:47 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int new_nb)
{
	const int	len = 10;
	char const	*base = "0123456789";
	int			nb;

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
