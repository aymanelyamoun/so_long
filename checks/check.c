/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:59:40 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/28 21:17:31 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

t_list	*check(int fd)
{
	t_list	*last;
	t_list	*parsed;

	last = NULL;
	parsed = parsing(&last, fd);
	if (!(check_if_rctnglr(parsed) && check_hrsntl(parsed->str, last->str) \
	&& check_vrtcl(parsed) && check_p(parsed) && check_c(parsed) \
	&& check_e(parsed) && check_outsiders(parsed)))
		exit_game(&parsed);
	return (parsed);
}
