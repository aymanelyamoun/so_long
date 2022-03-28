/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:31:26 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/28 15:42:05 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_p(t_data *data)
{
	if (data->p.p1.img != NULL)
		mlx_destroy_image(data->mlx, data->p.p1.img);
	if (data->p.p2.img != NULL)
		mlx_destroy_image(data->mlx, data->p.p2.img);
	if (data->p.p.img != NULL)
		mlx_destroy_image(data->mlx, data->p.p.img);
}
