/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:59:40 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/22 11:30:38 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "get_next_line_SL/get_next_line.h"




int	check()
{
	t_list *last;
	t_list *parsed;

	parsed = parsing(&last);
	if (!(check_hrsntl(parsed->str, last->str) && check_vrtcl(parsed) && check_P(parsed)\
	&& check_C(parsed) && check_E(parsed) && check_outsiders(parsed) && check_if_rctnglr(parsed)))
		exit_game(&parsed);
	return (1);
}