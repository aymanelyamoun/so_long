/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:59:40 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/24 14:12:25 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_SL/get_next_line.h"
#include "so_long.h"


t_list	*check(int fd)
{
	t_list *last;
	t_list *parsed;

	last = NULL;
	parsed = parsing(&last, fd);
	if (!(check_if_rctnglr(parsed) && check_hrsntl(parsed->str, last->str) && check_vrtcl(parsed) && check_P(parsed)\
	&& check_C(parsed) && check_E(parsed) && check_outsiders(parsed)))
		exit_game(&parsed);
	return (parsed);
}